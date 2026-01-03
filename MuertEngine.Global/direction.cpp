#include "pch.h"
#include "direction.h"
#include "../MuertEngine.Random/RandomWrapper.h"	 
#include <sstream>



namespace Spatial
{


	direction2d::direction2d()
	{

	}

	direction2d::~direction2d()
	{

	}

	int direction2d::getDirInt()
	{
		return 2;
	}

	Spatial::dir direction2d::getOppositeDirection(Spatial::dir Direction)
	{
		switch (Direction)
		{
		case Spatial::dir::North:
			return Spatial::dir::South;
		case Spatial::dir::South:
			return Spatial::dir::North;
		case Spatial::dir::West:
			return Spatial::dir::East;
		case Spatial::dir::East:
			return Spatial::dir::West;
		case Spatial::dir::Up:
			return Spatial::dir::Down;
		case Spatial::dir::Down:
			return Spatial::dir::Up;
		case Spatial::dir::NorthEast:
			return Spatial::dir::SouthWest;
		case Spatial::dir::SouthWest:
			return Spatial::dir::NorthEast;
		case Spatial::dir::NorthWest:
			return Spatial::dir::SouthEast;
		case Spatial::dir::SouthEast:
			return Spatial::dir::NorthWest;
		//default:
		//	return Spatial::dir::NoDirection;


		}
	}

	Spatial::dir direction2d::getRandomDir2d(bool includeNoDirection /*= false*/)
	{	   
		return (Spatial::dir)RND::rnd.intRand(0, (int)Spatial::dir::STATE_COUNT - 1); // (Spatial::dir)RND::rnd.intRand(0, Spatial::dir::STATE_COUNT - 1

	}

	int direction2d::getRandomDir2dInt(bool includeNoDirection /*= false*/)
	{
		return RND::rnd.intRand(0, (int)Spatial::dir::STATE_COUNT - 1);
	}



	direction3d::direction3d()
	{
		_dir3d = Spatial::dir3d::NoDirection;
	}

	direction3d::~direction3d()
	{

	}

	void direction3d::setDir3d(Spatial::dir3d Dir)
	{
		_dir3d = Dir;
	}

	Spatial::dir3d direction3d::getDir3d()
	{
		return _dir3d;
	}

	Spatial::dir3d direction3d::getRandomDir3d(bool includeNoDirection)
	{
		return (Spatial::dir3d)getRandomDir3dInt(includeNoDirection);
	}

	int direction3d::getRandomDir3dInt(bool includeNoDirection)
	{
		int startDir = includeNoDirection? 0 : 1;
		return RND::rnd.intRand(startDir, 26);
	}

	Spatial::dir3d direction3d::getRandomDir2d(bool includeNoDirection /*= false*/)
	{
		int res = RND::rnd.intRand(10, 17);
		return (Spatial::dir3d)res;
	}

	int direction3d::getRandomDir2dInt(bool includeNoDirection /*= false*/)
	{
		int res = RND::rnd.intRand(10, 17);
		return res;
	}

