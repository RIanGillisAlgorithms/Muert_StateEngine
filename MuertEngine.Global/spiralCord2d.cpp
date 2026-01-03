#include "pch.h"
#include "spiralCord2d.h"
#include <sstream>
#include "coordFunctions.h"
#include "globalLogging.h"

namespace SPATIAL
{

	SPIRAL_CORD_2d SpiralCord2d;


	SPIRAL_CORD_2d::SPIRAL_CORD_2d(int InitialRadius /*= 0*/)
	{					  		
		this->initSpiral(InitialRadius);
	}

	SPIRAL_CORD_2d::~SPIRAL_CORD_2d()
	{

	}

	int SPIRAL_CORD_2d::spiralCoordOffsetToPos(Point2D Offset)
	{
		return spiralCoordOffsetToIndex(Offset) + 1;
	}
	int SPIRAL_CORD_2d::spiralCoordOffsetToIndex(Point2D Offset)
	{
		if (Offset.x == 0 && Offset.y == 0)
		{
			return 0;
		}		
		int largestInteger = abs(Offset.GetX()) > abs(Offset.GetY())?
			abs(Offset.GetX()) : abs(Offset.GetY());
		if (largestInteger > 100)
		{
			std::stringstream tt;
			tt << "WARNING: LargestInteger > 100 (" << largestInteger << ")";
			throw std::logic_error(tt.str());
		}
		if (largestInteger > this->curSliceRadius)
		{
			//expand!
			this->initNextSliceRadius(largestInteger - curSliceRadius);
		}
		int indexToStartOn = ((largestInteger-1) * 2) + 1;
		indexToStartOn *= indexToStartOn;
		int indexToEndOn = (largestInteger * 2) + 1;
		indexToEndOn *= indexToEndOn;
		for (int pix = indexToStartOn; pix <= indexToEndOn; pix++)
		{
			if (this->spiralOffsets[pix] == Offset)
			{
				return pix;
			}
		}
		
		//the offset was not located in the expected radius...
		std::stringstream tt;
		tt << "WARNING: Performance degradation::Offset [" << Offset.GetX() << "," << Offset.GetY() << "] not found in expected radius. Searching entire spiralOffsets vector.";
		GLOBAL::Log("SPIRAL_CORD_2d", tt.str());
		for (int pix = 0; pix < this->spiralOffsets.size(); pix++)
		{
			if (this->spiralOffsets[pix] == Offset)
			{
				return pix;
			}
		}	
		tt.str("");
		tt << "Offset [" << Offset.GetX() << "," << Offset.GetY() << "] could not be located within the spiral radius of:"<<this->curSliceRadius<<" with map size:"<<this->curMapSize;
		GLOBAL::Log("SPIRAL_CORD_2d", tt.str());
	}

	Point2D SPIRAL_CORD_2d::spiralPosToCoordOffset(int Pos)
	{
		return spiralPosToCoordOffset(Pos - 1);
	}
	Point2D SPIRAL_CORD_2d::spiralIndexToCoordOffset(int Index)
	{
		if (Index < 0)
		{
			std::stringstream tt;
			tt << "Index cannot be less than 0. Index: " << Index;
			throw std::logic_error(tt.str());
		}
		if (Index >= this->spiralOffsets.size())
		{
			//how much more radius do we need?
			int moreRadius = 0;
			while (Index > (((moreRadius + this->curSliceRadius) * 2) - 1)
				* (((moreRadius + this->curSliceRadius) * 2) - 1))
			{
				moreRadius++;
			}
			if (moreRadius > 10)
			{
				std::stringstream tt;
				tt << "Index (" << Index << ") would increase the current radius by: " << moreRadius;
				throw std::logic_error(tt.str());
			}			
			this->initNextSliceRadius(moreRadius);
		}

		return this->spiralOffsets[Index];
	}

	void SPIRAL_CORD_2d::initSpiral(int InitialRadius /*= 0*/)
	{ 
		this->spiralOffsets.clear();
		this->spiralOffsetsMap.clear();

		this->spiralOffsets.push_back(Point2D(0, 0));
		//this->spiralOffsetsMap.push_back(std::vector<int>());
		this->spiralOffsetsMap[Point2D(0, 0)] = 0;
		//this->spiralOffsetsMap[0].push_back(0)
		//this->spiralOffsetsMap[0][0] = 0;
		//1x1
		this->curMapSize = 1;
		//radius=0
		this->curSliceRadius = 0;
		for (int pix = 0; pix < InitialRadius; pix++)
		{
			this->initNextSliceRadius();
		}
	}		

	void SPIRAL_CORD_2d::initNextSliceRadius(int NumberOfRingsToInit /*= 1*/)
	{
		for (int pix = 0; pix < NumberOfRingsToInit; pix++)
		{
			curSliceRadius++;
			curMapSize = (curSliceRadius * 2) + 1;
			int numMapsToAdd = (curMapSize * curMapSize) - this->spiralOffsets.size();
			Point2D CenterCordOffset;
			int curDir = 4;
			int firstTurnPoint = numMapsToAdd / 4;
			int curTurnPoint = firstTurnPoint - 1;
			//the start offset
			//CenterCordOffset.Set((curSliceRadius - 1) * -1, curSliceRadius);
			CenterCordOffset.Set((curSliceRadius - 1), curSliceRadius);

			for (int pix = 0; pix < numMapsToAdd; pix++)
			{					
				this->spiralOffsets.push_back(CenterCordOffset);
				this->spiralOffsetsMap[CenterCordOffset] = this->spiralOffsets.size() - 1;
				if (pix == curTurnPoint)
				{
					//turn counterclockwise
					curDir = CORDFUNC::nextDir(curDir, false);
					curDir = CORDFUNC::nextDir(curDir, false);
					curTurnPoint += firstTurnPoint;
				}
				CenterCordOffset = CenterCordOffset + CORDFUNC::dirToCoord(curDir, true);
			}
		}
	}
}

