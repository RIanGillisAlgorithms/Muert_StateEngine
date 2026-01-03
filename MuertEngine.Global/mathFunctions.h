//by ian.gillis
#pragma once
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define MATH_FUNCTIONS_H_API __declspec(dllexport)
#else
#define MATH_FUNCTIONS_H_API __declspec(dllimport)
#endif


#include <algorithm>
namespace mFunc
{
	extern "C" MATH_FUNCTIONS_H_API double cosIntrp(double a, double b, double x);
	extern "C" MATH_FUNCTIONS_H_API int absInt(int inp);
	extern "C" MATH_FUNCTIONS_H_API double linearDist(double x1, double y1, double x2, double y2);
	extern "C" MATH_FUNCTIONS_H_API int reverseNumberRange(int num, int min, int max);

	////from map_fixation_11a_worldMap

	//bool WORLD_MAP_BASE::interpolateValue(int startValue, int valueE, int valueS, int valueSE, int WMAPTILE::* pxi, int AREA_MAP_BASE::* pxj)
	//{
	//	// old grid
	//	//
	//	const int nx1 = 2;
	//	const int ny1 = 2;

	//	int g1[nx1][ny1];

	//	g1[0][0] = startValue;
	//	g1[1][0] = valueS;
	//	g1[0][1] = valueE;
	//	g1[1][1] = valueSE;
	//	//
	//	// give values to g1
	//	//

	//	//
	//	// new grid
	//	//
	//	const int nx2 = WMAP_X;
	//	const int ny2 = WMAP_Y;
	//	//int g2[200][200];
	//	//
	//	//
	//	// do the bi-linear interpolation
	//	//
	//	double xratio = (double)(nx1 - 1) / double(nx2 - 1);
	//	double yratio = (double)(ny1 - 1) / double(ny2 - 1);
	//	//
	//	for (int i = 0; i < nx2; i++)
	//	{
	//		double x = (double)i * xratio;
	//		int i1 = (int)x;
	//		double t = x - (double)i1;
	//		if (i1 == nx1 - 1)
	//		{
	//			i1 = nx1 - 2;
	//			t = 1.0;
	//		}
	//		for (int j = 0; j < ny2; j++)
	//		{
	//			double y = (double)j * yratio;
	//			int j1 = (int)y;
	//			double u = y - (double)j1;
	//			if (j1 == ny1 - 1)
	//			{
	//				j1 = ny1 - 2;
	//				u = 1.0;
	//			}
	//			//
	//			// this is the bi-linear interpolation line ...
	//			//
	//			double g_interp = (1 - t)*(1 - u)*(double)g1[i1][j1] +
	//				t*(1 - u)*(double)g1[i1 + 1][j1] +
	//				(1 - t)*u*(double)g1[i1][j1 + 1] +
	//				t*u*(double)g1[i1 + 1][j1 + 1];

	//			wMap[i][j].*pxi = (int)g_interp;
	//			wMap[i][j].area.*pxj = (int)g_interp;
	//			//g2[ i ][ j ] = (int)g_interp;
	//		}
	//	}
	//	return true;
	//}
	//bool WORLD_MAP_BASE::interpolateGodType(int startType, int typeE, int typeS, int typeSE)
	//{
	//	// old grid
	//	//
	//	const int nx1 = 2;
	//	const int ny1 = 2;

	//	int g1[nx1][ny1];

	//	g1[0][0] = startType;
	//	g1[1][0] = typeS;
	//	g1[0][1] = typeE;
	//	g1[1][1] = typeSE;

	//	int g2[200][200];
	//	int g3[200][200];
	//	int g4[200][200];
	//	int g5[200][200];

	//	bool doE = false;
	//	bool doS = false;
	//	bool doSE = false;

	//	g1[0][0] = 100;
	//	if (startType == typeS)
	//	{
	//		g1[1][0] = 100;
	//	}
	//	else
	//	{
	//		g1[1][0] = 0;
	//		doS = true;
	//	}
	//	if (startType == typeE)
	//	{
	//		g1[0][1] = 100;
	//	}
	//	else
	//	{
	//		g1[0][1] = 0;
	//		doE = true;
	//	}
	//	if (startType == typeSE)
	//	{
	//		g1[1][1] = 100;
	//	}
	//	else
	//	{
	//		g1[1][1] = 0;
	//		doSE = true;
	//	}

	//	//
	//	// give values to g1
	//	//