	Spatial::dir3d direction3d::getAdjacentDirection(Spatial::dir3d startDir, int choice)
	{
		if (choice < 1 || choice > 8)
		{
			throw std::logic_error("choice must be between 1 and 8");
		}
		if ((startDir == Spatial::dir3d::DownSouthEast
			|| startDir == Spatial::dir3d::DownSouthWest
			|| startDir == Spatial::dir3d::DownNorthEast
			|| startDir == Spatial::dir3d::DownNorthWest
			|| startDir == Spatial::dir3d::UpSouthEast
			|| startDir == Spatial::dir3d::UpSouthWest
			|| startDir == Spatial::dir3d::UpNorthEast
			|| startDir == Spatial::dir3d::UpNorthWest)
			&& choice > 6)
		{
			throw std::logic_error("choice must be between 1 and 6");
		}

		Spatial::dir3d toReturn = startDir;

		//directions start at 1, first direction on the same plane, stating at west, traveling clockwise
		// the remaining directions will be chosen in a clockwise fashion (as if facing north,down or west)
		// and will end at either 6 or 8, depending on the initial direction
		//6 for a diagonal, 8 for a non-diagonal
		//for example, if we start at UpNorthWest - 1 will check for west, which is not a valid direction
		//the first valid direction is UpNorth (east of UpNorthWest)
		//the next is Up, followed by UpWest, West, NorthWest, and North
		//for Up it would be UpWest,UpNorthWest,UpNorth,UpNorthEast,UpEast,UpSouthEast,UpSouth,UpSouthWest
		//etc
		switch (toReturn)
		{
			case Spatial::dir3d::Up:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpWest;
				case 2:
					return Spatial::dir3d::UpNorthWest;
				case 3:
					return Spatial::dir3d::UpNorth;
				case 4:
					return Spatial::dir3d::UpNorthEast;
				case 5:
					return Spatial::dir3d::UpEast;
				case 6:
					return Spatial::dir3d::UpSouthEast;
				case 7:
					return Spatial::dir3d::UpSouth;
				case 8:
					return Spatial::dir3d::UpSouthWest;
				}
			}
			case Spatial::dir3d::Down:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownWest;
				case 2:
					return Spatial::dir3d::DownNorthWest;
				case 3:
					return Spatial::dir3d::DownNorth;
				case 4:
					return Spatial::dir3d::DownNorthEast;
				case 5:
					return Spatial::dir3d::DownEast;
				case 6:
					return Spatial::dir3d::DownSouthEast;
				case 7:
					return Spatial::dir3d::DownSouth;
				case 8:
					return Spatial::dir3d::DownSouthWest;
				}
			}
			case Spatial::dir3d::North:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::NorthWest;
				case 2:
					return Spatial::dir3d::UpNorthWest;
				case 3:
					return Spatial::dir3d::UpNorth;
				case 4:
					return Spatial::dir3d::UpNorthEast;
				case 5:
					return Spatial::dir3d::NorthEast;
				case 6:
					return Spatial::dir3d::DownNorthEast;
				case 7:
					return Spatial::dir3d::DownNorth;
				case 8:
					return Spatial::dir3d::DownNorthWest;
				}
			}
			case Spatial::dir3d::South:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::SouthWest;
				case 2:
					return Spatial::dir3d::UpSouthWest;
				case 3:
					return Spatial::dir3d::UpSouth;
				case 4:
					return Spatial::dir3d::UpSouthEast;
				case 5:
					return Spatial::dir3d::SouthEast;
				case 6:
					return Spatial::dir3d::DownSouthEast;
				case 7:
					return Spatial::dir3d::DownSouth;
				case 8:
					return Spatial::dir3d::DownSouthWest;
				}
			}
			case Spatial::dir3d::West:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::SouthWest;
				case 2:
					return Spatial::dir3d::UpSouthWest;
				case 3:
					return Spatial::dir3d::UpWest;
				case 4:
					return Spatial::dir3d::UpNorthWest;
				case 5:
					return Spatial::dir3d::NorthWest;
				case 6:
					return Spatial::dir3d::DownNorthWest;
				case 7:
					return Spatial::dir3d::DownWest;
				case 8:
					return Spatial::dir3d::DownSouthWest;
				}
			}
			case Spatial::dir3d::East:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::SouthEast;
				case 2:
					return Spatial::dir3d::UpSouthEast;
				case 3:
					return Spatial::dir3d::UpEast;
				case 4:
					return Spatial::dir3d::UpNorthEast;
				case 5:
					return Spatial::dir3d::NorthEast;
				case 6:
					return Spatial::dir3d::DownNorthEast;
				case 7:
					return Spatial::dir3d::DownEast;
				case 8:
					return Spatial::dir3d::DownSouthEast;
				}
			}

			//4 diagonals
			case Spatial::dir3d::NorthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::North;
				case 2:
					return Spatial::dir3d::UpNorth;
				case 3:
					return Spatial::dir3d::UpNorthWest;
				case 4:
					return Spatial::dir3d::UpWest;
				case 5:
					return Spatial::dir3d::West;
				case 6:
					return Spatial::dir3d::DownWest;
				case 7:
					return Spatial::dir3d::DownNorthWest;
				case 8:
					return Spatial::dir3d::DownNorth;
				}
			}
			case Spatial::dir3d::NorthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::East;
				case 2:
					return Spatial::dir3d::UpEast;
				case 3:
					return Spatial::dir3d::UpNorthEast;
				case 4:
					return Spatial::dir3d::UpNorth;
				case 5:
					return Spatial::dir3d::North;
				case 6:
					return Spatial::dir3d::DownNorth;
				case 7:
					return Spatial::dir3d::DownNorthEast;
				case 8:
					return Spatial::dir3d::DownEast;
				}
			}
			case Spatial::dir3d::SouthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::South;
				case 2:
					return Spatial::dir3d::UpSouth;
				case 3:
					return Spatial::dir3d::UpSouthEast;
				case 4:
					return Spatial::dir3d::UpEast;
				case 5:
					return Spatial::dir3d::East;
				case 6:
					return Spatial::dir3d::DownEast;
				case 7:
					return Spatial::dir3d::DownSouthEast;
				case 8:
					return Spatial::dir3d::DownSouth;
				}
			}
			case Spatial::dir3d::SouthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::West;
				case 2:
					return Spatial::dir3d::UpWest;
				case 3:
					return Spatial::dir3d::UpSouthWest;
				case 4:
					return Spatial::dir3d::UpSouth;
				case 5:
					return Spatial::dir3d::South;
				case 6:
					return Spatial::dir3d::DownSouth;
				case 7:
					return Spatial::dir3d::DownSouthWest;
				case 8:
					return Spatial::dir3d::DownWest;
				}
			}

			//up cardinal directions
			case Spatial::dir3d::UpNorth:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpNorthEast;
				case 2:
					return Spatial::dir3d::UpEast;
				case 3:
					return Spatial::dir3d::Up;
				case 4:
					return Spatial::dir3d::UpWest;
				case 5:
					return Spatial::dir3d::UpNorthWest;
				case 6:
					return Spatial::dir3d::NorthWest;
				case 7:
					return Spatial::dir3d::North;
				case 8:
					return Spatial::dir3d::NorthEast;
				}
			}
			case Spatial::dir3d::UpEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpSouthEast;
				case 2:
					return Spatial::dir3d::UpSouth;
				case 3:
					return Spatial::dir3d::Up;
				case 4:
					return Spatial::dir3d::UpNorth;
				case 5:
					return Spatial::dir3d::UpNorthEast;
				case 6:
					return Spatial::dir3d::NorthEast;
				case 7:
					return Spatial::dir3d::East;
				case 8:
					return Spatial::dir3d::SouthEast;
				}
			}
			case Spatial::dir3d::UpSouth:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpSouthWest;
				case 2:
					return Spatial::dir3d::UpWest;
				case 3:
					return Spatial::dir3d::Up;
				case 4:
					return Spatial::dir3d::UpEast;
				case 5:
					return Spatial::dir3d::UpSouthEast;
				case 6:
					return Spatial::dir3d::SouthEast;
				case 7:
					return Spatial::dir3d::South;
				case 8:
					return Spatial::dir3d::SouthWest;
				}
			}
			case Spatial::dir3d::UpWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpNorthWest;
				case 2:
					return Spatial::dir3d::UpNorth;
				case 3:
					return Spatial::dir3d::Up;
				case 4:
					return Spatial::dir3d::UpSouth;
				case 5:
					return Spatial::dir3d::UpSouthWest;
				case 6:
					return Spatial::dir3d::SouthWest;
				case 7:
					return Spatial::dir3d::West;
				case 8:
					return Spatial::dir3d::NorthWest;
				}
			}

			//down cardinal directions
			case Spatial::dir3d::DownNorth:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownNorthEast;
				case 2:
					return Spatial::dir3d::DownEast;
				case 3:
					return Spatial::dir3d::Down;
				case 4:
					return Spatial::dir3d::DownWest;
				case 5:
					return Spatial::dir3d::DownNorthWest;
				case 6:
					return Spatial::dir3d::NorthWest;
				case 7:
					return Spatial::dir3d::North;
				case 8:
					return Spatial::dir3d::NorthEast;
				}
			}
			case Spatial::dir3d::DownEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownSouthEast;
				case 2:
					return Spatial::dir3d::DownSouth;
				case 3:
					return Spatial::dir3d::Down;
				case 4:
					return Spatial::dir3d::DownNorth;
				case 5:
					return Spatial::dir3d::DownNorthEast;
				case 6:
					return Spatial::dir3d::NorthEast;
				case 7:
					return Spatial::dir3d::East;
				case 8:
					return Spatial::dir3d::SouthEast;
				}
			}
			case Spatial::dir3d::DownSouth:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownSouthWest;
				case 2:
					return Spatial::dir3d::DownWest;
				case 3:
					return Spatial::dir3d::Down;
				case 4:
					return Spatial::dir3d::DownEast;
				case 5:
					return Spatial::dir3d::DownSouthEast;
				case 6:
					return Spatial::dir3d::SouthEast;
				case 7:
					return Spatial::dir3d::South;
				case 8:
					return Spatial::dir3d::SouthWest;
				}
			}
			case Spatial::dir3d::DownWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownNorthWest;
				case 2:
					return Spatial::dir3d::DownNorth;
				case 3:
					return Spatial::dir3d::Down;
				case 4:
					return Spatial::dir3d::DownSouth;
				case 5:
					return Spatial::dir3d::DownSouthWest;
				case 6:
					return Spatial::dir3d::SouthWest;
				case 7:
					return Spatial::dir3d::West;
				case 8:
					return Spatial::dir3d::NorthWest;
				}
			}

			//8 diagonals

			//up diagonals
			case Spatial::dir3d::UpNorthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpNorth;
				case 2:
					return Spatial::dir3d::Up;
				case 3:
					return Spatial::dir3d::UpWest;
				case 4:
					return Spatial::dir3d::West;
				case 5:
					return Spatial::dir3d::NorthWest;
				case 6:
					return Spatial::dir3d::North;
				}
			}
			case Spatial::dir3d::UpNorthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpEast;
				case 2:
					return Spatial::dir3d::Up;
				case 3:
					return Spatial::dir3d::UpNorth;
				case 4:
					return Spatial::dir3d::North;
				case 5:
					return Spatial::dir3d::NorthEast;
				case 6:
					return Spatial::dir3d::East;
				}
			}
			case Spatial::dir3d::UpSouthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpSouth;
				case 2:
					return Spatial::dir3d::Up;
				case 3:
					return Spatial::dir3d::UpEast;
				case 4:
					return Spatial::dir3d::East;
				case 5:
					return Spatial::dir3d::SouthEast;
				case 6:
					return Spatial::dir3d::South;
				}
			}
			case Spatial::dir3d::UpSouthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::UpWest;
				case 2:
					return Spatial::dir3d::Up;
				case 3:
					return Spatial::dir3d::UpSouth;
				case 4:
					return Spatial::dir3d::South;
				case 5:
					return Spatial::dir3d::SouthWest;
				case 6:
					return Spatial::dir3d::West;
				}
			}

			//down diagonals
			case Spatial::dir3d::DownNorthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownNorth;
				case 2:
					return Spatial::dir3d::Down;
				case 3:
					return Spatial::dir3d::DownWest;
				case 4:
					return Spatial::dir3d::West;
				case 5:
					return Spatial::dir3d::NorthWest;
				case 6:
					return Spatial::dir3d::North;
				}
			}
			case Spatial::dir3d::DownNorthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownEast;
				case 2:
					return Spatial::dir3d::Down;
				case 3:
					return Spatial::dir3d::DownNorth;
				case 4:
					return Spatial::dir3d::North;
				case 5:
					return Spatial::dir3d::NorthEast;
				case 6:
					return Spatial::dir3d::East;
				}
			}
			case Spatial::dir3d::DownSouthEast:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownSouth;
				case 2:
					return Spatial::dir3d::Down;
				case 3:
					return Spatial::dir3d::DownEast;
				case 4:
					return Spatial::dir3d::East;
				case 5:
					return Spatial::dir3d::SouthEast;
				case 6:
					return Spatial::dir3d::South;
				}
			}
			case Spatial::dir3d::DownSouthWest:
			{
				switch (choice)
				{
				case 1:
					return Spatial::dir3d::DownWest;
				case 2:
					return Spatial::dir3d::Down;
				case 3:
					return Spatial::dir3d::DownSouth;
				case 4:
					return Spatial::dir3d::South;
				case 5:
					return Spatial::dir3d::SouthWest;
				case 6:
					return Spatial::dir3d::West;
				}
			}
		}  
		std::stringstream tt;
		tt << "Invalid direction: (startDir)" << (int)startDir <<": (choice)"<<choice;
		throw std::logic_error(tt.str());
	}

	Spatial::dir3d direction3d::getOppositeDirection(Spatial::dir3d Direction)
	{
		switch (Direction)
		{
		case Spatial::dir3d::Up:
			return Spatial::dir3d::Down;
		case Spatial::dir3d::Down:
			return Spatial::dir3d::Up;
		case Spatial::dir3d::North:
			return Spatial::dir3d::South;
		case Spatial::dir3d::South:
			return Spatial::dir3d::North;
		case Spatial::dir3d::West:
			return Spatial::dir3d::East;
		case Spatial::dir3d::East:
			return Spatial::dir3d::West;
		case Spatial::dir3d::NorthWest:
			return Spatial::dir3d::SouthEast;
		case Spatial::dir3d::NorthEast:
			return Spatial::dir3d::SouthWest;
		case Spatial::dir3d::SouthEast:
			return Spatial::dir3d::NorthWest;
		case Spatial::dir3d::SouthWest:
			return Spatial::dir3d::NorthEast;
		case Spatial::dir3d::UpNorth:
			return Spatial::dir3d::DownSouth;
		case Spatial::dir3d::UpEast:
			return Spatial::dir3d::DownWest;
		case Spatial::dir3d::UpSouth:
			return Spatial::dir3d::DownNorth;
		case Spatial::dir3d::UpWest:
			return Spatial::dir3d::DownEast;
		case Spatial::dir3d::DownNorth:
			return Spatial::dir3d::UpSouth;
		case Spatial::dir3d::DownEast:
			return Spatial::dir3d::UpWest;
		case Spatial::dir3d::DownSouth:
			return Spatial::dir3d::UpNorth;
		case Spatial::dir3d::DownWest:
			return Spatial::dir3d::UpEast;
		case Spatial::dir3d::UpNorthWest:
			return Spatial::dir3d::DownSouthEast;
		case Spatial::dir3d::UpNorthEast:
			return Spatial::dir3d::DownSouthWest;
		case Spatial::dir3d::UpSouthEast:
			return Spatial::dir3d::DownNorthWest;
		case Spatial::dir3d::UpSouthWest:
			return Spatial::dir3d::DownNorthEast;
		case Spatial::dir3d::DownNorthWest:
			return Spatial::dir3d::UpSouthEast;
		case Spatial::dir3d::DownNorthEast:
			return Spatial::dir3d::UpSouthWest;
		case Spatial::dir3d::DownSouthEast:
			return Spatial::dir3d::UpNorthWest;
		case Spatial::dir3d::DownSouthWest:
			return Spatial::dir3d::UpNorthEast;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getNextClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::North:
			return Spatial::dir3d::NorthEast;
		case Spatial::dir3d::NorthEast:
			return Spatial::dir3d::East;
		case Spatial::dir3d::East:
			return Spatial::dir3d::SouthEast;
		case Spatial::dir3d::SouthEast:
			return Spatial::dir3d::South;
		case Spatial::dir3d::South:
			return Spatial::dir3d::SouthWest;
		case Spatial::dir3d::SouthWest:
			return Spatial::dir3d::West;
		case Spatial::dir3d::West:
			return Spatial::dir3d::NorthWest;
		case Spatial::dir3d::NorthWest:
			return Spatial::dir3d::North;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getNextCounterClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::North:
			return Spatial::dir3d::NorthWest;
		case Spatial::dir3d::NorthWest:
			return Spatial::dir3d::West;
		case Spatial::dir3d::West:
			return Spatial::dir3d::SouthWest;
		case Spatial::dir3d::SouthWest:
			return Spatial::dir3d::South;
		case Spatial::dir3d::South:
			return Spatial::dir3d::SouthEast;
		case Spatial::dir3d::SouthEast:
			return Spatial::dir3d::East;
		case Spatial::dir3d::East:
			return Spatial::dir3d::NorthEast;
		case Spatial::dir3d::NorthEast:
			return Spatial::dir3d::North;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getUpNextClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::UpNorth:
			return Spatial::dir3d::UpNorthEast;
		case Spatial::dir3d::UpNorthEast:
			return Spatial::dir3d::UpEast;
		case Spatial::dir3d::UpEast:
			return Spatial::dir3d::UpSouthEast;
		case Spatial::dir3d::UpSouthEast:
			return Spatial::dir3d::UpSouth;
		case Spatial::dir3d::UpSouth:
			return Spatial::dir3d::UpSouthWest;
		case Spatial::dir3d::UpSouthWest:
			return Spatial::dir3d::UpWest;
		case Spatial::dir3d::UpWest:
			return Spatial::dir3d::UpNorthWest;
		case Spatial::dir3d::UpNorthWest:
			return Spatial::dir3d::UpNorth;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getUpNextCounterClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::UpNorth:
			return Spatial::dir3d::UpNorthWest;
		case Spatial::dir3d::UpNorthWest:
			return Spatial::dir3d::UpWest;
		case Spatial::dir3d::UpWest:
			return Spatial::dir3d::UpSouthWest;
		case Spatial::dir3d::UpSouthWest:
			return Spatial::dir3d::UpSouth;
		case Spatial::dir3d::UpSouth:
			return Spatial::dir3d::UpSouthEast;
		case Spatial::dir3d::UpSouthEast:
			return Spatial::dir3d::UpEast;
		case Spatial::dir3d::UpEast:
			return Spatial::dir3d::UpNorthEast;
		case Spatial::dir3d::UpNorthEast:
			return Spatial::dir3d::UpNorth;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getDownNextClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::DownNorth:
			return Spatial::dir3d::DownNorthEast;
		case Spatial::dir3d::DownNorthEast:
			return Spatial::dir3d::DownEast;
		case Spatial::dir3d::DownEast:
			return Spatial::dir3d::DownSouthEast;
		case Spatial::dir3d::DownSouthEast:
			return Spatial::dir3d::DownSouth;
		case Spatial::dir3d::DownSouth:
			return Spatial::dir3d::DownSouthWest;
		case Spatial::dir3d::DownSouthWest:
			return Spatial::dir3d::DownWest;
		case Spatial::dir3d::DownWest:
			return Spatial::dir3d::DownNorthWest;
		case Spatial::dir3d::DownNorthWest:
			return Spatial::dir3d::DownNorth;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}

	Spatial::dir3d direction3d::getDownNextCounterClockwiseDir2d(Spatial::dir3d curDir)
	{
		switch (curDir)
		{
		case Spatial::dir3d::DownNorth:
			return Spatial::dir3d::DownNorthWest;
		case Spatial::dir3d::DownNorthWest:
			return Spatial::dir3d::DownWest;
		case Spatial::dir3d::DownWest:
			return Spatial::dir3d::DownSouthWest;
		case Spatial::dir3d::DownSouthWest:
			return Spatial::dir3d::DownSouth;
		case Spatial::dir3d::DownSouth:
			return Spatial::dir3d::DownSouthEast;
		case Spatial::dir3d::DownSouthEast:
			return Spatial::dir3d::DownEast;
		case Spatial::dir3d::DownEast:
			return Spatial::dir3d::DownNorthEast;
		case Spatial::dir3d::DownNorthEast:
			return Spatial::dir3d::DownNorth;
		default:
			return Spatial::dir3d::NoDirection;
		}
	}


	direction2d_orientation::direction2d_orientation()
	{
		z_orient = z_orientation::SamePlane;
		direc = dir::South;
	}

	direction2d_orientation::~direction2d_orientation()
	{

	}

}
