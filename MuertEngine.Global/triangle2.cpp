#include "pch.h"
#include "triangle2.h"

Triangle2D::Triangle2D()
{
	this->l1 = nullptr;
	this->l2 = nullptr;
	this->l3 = nullptr;
	this->p1 = nullptr;
	this->p2 = nullptr;
	this->p3 = nullptr;	
}

Triangle2D::Triangle2D(Point2D* p1, Point2D* p2, Point2D* p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;	
}

Triangle2D::Triangle2D(Line2D* l1, Line2D* l2, Line2D* l3)
{
	this->l1 = l1;
	this->l2 = l2;
	this->l3 = l3;
	updatePointsFromLines();
}

Triangle2D::~Triangle2D()
{

}

void Triangle2D::updatePointsFromLines()
{
	this->p1 = l1->p1;
	this->p2 = l2->p1;
	this->p3 = l3->p1;
}

Point2D Triangle2D::SelectRandomPointWithinMe()
{
	//char edgePoints[2];
	//edgePoints[0] = (char)RND::rnd.intRand(0, 179);
	//edgePoints[1] = (char)RND::rnd.intRand(0, 179);
	//if (edgePoints[0] + edgePoints[1] > 179)
	//{
	//	edgePoints[0] = 179 - edgePoints[0];
	//	edgePoints[1] = 179 - edgePoints[1];
	//}
	//char partnerEdgePoint = 179 - edgePoints[0] - edgePoints[1];
	////ignore point at 0,0 - it will always be 0
	//return Point2D((edgePoints[0]) + partnerEdgePoint, (edgePoints[1]) + partnerEdgePoint);
	////this->pointX = (edgePoints[0]) + partnerEdgePoint;
	////this->pointY = (edgePoints[1]) + partnerEdgePoint;
	return Point2D(0, 0);
}
Point2D Triangle2D::GetPointInTriangle(Point2D a, Point2D b, Point2D c)
{
	return Point2D(0, 0);
}

bool Triangle2D::isPoint(Point2D pToTest)
{
	return (((p2->GetY() - p1->GetY()) * (pToTest.x - p1->GetX())
		- (p2->GetX() - p1->GetX()) * (pToTest.y - p1->GetY()))
		| ((p3->GetY() - p2->GetY()) * (pToTest.x - p2->GetX())
			- (p3->GetX() - p2->GetX()) * (pToTest.y - p2->GetY()))
		| ((p1->GetY() - p3->GetY()) * (pToTest.x - p3->GetX())
			- (p1->GetX() - p3->GetX()) * (pToTest.y - p3->GetY()))) >= 0;
}
