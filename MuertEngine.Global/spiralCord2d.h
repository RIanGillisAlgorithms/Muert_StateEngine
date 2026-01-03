

//by ian.gillis
#pragma once
#ifndef SPIRAL_CORD_2D_H
#define SPIRAL_CORD_2D_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define SPIRAL_CORD_2D_H_API __declspec(dllexport)
#else
#define SPIRAL_CORD_2D_H_API __declspec(dllimport)
#endif


#include <vector>
#include <map>
#include "structureDefinitions.h"


namespace SPATIAL
{

	class SPIRAL_CORD_2D_H_API SPIRAL_CORD_2d
	{
	public:
		SPIRAL_CORD_2d(int InitialRadius = 0);
		~SPIRAL_CORD_2d();

		int spiralCoordOffsetToPos(Point2D Offset);
		int spiralCoordOffsetToIndex(Point2D Offset);
		Point2D spiralPosToCoordOffset(int Pos);
		Point2D spiralIndexToCoordOffset(int Index);

		void initSpiral(int InitialRadius = 0);
		//starts at 0
		int curSliceRadius;
		//starts at 1 (i.e. 1x1, 3x3 etc.)
		int curMapSize;
		void initNextSliceRadius(int NumberOfRingsToInit = 1);

	private:
		std::vector<Point2D> spiralOffsets;
		std::map<Point2D, int> spiralOffsetsMap;
		//std::vector<std::vector<int>> spiralOffsetsMap;
	};

	extern "C" SPIRAL_CORD_2D_H_API SPIRAL_CORD_2d SpiralCord2d;

}


#endif