#include "pch.h"
#include "structureDefinitions.h"

CORD3D::CORD3D()
{
}

CORD3D::CORD3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

CORD3D::~CORD3D()
{
}

CORD::CORD()
{
	this->x = -1;
	this->y = -1;
}

CORD::CORD(int x, int y)
{
	this->x = x;
	this->y = y;  
}

CORD::~CORD()
{

}

CORDDOUBLE::CORDDOUBLE()
{
	x = 0;
	y = 0;
}

CORDDOUBLE::CORDDOUBLE(double X, double Y)
{
	this->x = X;
	this->y = Y;
}

RECT_CORD::RECT_CORD()
{
	set(CORD(-1, -1), CORD(-1, -1));
}

RECT_CORD::RECT_CORD(CORD TopLeft, CORD BotRight)
{
	set(TopLeft, BotRight);
}

RECT_CORD::~RECT_CORD()
{

}

void RECT_CORD::set(CORD TopLeft, CORD BotRight)
{
	topLeft = TopLeft;
	botRight = BotRight;
}

int RECT_CORD::getTopLeftX()
{
	return topLeft.x;
}

int RECT_CORD::getTopLeftY()
{
	return topLeft.y;
}

CORD RECT_CORD::getTopLeft()
{
	return topLeft;
}

void RECT_CORD::setTopLeftX(int setter)
{
	topLeft.x = setter;
}

void RECT_CORD::setTopLeftY(int setter)
{
	topLeft.y = setter;
}

void RECT_CORD::setTopLeft(CORD setter)
{
	topLeft = setter;
}

int RECT_CORD::getBotRightX()
{
	return botRight.x;
}

int RECT_CORD::getBotRightY()
{
	return botRight.y;
}

CORD RECT_CORD::getBotRight()
{
	return botRight;
}

void RECT_CORD::setBotRightX(int setter)
{
	botRight.x = setter;
}

void RECT_CORD::setBotRightY(int setter)
{
	botRight.y = setter;
}

void RECT_CORD::setBotRight(CORD setter)
{
	botRight = setter;
}

int RECT_CORD::getTopRightX()
{
	return botRight.x;
}

int RECT_CORD::getTopRightY()
{
	return topLeft.y;
}

CORD RECT_CORD::getTopRight()
{
	return CORD(getTopRightX(), getTopRightY());
}

int RECT_CORD::getBotLeftX()
{
	return topLeft.x;
}

int RECT_CORD::getBotLeftY()
{
	return botRight.y;
}

CORD RECT_CORD::getBotLeft()
{
	return CORD(getBotLeftX(), getBotLeftY());
}
