#include "pch.h"
#include "globalGenerics.h"
#include "coordFunctions.h"
#include "direction.h"



void GenerateShuffledIntegers(int Size, std::vector<int>& IndexVector)
{
	IndexVector.clear();
	for (int pix = 0; pix < Size; pix++)
	{
		IndexVector.push_back(pix);
	}
	//shuffle
	for (int pix = 0; pix < IndexVector.size(); pix++)
	{
		std::swap(IndexVector[pix], IndexVector[RND::rnd.intRand(0, IndexVector.size() - 1)]);
	}
}

Point2D IndexTo2dCoords(int Index, int MaxDim)
{
	Point2D Coords;
	Coords.x = Index % MaxDim;
	Coords.y = Index / MaxDim;
	return Coords;
}

Point3D IndexTo3dCoords(int Index, int MaxDim)
{
	Point3D Coords;
	Coords.x = Index % MaxDim;
	Coords.y = (Index / MaxDim) % MaxDim;
	Coords.z = Index / (MaxDim * MaxDim);
	return Coords;
}

int Coords2dToIndex(Point2D Coords, int MaxDim)
{
	return Coords.GetY() * MaxDim + Coords.GetX();
}

int Coords3dToIndex(Point3D Coords, int MaxDim)
{
	return Coords.GetZ() * MaxDim * MaxDim + Coords.GetY() * MaxDim + Coords.GetX();
}

Point3D SelectRandomPointAlongEdge3d(Spatial::dir3d dirr, int maxDims)
{
	if (maxDims < 3)
	{
		throw std::logic_error("maxDims must be greater than 2");
	}
	Point3D toReturn;
	switch (dirr)
	{
		//do the cardinal directions first
	case Spatial::dir3d::Down:
		//z is 0, x is 1-maxDims-2, y is 1-maxDims-2
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), RND::rnd.intRand(1, maxDims - 2), 0);
		break;
	case Spatial::dir3d::Up:
		//z is maxDims-1, x is 1-maxDims-2, y is 1-maxDims-2
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), RND::rnd.intRand(1, maxDims - 2), maxDims - 1);
		break;
	case Spatial::dir3d::North:
		//y is maxDims-1, x is 1-maxDims-2, z is 1-maxDims-2
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), maxDims - 1, RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::South:
		//y is 0, x is 1-maxDims-2, z is 1-maxDims-2
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), 0, RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::East:
		//x is maxDims-1, y is 1-maxDims-2, z is 1-maxDims-2
		toReturn.Set(maxDims - 1, RND::rnd.intRand(1, maxDims - 2), RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::West:
		//x is 0, y is 1-maxDims-2, z is 1-maxDims-2
		toReturn.Set(0, RND::rnd.intRand(1, maxDims - 2), RND::rnd.intRand(1, maxDims - 2));
		break;

#pragma region diagonals
		//now do the diagonals
	case Spatial::dir3d::NorthEast:
		//y is maxDims-1, x is maxDims-1, z is 1-maxDims-2
		toReturn.Set(maxDims - 1, maxDims - 1, RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::NorthWest:
		//y is maxDims-1, x is 0, z is 1-maxDims-2
		toReturn.Set(0, maxDims - 1, RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::SouthEast:
		//y is 0, x is maxDims-1, z is 1-maxDims-2
		toReturn.Set(maxDims - 1, 0, RND::rnd.intRand(1, maxDims - 2));
		break;
	case Spatial::dir3d::SouthWest:
		//y is 0, x is 0, z is 1-maxDims-2
		toReturn.Set(0, 0, RND::rnd.intRand(1, maxDims - 2));
		break;

//now down diagonals
	case Spatial::dir3d::DownNorthEast:
		//y is maxDims-1, x is maxDims-1, z is maxDims-1
		toReturn.Set(maxDims - 1, maxDims - 1, 0);
		break;
	case Spatial::dir3d::DownNorthWest:
		//y is maxDims-1, x is 0, z is maxDims-1
		toReturn.Set(0, maxDims - 1, 0);
		break;
	case Spatial::dir3d::DownSouthEast:
		//y is 0, x is maxDims-1, z is maxDims-1
		toReturn.Set(maxDims - 1, 0, 0);
		break;
	case Spatial::dir3d::DownSouthWest:
		//y is 0, x is 0, z is maxDims-1
		toReturn.Set(0, 0, 0);
		break;

		//now up diagonals
	case Spatial::dir3d::UpNorthEast:
		//y is maxDims-1, x is maxDims-1, z is maxDims-1
		toReturn.Set(maxDims - 1, maxDims - 1, maxDims - 1);
		break;
	case Spatial::dir3d::UpNorthWest:
		//y is maxDims-1, x is 0, z is maxDims-1
		toReturn.Set(0, maxDims - 1, maxDims - 1);
		break;
	case Spatial::dir3d::UpSouthEast:
		//y is 0, x is maxDims-1, z is maxDims-1
		toReturn.Set(maxDims - 1, 0, maxDims - 1);
		break;
	case Spatial::dir3d::UpSouthWest:
		//y is 0, x is 0, z is maxDims-1
		toReturn.Set(0, 0, maxDims - 1);
		break;

#pragma endregion
#pragma region down
	case Spatial::dir3d::DownNorth:
		//y is maxDims-1, x is 1-maxDims-2, z is 0
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), maxDims - 1, 0);
		break;
	case Spatial::dir3d::DownSouth:
		//y is 0, x is 1-maxDims-2, z is 0
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), 0, 0);
		break;
	case Spatial::dir3d::DownEast:
		//x is maxDims-1, y is 1-maxDims-2, z is 0
		toReturn.Set(maxDims - 1, RND::rnd.intRand(1, maxDims - 2), 0);
		break;
	case Spatial::dir3d::DownWest:
		//x is 0, y is 1-maxDims-2, z is 0
		toReturn.Set(0, RND::rnd.intRand(1, maxDims - 2), 0);
		break;
