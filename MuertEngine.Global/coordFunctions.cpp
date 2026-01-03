#include "pch.h"
#include "coordFunctions.h"
#include "point3.h"
#include <sstream>
#include "spiralCord2d.h"

namespace CORDFUNC
{

	Point2D dirToCoord(int dir, bool eightDir)
	{
		Point2D out;
		out.SetX(0);
		out.SetY(0);
		if (eightDir)
		{
			//there are eight directions!
			//so:
			//			1 = sw
			//			2 = s
			//			3 = se
			//			4 = west
			//			6 = east
			//			7 = nw
			//			8 = n
			//			9 = ne

			switch (dir)
			{
			case 1:
				out.SetX(-1);
				out.SetY(-1);
				break;
			case 2:
				out.SetX(0);
				out.SetY(-1);
				break;
			case 3:
				out.SetX(1);
				out.SetY(-1);
				break;
			case 4:
				out.SetX(-1);
				out.SetY(0);
				break;
			case 6:
				out.SetX(1);
				out.SetY(0);
				break;
			case 7:
				out.SetX(-1);
				out.SetY(1);
				break;
			case 8:
				out.SetX(0);
				out.SetY(1);
				break;
			case 9:
				out.SetX(1);
				out.SetY(1);
				break;

			}

		}
		else
		{
			//no eight directions
			switch (dir)
			{
			case 1:
			case 2:
				out.SetX(0);
				out.SetY(1);
				break;
			case 3:
			case 6:
				out.SetX(1);
				out.SetY(0);
				break;
			case 8:
			case 9:
				out.SetX(0);
				out.SetY(-1);
				break;
			case 4:
			case 7:
				out.SetX(-1);
				out.SetY(0);
				break;
			}
		}
		return out;
	}
	int coordToDir(Point2D coord, bool eightDir)
	{
		int out = -1;
		if (eightDir)
		{
			if (coord.GetX() == -1 && coord.GetY() == -1)
			{
				out = 1;
			}
			else if (coord.GetX() == 0 && coord.GetY() == -1)
			{
				out = 2;
			}
			else if (coord.GetX() == 1 && coord.GetY() == -1)
			{
				out = 3;
			}
			else if (coord.GetX() == -1 && coord.GetY() == 0)
			{
				out = 4;
			}
			else if (coord.GetX() == 1 && coord.GetY() == 0)
			{
				out = 6;
			}
			else if (coord.GetX() == -1 && coord.GetY() == 1)
			{
				out = 7;
			}
			else if (coord.GetX() == 0 && coord.GetY() == 1)
			{
				out = 8;
			}
			else if (coord.GetX() == 1 && coord.GetY() == 1)
			{
				out = 9;
			}
			else if (coord.GetX() == 0 && coord.GetY() == 0)
			{
				out = 5;
			}

		}
		else
		{
			//only 4 directions
			if (coord.GetX() == -1)
			{
				out = 3;
			}
			else if (coord.GetX() == 1)
			{
				out = 1;
			}
			else if (coord.GetY() == -1)
			{
				out = 0;
			}
			else if (coord.GetY() == 1)
			{
				out = 2;
			}
		}

		return out;

	}

	Point2D spiralIndexToCoordOffset2d(int pos)
	{
		if (pos < 0)
		{
			std::stringstream tt;
			tt << "Invalid spiral position: " << pos;
			throw new std::logic_error(tt.str());
		}

		return SPATIAL::SpiralCord2d.spiralIndexToCoordOffset(pos);

		std::stringstream tt;
		tt << "Invalid spiral position: " << pos << " (has the lazy switch CORDFUNC::spiralPosToCoordOffset been expanded to this level? If not then feast your eyes on the draw-backs of being lazy and letting ai generate switch statements for you instead of figuring out a math algo. Stupid lazy programmer. [The Programmer: I was on vacaation in Turks & Caicos at the time, so I have a good excuse for not wanting to do math])";
		throw new std::logic_error(tt.str());
	}

