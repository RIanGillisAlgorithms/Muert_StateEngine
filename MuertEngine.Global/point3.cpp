


#include "pch.h"
#include <string>//Needed only for the ToString() function
#include <sstream>//Needed to compile logical_error exception messages
#include "point3.h" //Our header file See: //<http://www.programmingmoney.com/source-code-point2d-header/>
#include "../MuertEngine.Random/RandomWrapper.h"
#include "point2.h"
#include "coordFunctions.h"

//Constructors and Destructor

//==================================================================
//Constructors/Destructors
//A point that holds the position of our characters
//------------------------------------------------------------------
Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
}
Point3D::Point3D(const int x, const int y, const int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Point3D::Point3D(const Point2D inp)
{
	this->x = inp.GetX();
	this->y = inp.GetY();
	this->z = 0;
}

Point3D::~Point3D()
{
	//Nothing to do here
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//Struct Setters

//===================================================================
//Struct Setters
//Allows us to set the data without having to instantiate
//-------------------------------------------------------------------
void Point3D::Set(const int x, const int y, const int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Point3D::Set(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
void Point3D::Set(const Point3D &other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}
void Point3D::Set(const Point2D &other)
{
	this->x = other.x;
	this->y = other.y;
	//don't change z in case we want to maintain the current value
	//this->z = 0;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Getter and Setter Mutators

//==================================================================
//Getter and Setter Mutators
//Although x and y are public, it is good practice to have these
//------------------------------------------------------------------
void Point3D::SetX(const int x)
{
	this->x = x;
}
void Point3D::SetY(const int y)
{
	this->y = y;
}
void Point3D::SetZ(const int z)
{
	this->z = z;
}
int Point3D::GetX() const
{
	return x;
}
int Point3D::GetY() const
{
	return y;
}
int Point3D::GetZ() const
{
	return z;
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
//const Point3D &other: a Point3D you want to find the distance too
Point3D Point3D::ManhattanCoords(const Point3D &other) const
{
	return Point3D(other.x - x, other.y - y, other.z - z);
}

//===-------------------------------------------------------------===
//This returns the manhattenDistance abs(sum) between two points
//const Point3D &other: a Point3D you want to find the distance too
int Point3D::ManhattanDistance(const Point3D &other) const
{
	//Point3D manDist(other.x - x, other.y - y);
	//return abs(manDist.x) + abs(manDist.y);

	//taken from: https://stackoverflow.com/a/3693557/2367188
	//float CBox::ManhattanDistance(Vec3 c1, Vec3 c2)
	//{
	//	float dx = abs(c2.x - c1.x);
	//	float dy = abs(c2.y - c1.y);
	//	float dz = abs(c2.z - c1.z);

	//	return dx + dy + dz;
	//}
	float dx = abs(other.GetX() - GetX());
	float dy = abs(other.GetY() - GetY());
	float dz = abs(other.GetZ() - GetZ());

	return dx + dy + dz;

}

int Point3D::IanDistance(const Point3D& other) const
{
	float dx = abs(other.GetX() - GetX());
	float dy = abs(other.GetY() - GetY());
	float dz = abs(other.GetZ() - GetZ());

	//std::max isn't working for some reason? Can't find where this #define max is coming from...
	return max(max(dx, dy), dz);
}

//This returns the highest of the absolute value of x,y,z - [-30,28,1] will return 30
int Point3D::absExtent() const
{
	//std::max isn't working for some reason? Can't find where this #define max is coming from...
	return max(max(abs(x), abs(y)), abs(z));
}

int Point3D::coordToIndex_WithNegativeCoords() const
{
	int dist = absExtent();
	if (dist == 0)
	{
		return 0;
	}
	if (dist == 1)
	{
		return (int)CORDFUNC::coordToDir3d(*this);
	}
	if (dist == 2)
	{
		//return 26 + (int)CORDFUNC::coordToDir3d(*this);
	}
	return -1;

}

//===-------------------------------------------------------------===
//This returns the total number of x,y positions within a given manDist
//const int manDist: this is the the radius, of which area will be calculated
int Point3D::ManhattanArea(const int manDist) const
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
int Point3D::ManhattanCityLimit(const int manArea) const
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
//const Point3D &other: a Point3D, being checked for proximity
//int manDist: an int, that represents a radius away from this Point3D
bool Point3D::IsWithinManhattanDistance(const Point3D &other, int manDist) const
{
	//float CBox::Within3DManhattanDistance(Vec3 c1, Vec3 c2, float distance)
	//{
	//	float dx = abs(c2.x - c1.x);
	//	if (dx > distance) return 0; // too far in x direction

	//	float dy = abs(c2.y - c1.y);
	//	if (dy > distance) return 0; // too far in y direction

	//	// since x and y distance are likely to be larger than
	//	// z distance most of the time we don't need to execute
	//	// the code below:

	//	float dz = abs(c2.z - c1.z);
	//	if (dz > distance) return 0; // too far in z direction

	//	return 1; // we're within the cube
	//}




	//return (ManhattanDistance(other) <= manDist);



		//float dx = abs(other.GetX() - GetX());
		//if (dx > manDist) return 0; // too far in x direction

		//float dy = abs(other.GetX() - GetY());
		//if (dy > manDist) return 0; // too far in y direction

		//// since x and y distance are likely to be larger than
		//// z distance most of the time we don't need to execute
		//// the code below:

		//float dz = abs(other.GetX() - GetZ());
		//if (dz > manDist) return 0; // too far in z direction

		//return 1; // we're within the cube


	return (ManhattanDistance(other) <= manDist);
}

//===-------------------------------------------------------------===
//This gets a random point within a givin manhattan distance
//const int manArea: an int, used to get a random Point3D
Point3D Point3D::GetRandomStreetInManhattan(int manDist) const
{
	Point3D randMan(
		RND::rnd.intRand(x - manDist, x + manDist),
		RND::rnd.intRand(y - manDist, y + manDist),
		RND::rnd.intRand(z - manDist, z + manDist)
	);

	while (!IsWithinManhattanDistance(randMan, manDist))
	{
		randMan.Set(
			RND::rnd.intRand(x - manDist, x + manDist),
			RND::rnd.intRand(y - manDist, y + manDist),
			RND::rnd.intRand(z - manDist, z + manDist)
		);
	}
	return randMan;
}

//===-------------------------------------------------------------===
//Check to see if the point is in the map
//const int left: an int, left (x) pos of a rectangle
//const int right: an int, right (x) pos of a rectangle
//const int top: an int, top (y) pos of a rectangle
//const int bottom: an int, bottom (y) pos of a rectangle
bool Point3D::IsInRectangle(const int left, const int right, const int top, const int bottom) const
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

bool Point3D::IsInCube(const int minX, const int maxX, const int minY, const int maxY, const int minZ, const int maxZ)
{
	if (x >= minX && x <= maxX &&
		y >= minY && y <= maxY &&
		z >= minZ && z <= maxZ)
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
void Point3D::ClampToRectangle(const int left, const int right, const int top, const int bottom)
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

void Point3D::ShiftDirection2d(int DirectionToShift, int NumStepsToShift)
{
	if (DirectionToShift < 1 || DirectionToShift > 9 || DirectionToShift == 5)
	{
		if (DirectionToShift == 5)
		{
			return;
		}
		std::stringstream ss;
		ss << "Attempted to ShiftDirection2d using an invalid DirectionToShift (" << DirectionToShift << ").";
		throw std::logic_error(ss.str());
	}
	Point2D ShiftDir = CORDFUNC::dirToCoord(DirectionToShift, true);
	ShiftDir *= NumStepsToShift;
	this->SetX(this->GetX() + ShiftDir.GetX());
	this->SetY(this->GetY() + ShiftDir.GetY());
}
void Point3D::ShiftDirection2d(Spatial::dir DirectionToShift, int NumStepsToShift)
{
	if (DirectionToShift == Spatial::dir::Up
		|| DirectionToShift == Spatial::dir::up
		|| DirectionToShift == Spatial::dir::Down
		|| DirectionToShift == Spatial::dir::down)
	{
		std::stringstream ss;
		ss << "Attempted to ShiftDirection2d using an invalid DirectionToShift (" << 
			EnumMapping::getNameForValue(
				Spatial::v_dir, DirectionToShift)
			 << ").";
		throw std::logic_error(ss.str());
	}
	Point2D ShiftDir = CORDFUNC::dirToCoord((int)DirectionToShift, true);
	ShiftDir *= NumStepsToShift;
	this->SetX(this->GetX() + ShiftDir.GetX());
	this->SetY(this->GetY() + ShiftDir.GetY());
}
void Point3D::ShiftDirection3d(Spatial::dir DirectionToShift, int NumStepsToShift)
{
	Point3D ShiftDir = CORDFUNC::dirToCoord3d(DirectionToShift);
	ShiftDir *= NumStepsToShift;
	this->SetX(this->GetX() + ShiftDir.GetX());
	this->SetY(this->GetY() + ShiftDir.GetY());
	this->SetZ(this->GetZ() + ShiftDir.GetZ());
}

void Point3D::ShiftDirection3d(Point3D DirectionToShift3d, int NumStepsToShift)
{
	this->Set(this->GetX() + (DirectionToShift3d.GetX() * NumStepsToShift),
		this->GetY() + (DirectionToShift3d.GetY() * NumStepsToShift),
		this->GetZ() + (DirectionToShift3d.GetZ() * NumStepsToShift)
	);
}
//===-------------------------------------------------------------===
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Mathematical Functions

//===================================================================
//Mathematical Functions
//Other function I added after finishing the game, for you to use
//-------------------------------------------------------------------
//Swaps the x and y values so taht x = y and y = x
void Point3D::Swap()
{
	x = x + y;
	y = x - y;
	x = x - y;
}

//Takes the Point3D to the second power by multiplying itself
void Point3D::Square()
{
	x = x * x;
	y = y * y;
}

//Takes the Point3D to the third power by multiplying itself
void Point3D::Cube()
{
	x = x * x * x;
	y = y * y * y;
}

//Halfs the x and y values of the Point3D
void Point3D::Half()
{
	x = (int)(x * 0.5) + 0.5f;
	y = (int)(y * 0.5) + 0.5f;
	z = (int)(z * 0.5) + 0.5f;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// ToString function

//====================================================================
//ToString function
//If you wish not to use this funciton, you can remove the corresponding
//#include<> statements, as commented. This was used for logging data
//--------------------------------------------------------------------
std::string Point3D::ToString() const
{
	std::string s = "(x: ";
	s += std::to_string((long double)x);
	s += ',';
	s += ' ';
	s += 'y';
	s += ':';
	s += ' ';
	s += std::to_string((long double)y);
	s += ',';
	s += ' ';
	s += 'z';
	s += ':';
	s += ' ';
	s += std::to_string((long double)z);
	s += ')';
	return s;
}

bool Point3D::IsAdjacent(const Point3D& other) const
{
	if (abs(x - other.x) <= 1 && abs(y - other.y) <= 1 && abs(z - other.z) <= 1)
	{
		return true;
	}
	return false;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Point3D Math Operations

//======================================================================
//Operations
//The game only used == != + - * and +=, but I decided to be complete.
//All other operator methods were programmed after the game was finished
//----------------------------------------------------------------------
//---Addition---
Point3D Point3D::operator+ (const Point3D &other) const
{
	Point3D result(x + other.x, y + other.y, z + other.z);
	return result;
}
Point3D Point3D::operator+ (const int other) const
{
	Point3D result(x + other, y + other, z + other);
	return result;
}

//---Subtraction---
Point3D Point3D::operator- (const int other) const
{
	Point3D result(x - other, y - other, z - other);
	return result;
}
Point3D Point3D::operator- (const Point3D &other) const
{
	Point3D result(x - other.x, y - other.y, z - other.z);
	return result;
}

//---Division---
Point3D Point3D::operator/ (const int other) const
{
	if (other == 0 || other == 0)
	{
		//DIVIDE BY ZERO ERROR
		return Zero();
	}
	Point3D result(x / other, y / other, z / other);
	return result;
}

Point3D Point3D::operator/ (const Point3D &other) const
{
	if (other.x == 0 || other.y == 0 || other.z == 0)
	{
		//DIVIDE BY ZERO ERROR
		return Zero();
	}
	Point3D result(x / other.x, y / other.y, z / other.z);
	return result;
}

//---Multiplication---
Point3D Point3D::operator* (const int other) const
{
	Point3D result(x * other, y * other, z * other);
	return result;
}
Point3D Point3D::operator* (const Point3D &other) const
{
	Point3D result(x * other.x, y * other.y, z * other.z);
	return result;
}

//---Self-Addition---
void Point3D::operator+= (const Point3D &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}
void Point3D::operator+= (const int other)
{
	x += other;
	y += other;
	z += other;
}

//---Self-Subtraction---
void Point3D::operator-= (const Point3D &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}
void Point3D::operator-= (const int other)
{
	x -= other;
	y -= other;
	z -= other;
}

//---Self-Multiplication---
void Point3D::operator*= (const int other)
{
	x = x * other;
	y = y * other;
	z = z * other;
}
void Point3D::operator*= (const float other)
{
	x = (int)((x * other) + 0.5f);
	y = (int)((y * other) + 0.5f);
	z = (int)((z * other) + 0.5f);
}
void Point3D::operator*= (const Point3D &other)
{
	x = (int)((float)x * (float)other.x + 0.5f);
	y = (int)((float)y * (float)other.y + 0.5f);
	z = (int)((float)z * (float)other.z + 0.5f);
}

//---Self-Division---
void Point3D::operator/= (const int other)
{
	if (other == 0 || other == 0)
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point3D result(x / other, y / other, z / other);
}
void Point3D::operator/= (const float other)
{
	if (other == 0 || other == 0)
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point3D result(x / other, y / other, z / other);
}
void Point3D::operator/= (const Point3D &other)
{
	if (other.x == 0 || other.y == 0 || other.z == 0)
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point3D result(x / other.x, y / other.y, z / other.z);
}

//---Equality---
bool Point3D::operator==(const int other) const
{
	return (x == other && y == other && z == other);
}
bool Point3D::operator==(const Point3D &other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

//---Inequality---
bool Point3D::operator!=(const int other) const
{
	return (x != other || y != other || z != other);
}
bool Point3D::operator!=(const Point3D &other) const
{
	return (x != other.x || y != other.y || z != other.z);
}

//---Greater/Less
bool Point3D::operator>(const int other) const
{
	return (x > other && y > other && z > other);
}
bool Point3D::operator>(const Point3D &other) const
{
	return (x > other.x && y > other.y && z > other.z);
}
bool Point3D::operator<(const int other) const
{
	return (x < other && y < other && z < other);
}
bool Point3D::operator<(const Point3D &other) const
{
	//return (x < other.x && y < other.y && z < other.z);
	if (x != other.x) {
		return x < other.x;
	}
	else if (y != other.y) {
		return y < other.y;
	}
	else {
		return z < other.z;
	}
}

//---Self-Greater/Less---
bool Point3D::operator>=(const int other) const
{
	return (x >= other && y >= other && z >= other);
}
bool Point3D::operator>=(const Point3D &other) const
{
	return (x >= other.x && y >= other.y && z >= other.z);
}
bool Point3D::operator<=(const int other) const
{
	return (x <= other && y <= other && z <= other);
}
bool Point3D::operator<=(const Point3D &other) const
{
	return (x <= other.x && y <= other.y && z <= other.z);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// Static Functions

//================================================================
//Static Functions
//These were added after finishing the game
//Inspired by XNA Game Studio's Point3D functions
//----------------------------------------------------------------
Point3D Point3D::Zero()
{
	return Point3D(0, 0, 0);
}
Point3D Point3D::One()
{
	return Point3D(1, 1, 1);
}
Point3D Point3D::NegativeOne()
{
	return Point3D(-1, -1, -1);
}





//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx