#include "pch.h"
#include "GLPrimitives.h"

namespace DRAW
{


	GRECTANGLE::GRECTANGLE()
	{

	}

	GRECTANGLE::~GRECTANGLE()
	{

	}

	CORDDOUBLE GRECTANGLE::getTopRight()
	{
		//top right [8,9]
		return CORDDOUBLE(*dubs[8], *dubs[9]);
	}

	CORDDOUBLE GRECTANGLE::getTopLeft()
	{
		//top left [0,1] or [10,11]
		return CORDDOUBLE(*dubs[0], *dubs[1]);
	}

	CORDDOUBLE GRECTANGLE::getBotRight()
	{
		//bot right [4,5] or [6,7]
		return CORDDOUBLE(*dubs[4], *dubs[5]);
	}

	CORDDOUBLE GRECTANGLE::getBotLeft()
	{
		//bot left [2,3]
		return CORDDOUBLE(*dubs[2], *dubs[3]);
	}

	void GRECTANGLE::setTopRight(double X, double Y)
	{
		//top right [8,9]
		*dubs[8] = X;
		*dubs[9] = Y;

		//also update the top left Y to match top right Y
		//and bot right X to match top right X
		*dubs[1] = Y;
		*dubs[11] = Y;
		*dubs[4] = X;
		*dubs[6] = X;
	}

	void GRECTANGLE::setTopLeft(double X, double Y)
	{
		//top left [0,1] or [10,11]
		*dubs[0] = X;
		*dubs[1] = Y;
		*dubs[10] = X;
		*dubs[11] = Y;

		//also update the top right Y to match top left Y
		//and bot left X to match top left X
		*dubs[9] = Y;
		*dubs[2] = X;
	}

	void GRECTANGLE::setBotRight(double X, double Y)
	{
		//bot right [4,5] or [6,7]
		*dubs[4] = X;
		*dubs[5] = Y;
		*dubs[6] = X;
		*dubs[7] = Y;

		//also update the bot left Y to match bot right Y
		//and top right X to match bot right X
		*dubs[3] = Y;
		*dubs[8] = X;		
	}




	void GRECTANGLE::setBotLeft(double X, double Y)
	{
		//bot left [2,3]
		*dubs[2] = X;
		*dubs[3] = Y;

		//also update the top left X to match bot left X
		//and bot right Y to match bot left Y
		*dubs[0] = X;
		*dubs[10] = X;
		*dubs[5] = Y;
		*dubs[7] = Y;
	}

	void GRECTANGLE::adjustRightSide(double adjustment)
	{
		*dubs[4] += adjustment;
		*dubs[6] += adjustment;
		*dubs[8] += adjustment;
	}

	void GRECTANGLE::adjustLeftSide(double adjustment)
	{
		//left and down -=
		*dubs[0] -= adjustment;
		*dubs[2] -= adjustment;
		*dubs[10] -= adjustment;
	}

	void GRECTANGLE::adjustUpSide(double adjustment)
	{
		*dubs[1] += adjustment;
		*dubs[9] += adjustment;
		*dubs[11] += adjustment;
	}

	void GRECTANGLE::adjustDownSide(double adjustment)
	{
		//left and down -=
		*dubs[3] -= adjustment;
		*dubs[5] -= adjustment;
		*dubs[7] -= adjustment;
	}

	void GRECTANGLE::adjustRightUpSide(double xAdjustment, double yAdjustment)
	{
		*dubs[4] += xAdjustment;
		*dubs[6] += xAdjustment;
		*dubs[8] += xAdjustment;

		*dubs[1] += yAdjustment;
		*dubs[9] += yAdjustment;
		*dubs[11] += yAdjustment;
	}

	void GRECTANGLE::adjustRightDownSide(double xAdjustment, double yAdjustment)
	{
		*dubs[4] += xAdjustment;
		*dubs[6] += xAdjustment;
		*dubs[8] += xAdjustment;

		*dubs[3] -= yAdjustment;
		*dubs[5] -= yAdjustment;
		*dubs[7] -= yAdjustment;
	}

	void GRECTANGLE::adjustLeftUpSide(double xAdjustment, double yAdjustment)
	{
		*dubs[0] -= xAdjustment;
		*dubs[2] -= xAdjustment;
		*dubs[10] -= xAdjustment;

		*dubs[1] += yAdjustment;
		*dubs[9] += yAdjustment;
		*dubs[11] += yAdjustment;
	}

	void GRECTANGLE::adjustLeftDownSide(double xAdjustment, double yAdjustment)
	{
		*dubs[0] -= xAdjustment;
		*dubs[2] -= xAdjustment;
		*dubs[10] -= xAdjustment;

		*dubs[3] -= yAdjustment;
		*dubs[5] -= yAdjustment;
		*dubs[7] -= yAdjustment;
	}

	GRECTANGLES::GRECTANGLES()
	{
		for (int rectIdx = 0; rectIdx < NumRectangles; rectIdx++)
		{
			for (int dubIdx = 0; dubIdx < NumDoublesPerRectangle; dubIdx++)
			{
				gRect[rectIdx].dubs[dubIdx] = &gPoint[(rectIdx * NumDoublesPerRectangle) + dubIdx];
			}			
		}


		////, .3, (double)-1
		////, 1, -.3

		//gRect[0].setBotLeft(-1, -.7);
		//gRect[0].setTopRight(.7, 1);
		////gRect[0].setBotLeft(-1, -1);
		////gRect[0].setTopRight(.7, .7);

		////gRect[0].setBotLeft(-1, -1);
		////gRect[0].setTopRight(1, 1);
		////gRect[0].setBotLeft(.3, -1);
		////gRect[0].setTopRight(1, -.3);
		//gRectVisible[0] = true;

		//gRect[1].setBotLeft(-1, -1);
		//gRect[1].setTopRight(.7, -.7);
		////gRect[1].setBotLeft(-1, .7);
		////gRect[1].setTopRight(.7, 1);
		//gRectVisible[1] = true;

		//gRect[2].setBotLeft(.7, -1);
		//gRect[2].setTopRight(1, 1);
		//gRectVisible[2] = true;


		////gRect[3].setBotLeft(-1, -.27);
		////gRect[3].setTopRight(-.3, .27);
		////gRectVisible[3] = true;

		////gRect[4].setBotLeft(-.27, -.27);
		////gRect[4].setTopRight(.27, .27);
		////gRectVisible[4] = true;

		////gRect[5].setBotLeft(.3, -.27);
		////gRect[5].setTopRight(1, .27);
		////gRectVisible[5] = true;


		////gRect[6].setBotLeft(-1, -1);
		////gRect[6].setTopRight(-.3, -.3);
		////gRectVisible[6] = true;

		////gRect[7].setBotLeft(-.27, -1);
		////gRect[7].setTopRight(.27, -.3);
		////gRectVisible[7] = true;

		//////, -1, (double).3
		//////, -.3, 1
		//////gRect[8].setBotLeft(.3, -.3);
		//////gRect[8].setTopRight(.3, -.3);
		////gRect[8].setBotLeft(.3, -1);
		////gRect[8].setTopRight(1, -.3);
		//////gRect[8].setBotLeft(-1, .3);
		//////gRect[8].setTopRight(-.3, 1);
		////gRectVisible[8] = true;
	}

	GRECTANGLES::~GRECTANGLES()
	{

	}

	void GRECTANGLES::ToggleGRectVisible(int GRectIndex)
	{
		gRectVisible[GRectIndex] = !gRectVisible[GRectIndex];
	}

}