	//	//
	//	// new grid
	//	//
	//	const int nx2 = WMAP_X;
	//	const int ny2 = WMAP_Y;
	//	//int g2[200][200];
	//	//
	//	//
	//	// do the bi-linear interpolation
	//	//
	//	double xratio = (double)(nx1 - 1) / double(nx2 - 1);
	//	double yratio = (double)(ny1 - 1) / double(ny2 - 1);
	//	for (int piX = 0; piX < WMAP_X; piX++)
	//	{
	//		for (int piY = 0; piY < WMAP_Y; piY++)
	//		{
	//			g2[piX][piY] = mtrandW.rand(51);
	//			g2[piX][piY] -= 25;

	//			g5[piX][piY] = mtrandW.rand(51);
	//			g5[piX][piY] -= 25;

	//			g4[piX][piY] = mtrandW.rand(51);
	//			g4[piX][piY] -= 25;

	//			g3[piX][piY] = mtrandW.rand(51);
	//			g3[piX][piY] -= 25;

	//			//g2[piX][piY] = 0;
	//			//g3[piX][piY] = 0;
	//			//g4[piX][piY] = 0;
	//			//g5[piX][piY] = 0;

	//		}

	//	}
	//	//

	//	for (int i = 0; i < nx2; i++)
	//	{
	//		double x = (double)i * xratio;
	//		int i1 = (int)x;
	//		double t = x - (double)i1;
	//		if (i1 == nx1 - 1)
	//		{
	//			i1 = nx1 - 2;
	//			t = 1.0;
	//		}
	//		for (int j = 0; j < ny2; j++)
	//		{
	//			double y = (double)j * yratio;
	//			int j1 = (int)y;
	//			double u = y - (double)j1;
	//			if (j1 == ny1 - 1)
	//			{
	//				j1 = ny1 - 2;
	//				u = 1.0;
	//			}
	//			//
	//			// this is the bi-linear interpolation line ...
	//			//
	//			double g_interp = (1 - t)*(1 - u)*(double)g1[i1][j1] +
	//				t*(1 - u)*(double)g1[i1 + 1][j1] +
	//				(1 - t)*u*(double)g1[i1][j1 + 1] +
	//				t*u*(double)g1[i1 + 1][j1 + 1];

	//			g2[i][j] += (int)g_interp;
	//			//g2[ i ][ j ] = (int)g_interp;
	//		}
	//	}

	//	if (doS)
	//	{
	//		g1[0][0] = 0;
	//		g1[1][0] = 100;

	//		if (typeS == typeE)
	//		{
	//			g1[0][1] = 100;
	//			doE = false;
	//		}
	//		else
	//		{
	//			g1[0][1] = 0;
	//		}
	//		if (typeS == typeSE)
	//		{
	//			g1[1][1] = 100;
	//			doSE = false;
	//		}
	//		else
	//		{
	//			g1[1][1] = 0;
	//		}

	//		for (int i = 0; i < nx2; i++)
	//		{
	//			double x = (double)i * xratio;
	//			int i1 = (int)x;
	//			double t = x - (double)i1;
	//			if (i1 == nx1 - 1)
	//			{
	//				i1 = nx1 - 2;
	//				t = 1.0;
	//			}
	//			for (int j = 0; j < ny2; j++)
	//			{
	//				double y = (double)j * yratio;
	//				int j1 = (int)y;
	//				double u = y - (double)j1;
	//				if (j1 == ny1 - 1)
	//				{
	//					j1 = ny1 - 2;
	//					u = 1.0;
	//				}
	//				//
	//				// this is the bi-linear interpolation line ...
	//				//
	//				double g_interp = (1 - t)*(1 - u)*(double)g1[i1][j1] +
	//					t*(1 - u)*(double)g1[i1 + 1][j1] +
	//					(1 - t)*u*(double)g1[i1][j1 + 1] +
	//					t*u*(double)g1[i1 + 1][j1 + 1];

	//				g3[i][j] += (int)g_interp;
	//				//g2[ i ][ j ] = (int)g_interp;
	//			}
	//		}
	//	}
	//	if (doE)
	//	{
	//		g1[0][0] = 0;
	//		g1[0][1] = 100;

	//		//if(typeE == typeS)
	//		//{
	//		//	g1[1][0] = 100;			
	//		//}
	//		//else
	//		//{
	//		g1[1][0] = 0;
	//		//}
	//		if (typeE == typeSE)
	//		{
	//			g1[1][1] = 100;
	//			doSE = false;
	//		}
	//		else
	//		{
	//			g1[1][1] = 0;
	//		}