	int coordOffset2dToSpiralIndex(Point2D cordOffset)
	{
		return SPATIAL::SpiralCord2d.spiralCoordOffsetToIndex(cordOffset);
	}

	int nextDir(int curDir, bool clockwise)
	{
		//this rotates the direction clockwise or counterclockwise

		if (clockwise)
		{
			switch (curDir)
			{
			case 1:
				return 4;
				break;
			case 2:
				return 1;
				break;
			case 3:
				return 2;
				break;
			case 4:
				return 7;
				break;
			case 6:
				return 3;
				break;
			case 7:
				return 8;
				break;
			case 8:
				return 9;
				break;
			case 9:
				return 6;
				break;

			}
		}
		else
		{
			//counterclockwise
			switch (curDir)
			{
			case 1:
				return 2;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 6;
				break;
			case 4:
				return 1;
				break;
			case 6:
				return 9;
				break;
			case 7:
				return 4;
				break;
			case 8:
				return 7;
				break;
			case 9:
				return 8;
				break;

			}
		}

		//broken if you get to this point!
		return -1;

	}
	void getAllDirsBetweenTwoDirs(int startDir, int endDir, std::vector<int> &Dirs)
	{
		if (Dirs.size() != 0)
		{
			Dirs.clear();
		}

		bool isClockwise = true;
		bool found = false;
		int tempClock = startDir;
		int tempCounter = startDir;
		std::vector<int> clockwiseDirs;
		std::vector<int> counterClockwiseDirs;
		while (!found)
		{
			clockwiseDirs.push_back(tempClock);
			if (tempClock == endDir)
			{
				Dirs = clockwiseDirs;
				return;
			}
			counterClockwiseDirs.push_back(tempCounter);
			if (tempCounter == endDir)
			{
				Dirs = counterClockwiseDirs;
				return;
			}
			tempClock = nextDir(tempClock, true);
			tempCounter = nextDir(tempCounter, false);
		}
	}

	void getAllDirsBetweenTwoDirsTopDown(std::vector<int>& toFill, int botLeftDir, int topRightDir)
	{
		if (botLeftDir == topRightDir)
		{
			toFill.push_back(botLeftDir);
		}
		switch (botLeftDir)
		{
		case 1:
		{
			switch (topRightDir)
			{
			case 2:
			{
				toFill.push_back(1);
				toFill.push_back(2);
			}
			case 3:
			{
				toFill.push_back(1);
				toFill.push_back(2);
				toFill.push_back(3);
			}
			case 4:
			{
				toFill.push_back(1);
				toFill.push_back(4);
			}
			case 5:
			{
				toFill.push_back(1);
				toFill.push_back(2);
				toFill.push_back(4);
				toFill.push_back(5);
			}
			case 6:
			{
				toFill.push_back(1);
				toFill.push_back(2);
				toFill.push_back(3);
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(6);
			}
			case 7:
			{
				toFill.push_back(1);
				toFill.push_back(4);
				toFill.push_back(7);
			}
			case 8:
			{
				toFill.push_back(1);
				toFill.push_back(2);
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(7);
				toFill.push_back(8);
			}
			case 9:
			{
				toFill.push_back(1);
				toFill.push_back(2);
				toFill.push_back(3);
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(6);
				toFill.push_back(7);
				toFill.push_back(8);
				toFill.push_back(9);
			}				
			}
		}
		case 2:
		{
			switch(topRightDir)
			{
			case 3:
			{
				toFill.push_back(2);
				toFill.push_back(3);
			}
			case 5:
			{
				toFill.push_back(2);
				toFill.push_back(5);
			}
			case 6:
			{
				toFill.push_back(2);
				toFill.push_back(3);
				toFill.push_back(5);
				toFill.push_back(6);
			}
			case 8:
			{
				toFill.push_back(2);
				toFill.push_back(5); 
				toFill.push_back(8);
			}
			case 9:
			{
				toFill.push_back(2);
				toFill.push_back(3);
				toFill.push_back(5);
				toFill.push_back(6);
				toFill.push_back(8);
				toFill.push_back(9);
			}
			}
		}
		case 3:
		{
			switch (topRightDir)
			{
			case 6:
			{
				toFill.push_back(3);
				toFill.push_back(6);
			}
			case 9:
			{
				toFill.push_back(3);
				toFill.push_back(6);
				toFill.push_back(9);
			}
			}
		}
		case 4:
		{
			switch (topRightDir)
			{
			case 5:
			{
				toFill.push_back(4);
				toFill.push_back(5);
			}
			case 6:
			{
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(6);
			}
			case 7:
			{
				toFill.push_back(4);
				toFill.push_back(7);
			}
			case 8:
			{
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(7);
				toFill.push_back(8);
			}
			case 9:
			{
				toFill.push_back(4);
				toFill.push_back(5);
				toFill.push_back(6);
				toFill.push_back(7);
				toFill.push_back(8);
				toFill.push_back(9);
			}
			}
		}
		case 5:
		{
			switch (topRightDir)
			{
			case 6:
			{
				toFill.push_back(5);
				toFill.push_back(6);
			}
			case 8:
			{
				toFill.push_back(5);
				toFill.push_back(8);
			}
			case 9:
			{
				toFill.push_back(5);
				toFill.push_back(6);
				toFill.push_back(8);
				toFill.push_back(9);
			}
			}
		}
		case 6:
		{
			switch (topRightDir)
			{
			case 9:
			{
				toFill.push_back(6);
				toFill.push_back(9);
			}
			}
		}
		case 7:
		{
			switch (topRightDir)
			{
			case 8:
			{
				toFill.push_back(7);
				toFill.push_back(8);
			}
			case 9:
			{
				toFill.push_back(7);
				toFill.push_back(8);
				toFill.push_back(9);
			}
			}
		}
		case 8:
		{
			switch (topRightDir)
			{
			case 9:
			{
				toFill.push_back(8);
				toFill.push_back(9);
			}
			}

		}
		}
		std::stringstream tt;
		tt << "Invalid directions: botLeftDir: " << botLeftDir << " topRightDir: " << topRightDir;
		throw std::logic_error(tt.str());
	}

