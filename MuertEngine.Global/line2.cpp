#include "pch.h"
#include "line2.h"

Line2D::Line2D()
{
	this->p1 = nullptr;
	this->p2 = nullptr;
}	

Line2D::Line2D(Point2D* p1, Point2D* p2)
{
	setLine(p1,p2);
}

void Line2D::setLine(Point2D* p1, Point2D* p2)
{
	this->p1 = p1;
	this->p2 = p2;
	recalcVecs();	
}

void Line2D::recalcVecs()
{
	this->vec1 = (*p2) - (*p1);
	this->vec2 = (*p1) - (*p2);
}

int Line2D::interceptPointY(unsigned char interceptValToCheck, bool interceptsY /*= true*/)
{
	if (interceptsY)
	{
		//dx = line->x2 - line->x1;
		//dy = line->y2 - line->y1;

		//deltay = yintercept - line->y2;
		//if (dy != 0) {
		//	//dy very close to 0 will be numerically unstable, account for that
		//	intercept = line->x2 + (dx / dy) * deltay;
		//}
		//else {
		//	//line is parrallel to x-axis, will never reach yintercept
		//	intercept = NaN;
		//}
		int dx = this->p2->GetX() - this->p1->GetX();
		int dy = this->p2->GetY() - this->p1->GetY();

		double deltay = interceptValToCheck - this->p2->GetY();
		if (dy != 0) {
			//dy very close to 0 will be numerically unstable, account for that
			return this->p2->GetX() + ((double)dx / (double)dy) * deltay;
		}
		else {
			//line is parrallel to x-axis, will never reach yintercept
			//throw new
			//intercept = NaN;
			//throw an exception here instead.
			return 0;
		}
	}
	else
	{
		int dx = this->p2->GetX() - this->p1->GetX();
		int dy = this->p2->GetY() - this->p1->GetY();

		double deltax = interceptValToCheck - this->p2->GetX();
		if (dx != 0) {
			//dy very close to 0 will be numerically unstable, account for that
			return this->p2->GetY() + ((double)dy / (double)dx) * deltax;
		}
		else {
			//line is parrallel to x-axis, will never reach yintercept
			//throw new
			//intercept = NaN;
			//throw an exception here instead.
			return 0;
		}
	}
}

Line2D::~Line2D()
{

}

Point2D_Line2D::Point2D_Line2D()
{

}

Point2D_Line2D::Point2D_Line2D(Point2D p1, Point2D p2)
{
	setLine(p1, p2);
}

Point2D_Line2D::~Point2D_Line2D()
{

}

void Point2D_Line2D::setLine(Point2D p1, Point2D p2)
{
	this->p1 = p1;
	this->p2 = p2;
	recalcVecs();
}

void Point2D_Line2D::recalcVecs()
{
	this->vec1 = (p2) - (p1);
	this->vec2 = (p1) - (p2);

}

int Point2D_Line2D::interceptPointY(unsigned char interceptValToCheck, bool interceptsY /*= true*/)
{
	if (interceptsY)
	{
		//dx = line->x2 - line->x1;
		//dy = line->y2 - line->y1;

		//deltay = yintercept - line->y2;
		//if (dy != 0) {
		//	//dy very close to 0 will be numerically unstable, account for that
		//	intercept = line->x2 + (dx / dy) * deltay;
		//}
		//else {
		//	//line is parrallel to x-axis, will never reach yintercept
		//	intercept = NaN;
		//}
		int dx = this->p2.GetX() - this->p1.GetX();
		int dy = this->p2.GetY() - this->p1.GetY();

		double deltay = interceptValToCheck - this->p2.GetY();
		if (dy != 0) {
			//dy very close to 0 will be numerically unstable, account for that
			return this->p2.GetX() + ((double)dx / (double)dy) * deltay;
		}
		else {
			//line is parrallel to x-axis, will never reach yintercept
			//throw new
			//intercept = NaN;
			//throw an exception here instead.
			return 0;
		}
	}
	else
	{
		int dx = this->p2.GetX() - this->p1.GetX();
		int dy = this->p2.GetY() - this->p1.GetY();

		double deltax = interceptValToCheck - this->p2.GetX();
		if (dx != 0) {
			//dy very close to 0 will be numerically unstable, account for that
			return this->p2.GetY() + ((double)dy / (double)dx) * deltax;
		}
		else {
			//line is parrallel to x-axis, will never reach yintercept
			//throw new
			//intercept = NaN;
			//throw an exception here instead.
			return 0;
		}
	}
}
