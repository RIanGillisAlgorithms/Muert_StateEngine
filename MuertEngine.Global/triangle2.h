

//by ian.gillis
#pragma once
#ifndef TRIANGLE2_H
#define TRIANGLE2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define TRIANGLE2_H_API __declspec(dllexport)
#else
#define TRIANGLE2_H_API __declspec(dllimport)
#endif


#include "../MuertEngine.Random/RandomWrapper.h"
#include "line2.h"


struct TRIANGLE2_H_API Triangle2D
{
public:
	Triangle2D();
	Triangle2D(Point2D* p1, Point2D* p2, Point2D* p3);
	Triangle2D(Line2D* l1, Line2D* l2, Line2D* l3);
	~Triangle2D();

	Point2D * p1;
	Point2D * p2;
	Point2D * p3;

	//line 1 goes from p1 to p2
	Line2D * l1;
	//line 2 goes from p2 to p3
	Line2D * l2;
	//line 3 goes from p3 to p1
	Line2D * l3;

	void updatePointsFromLines();	
	Point2D SelectRandomPointWithinMe();
	Point2D GetPointInTriangle(Point2D a, Point2D b, Point2D c);
	bool isPoint(Point2D pToTest);
};
#endif
