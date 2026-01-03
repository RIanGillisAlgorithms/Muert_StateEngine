//by ian.gillis
#pragma once
#ifndef POINT2_2_h
#define POINT2_2_h

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define POINT2_2_h_API __declspec(dllexport)
#else
#define POINT2_2_h_API __declspec(dllimport)
#endif


#include "point2.h"
#include "Int0To100Predicate.h"


struct POINT2_2_h_API TwoPoint2D
{
public:
	TwoPoint2D() {};
	TwoPoint2D(Point2D Cur, Point2D Acur);
	Point2D cur;
	Point2D acur;
};

struct POINT2_2_h_API TwoPoint2D_Elevation
{
public:
	TwoPoint2D_Elevation() {};
	TwoPoint2D_Elevation(TwoPoint2D Coord, int Elevation);
	TwoPoint2D coord;
	Property <int, Int0To10000 <ThrowError> > elevation;

};

#endif