	Point2D cordSlope(int x1, int y1, int x2, int y2)
	{
		//Point2D out;
		//out.SetX(x2 - x1);
		//out.SetY(y2 - y1);
		return Point2D(x2 - x1, y2 - y1);
		//return out;
	}
	DOUBLEBOOL doubleSlope(Point2D stepSlope)
	{
		DOUBLEBOOL out;

		if (stepSlope.GetX() == 0)
		{
			//undefined;
			out.tf = true;
			return out;
		}
		else
		{
			out.dbl = (double)(stepSlope.GetY() / stepSlope.GetX());
			return(out);
		}
	}
	int slopeToDir(int x, int y, int endX, int endY)
	{
		Point2D st, end;
		st.SetX(x);
		st.SetY(y);
		end.SetX(endX);
		end.SetY(endY);
		return(slopeToDir_Point2D(st, end));
	}
	int slopeToDir_Point2D(Point2D xSlope, Point2D ySlope)
	{
		int great[4];
		int less[4];
		int head[4];
		//great[0] = 4;
		//great[1] = 6;
		//great[2] = 8;
		//great[3] = 2;

		//less[0] = 4;
		//less[1] = 6;
		//less[2] = 8;
		//less[3] = 2;
		great[0] = 3;
		great[1] = 9;
		great[2] = 7;
		great[3] = 1;

		less[0] = 3;
		less[1] = 9;
		less[2] = 7;
		less[3] = 1;

		head[0] = 3;
		head[1] = 9;
		head[2] = 7;
		head[3] = 1;
		//ok - slope to dir
		//ok
		//think, Ian, thinak!

		//slope X is straight up - so that is always dir 8 - 
		//slope 1/1 is diagonal - so that is always dir 9 - 
		//slope 0 is always straight east 0 - so that is always 6

		//check to see if we are north & south

		//ahh - I knew I would run into trouble leaving the
		//stupid variables as xSlope and ySlope!
		//don't do the error!

		if (xSlope.GetX() == ySlope.GetX())
		{
			//straight up & down!
			if (xSlope.GetY() > ySlope.GetY())
			{
				//down - dir = 2
				return 8;
			}
			else
			{
				//up
				return 2;
			}
		}

		//check to see if we are east & west
		if (xSlope.GetY() == ySlope.GetY())
		{
			//straight east & west!

			if (xSlope.GetX() > ySlope.GetX())
			{
				return 4;
			}
			else
			{
				return 6;
			}
		}

		//ok - now we determine the quadrant
		int quad;	//1 ne 
					//2 se
					//3 sw
					//4 nw
		Point2D stepSlope = cordSlope(xSlope.GetX(), xSlope.GetY(), ySlope.GetX(), ySlope.GetY());
		DOUBLEBOOL slope = doubleSlope(stepSlope);

		//there should be no way that slope.tf == true at this point, because
		//if so, we would already have returned from when we checked above
		//so I will just leave this glaring vulnerability open. =Z

		if (stepSlope.GetX() > 0 && stepSlope.GetY() > 0)
		{
			quad = 1;	  //3		   1
		}
		else if (stepSlope.GetX() > 0 && stepSlope.GetY() < 0)
		{
			quad = 2;		 //9				  7
		}
		else if (stepSlope.GetX() < 0 && stepSlope.GetY() < 0)
		{
			quad = 3;			//7									 9
		}
		else
		{						   
			quad = 4;			   //1																	3
		}

		//slope.dbl = abs(slope.dbl);
		if (slope.dbl > 1.5)
		{

			switch (quad)
			{
			case 1:
				return great[0];
				break;
			case 2:
				return great[1];
				break;
			case 3:
				return great[2];
				break;
			case 4:
				return great[3];
				break;
			}
		}
		else if (slope.dbl < .5)
		{
			switch (quad)
			{
			case 1:
				return less[0];
				break;
			case 2:
				return less[1];
				break;
			case 3:
				return less[2];
				break;
			case 4:
				return less[3];
				break;
			}
		}
		else
		{
			switch (quad)
			{
			case 1:
				return head[0];
				break;
			case 2:
				return head[1];
				break;
			case 3:
				return head[2];
				break;
			case 4:
				return head[3];
				break;
			}
		}
	}

