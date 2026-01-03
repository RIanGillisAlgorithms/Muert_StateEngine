//by ian.gillis
#pragma once
#ifndef point3_2_H
#define point3_2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define point3_2_H_API __declspec(dllexport)
#else
#define point3_2_H_API __declspec(dllimport)
#endif


// point3_2.h
// by Ian

#include "point3.h"
#include "Int0To100Predicate.h"


struct point3_2_H_API TwoPoint3D
{
public:
	TwoPoint3D() {};
	TwoPoint3D(Point3D Cur, Point3D Acur);
	Point3D cur;
	Point3D &topLeft() {return cur;}
	Point3D acur;
	Point3D &botRight() {return acur;}
	
	Point3D getTopLeft();
	Point3D getBotLeft();
	void setTopLeft(Point3D& Setter);
	void setBotLeft(Point3D& Setter);
	Point3D getBotRight();
	Point3D getTopRight();
	void setBotRight(Point3D& Setter);
	void setTopRight(Point3D& Setter);

	bool isPointWithinTopLeftToBotRight(Point3D &Checker);
	TwoPoint3D getIntersection(TwoPoint3D intersector);
};

struct point3_2_H_API TwoPoint3D_Elevation
{
public:
	TwoPoint3D_Elevation() {};
	TwoPoint3D_Elevation(TwoPoint3D Coord, int Elevation);
	TwoPoint3D coord;
	Property <int, Int0To10000 <ThrowError> > elevation;

};





#endif