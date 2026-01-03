#include "pch.h"
#include "mathFunctions.h"

namespace mFunc
{
	double cosIntrp(double a, double b, double x)
	{
		// function Cosine_Interpolate(a, b, x)
		//ft = x * 3.1415927
		//f = (1 - cos(ft)) * .5

		//return  a*(1-f) + b*f
		// end of function

		double ft = x * 3.1415927;
		double f = (1 - cos(ft)) * .5;

		return(a* (1 - f) + (b * f));
	}

	int absInt(int inp)
	{
		if (inp < 0)
		{
			return -inp;
		}
		return inp;
	}

	double linearDist(double x1, double y1, double x2, double y2) // Return a double, not an int
	{
		double dx = x2 - x1;
		double dy = y2 - y1;

		dx = dx * dx + dy * dy;
		if (dx != 0)
		{
			return sqrt(dx);
		}
		else
		{
			return 0;
		}
	}

	int reverseNumberRange(int num, int min, int max)
	{		   
		if (max < min)
		{
			throw("max < min");
		}
		return (max + min) - num;
	}


}