//by ian.gillis
#pragma once
#ifndef NON_LEAKY_RECTANGULAR_STRING_RAW_H
#define NON_LEAKY_RECTANGULAR_STRING_RAW_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define NON_LEAKY_RECTANGULAR_STRING_RAW_H_API __declspec(dllexport)
#else
#define NON_LEAKY_RECTANGULAR_STRING_RAW_H_API __declspec(dllimport)
#endif	 


#include "nonLeakyRectangularString.h"


namespace COMM
{


	/// <summary>
	/// Holds a raw string and a rectString
	/// </summary>
	class NON_LEAKY_RECTANGULAR_STRING_RAW_H_API RECT_STRING_RAW
	{
	public:
		RECT_STRING_RAW();
		RECT_STRING_RAW(std::string NewString, bool WordifyText = false);
		~RECT_STRING_RAW();

		bool isWordified;
		std::string rawString;
		RECT_STRING rectString;


		void setRawString(std::string newString);
		std::string getRawString();
		RECT_STRING* getRectString();
	};

}

#endif
