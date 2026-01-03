//by ian.gillis
#pragma once
#ifndef PENT2_H
#define PENT2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define PENT2_H_API __declspec(dllexport)
#else
#define PENT2_H_API __declspec(dllimport)
#endif


#include "quad2.h"


struct PENT2_H_API Pent2D
{
public:
	Pent2D();
	Pent2D(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5);
	Pent2D(Line2D* l1, Line2D* l2, Line2D* l3, Line2D* l4, Line2D* l5);

	~Pent2D();

	Point2D * p1;
	Point2D * p2;
	Point2D * p3;
	Point2D * p4;
	Point2D * p5;
	//line 1 goes from p1 to p2
	Line2D * l1;
	//line 2 goes from p2 to p3
	Line2D * l2;
	//line 3 goes from p3 to p4
	Line2D * l3;
	//line 4 goes from p4 to p5
	Line2D * l4;
	//line 4 goes from p5 to p1
	Line2D * l5;

	void updatePointsFromLines();

};

#endif
