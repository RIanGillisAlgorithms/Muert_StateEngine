//by ian.gillis
#pragma once
#ifndef GLPRIMITIVES_H
#define GLPRIMITIVES_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define GLPRIMITIVES_H_API __declspec(dllexport)
#else
#define GLPRIMITIVES_H_API __declspec(dllimport)
#endif


#include "globalIncludes.h"
#include "structureDefinitions.h"


//we need 108 GLdoubles to define the 9 view ports:
//(x,y) * 3 triangles corners * 2 triangles * 9 view ports = 108
//there are 54 2d points
//there are 18 triangles
//there are 9 rectangles
namespace DRAW
{


	//class GLPRIMITIVES_H_API GRECTANGLE_POINTMAP
	//{
	//public:
	//	GRECTANGLE_POINTMAP();
	//	~GRECTANGLE_POINTMAP();

	//	int doubleToPointIndex[108];
	//	int doubleToTriangleIndex[108];
	//	int doubleToRectangleIndex[108];
	//	
	//	int pointToTriangleIndex[16];
	//	int pointToRectangleIndex[16];
	//	int triangleToRectangleIndex[18];

	//};


	class GLPRIMITIVES_H_API GRECTANGLE
	{
	public:
		GRECTANGLE();
		~GRECTANGLE();

		int id;
		

		CORDDOUBLE getTopRight();
		CORDDOUBLE getTopLeft();
		CORDDOUBLE getBotRight();
		CORDDOUBLE getBotLeft();

		void setTopRight(double X, double Y);
		void setTopLeft(double X, double Y);
		void setBotRight(double X, double Y);
		void setBotLeft(double X, double Y);

		void adjustRightSide(double adjustment);
		void adjustLeftSide(double adjustment);
		void adjustUpSide(double adjustment);
		void adjustDownSide(double adjustment);
		void adjustRightUpSide(double xAdjustment, double yAdjustment);
		void adjustRightDownSide(double xAdjustment, double yAdjustment);
		void adjustLeftUpSide(double xAdjustment, double yAdjustment);
		void adjustLeftDownSide(double xAdjustment, double yAdjustment);


		GLdouble* dubs[12];

	};

	class GLPRIMITIVES_H_API GRECTANGLES
	{
	public:
		GRECTANGLES();
		~GRECTANGLES();

		const static int NumRectangles = 9;
		const static int NumTriangles = 18;
		const static int NumPoints = 54;
		const static int NumDoubles = 108;
		const static int NumPointsPerTriangle = 3;
		const static int NumDoublesPerTriangle = 6;
		const static int NumPointsPerRectangle = 6;
		const static int NumDoublesPerRectangle = 12;

		bool gRectVisible[9];
		GRECTANGLE gRect[9];
		//12 * 9
		GLdouble gPoint[108];


		/// <summary>
		/// No error-checking
		/// </summary>
		/// <param name="GRectIndex"></param>
		void ToggleGRectVisible(int GRectIndex);
	};









}


#endif