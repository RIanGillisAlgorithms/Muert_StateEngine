#include "pch.h"
#include "tileDisplayObject.h"



namespace DRAW
{




	TILE_DISPLAY_OBJECT_2::TILE_DISPLAY_OBJECT_2()
	{

		clear();
	}

	TILE_DISPLAY_OBJECT_2::TILE_DISPLAY_OBJECT_2(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_2::TILE_DISPLAY_OBJECT_2(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_2::~TILE_DISPLAY_OBJECT_2()
	{

	}

	void TILE_DISPLAY_OBJECT_2::set(int First)
	{
		display[0] = First;
		numLayers = 1;
	}

	void TILE_DISPLAY_OBJECT_2::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_2::clear()
	{
		display[0];
		display[1];
		numLayers = 0;
	}

	int TILE_DISPLAY_OBJECT_2::getNumLayers()
	{
		return numLayers;
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_2::toTDO1()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_1(display[0]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_2::toTDO3()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_3(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_3(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_2::toTDO4()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_4(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_2::toTDO5()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_5(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_2::toTDO6()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_6(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_2::toTDO7()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_7(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_2::toTDO8()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_8(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_2::toTDO9()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_9(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_9(display[0], display[1]);
		}

	}

	int TILE_DISPLAY_OBJECT_2::numDisplayLayers()
	{
		return 2;
	}

	TILE_DISPLAY_OBJECT_3::TILE_DISPLAY_OBJECT_3()
	{
		clear();
	}

	TILE_DISPLAY_OBJECT_3::TILE_DISPLAY_OBJECT_3(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_3::TILE_DISPLAY_OBJECT_3(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_3::TILE_DISPLAY_OBJECT_3(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_3::~TILE_DISPLAY_OBJECT_3()
	{

	}

	void TILE_DISPLAY_OBJECT_3::set(int First)
	{
		display[0] = First;
		display[1];
		display[2];
		numLayers = 1;
	}

	void TILE_DISPLAY_OBJECT_3::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2];
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_3::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_3::clear()
	{
		display[0];
		display[1];
		display[2];
		numLayers = 0;
	}

	int TILE_DISPLAY_OBJECT_3::getNumLayers()
	{
		return numLayers;
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_3::toTDO1()
	{
		switch (this->getNumLayers())
		{
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_1(display[0]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_3::toTDO2()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_2(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_2(display[0], display[1]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_3::toTDO4()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_4(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_3::toTDO5()
	{

		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_5(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_3::toTDO6()
	{

		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_6(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_3::toTDO7()
	{

		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_7(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_3::toTDO8()
	{

		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_8(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_3::toTDO9()
	{

		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_9(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_9(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_9(display[0], display[1], display[2]);
		}
	}

	void TILE_DISPLAY_OBJECT_3::addToTopOfDisplay(int First, bool WillDropLastDisplayIfNeeded)
	{
		if (!WillDropLastDisplayIfNeeded && this->numLayers == 3)
		{
			//cannot do anything!
		}
		else if (this->numLayers == 3)
		{			
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
		}
		else if (this->numLayers == 2)
		{
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 3;
		}
		else if(this->numLayers == 1)
		{
			display[1] = display[0];
			display[0] = First;
			numLayers = 2;
		}
		else if (this->numLayers == 0)
		{
			display[0] = First;
			numLayers = 1;
		}
	}

	TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_3::tempAddToTopOfDisplayAndReturn(int First, bool WillDropLastDisplayIfNeeded /*= false*/)
	{
		auto toReturn = *this;
		toReturn.addToTopOfDisplay(First, WillDropLastDisplayIfNeeded);
		return toReturn;
	}

	void TILE_DISPLAY_OBJECT_3::addToBottomOfDisplay(int Last, bool WillReplaceLastDisplayIfNeeded /*= false*/)
	{
		if (!WillReplaceLastDisplayIfNeeded && this->numLayers == 3)
		{
			//cannot do anything!
		}
		else if (this->numLayers == 3)
		{
			display[2] = Last;
			numLayers = 3;
		}
		else if (this->numLayers == 2)
		{
			display[2] = Last;
			numLayers = 2;
		}
		else if(this->numLayers == 1)
		{
			display[1] = Last;
			numLayers = 2;
		}
		else if (this->numLayers == 0)
		{
			display[0] = Last;
			numLayers = 1;
		}
	}

	TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_3::tempAddToBottomOfDisplayAndReturn(int First, bool WillReplaceLastDisplayIfNeeded /*= false*/)
	{
		auto toReturn = *this;
		toReturn.addToBottomOfDisplay(First, WillReplaceLastDisplayIfNeeded);
		return toReturn;
	}

	int TILE_DISPLAY_OBJECT_3::numDisplayLayers()
	{
		return 3;
	}

	CHAR_CONSOLECOLOR::CHAR_CONSOLECOLOR()
	{
		disp = '#';
		foreColor = DRAW::CONSOLE_COLOR::WHITE;
		backColor = DRAW::CONSOLE_COLOR::BLACK;
	}

	CHAR_CONSOLECOLOR::CHAR_CONSOLECOLOR(char def, DRAW::CONSOLE_COLOR fColor, DRAW::CONSOLE_COLOR bColor)
	{
		disp = def;
		foreColor = fColor;
		backColor = bColor;
	}

	CHAR_CONSOLECOLOR::~CHAR_CONSOLECOLOR()
	{
	}

	TILE_DISPLAY_OBJECT_1::TILE_DISPLAY_OBJECT_1(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_1::TILE_DISPLAY_OBJECT_1()
	{
		clear();
	}

	TILE_DISPLAY_OBJECT_1::~TILE_DISPLAY_OBJECT_1()
	{

	}

	void TILE_DISPLAY_OBJECT_1::set(int First)
	{
		display[0] = First;
		numLayers = 1;
	}

	void TILE_DISPLAY_OBJECT_1::clear()
	{
		display[0];
		numLayers = 0;
	}

	int TILE_DISPLAY_OBJECT_1::getNumLayers()
	{
		return numLayers;
	}

	TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_1::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_1::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_1::toTDO4()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_1::toTDO5()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_1::toTDO6()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_1::toTDO7()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_1::toTDO8()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_1::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_1::numDisplayLayers()
	{
		return 1;
	}

	int TILE_DISPLAY_OBJECT_4::numDisplayLayers()
	{
		return 4;
	}

	int TILE_DISPLAY_OBJECT_4::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_4::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_4::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_4::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_4::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_4::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_4::~TILE_DISPLAY_OBJECT_4()
	{

	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4(TILE_DISPLAY_OBJECT_3 Inp)
	{
		if (Inp.getNumLayers() == 1)
		{
			set(Inp.display[0]);
		}
		else if (Inp.getNumLayers() == 2)
		{
			set(Inp.display[0], Inp.display[1]);
		}
		else
		{
			set(Inp.display[0], Inp.display[1], Inp.display[2]);
		}
	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4(int First, int Second, int Third, int Fourth)
	{

		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_4::TILE_DISPLAY_OBJECT_4()
	{
		clear();
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_4::toTDO1()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_4::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_4::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_4::toTDO5()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_4::toTDO6()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_4::toTDO7()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_4::toTDO8()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_4::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_5::numDisplayLayers()
	{
		return 5;
	}

	int TILE_DISPLAY_OBJECT_5::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_5::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_5::set(int First, int Second, int Third, int Fourth, int Fifth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		numLayers = 5;
	}

	void TILE_DISPLAY_OBJECT_5::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = 32;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_5::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		display[4] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_5::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_5::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_5::~TILE_DISPLAY_OBJECT_5()
	{

	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(TILE_DISPLAY_OBJECT_3 Inp)
	{
		if (Inp.getNumLayers() == 1)
		{
			set(Inp.display[0]);
		}
		else if (Inp.getNumLayers() == 2)
		{
			set(Inp.display[0], Inp.display[1]);
		}
		else
		{
			set(Inp.display[0], Inp.display[1], Inp.display[2]);
		}
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(int First, int Second, int Third, int Fourth, int Fifth)
	{
		set(First, Second, Third, Fourth, Fifth);
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(int First, int Second, int Third, int Fourth)
	{
		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_5::TILE_DISPLAY_OBJECT_5()
	{
		clear();
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_5::toTDO1()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_5::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_5::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_5::toTDO4()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_5::toTDO6()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_5::toTDO7()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_5::toTDO8()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_5::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_6::numDisplayLayers()
	{
		return 6;
	}

	int TILE_DISPLAY_OBJECT_6::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_6::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		numLayers = 6;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First, int Second, int Third, int Fourth, int Fifth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = 32;
		numLayers = 5;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = 32;
		display[5] = 32;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_6::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_6::~TILE_DISPLAY_OBJECT_6()
	{

	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(TILE_DISPLAY_OBJECT_3 Inp)
	{
		if (Inp.getNumLayers() == 1)
		{
			set(Inp.display[0]);
		}
		else if (Inp.getNumLayers() == 2)
		{
			set(Inp.display[0], Inp.display[1]);
		}
		else
		{
			set(Inp.display[0], Inp.display[1], Inp.display[2]);
		}
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth, int Fifth)
	{
		set(First, Second, Third, Fourth, Fifth);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth)
	{
		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_6::TILE_DISPLAY_OBJECT_6()
	{
		clear();
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_6::toTDO1()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_6::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_6::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_6::toTDO4()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_6::toTDO5()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_6::toTDO7()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_6::toTDO8()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_6::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_7::numDisplayLayers()
	{
		return 7;
	}

	int TILE_DISPLAY_OBJECT_7::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_7::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		numLayers = 6;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = 32;
		numLayers = 6;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second, int Third, int Fourth, int Fifth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = 32;
		display[6] = 32;
		numLayers = 5;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_7::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_7::~TILE_DISPLAY_OBJECT_7()
	{

	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(TILE_DISPLAY_OBJECT_3 Inp)
	{
		if (Inp.getNumLayers() == 1)
		{
			set(Inp.display[0]);
		}
		else if (Inp.getNumLayers() == 2)
		{
			set(Inp.display[0], Inp.display[1]);
		}
		else
		{
			set(Inp.display[0], Inp.display[1], Inp.display[2]);
		}
	}
	
	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth)
	{
		set(First, Second, Third, Fourth, Fifth);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth)
	{
		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_7::TILE_DISPLAY_OBJECT_7()
	{
		clear();
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_7::toTDO1()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_7::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_7::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_7::toTDO4()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_7::toTDO5()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_7::toTDO6()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_7::toTDO8()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_7::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_8::numDisplayLayers()
	{
		return 8;
	}

	int TILE_DISPLAY_OBJECT_8::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_8::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		display[7] = Eighth;
		numLayers = 8;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		display[7] = 32;
		numLayers = 7;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = 32;
		display[7] = 32;
		numLayers = 6;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third, int Fourth, int Fifth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 5;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_8::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_8::~TILE_DISPLAY_OBJECT_8()
	{

	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(TILE_DISPLAY_OBJECT_3 Inp)
	{
		if (Inp.getNumLayers() == 1)
		{
			set(Inp.display[0]);
		}
		else if (Inp.getNumLayers() == 2)
		{
			set(Inp.display[0], Inp.display[1]);
		}
		else
		{
			set(Inp.display[0], Inp.display[1], Inp.display[2]);
		}
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth)
	{
		set(First, Second, Third, Fourth, Fifth);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth)
	{
		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_8::TILE_DISPLAY_OBJECT_8()
	{
		clear();
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_8::toTDO1()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_8::toTDO2()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_8::toTDO3()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_8::toTDO4()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_8::toTDO5()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_8::toTDO6()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_8::toTDO7()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	DRAW::TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_8::toTDO9()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int TILE_DISPLAY_OBJECT_9::numDisplayLayers()
	{
		return 9;
	}

	void TILE_DISPLAY_OBJECT_9::combine(TILE_DISPLAY_OBJECT_4 td)
	{
		int curTargetLayer = 0;
		while (numLayers < 8 && curTargetLayer < td.getNumLayers())
		{
			display[numLayers] = td.display[curTargetLayer];
			curTargetLayer++;
			numLayers++;
		}
	}

	void TILE_DISPLAY_OBJECT_9::combine(TILE_DISPLAY_OBJECT_3 td)
	{
		int curTargetLayer = 0;
		while (numLayers < 8 && curTargetLayer < td.getNumLayers())
		{
			display[numLayers] = td.display[curTargetLayer];
			curTargetLayer++;
			numLayers++;
		}
	}

	void TILE_DISPLAY_OBJECT_9::combine(TILE_DISPLAY_OBJECT_2 td)
	{
		int curTargetLayer = 0;
		while (numLayers < 8 && curTargetLayer < td.getNumLayers())
		{
			display[numLayers] = td.display[curTargetLayer];
			curTargetLayer++;
			numLayers++;
		}
	}

	void TILE_DISPLAY_OBJECT_9::combine(TILE_DISPLAY_OBJECT_1 td)
	{
		if (numLayers < 8)
		{
			display[numLayers] = td.display[0];
			numLayers++;
		}
	}

	int TILE_DISPLAY_OBJECT_9::getNumLayers()
	{
		return numLayers;
	}

	void TILE_DISPLAY_OBJECT_9::clear()
	{
		display[0] = 32;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 0;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth, int Ninth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		display[7] = Eighth;
		display[8] = Ninth;
		numLayers = 9;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		display[7] = Eighth;
		display[8] = 32;
		numLayers = 8;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = Seventh;
		display[7] = 32;
		display[8] = 32;
		numLayers = 7;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = Sixth;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 6;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth, int Fifth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = Fifth;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 5;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third, int Fourth)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = Fourth;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 4;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second, int Third)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = Third;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 3;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First, int Second)
	{
		display[0] = First;
		display[1] = Second;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 2;
	}

	void TILE_DISPLAY_OBJECT_9::set(int First)
	{
		display[0] = First;
		display[1] = 32;
		display[2] = 32;
		display[3] = 32;
		display[4] = 32;
		display[5] = 32;
		display[6] = 32;
		display[7] = 32;
		display[8] = 32;
		numLayers = 1;
	}

	TILE_DISPLAY_OBJECT_9::~TILE_DISPLAY_OBJECT_9()
	{

	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_8& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else if (Setter.getNumLayers() == 3)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
		else if (Setter.getNumLayers() == 4)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3]);
		}
		else if (Setter.getNumLayers() == 5)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4]);
		}
		else if (Setter.getNumLayers() == 6)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5]);
		}
		else  if (Setter.getNumLayers() == 7)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5], Setter.display[6]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5], Setter.display[6], Setter.display[7]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_7& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else if (Setter.getNumLayers() == 3)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
		else if (Setter.getNumLayers() == 4)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3]);
		}
		else if (Setter.getNumLayers() == 5)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4]);
		}
		else if (Setter.getNumLayers() == 6)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5], Setter.display[6]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_6& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else if (Setter.getNumLayers() == 3)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
		else if (Setter.getNumLayers() == 4)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3]);
		}
		else if (Setter.getNumLayers() == 5)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4], Setter.display[5]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_5& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else if (Setter.getNumLayers() == 3)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
		else if (Setter.getNumLayers() == 4)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3], Setter.display[4]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_4& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else if (Setter.getNumLayers() == 3)
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2], Setter.display[3]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_3& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else if (Setter.getNumLayers() == 2)
		{
			set(Setter.display[0], Setter.display[1]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1], Setter.display[2]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_2& Setter)
	{
		if (Setter.getNumLayers() == 1)
		{
			set(Setter.display[0]);
		}
		else
		{
			set(Setter.display[0], Setter.display[1]);
		}
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_1& Setter)
	{
		set(Setter.display[0]);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth, int Ninth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Ninth);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth, Seventh);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth, int Fifth, int Sixth)
	{
		set(First, Second, Third, Fourth, Fifth, Sixth);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth, int Fifth)
	{
		set(First, Second, Third, Fourth, Fifth);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth)
	{
		set(First, Second, Third, Fourth);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second, int Third)
	{
		set(First, Second, Third);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First, int Second)
	{
		set(First, Second);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9(int First)
	{
		set(First);
	}

	TILE_DISPLAY_OBJECT_9::TILE_DISPLAY_OBJECT_9()
	{
		clear();
	}

	void TILE_DISPLAY_OBJECT_9::addToTopOfDisplay(TILE_DISPLAY_OBJECT_9 InsertBeforeFirst, bool WillPushOutLastDisplayIfNeeded)
	{
		if (!WillPushOutLastDisplayIfNeeded
			&& (this->numLayers == 9 || (this->numLayers - 9) > InsertBeforeFirst.getNumLayers()))
		{
			//cannot do anything!
			return;
		}
		if (!WillPushOutLastDisplayIfNeeded)
		{
			//we do 8-numLayers to take into account the -1 for the 0-index & because we are doing >= 0
			//Why did I put 8 - this->numLayers? Don't make no sens....
			for (int pix = InsertBeforeFirst.getNumLayers() - 1; pix >= 0; pix--)
			{
				addToTopOfDisplay(InsertBeforeFirst.display[pix]);
			}
			return;
		}
		for (int pix = InsertBeforeFirst.getNumLayers() - 1; pix >= 0; pix--)
		{
			addToTopOfDisplay(InsertBeforeFirst.display[pix]);
		}
		return;
	}

	void TILE_DISPLAY_OBJECT_9::addToTopOfDisplay(int First, bool WillDropLastDisplayIfNeeded)
	{
		if (!WillDropLastDisplayIfNeeded && this->numLayers == 9)
		{
			//cannot do anything!
		}
		else if (this->numLayers == 8)
		{
			//drop 9
			display[8] = display[7];
			display[7] = display[6];
			display[6] = display[5];
			display[5] = display[4];
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
		}
		else if (this->numLayers == 8)
		{
			display[8] = display[7];
			display[7] = display[6];
			display[6] = display[5];
			display[5] = display[4];
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 9;
		}
		else if (this->numLayers == 7)
		{
			display[7] = display[6];
			display[6] = display[5];
			display[5] = display[4];
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 8;
		}
		else if (this->numLayers == 6)
		{
			display[6] = display[5];
			display[5] = display[4];
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 7;
		}
		else if (this->numLayers == 5)
		{
			display[5] = display[4];
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 6;
		}
		else if (this->numLayers == 4)
		{
			display[4] = display[3];
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 5;
		}
		else if (this->numLayers == 3)
		{
			display[3] = display[2];
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 4;
		}
		else if (this->numLayers == 2)
		{
			display[2] = display[1];
			display[1] = display[0];
			display[0] = First;
			numLayers = 3;
		}
		else if (this->numLayers == 1)
		{
			display[1] = display[0];
			display[0] = First;
			numLayers = 2;
		}
		else if (this->numLayers == 0)
		{
			display[0] = First;
			numLayers = 1;
		}
	}

	TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_9::tempAddToTopOfDisplayAndReturn(int First, bool WillDropLastDisplayIfNeeded /*= false*/)
	{
		auto toReturn = *this;
		toReturn.addToTopOfDisplay(First, WillDropLastDisplayIfNeeded);
		return toReturn;
	}

	void TILE_DISPLAY_OBJECT_9::addToBottomOfDisplay(TILE_DISPLAY_OBJECT_9 InsertAfterLast, bool WillPushOutFrontDisplayIfNeeded /*= false*/)
	{
		if (!WillPushOutFrontDisplayIfNeeded 
			&& (this->numLayers == 9 || (this->numLayers - 9) > InsertAfterLast.getNumLayers()))
		{
			//cannot do anything!
			return;
		}
		if (!WillPushOutFrontDisplayIfNeeded)
		{
			for (int pix = 0; pix < this->numLayers - 9; pix++)
			{
				addToBottomOfDisplay(InsertAfterLast.display[pix]);
			}
			return;
		}
		for (int pix = 0; pix < InsertAfterLast.getNumLayers(); pix++)
		{
			addToBottomOfDisplay(InsertAfterLast.display[pix]);
		}
	}

	void TILE_DISPLAY_OBJECT_9::addToBottomOfDisplay(int Last, bool WillReplaceFirstDisplayIfNeeded /*= false*/)
	{
		if (!WillReplaceFirstDisplayIfNeeded && this->numLayers == 9)
		{
			//cannot do anything!
		}
		else if (this->numLayers == 9)
		{
			display[8] = Last;
		}
		else if (this->numLayers == 8)
		{
			display[8] = Last;
			numLayers = 9;
		}
		else if (this->numLayers == 7)
		{
			display[7] = Last;
			numLayers = 8;
		}
		else if (this->numLayers == 6)
		{
			display[6] = Last;
			numLayers = 7;
		}
		else if (this->numLayers == 5)
		{
			display[5] = Last;
			numLayers = 6;
		}
		else if (this->numLayers == 4)
		{
			display[4] = Last;
			numLayers = 5;
		}
		else if (this->numLayers == 3)
		{
			display[3] = Last;
			numLayers = 4;
		}
		else if (this->numLayers == 2)
		{
			display[2] = Last;
			numLayers = 3;
		}
		else if (this->numLayers == 1)
		{
			display[1] = Last;
			numLayers = 2;
		}
		else if (this->numLayers == 0)
		{
			display[0] = Last;
			numLayers = 1;
		}
	}

	TILE_DISPLAY_OBJECT_9 TILE_DISPLAY_OBJECT_9::tempAddToBottomOfDisplayAndReturn(int First, bool WillReplaceLastDisplayIfNeeded /*= false*/)
	{
		auto toReturn = *this;
		toReturn.addToBottomOfDisplay(First, WillReplaceLastDisplayIfNeeded);
		return toReturn;
	}

	DRAW::TILE_DISPLAY_OBJECT_1 TILE_DISPLAY_OBJECT_9::toTDO1()
	{
		switch (this->getNumLayers())
		{
		case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_1(display[0]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_2 TILE_DISPLAY_OBJECT_9::toTDO2()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_2(display[0]);
		case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_2(display[0], display[1]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_3 TILE_DISPLAY_OBJECT_9::toTDO3()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_3(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_3(display[0], display[1]);
		case 3:case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_3(display[0], display[1], display[2]);
		}
	}

	DRAW::TILE_DISPLAY_OBJECT_4 TILE_DISPLAY_OBJECT_9::toTDO4()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_4(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1]);
		case 3:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1], display[2]);
		case 4:case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_4(display[0], display[1], display[2], display[3]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_5 TILE_DISPLAY_OBJECT_9::toTDO5()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_5(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1]);
		case 3:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1], display[2]);
		case 4:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1], display[2], display[3]);
		case 5:case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_5(display[0], display[1], display[2], display[3], display[4]);		
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_6 TILE_DISPLAY_OBJECT_9::toTDO6()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_6(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1]);
		case 3:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1], display[2]);
		case 4:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1], display[2], display[3]);
		case 5:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1], display[2], display[3], display[4]);
		case 6:case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_6(display[0], display[1], display[2], display[3], display[4], display[5]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_7 TILE_DISPLAY_OBJECT_9::toTDO7()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_7(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1]);
		case 3:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2]);
		case 4:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2], display[3]);
		case 5:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2], display[3], display[4]);
		case 6:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2], display[3], display[4], display[5]);
		case 7:case 8:case 9:
			return TILE_DISPLAY_OBJECT_7(display[0], display[1], display[2], display[3], display[4], display[5], display[6]);
		}

	}

	DRAW::TILE_DISPLAY_OBJECT_8 TILE_DISPLAY_OBJECT_9::toTDO8()
	{
		switch (this->getNumLayers())
		{
		case 1:
			return TILE_DISPLAY_OBJECT_8(display[0]);
		case 2:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1]);
		case 3:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2]);
		case 4:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2], display[3]);
		case 5:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2], display[3], display[4]);
		case 6:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2], display[3], display[4], display[5]);
		case 7:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2], display[3], display[4], display[5], display[6]);
		case 8: case 9:
			return TILE_DISPLAY_OBJECT_8(display[0], display[1], display[2], display[3], display[4], display[5], display[6], display[7]);
		}
	}

}