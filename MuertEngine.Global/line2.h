

//by ian.gillis
#pragma once
#ifndef LINE2_H
#define LINE2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define LINE2_H_API __declspec(dllexport)
#else
#define LINE2_H_API __declspec(dllimport)
#endif


#include <cmath>

#include "point2.h"

struct LINE2_H_API Line2D
{
public:
	Line2D();
	Line2D(Point2D* p1, Point2D* p2);
	~Line2D();

	void setLine(Point2D* p1, Point2D* p2);
	void recalcVecs();	  
	Point2D * p1;
	Point2D * p2;
	Point2D vec1;
	Point2D vec2;

	int interceptPointY(unsigned char interceptValToCheck, bool interceptsY = true);
};

struct LINE2_H_API Point2D_Line2D
{
public:
	Point2D_Line2D();
	Point2D_Line2D(Point2D p1, Point2D p2);
	~Point2D_Line2D();

	void setLine(Point2D p1, Point2D p2);
	void recalcVecs();
	Point2D p1;
	Point2D p2;
	Point2D vec1;
	Point2D vec2;

	int interceptPointY(unsigned char interceptValToCheck, bool interceptsY = true);
};

#endif // _DEBUG
