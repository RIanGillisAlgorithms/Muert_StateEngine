#include "pch.h"
#include "point3_2.h"



TwoPoint3D::TwoPoint3D(Point3D Cur, Point3D Acur)
{
	cur = Cur;
	acur = Acur;
}

Point3D TwoPoint3D::getTopLeft()
{
	return cur;
}

Point3D TwoPoint3D::getBotLeft()
{
	return Point3D(cur.GetX(), acur.GetY(), acur.GetZ());
}

void TwoPoint3D::setTopLeft(Point3D& Setter)
{
	cur.Set(Setter.GetX(),Setter.GetY(),Setter.GetZ());
}

void TwoPoint3D::setBotLeft(Point3D& Setter)
{
	cur.Set(Setter.GetX(), cur.GetY(), cur.GetZ());
	acur.Set(acur.GetX(), Setter.GetY(), Setter.GetZ());
}

Point3D TwoPoint3D::getBotRight()
{
	return acur;
}

Point3D TwoPoint3D::getTopRight()
{
	return Point3D(acur.GetX(), cur.GetY(), cur.GetZ());
}

void TwoPoint3D::setBotRight(Point3D& Setter)
{
	acur.Set(Setter.GetX(), Setter.GetY(), Setter.GetZ());
}

void TwoPoint3D::setTopRight(Point3D& Setter)
{
	cur.Set(cur.GetX(), Setter.GetY(), Setter.GetZ());
	acur.Set(Setter.GetX(), acur.GetY(), acur.GetZ());
}

bool TwoPoint3D::isPointWithinTopLeftToBotRight(Point3D &Checker)
{
	if (topLeft().GetX() <= Checker.GetX() 
		&& Checker.GetX() <= botRight().GetX()
		&& botRight().GetY() <= Checker.GetY()
		&& Checker.GetY() <= topLeft().GetY()
		&& topLeft().GetZ() <= Checker.GetZ() 
		&& Checker.GetZ() <= botRight().GetZ())
	{
		return true;
	}
	return false;
}

TwoPoint3D TwoPoint3D::getIntersection(TwoPoint3D intersector)
{
	//return TwoPoint3D(Point3D(-1,-1,-1),Point3D(-1,-1,-1));
	//void FindPoints(int x1, int y1, int x2, int y2,
	//	int x3, int y3, int x4, int y4)
	//{
		// gives bottom-left point
		// of intersection rectangle
	Point3D botLeft = this->getBotLeft();
	Point3D intBotLeft = intersector.getBotLeft();
	int x5 = max(botLeft.GetX(), intBotLeft.GetX());
	int y5 = max(botLeft.GetY(), intBotLeft.GetY());
	int z5 = max(botLeft.GetZ(), intBotLeft.GetZ());

	// gives top-right point
	// of intersection rectangle	
	Point3D topRight = this->getTopRight();
	Point3D intTopRight = intersector.getTopRight();

	int x6 = min(topRight.GetX(), intTopRight.GetX());
	int y6 = min(topRight.GetY(), intTopRight.GetY());
	int z6 = min(topRight.GetZ(), intTopRight.GetZ());

	// no intersection
	if (x5 > x6 || y5 > y6 || z5 > z6	 
		//|| intersector.getBotLeft().GetZ() < this->getTopLeft().GetZ()
		//|| intersector.getTopRight().GetZ() > this->getBotRight().GetZ()
		)
	{
		//cout << "No intersection";
		return TwoPoint3D(Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	//cout << "(" << x5 << ", " << y5 << ") ";

	//cout << "(" << x6 << ", " << y6 << ") ";

	// gives top-left point
	// of intersection rectangle
	int x7 = x5;
	int y7 = y6;
	int z7 = z5;

	//cout << "(" << x7 << ", " << y7 << ") ";

	// gives bottom-right point
	// of intersection rectangle
	int x8 = x6;
	int y8 = y5;
	int z8 = z6;

	//cout << "(" << x8 << ", " << y8 << ") ";
	return TwoPoint3D(Point3D(x7, y7, z7), Point3D(x8, y8, z8));
	//}

}

TwoPoint3D_Elevation::TwoPoint3D_Elevation(TwoPoint3D Coord, int Elevation)
{
	coord.cur.Set(Coord.cur.GetX(), Coord.cur.GetY(), Coord.cur.GetZ());
	coord.acur.Set(Coord.acur.GetX(), Coord.acur.GetY(), Coord.acur.GetZ());
	elevation = Elevation;
}
