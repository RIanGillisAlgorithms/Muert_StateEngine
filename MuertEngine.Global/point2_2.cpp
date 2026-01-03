#include "pch.h"
#include "point2_2.h"



TwoPoint2D::TwoPoint2D(Point2D Cur, Point2D Acur)
{
	cur = Cur;
	acur = Acur;
}

TwoPoint2D_Elevation::TwoPoint2D_Elevation(TwoPoint2D Coord, int Elevation)
{
	coord = Coord;
	elevation = Elevation;
}