	Point2D normalizeCoordToDirection2d(Point2D Coord, int MaxDimensions)
	{
		if (Coord.GetX() >= 0 && Coord.GetX() < MaxDimensions)
		{
			Coord.SetX(0);
		}
		else if (Coord.GetX() < 0)
		{
			Coord.SetX(-1);
		}
		else
		{
			Coord.SetX(1);
		}

		if (Coord.GetY() >= 0 && Coord.GetY() < MaxDimensions)
		{
			Coord.SetY(0);
		}
		else if (Coord.GetY() < 0)
		{
			Coord.SetY(-1);
		}
		else
		{
			Coord.SetY(1);
		}
		return Coord;
	}
	Spatial::dir3d normalizeCoordToDirection3d(Point3D Coord, int MaxDimensions)
	{
		if (Coord.GetX() >= 0 && Coord.GetX() < MaxDimensions)
		{
			Coord.SetX(0);
		}
		else if (Coord.GetX() < 0)
		{
			Coord.SetX(-1);
		}
		else
		{
			Coord.SetX(1);
		}

		if (Coord.GetY() >= 0 && Coord.GetY() < MaxDimensions)
		{
			Coord.SetY(0);
		}
		else if (Coord.GetY() < 0)
		{
			Coord.SetY(-1);
		}
		else
		{
			Coord.SetY(1);
		}

		if (Coord.GetZ() >= 0 && Coord.GetZ() < MaxDimensions)
		{
			Coord.SetZ(0);
		}
		else if (Coord.GetZ() < 0)
		{
			Coord.SetZ(-1);
		}
		else
		{
			Coord.SetZ(1);
		}
		return coordToDir3d(Coord);
	}


