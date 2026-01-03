/*
* Point2D.h
* Republican & Democrat Simulator
*
* Created by Anthony Popp on 11/5/14.
* Copyright 2014. All rights reserved.
*
* This file is part of Republican & Democrat Simulator. This file alone is being released
* under the GNU General Public License
*
* you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Point.h is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* A copy of the GNU General Public License is available at <http://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef POINT2_H
#define POINT2_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define POINT2_H_API __declspec(dllexport)
#else
#define POINT2_H_API __declspec(dllimport)
#endif

#include <cmath>

#include "../MuertEngine.Random/RandomWrapper.h"
struct POINT2_H_API Point3D;

//======================================================//
//======================================================//
//General purpose Point2D class I programmed for my
//college console game, R&D simulator
//I am relaseing this on the web. If you wish to use it,
//all a ask is that you provide attribution.
//Also, it would be really cool if you can do the one of the following for me.
//2. Tweet about my blog, share it on Facebook, sending an email.
//======================================================//
//======================================================//
struct POINT2_H_API Point2D
{
public:
	//Variables
	int x;
	int y;

	//===============================
	//Constructors
	//===============================
	Point2D();
	Point2D(const int x, const int y);
	Point2D(const Point3D inp3d);
	~Point2D();
	//===============================
	//Struct Setters
	//===============================
	void Set(const int x, const int y);
	void Set(const Point2D &other);
	//======================================================//
	//Getters and Setter
	//------------------------------------------------------//
	void SetX(const int x);
	void SetY(const int y);
	int GetX() const;
	int GetY() const;
	//======================================================//
	//======================================================//
	//Author Note: Manhattan is shorthanded for Man //
	//------------------------------------------------------//

	//This returns the x,y coords of the distance between two points
	Point2D ManhattanCoords(const Point2D &other) const;
	//This returns the ManhattanDistance between two points
	int ManhattanDistance(const Point2D &other) const;
	//This returns the total number of x,y positions within a given manDist good for a collection of points
	int ManhattanArea(const int manDist) const;
	//This returns the Manhattan distance that best conceals a given area
	int ManhattanCityLimit(const int manArea) const;
	//Is this point within the desired Manhattan distance of another point
	bool IsWithinManhattanDistance(const Point2D &other, int manDist);
	//This gets a random point within a givin Manhattan distance
	Point2D GetRandomStreetInManhattan(int manDist);
	//Check to see if the point is in the map
	bool IsInRectangle(const int left, const int right, const int top, const int bottom) const;
	void ClampToRectangle(const int left, const int right, const int top, const int bottom);
	//Mathmatical Functions
	//Swaps the x and y values so that x = y and y = x
	void Swap();
	//Takes the Point2D to the second power by multiplying itself
	void Square();
	//Takes the Point2D to the second power by multiplying itself
	void Cube();
	//Halfs the x and y values of the Point2D
	void Half();
	std::string ToString() const;

	//======================================================//
	//Operators
	//------------------------------------------------------//
	Point2D operator+ (const Point2D &other) const;
	Point2D operator+ (const int other) const;
	Point2D operator- (const Point2D &other) const;
	Point2D operator- (const int other) const;
	Point2D operator* (const Point2D &other) const;
	Point2D operator* (const int other) const;
	Point2D operator/ (const Point2D &other) const;
	Point2D operator/ (const int other) const;
	void operator+= (const Point2D &other);
	void operator+= (const int other);
	void operator-= (const Point2D &other);
	void operator-= (const int other);
	void operator*= (const int other);
	void operator*= (const float other);
	void operator*= (const Point2D &other);
	void operator/= (const int other);
	void operator/= (const float other);
	void operator/= (const Point2D &other);
	bool operator== (const int other) const;
	bool operator== (const Point2D &other) const;
	bool operator!= (const int other) const;
	bool operator!= (const Point2D &other) const;
	bool operator> (const int other) const;
	bool operator> (const Point2D &other) const;
	bool operator< (const int other) const;
	bool operator< (const Point2D &other) const;
	bool operator>= (const int other) const;
	bool operator>= (const Point2D &other) const;
	bool operator<= (const int other) const;
	bool operator<= (const Point2D &other) const;
	//===============================================================//
	//===============================================================//
	//Static Function
	//---------------------------------------------------------------//
	static Point2D Zero();
	static Point2D One();
	static Point2D NegativeOne();
	//===============================================================//
};

//struct point
//{
//	double x, y;
//	point(double x = 0, double y = 0) : x(x), y(y) { }
//};

struct POINT2_H_API intersection : public Point2D
{
	bool parallel;
	bool collinear;
	enum extends_type { none, AB, BA, CD, DC } extends;

	intersection(Point2D A, Point2D B, Point2D C, Point2D D, double epsilon = 0.000000001) :
		parallel(false),
		collinear(false),
		extends(none)
	{
		// Uses the determinant of the two lines. For more information, refer to one of the following:
		// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection#Given_two_points_on_each_line
		// http://www.faqs.org/faqs/graphics/algorithms-faq/ (Subject 1.03)

		double d = denominator(A, B, C, D);

		if (std::abs(d) < epsilon)
		{
			parallel = true;
			collinear = abs(numerator(A, C, C, D)) < epsilon;
			return;
		}

		double r = numerator(A, C, C, D) / d;
		double s = numerator(A, C, A, B) / d;

		x = A.x + r * (double)(B.x - A.x);
		y = A.y + r * (double)(B.y - A.y);

		extends = (extends_type)((r > 1) + 2 * (r < 0) + 3 * (s>1) + 4 * (s < 0));
	}

private:
	inline double numerator(Point2D A, Point2D C, Point2D E, Point2D F) { return (A.y - C.y) * (F.x - E.x) - (A.x - C.x) * (F.y - E.y); }
	inline double denominator(Point2D A, Point2D B, Point2D C, Point2D D) { return (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x); }
};






#endif