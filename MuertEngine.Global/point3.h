//by ian.gillis
#pragma once
#ifndef point_3d_H
#define point_3d_H
// point_3d.h
// by Ian

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define point_3d_H_API __declspec(dllexport)
#else
#define point_3d_H_API __declspec(dllimport)
#endif

#include <string>
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"

struct point_3d_H_API Point2D;
struct point_3d_H_API Point3D
{
public:
	//Variables
	int x;
	int y;
	int z;

	//===============================
	//Constructors
	//===============================
	Point3D();
	Point3D(const int x, const int y, const int z);
	//Point3D::Point3D(const Point2D inp);
	Point3D(const Point2D inp);
	~Point3D();
	//===============================
	//Struct Setters
	//===============================
	void Set(const int x, const int y, const int z);
	void Set(const Point3D &other);
	void Set(const Point2D &other);
	void Set(const int x, const int y);
	//======================================================//
	//Getters and Setter
	//------------------------------------------------------//
	void SetX(const int x);
	void SetY(const int y);
	void SetZ(const int z);
	int GetX() const;
	int GetY() const;
	int GetZ() const;
	//======================================================//
	//======================================================//
	//Author Note: Manhattan is shorthanded for Man //
	//------------------------------------------------------//

	//This returns the x,y,z coords of the distance between two points
	Point3D ManhattanCoords(const Point3D &other) const;
	//This returns the ManhattanDistance between two points
	int ManhattanDistance(const Point3D &other) const;
	//This returns the absolute distance between this and other (i.e. 0,0,0 to 1,200,10 = 200)
	int IanDistance(const Point3D& other) const;
	//This returns the highest of the absolute value of x,y,z - [-30,28,1] will return 30
	int absExtent() const;

	//This will return convert the x,y,z coords to a singular index
	// starting with 0,0,0 = 0	
	//	anything between -1,1 will be 1-26
	//  anything between -2,2 will be 27-124
	//	anything between -3,3 will be 125-342
	//	anything between -4,4 will be 343-728
	//	anything between -5,5 will be 729-1330
	int coordToIndex_WithNegativeCoords() const;

	//This returns the total number of x,y positions within a given manDist good for a collection of points
	int ManhattanArea(const int manDist) const;
	//This returns the Manhattan distance that best conceals a given area
	int ManhattanCityLimit(const int manArea) const;
	//Is this point within the desired Manhattan distance of another point
	bool IsWithinManhattanDistance(const Point3D &other, int manDist) const;
	//This gets a random point within a givin Manhattan distance
	Point3D GetRandomStreetInManhattan(int manDist) const;
	//Check to see if the point is in the map
	bool IsInRectangle(const int left, const int right, const int top, const int bottom) const;
	bool IsInCube(const int minX, const int maxX, const int minY, const int maxY, const int minZ, const int maxZ);
	void ClampToRectangle(const int left, const int right, const int top, const int bottom);
	void ShiftDirection2d(int DirectionToShift, int NumStepsToShift);
	void ShiftDirection2d(Spatial::dir DirectionToShift, int NumStepsToShift);
	void ShiftDirection3d(Spatial::dir DirectionToShift, int NumStepsToShift);
	void ShiftDirection3d(Point3D DirectionToShift, int NumStepsToShift);
	//Mathmatical Functions
	//Swaps the x and y values so that x = y and y = x
	void Swap();
	//Takes the Point3D to the second power by multiplying itself
	void Square();
	//Takes the Point3D to the second power by multiplying itself
	void Cube();
	//Halfs the x and y values of the Point3D
	void Half();
	std::string ToString() const;

	bool IsAdjacent(const Point3D& other) const;
	

	//======================================================//
	//Operators
	//------------------------------------------------------//
	Point3D operator+ (const Point3D &other) const;
	Point3D operator+ (const int other) const;
	Point3D operator- (const Point3D &other) const;
	Point3D operator- (const int other) const;
	Point3D operator* (const Point3D &other) const;
	Point3D operator* (const int other) const;
	Point3D operator/ (const Point3D &other) const;
	Point3D operator/ (const int other) const;
	void operator+= (const Point3D &other);
	void operator+= (const int other);
	void operator-= (const Point3D &other);
	void operator-= (const int other);
	void operator*= (const int other);
	void operator*= (const float other);
	void operator*= (const Point3D &other);
	void operator/= (const int other);
	void operator/= (const float other);
	void operator/= (const Point3D &other);
	bool operator== (const int other) const;
	bool operator== (const Point3D &other) const;
	bool operator!= (const int other) const;
	bool operator!= (const Point3D &other) const;
	bool operator> (const int other) const;
	bool operator> (const Point3D &other) const;
	bool operator< (const int other) const;
	bool operator< (const Point3D &other) const;
	bool operator>= (const int other) const;
	bool operator>= (const Point3D &other) const;
	bool operator<= (const int other) const;
	bool operator<= (const Point3D &other) const;
	//===============================================================//
	//===============================================================//
	//Static Function
	//---------------------------------------------------------------//
	static Point3D Zero();
	static Point3D One();
	static Point3D NegativeOne();
	//===============================================================//
};





#endif