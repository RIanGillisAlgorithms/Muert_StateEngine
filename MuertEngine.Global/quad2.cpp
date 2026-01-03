#include "pch.h"
#include "quad2.h"

Quad2D::Quad2D()
{
	this->p1 = nullptr;
	this->p2 = nullptr;
	this->p3 = nullptr;
	this->p4 = nullptr;

	this->l1 = nullptr;
	this->l2 = nullptr;
	this->l3 = nullptr;
	this->l4 = nullptr;
}

Quad2D::Quad2D(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
}

Quad2D::Quad2D(Line2D* l1, Line2D* l2, Line2D* l3, Line2D* l4)
{
	this->l1 = l1;
	this->l2 = l2;
	this->l3 = l3;
	this->l4 = l4;
	updatePointsFromLines();
}

Quad2D::~Quad2D()
{

}

void Quad2D::updatePointsFromLines()
{
	this->p1 = l1->p1;
	this->p2 = l2->p1;
	this->p3 = l3->p1;
	this->p4 = l4->p1;
}