	Point3D dirToCoord3d(Spatial::dir dir)
	{
		switch (dir)
		{
		case Spatial::dir::North:
			return Point3D(0, 1, 0);
		case Spatial::dir::NorthEast:
			return Point3D(1, 1, 0);
		case Spatial::dir::East:
			return Point3D(1, 0, 0);
		case Spatial::dir::SouthEast:
			return Point3D(1, -1, 0);
		case Spatial::dir::South:
			return Point3D(0, -1, 0);
		case Spatial::dir::SouthWest:
			return Point3D(-1, -1, 0);
		case Spatial::dir::West:
			return Point3D(-1, 0, 0);
		case Spatial::dir::NorthWest:
			return Point3D(-1, 1, 0);
		case Spatial::dir::Up:
			return Point3D(0,0,1);
		case Spatial::dir::Down:
			return Point3D(0, 0, -1);
		default:
			return Point3D(0, 0, 0);
		}
	}

	Point3D dir3dToCoord3d(Spatial::dir3d dir)
	{
		//0 no direction
		//	 down			same			up	
		//7	 8	9		15	16	17		24	25	26
		//4	 5	6		13	0	14		21	22	23
		//1	 2	3		10	11	12		18	19	20

		//1-9, down & sw,s,se,w,d,e,nw,n,ne
		//10-17, same level & sw,s,se,w,e,nw,n,ne
		//18-26, up & sw,s,se,w,up,e,nw,n,ne
		switch ((int)dir)
		{
		case 0:
			return Point3D(0,0,0);
		//down
		case 1:
			return Point3D(-1, -1, -1);
		case 2:
			return Point3D(0, -1, -1);
		case 3:
			return Point3D(1, -1, -1);
		case 4:
			return Point3D(-1, 0, -1);
		case 5:
			return Point3D(0, 0, -1);
		case 6:
			return Point3D(1, 0, -1);
		case 7:
			return Point3D(-1, 1, -1);
		case 8:
			return Point3D(0, 1, -1);
		case 9:
			return Point3D(1, 1, -1);
		//level 
		case 10:
			return Point3D(-1, -1, 0);
		case 11:
			return Point3D(0, -1, 0);
		case 12:
			return Point3D(1, -1, 0);
		case 13:
			return Point3D(-1, 0, 0);
		case 14:
			return Point3D(1, 0, 0);
		case 15:
			return Point3D(-1, 1, 0);
		case 16:
			return Point3D(0, 1, 0);
		case 17:
			return Point3D(1, 1, 0);
		//up
		case 18:
			return Point3D(-1, -1, 1);
		case 19:
			return Point3D(0, -1, 1);
		case 20:
			return Point3D(1, -1, 1);
		case 21:
			return Point3D(-1, 0, 1);
		case 22:
			return Point3D(0, 0, 1);
		case 23:
			return Point3D(1, 0, 1);
		case 24:
			return Point3D(-1, 1, 1);
		case 25:
			return Point3D(0, 1, 1);
		case 26:
			return Point3D(1, 1, 1);
		default:
			return Point3D(0, 0, 0);
		}
	}

