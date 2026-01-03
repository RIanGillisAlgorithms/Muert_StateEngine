

//by ian.gillis
#pragma once
#ifndef globalGenerics_H
#define globalGenerics_H


#ifdef MUERTENGINEGLOBAL_EXPORTS
#define globalGenerics_H_API __declspec(dllexport)
#else
#define globalGenerics_H_API __declspec(dllimport)
#endif


// globalGenerics.h
// by Ian

#include <vector>
#include <fstream>
#include "../MuertEngine.Random/RandomWrapper.h"
#include "point2.h"
#include "point3.h"
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"



extern "C" globalGenerics_H_API void GenerateShuffledIntegers(int Size, std::vector<int>& IndexVector);

//convert from 1d to 2d coordinates
extern "C" globalGenerics_H_API Point2D IndexTo2dCoords(int Index, int MaxDim);

//convert from 1d to 3d coordinates
extern "C" globalGenerics_H_API Point3D IndexTo3dCoords(int Index, int MaxDim);

//convert from 2d to 1d coordinate
extern "C" globalGenerics_H_API int Coords2dToIndex(Point2D Coords, int MaxDim);

//convert from 3d to 1d coordinate
extern "C" globalGenerics_H_API int Coords3dToIndex(Point3D Coords, int MaxDim);

extern "C" globalGenerics_H_API Point3D SelectRandomPointAlongEdge3d(Spatial::dir3d dirr, int maxDims);

extern "C" globalGenerics_H_API Spatial::dir3d DrunkWalk3d(Point3D startPoint, Point3D endPoint, double chanceToStumble);



#endif