	//		for (int i = 0; i < nx2; i++)
	//		{
	//			double x = (double)i * xratio;
	//			int i1 = (int)x;
	//			double t = x - (double)i1;
	//			if (i1 == nx1 - 1)
	//			{
	//				i1 = nx1 - 2;
	//				t = 1.0;
	//			}
	//			for (int j = 0; j < ny2; j++)
	//			{
	//				double y = (double)j * yratio;
	//				int j1 = (int)y;
	//				double u = y - (double)j1;
	//				if (j1 == ny1 - 1)
	//				{
	//					j1 = ny1 - 2;
	//					u = 1.0;
	//				}
	//				//
	//				// this is the bi-linear interpolation line ...
	//				//
	//				double g_interp = (1 - t)*(1 - u)*(double)g1[i1][j1] +
	//					t*(1 - u)*(double)g1[i1 + 1][j1] +
	//					(1 - t)*u*(double)g1[i1][j1 + 1] +
	//					t*u*(double)g1[i1 + 1][j1 + 1];

	//				g4[i][j] += (int)g_interp;
	//				//g2[ i ][ j ] = (int)g_interp;
	//			}
	//		}
	//	}
	//	if (doSE)
	//	{
	//		g1[0][0] = 0;
	//		g1[1][1] = 100;

	//		//g1[1][0] = 100;

	//		//if(typeSE == typeS)
	//		//{
	//		//	g1[1][0] = 100;
	//		//	doS = false;
	//		//}
	//		//else
	//		//{
	//		g1[1][0] = 0;
	//		//}
	//		//if(typeSE == typeE)
	//		//{
	//		//	g1[0][1] = 100;
	//		//	doE = false;
	//		//}
	//		//else
	//		//{
	//		g1[0][1] = 0;
	//		//}

	//		for (int i = 0; i < nx2; i++)
	//		{
	//			double x = (double)i * xratio;
	//			int i1 = (int)x;
	//			double t = x - (double)i1;
	//			if (i1 == nx1 - 1)
	//			{
	//				i1 = nx1 - 2;
	//				t = 1.0;
	//			}
	//			for (int j = 0; j < ny2; j++)
	//			{
	//				double y = (double)j * yratio;
	//				int j1 = (int)y;
	//				double u = y - (double)j1;
	//				if (j1 == ny1 - 1)
	//				{
	//					j1 = ny1 - 2;
	//					u = 1.0;
	//				}
	//				//
	//				// this is the bi-linear interpolation line ...
	//				//
	//				double g_interp = (1 - t)*(1 - u)*(double)g1[i1][j1] +
	//					t*(1 - u)*(double)g1[i1 + 1][j1] +
	//					(1 - t)*u*(double)g1[i1][j1 + 1] +
	//					t*u*(double)g1[i1 + 1][j1 + 1];

	//				g5[i][j] += (int)g_interp;
	//				//g2[ i ][ j ] = (int)g_interp;
	//			}
	//		}
	//	}

	//	//ok - now we determine what goes where!!
	//	int tipp;
	//	for (int piX = 0; piX < WMAP_X; piX++)
	//	{
	//		for (int piY = 0; piY < WMAP_Y; piY++)
	//		{

	//			this->wMap[piX][piY].setGodType(startType);
	//			if (doS && g3[piX][piY] > g2[piX][piY] && ((doE && g3[piX][piY] > g4[piX][piY]) || (!doE)) && ((doSE && g3[piX][piY] > g5[piX][piY]) || (!doSE)))
	//			{
	//				//setMess("setting type S....");
	//				this->wMap[piX][piY].setGodType(typeS);
	//			}
	//			else if (doE && g4[piX][piY] > g2[piX][piY] && ((doS && g4[piX][piY] > g3[piX][piY]) || (!doS)) && ((doSE && g4[piX][piY] > g5[piX][piY]) || (!doSE)))
	//			{
	//				//setMess("setting type E....");
	//				this->wMap[piX][piY].setGodType(typeE);
	//			}
	//			//else if(doSE && g5[piX][piY] > g2[piX][piY] && ( (doS && g5[piX][piY] > g3[piX][piY]) || (!doS) ) && ( (doE && g5[piX][piY] > g4[piX][piY]) || (!doE) ))
	//			//{
	//			//	setMess("setting type SE....");
	//			//	this->wMap[piX][piY].setGodType(typeSE);
	//			//}
	//		}
	//	}

	//	return true;
	//}

}

#endif