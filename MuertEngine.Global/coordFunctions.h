

//by ian.gillis
#pragma once
#ifndef COORD_FUNCTIONS_H
#define COORD_FUNCTIONS_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define COORD_FUNCTIONS_H_API __declspec(dllexport)
#else
#define COORD_FUNCTIONS_H_API __declspec(dllimport)
#endif


#include <vector>

#include "point2.h"
#include "typeCombos.h"
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"


namespace CORDFUNC
{

	

	//Point2D coord32(int number);

	//int numb32(Point2D inp);

	extern "C" COORD_FUNCTIONS_H_API Point2D dirToCoord(int dir, bool eightDir);
	extern "C" COORD_FUNCTIONS_H_API int coordToDir(Point2D coord, bool eightDir);

	//CORD_3D dirToCoord_3D(int dir, bool eightDir);
	//int coordToDir_3D(CORD_3D coord, bool eightDir);


	extern "C" COORD_FUNCTIONS_H_API Point2D spiralIndexToCoordOffset2d(int pos);

	extern "C" COORD_FUNCTIONS_H_API int coordOffset2dToSpiralIndex(Point2D cordOffset);

	extern "C" COORD_FUNCTIONS_H_API int nextDir(int curDir, bool clockwise);
	extern "C" COORD_FUNCTIONS_H_API void getAllDirsBetweenTwoDirs(int startDir, int endDir, std::vector<int> &Dirs);

	//this will get all 2d eightDir directions between two directions, as if looking from the top-down
	//	e.g. botLeftDir = 1, topRightDir = 5, then 1,2,4,5
	//	e.g. botLeftDir = 5, topRightDir = 6, then 5,6
	//	e.g. botLeftDir = 2, topRightDir = 9, then 2,3,5,6,8,9
	extern "C" COORD_FUNCTIONS_H_API void getAllDirsBetweenTwoDirsTopDown(std::vector<int>& toFill, int botLeftDir, int topRightDir);
 
	extern "C" COORD_FUNCTIONS_H_API Point2D cordSlope(int x1, int y1, int x2, int y2);
	extern "C" COORD_FUNCTIONS_H_API DOUBLEBOOL doubleSlope(Point2D stepSlope);
	extern "C" COORD_FUNCTIONS_H_API int slopeToDir(int x, int y, int endX, int endY);
	extern "C" COORD_FUNCTIONS_H_API int slopeToDir_Point2D(Point2D xSlope, Point2D ySlope);

	/// <summary>
	/// Using the MaxDimensions input, convert a Coord to a CoordDir
	/// e.g. You have a Coord(150,-50) and MaxDimensions(100,100)
	///		The output will be (1,-1)
	/// e.g. You have a Coord(50,550) and MaxDimensions(100,100)
	///		The output will be (0,1)
	/// </summary>
	/// <param name="Coord"></param>
	/// <param name="MaxDimensions"></param>
	/// <returns></returns>
	extern "C" COORD_FUNCTIONS_H_API Point2D normalizeCoordToDirection2d(Point2D Coord, int MaxDimensions);
	extern "C" COORD_FUNCTIONS_H_API Spatial::dir3d normalizeCoordToDirection3d(Point3D Coord, int MaxDimensions);
	extern "C" COORD_FUNCTIONS_H_API Point3D dirToCoord3d(Spatial::dir dir);
	extern "C" COORD_FUNCTIONS_H_API Point3D dir3dToCoord3d(Spatial::dir3d dir);
	extern "C" COORD_FUNCTIONS_H_API Spatial::dir3d coordToDir3d(Point3D coord);
	extern "C" COORD_FUNCTIONS_H_API Spatial::dir dir3dToDir2d(Spatial::dir3d Dir3d);



	//ToDo: I don't think this is really necessary - anything past the adjacent from NoDirection index etc is pretty arbitrary
	//if this is < Spatial::dir3d::STATE_COUNT then it returns the dir3d value
	//else it returns subsequently larger values:
	// 5x5 = 25
	// 5x5 = 25
	// 5x3 = 15
	// 5x3 = 15
	// 3x3 = 9
	// 3x3 = 9
	// 27-124 for the first level
	// 27-51 for the 5x5 on the lowest z-level, each row, sw to ne
	// 52-76 for the 5x5 on the highest z-level, each row, sw to ne
	// then it returns the rest, starting with sw, south, se, west, east, nw, north, ne - bottom-to-top, west to east, south to north	
	// 77-79 for sw corner, bottom to top
	// 80-82 for south, lowest level, west to east
	// 83-85 for south middle level, west to east
	// 86-88 for south top level, west to east
	// 89-91 for se corner, bottom to top
	// 92-94 for west, lowest level, south to north
	// 95-97 for west, middle level, south to north
	// 98-100 for west, top level, south to north
	// 101-103 for east, lowest level, south to north
	// 104-106 for east, middle level, south to north
	// 107-109 for east, top level, south to north
	// 110-112 for nw corner, bottom to top
	// 113-115 for north, lowest level, west to east
	// 116-118 for north, middle level, west to east
	// 119-121 for north, top level, west to east
	// 122-124 for ne corner, bottom to top

	// anything beyond that continues the pattern


	////We'll just use the default Point3D sort
	//Point3D indexToCoord3d(int index);
	//int coordToIndex3d(Point3D coord);



}
#endif
