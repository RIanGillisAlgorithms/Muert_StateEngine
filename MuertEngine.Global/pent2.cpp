#include "pch.h"
#include "pent2.h"

Pent2D::Pent2D()
{
	this->p1 = nullptr;
	this->p2 = nullptr;
	this->p3 = nullptr;
	this->p4 = nullptr;
	this->p5 = nullptr;

	this->l1 = nullptr;
	this->l2 = nullptr;
	this->l3 = nullptr;
	this->l4 = nullptr;
	this->l5 = nullptr;
}

Pent2D::Pent2D(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->p5 = p5;
}

Pent2D::Pent2D(Line2D* l1, Line2D* l2, Line2D* l3, Line2D* l4, Line2D* l5)
{
	this->l1 = l1;
	this->l2 = l2;
	this->l3 = l3;
	this->l4 = l4;
	this->l5 = l5;
	updatePointsFromLines();
}

Pent2D::~Pent2D()
{

}

void Pent2D::updatePointsFromLines()
{
	this->p1 = l1->p1;
	this->p2 = l2->p1;
	this->p3 = l3->p1;
	this->p4 = l4->p1;
	this->p5 = l5->p1;
}
