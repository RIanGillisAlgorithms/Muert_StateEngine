

//by ian.gillis
#pragma once
#ifndef QUAD2_H
#define QUAD2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define QUAD2_H_API __declspec(dllexport)
#else
#define QUAD2_H_API __declspec(dllimport)
#endif



#include "triangle2.h"

struct QUAD2_H_API Quad2D
{
public:
	Quad2D();
	Quad2D(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4);
	Quad2D(Line2D* l1, Line2D* l2, Line2D* l3, Line2D* l4);	   
	~Quad2D();
	Point2D * p1;
	Point2D * p2;
	Point2D * p3;
	Point2D * p4;

	//line 1 goes from p1 to p2
	Line2D * l1;
	//line 2 goes from p2 to p3
	Line2D * l2;
	//line 3 goes from p3 to p4
	Line2D * l3;
	//line 4 goes from p4 to p1
	Line2D * l4;

	void updatePointsFromLines();

};

#endif
