/*
* Point2D.cpp
* Republican & Democrat Simulator
*
* Created by Anthony Popp on 11/5/14.
* Copyright 2014. All rights reserved.
*
* This file is part of Republican & Democrat Simulator. This file alone is beging released
* under the GNU General Public License
*
* you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Point.cpp is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* A copy of the GNU General Public License is avaiable at <http://www.gnu.org/licenses/>.
*/
#include "pch.h"

#include <string>//Needed only for the ToString() function
//#include //Needed only for the ToString() function
#include "point2.h" //Our header file See: //<http://www.programmingmoney.com/source-code-point2d-header/>
#include "point3.h"
//#include "Library.h" //Needed for the Random() function calls

////////////////////////////////////////////////
//
//General purpose Point2D class that I programmed
//college consoel game, R&D simulator
//http://www.programmingmoney.com
//I am relaseing this on the web. If you wish to use it,
//all a ask is that you provide proper attribution, and abloge to the license
//
//////////////////////////////////////////////////
//
//Also, if you find this useful, it would be really cool if you could do one of the following:
// - Tweet about my blog,
// - share it on Facebook,
// - sending an email,
// - talk about it with someone
//
/////////////////////////////////////////////////

//Constructors and Destructor

//==================================================================
//Constructors/Destructors
//A point that holds the position of our characters
//------------------------------------------------------------------
Point2D::Point2D()
{
	x = 0;
	y = 0;
}
Point2D::Point2D(const int x, const int y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D(const Point3D inp3d)
{
	this->x = inp3d.x;
	this->y = inp3d.y;
}

Point2D::~Point2D()
{
	//Nothing to do here
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//Struct Setters

//===================================================================
//Struct Setters
//Allows us to set the data without having to instantiate
//-------------------------------------------------------------------
void Point2D::Set(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
void Point2D::Set(const Point2D &other)
{
	this->x = other.x;
	this->y = other.y;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Getter and Setter Mutators

//==================================================================
//Getter and Setter Mutators
//Although x and y are public, it is good practice to have these
//------------------------------------------------------------------
void Point2D::SetX(const int x)
{
	this->x = x;
}
void Point2D::SetY(const int y)
{
	this->y = y;
}
int Point2D::GetX() const
{
	return x;
}
int Point2D::GetY() const
{
	return y;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//Manhattan Member Function Implementations

//===================================================================
//=== Manhattan Member Function Implementations ===
//-------------------------------------------------------------------
//Author Note: Manhattan is shorthanded for Man*/
//(For example, manDist = manhattanDistance)

//===-------------------------------------------------------------===
//This returns the x,y coords of the distance between two points
//const Point2D &other: a Point2D you want to find the distance too
Point2D Point2D::ManhattanCoords(const Point2D &other) const
{
	return Point2D(other.x - x, other.y - y);
}

//===-------------------------------------------------------------===
//This returns the manhattenDistance abs(sum) between two points
//const Point2D &other: a Point2D you want to find the distance too
int Point2D::ManhattanDistance(const Point2D &other) const
{
	Point2D manDist(other.x - x, other.y - y);
	return abs(manDist.x) + abs(manDist.y);
}

//===-------------------------------------------------------------===
//This returns the total number of x,y positions within a given manDist
//const int manDist: this is the the radius, of which area will be calculated
int Point2D::ManhattanArea(const int manDist) const
{
	int area = 0;
	for (int i = 0; i <= manDist; i++)
	{
		area += 2 * (1 + ((manDist - i) * 2));
	}
	/*
	1
	.....x0
	....xox 4 5
	.....x
	2
	.....x
	....xxx2
	...xxoxx 12 13
	....xxx
	.....x
	3
	.....x
	....xxx
	...xxxxx4
	..xxxoxxx 24 25
	...xxxxx
	....xxx
	....x
	4
	....x
	...xxx
	..xxxxx
	.xxxxxxx
	xxxxoxxxx 40 41
	.xxxxxxx
	..xxxxx
	...xxx
	....x
	*/
	return area;
}

//===-------------------------------------------------------------===
//This returns the manhattan distance that best conceals a given area
//const int manArea: this a number of points, which the function will contain
int Point2D::ManhattanCityLimit(const int manArea) const
{
	int manDist = 0;
	int area = 0;
	do
	{
		area = 0;
		for (int i = 0; i <= manDist; i++)
		{
			area += 2 * (1 + ((manDist - i) * 2));
		}
		manDist++;
	} while (area < manArea);
	return manDist;
}

//===-------------------------------------------------------------===
//Is this point within the desired manhattan distance of another point
//const Point2D &other: a Point2D, being checked for proximity
//int manDist: an int, that represents a radius away from this Point2D
bool Point2D::IsWithinManhattanDistance(const Point2D &other, int manDist)
{
	return (ManhattanDistance(other) <= manDist);
}

//===-------------------------------------------------------------===
//This gets a random point within a givin manhattan distance
//const int manArea: an int, used to get a random Point2D
Point2D Point2D::GetRandomStreetInManhattan(int manDist)
{
	Point2D randMan(		
		RND::rnd.intRand(x - manDist, x + manDist),
		RND::rnd.intRand(y - manDist, y + manDist));

	while (!IsWithinManhattanDistance(randMan, manDist))
	{
		randMan.Set(
			RND::rnd.intRand(x - manDist, x + manDist),
			RND::rnd.intRand(y - manDist, y + manDist));
	}
	return randMan;
}

//===-------------------------------------------------------------===
//Check to see if the point is in the map
//const int left: an int, left (x) pos of a rectangle
//const int right: an int, right (x) pos of a rectangle
//const int top: an int, top (y) pos of a rectangle
//const int bottom: an int, bottom (y) pos of a rectangle
bool Point2D::IsInRectangle(const int left, const int right, const int top, const int bottom) const
{
	if (x >= left && x <= right &&
		y >= top && y <= bottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//===-------------------------------------------------------------===
//Clamps a point to the bounds of a rectangle
//const int left: an int, left (x) pos of a rectangle
//const int right: an int, right (x) pos of a rectangle
//const int top: an int, top (y) pos of a rectangle
//const int bottom: an int, bottom (y) pos of a rectangle
void Point2D::ClampToRectangle(const int left, const int right, const int top, const int bottom)
{
	if (x < left)
		x = 0;
	if (y < top)
		y = 0;
	if (x > right)
		x = right - 1;
	if (y > bottom)
		y = bottom - 1;
}

//===-------------------------------------------------------------===
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Mathematical Functions

//===================================================================
//Mathematical Functions
//Other function I added after finishing the game, for you to use
//-------------------------------------------------------------------
//Swaps the x and y values so taht x = y and y = x
void Point2D::Swap()
{
	x = x + y;
	y = x - y;
	x = x - y;
}

//Takes the Point2D to the second power by multiplying itself
void Point2D::Square()
{
	x = x * x;
	y = y * y;
}

//Takes the Point2D to the third power by multiplying itself
void Point2D::Cube()
{
	x = x * x * x;
	y = y * y * y;
}

//Halfs the x and y values of the Point2D
void Point2D::Half()
{
	x = (int)(x * 0.5) + 0.5f;
	y = (int)(y * 0.5) + 0.5f;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// ToString function

//====================================================================
//ToString function
//If you wish not to use this funciton, you can remove the corresponding
//#include<> statements, as commented. This was used for logging data
//--------------------------------------------------------------------
std::string Point2D::ToString() const
{
	std::string s = "(x: ";
	s += std::to_string((long double)x);
	s += ',';
	s += ' ';
	s += 'y';
	s += ':';
	s += ' ';
	s += std::to_string((long double)y);
	s += ')';
	return s;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Point2D Math Operations

//======================================================================
//Operations
//The game only used == != + - * and +=, but I decided to be complete.
//All other operator methods were programmed after the game was finished
//----------------------------------------------------------------------
//---Addition---
Point2D Point2D::operator+ (const Point2D &other) const
{
	Point2D result(x + other.x, y + other.y);
	return result;
}
Point2D Point2D::operator+ (const int other) const
{
	Point2D result(x + other, y + other);
	return result;
}

//---Subtraction---
Point2D Point2D::operator- (const int other) const
{
	Point2D result(x - other, y - other);
	return result;
}
Point2D Point2D::operator- (const Point2D &other) const
{
	Point2D result(x - other.x, y - other.y);
	return result;
}

//---Division---
Point2D Point2D::operator/ (const int other) const
{
	if (other == 0 || other == 0)
	{
		//DIVIDE BY ZERO ERROR
		return Zero();
	}
	Point2D result(x / other, y / other);
	return result;
}

Point2D Point2D::operator/ (const Point2D &other) const
{
	if (other.x == 0 || other.y == 0)
	{
		//DIVIDE BY ZERO ERROR
		return Zero();
	}
	Point2D result(x / other.x, y / other.y);
	return result;
}

//---Multiplication---
Point2D Point2D::operator* (const int other) const
{
	Point2D result(x * other, y * other);
	return result;
}
Point2D Point2D::operator* (const Point2D &other) const
{
	Point2D result(x * other.x, y * other.y);
	return result;
}

//---Self-Addition---
void Point2D::operator+= (const Point2D &other)
{
	x += other.x;
	y += other.y;
}
void Point2D::operator+= (const int other)
{
	x += other;
	y += other;
}

//---Self-Subtraction---
void Point2D::operator-= (const Point2D &other)
{
	x -= other.x;
	y -= other.y;
}
void Point2D::operator-= (const int other)
{
	x -= other;
	y -= other;
}

//---Self-Multiplication---
void Point2D::operator*= (const int other)
{
	x = x * other;
	y = y * other;
}
void Point2D::operator*= (const float other)
{
	x = (int)((x * other) + 0.5f);
	y = (int)((y * other) + 0.5f);
}
void Point2D::operator*= (const Point2D &other)
{
	x = (int)((float)x * (float)other.x + 0.5f);
	y = (int)((float)y * (float)other.y + 0.5f);
}

//---Self-Division---
void Point2D::operator/= (const int other)
{
	if (other == 0 || other == 0)
	{
		x = 0;
		y = 0;
	}
	Point2D result(x / other, y / other);
}
void Point2D::operator/= (const float other)
{
	if (other == 0 || other == 0)
	{
		x = 0;
		y = 0;
	}
	Point2D result(x / other, y / other);
}
void Point2D::operator/= (const Point2D &other)
{
	if (other.x == 0 || other.y == 0)
	{
		x = 0;
		y = 0;
	}
	Point2D result(x / other.x, y / other.y);
}

//---Equality---
bool Point2D::operator==(const int other) const
{
	return (x == other && y == other);
}
bool Point2D::operator==(const Point2D &other) const
{
	return (x == other.x && y == other.y);
}

//---Inequality---
bool Point2D::operator!=(const int other) const
{
	return (x != other || y != other);
}
bool Point2D::operator!=(const Point2D &other) const
{
	return (x != other.x || y != other.y);
}

//---Greater/Less
bool Point2D::operator>(const int other) const
{
	return (x > other && y > other);
}
bool Point2D::operator>(const Point2D &other) const
{
	return (x > other.x && y > other.y);
}
bool Point2D::operator<(const int other) const
{
	return (x < other && y < other);
}
bool Point2D::operator<(const Point2D &other) const
{
	if (other.y < y)
	{
		return true;
	}
	else if (y < other.y)
	{
		return false;
	}
	else if (other.x < x)
	{
		return true;
	}
	else /* (gpCord.GetX() < other.gpCord.GetX()) */
	{
		return false;
	}
}

//---Self-Greater/Less---
bool Point2D::operator>=(const int other) const
{
	return (x >= other && y >= other);
}
bool Point2D::operator>=(const Point2D &other) const
{
	return (x >= other.x && y >= other.y);
}
bool Point2D::operator<=(const int other) const
{
	return (x <= other && y <= other);
}
bool Point2D::operator<=(const Point2D &other) const
{
	return (x <= other.x && y <= other.y);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Static Functions

//================================================================
//Static Functions
//These were added after finishing the game
//Inspired by XNA Game Studio's Point2D functions
//----------------------------------------------------------------
Point2D Point2D::Zero()
{
	return Point2D(0, 0);
}
Point2D Point2D::One()
{
	return Point2D(1, 1);
}

Point2D Point2D::NegativeOne()
{
	return Point2D(-1, -1);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx