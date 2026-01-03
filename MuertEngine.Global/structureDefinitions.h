

//by ian.gillis
#pragma once
#ifndef STRUCTURE_DEFINITIONS_H
#define STRUCTURE_DEFINITIONS_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define STRUCTURE_DEFINITIONS_H_API __declspec(dllexport)
#else
#define STRUCTURE_DEFINITIONS_H_API __declspec(dllimport)
#endif


#include <limits.h>
#include "point2.h"
#include "point3.h"


class STRUCTURE_DEFINITIONS_H_API CORD
{
public:
	CORD();
	CORD(int x, int y);
	~CORD();

	int x;
	int y;

};

class STRUCTURE_DEFINITIONS_H_API CORD3D:public CORD
{
public:

	CORD3D();
	CORD3D(int x, int y, int z);
	~CORD3D();

	int z;
};

class STRUCTURE_DEFINITIONS_H_API RECT_CORD
{
public:
	RECT_CORD();
	RECT_CORD(CORD TopLeft, CORD BotRight);
	~RECT_CORD();

private:
	CORD topLeft;
	CORD botRight;

public:
	void set(CORD TopLeft, CORD BotRight);

	int getTopLeftX();
	int getTopLeftY();
	CORD getTopLeft();
	void setTopLeftX(int setter);
	void setTopLeftY(int setter);
	void setTopLeft(CORD setter);

	int getBotRightX();
	int getBotRightY();
	CORD getBotRight();
	void setBotRightX(int setter);
	void setBotRightY(int setter);
	void setBotRight(CORD setter);


	int getTopRightX();
	int getTopRightY();
	CORD getTopRight();

	int getBotLeftX();
	int getBotLeftY();
	CORD getBotLeft();

};


class STRUCTURE_DEFINITIONS_H_API DIMENSION
{
public:
	DIMENSION() { width = 0; height = 0; };
	DIMENSION(int Width, int Height) { setWidth(Width); setHeight(Height); };
	~DIMENSION() {};
	void setX(int Width) { width = Width; }
	void setWidth(int Width) { width = Width; }
	int getX() { return width; }
	int getWidth() { return width; }
	void setY(int Height) { height = Height; }
	void setHeight(int Height) { height = Height; }
	int getY() { return height; }
	int getHeight() { return height; }

	int coordToInt(Point2D Inp) { return (Inp.GetY() * getWidth()) + Inp.GetX(); }
	int coordToInt(int X, int Y) { return (Y * getWidth()) + X; }
	Point2D intToCoord(int Inp) { return Point2D(Inp%getWidth(), Inp/getWidth()); }
protected:
	int width;
	int height;
};

class STRUCTURE_DEFINITIONS_H_API DIMENSION3D:public DIMENSION
{
public:
	DIMENSION3D() { width = 0; height = 0; depth = 0; };
	DIMENSION3D(int Width, int Height, int Depth) {
		setWidth(Width); setHeight(Height); setDepth(Depth);
	};
	~DIMENSION3D() {};
	void setZ(int Depth) { depth = Depth; }
	void setDepth(int Depth) { depth = Depth; }
	int getZ() { return depth; }
	int getDepth() { return depth; }



	int coordToInt(Point3D Inp) { return (Inp.GetZ() * getWidth() * getHeight()) 
		+ (Inp.GetY() * getWidth()) + Inp.GetX(); }
	int coordToInt(int X, int Y, int Z) { return (Z * getWidth() * getHeight())
		+ (Y * getWidth()) + X; }
	Point3D intToCoord(int Inp) { return Point3D(
		Inp%getWidth()
		, (Inp / getWidth()) % getHeight()
		, Inp / (getWidth()*getHeight())
	); 
	
	}



	//i = x + width * y + width * height*z;
	//and reverse:

	//x = i % width;
	//y = (i / width) % height;
	//z = i / (width*height);

protected:
	int depth;
};

class STRUCTURE_DEFINITIONS_H_API CORDDOUBLE
{
public:
	CORDDOUBLE();
	CORDDOUBLE(double x, double y);

	double x;
	double y;
};





class STRUCTURE_DEFINITIONS_H_API GODCOORD
{
public:
	GODCOORD() { gCoord.Set(-1, -1); };
	~GODCOORD() {};
	Point2D gCoord;
};
class STRUCTURE_DEFINITIONS_H_API WORLDCOORD :public GODCOORD
{
public:
	WORLDCOORD() { wCoord.Set(-1, -1); };
	~WORLDCOORD() {};
	Point2D wCoord;
};
class STRUCTURE_DEFINITIONS_H_API AREACOORD :public WORLDCOORD
{
public:
	AREACOORD() { aCoord.Set(-1, -1, -1); };
	~AREACOORD() {};
	Point3D aCoord;
};
class STRUCTURE_DEFINITIONS_H_API REGIONCOORD :public AREACOORD
{
public:
	REGIONCOORD() { rCoord.Set(-1, -1, -1); };
	~REGIONCOORD() {};
	Point3D rCoord;
};
class STRUCTURE_DEFINITIONS_H_API LOCALCOORD :public REGIONCOORD
{
public:
	LOCALCOORD() { lCoord.Set(-1, -1, -1); };
	~LOCALCOORD() {};
	Point3D lCoord;
};




#endif // !STRUCTURE_DEFINITIONS_H

