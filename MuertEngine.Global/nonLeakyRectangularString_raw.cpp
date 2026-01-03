#include "pch.h"
#include "nonLeakyRectangularString_raw.h"
#include "stringManipulation.h"


namespace COMM
{

	RECT_STRING_RAW::RECT_STRING_RAW()
	{

	}

	RECT_STRING_RAW::RECT_STRING_RAW(std::string NewString, bool WordifyText /*= false*/)
	{
		setRawString(NewString);
	}

	RECT_STRING_RAW::~RECT_STRING_RAW()
	{

	}

	void RECT_STRING_RAW::setRawString(std::string newString)
	{
		this->rawString = newString;
		this->isWordified = false;		
	}

	std::string RECT_STRING_RAW::getRawString()
	{
		return this->rawString;
	}

	COMM::RECT_STRING* RECT_STRING_RAW::getRectString()
	{
		if (!isWordified)
		{
			rectString.Words.clear();
			s::WordifyText(this->rawString, rectString);
			isWordified = true;
		}
		return &rectString;
	}
}