	Spatial::dir3d coordToDir3d(Point3D coord)
	{
		//reduce to -1, 0 or 1
		coord.SetX(coord.GetX() == 0 ? 0 : coord.GetX() > 0 ? 1 : -1);
		coord.SetY(coord.GetY() == 0 ? 0 : coord.GetY() > 0 ? 1 : -1);
		coord.SetZ(coord.GetZ() == 0 ? 0 : coord.GetZ() > 0 ? 1 : -1);
		if (coord.z == -1)
		{
			if (coord.x == -1 && coord.y == -1) {
				return Spatial::dir3d::DownSouthWest;
			}
			else if (coord.x == 0 && coord.y == -1) {
				return Spatial::dir3d::DownSouth;
			}
			else if (coord.x == 1 && coord.y == -1) {
				return Spatial::dir3d::DownSouthEast;
			}
			else if (coord.x == -1 && coord.y == 0) {
				return Spatial::dir3d::DownWest;
			}
			else if (coord.x == 0 && coord.y == 0) {
				return Spatial::dir3d::Down;
			}
			else if (coord.x == 1 && coord.y == 0) {
				return Spatial::dir3d::DownEast;
			}
			else if (coord.x == -1 && coord.y == 1) {
				return Spatial::dir3d::DownNorthWest;
			}
			else if (coord.x == 0 && coord.y == 1) {
				return Spatial::dir3d::DownNorth;
			}
			else if (coord.x == 1 && coord.y == 1) {
				return Spatial::dir3d::DownNorthEast;
			}
		}
		else if (coord.z == 0)
		{
			if (coord.x == -1 && coord.y == -1)
			{
				return Spatial::dir3d::SouthWest;
			}
			else if (coord.x == 0 && coord.y == -1)
			{
				return Spatial::dir3d::South;
			}
			else if (coord.x == 1 && coord.y == -1)
			{
				return Spatial::dir3d::SouthEast;
			}
			else if (coord.x == -1 && coord.y == 0)
			{
				return Spatial::dir3d::West;
			}
			else if (coord.x == 0 && coord.y == 0)
			{
				return Spatial::dir3d::NoDirection;
			}
			else if (coord.x == 1 && coord.y == 0)
			{
				return Spatial::dir3d::East;
			}
			else if (coord.x == -1 && coord.y == 1)
			{
				return Spatial::dir3d::NorthWest;
			}
			else if (coord.x == 0 && coord.y == 1)
			{
				return Spatial::dir3d::North;
			}
			else if (coord.x == 1 && coord.y == 1)
			{
				return Spatial::dir3d::NorthEast;
			}
		}
		else if (coord.z == 1)
		{
			if (coord.x == -1 && coord.y == -1)
			{
				return Spatial::dir3d::UpSouthWest;
			}
			else if (coord.x == 0 && coord.y == -1)
			{
				return Spatial::dir3d::UpSouth;
			}
			else if (coord.x == 1 && coord.y == -1)
			{
				return Spatial::dir3d::UpSouthEast;
			}
			else if (coord.x == -1 && coord.y == 0)
			{
				return Spatial::dir3d::UpWest;
			}
			else if (coord.x == 0 && coord.y == 0)
			{
				return Spatial::dir3d::Up;
			}
			else if (coord.x == 1 && coord.y == 0)
			{
				return Spatial::dir3d::UpEast;
			}
			else if (coord.x == -1 && coord.y == 1)
			{
				return Spatial::dir3d::UpNorthWest;
			}
			else if (coord.x == 0 && coord.y == 1)
			{
				return Spatial::dir3d::UpNorth;
			}
			else if (coord.x == 1 && coord.y == 1)
			{
				return Spatial::dir3d::UpNorthEast;
			}
		}

		//should never get here
		std::stringstream tt;
		tt << "Invalid direction: Coord: " << coord.ToString();
		throw std::logic_error(tt.str());
	}

	Spatial::dir dir3dToDir2d(Spatial::dir3d Dir3d)
	{
		switch (Dir3d)
		{
		case Spatial::dir3d::SouthWest:
			return Spatial::dir::SouthWest;
			break;
		case Spatial::dir3d::South:
			return Spatial::dir::South;
			break;
		case Spatial::dir3d::SouthEast:
			return Spatial::dir::SouthEast;
			break;
		case Spatial::dir3d::West:
			return Spatial::dir::West;
			break;
		case Spatial::dir3d::East:
			return Spatial::dir::East;
			break;
		case Spatial::dir3d::NorthWest:
			return Spatial::dir::NorthWest;
			break;
		case Spatial::dir3d::North:
			return Spatial::dir::North;
			break;
		case Spatial::dir3d::NorthEast:
			return Spatial::dir::NorthEast;
			break;
		default:
			std::stringstream st;
			st << "Invalid conversion from 3d direction to 2d direction: " << (int)Dir3d;
			auto newStr = st.str();
			throw new std::exception(newStr.c_str());
		}
	}


	//Point3D indexToCoord3d(int index)
	//{

	//}

	//int coordToIndex3d(Point3D coord)
	//{

	//}

}