#pragma endregion
#pragma region up
	case Spatial::dir3d::UpNorth:
		//y is maxDims-1, x is 1-maxDims-2, z is maxDims-1
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), maxDims - 1, maxDims - 1);
		break;
	case Spatial::dir3d::UpSouth:
		//y is 0, x is 1-maxDims-2, z is maxDims-1
		toReturn.Set(RND::rnd.intRand(1, maxDims - 2), 0, maxDims - 1);
		break;
	case Spatial::dir3d::UpEast:
		//x is maxDims-1, y is 1-maxDims-2, z is maxDims-1
		toReturn.Set(maxDims - 1, RND::rnd.intRand(1, maxDims - 2), maxDims - 1);
		break;
	case Spatial::dir3d::UpWest:
		//x is 0, y is 1-maxDims-2, z is maxDims-1
		toReturn.Set(0, RND::rnd.intRand(1, maxDims - 2), maxDims - 1);
		break;
#pragma endregion

	default:
		throw std::logic_error("Invalid direction");

	}
	return toReturn;
}

Spatial::dir3d DrunkWalk3d(Point3D startPoint, Point3D endPoint, double chanceToStumble)
{

	//find the direction from startPoint to endPoint
	Spatial::dir3d toReturn = CORDFUNC::normalizeCoordToDirection3d(endPoint - startPoint, 1);

	double willStumble = RND::rnd.doubleRand(0, 1);
	if (chanceToStumble <= willStumble)
	{
		//stumble
		return toReturn;
	}

	//now we need to add some randomness to the direction
	//how many random directions can we go in?
	//if a diagonal, then 6, else 8
	int numDirs = 8;
	if (toReturn == Spatial::dir3d::DownSouthEast
		|| toReturn == Spatial::dir3d::DownSouthWest
		|| toReturn == Spatial::dir3d::DownNorthEast
		|| toReturn == Spatial::dir3d::DownNorthWest
		|| toReturn == Spatial::dir3d::UpSouthEast
		|| toReturn == Spatial::dir3d::UpSouthWest
		|| toReturn == Spatial::dir3d::UpNorthEast
		|| toReturn == Spatial::dir3d::UpNorthWest)	
	{
		numDirs = 6;
	}

	int totalChoices = (numDirs) + 2;
	//if 0 or totalChoices-1, then we are going to go some completely random direction
	//else move in the direction indicated
	int choice = RND::rnd.intRand(0, totalChoices - 1);
	if (choice == 0 || choice == totalChoices - 1)
	{		
		return Spatial::direction3d::getRandomDir3d();
	}
	
	Spatial::dir3d adjacentDir = Spatial::direction3d::getAdjacentDirection(toReturn, choice);
	
	//move in the direction indicated
	return adjacentDir;
}

