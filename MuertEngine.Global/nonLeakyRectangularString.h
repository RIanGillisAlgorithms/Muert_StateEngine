

//by ian.gillis
#pragma once
#ifndef NON_LEAKY_RECTANGULAR_STRING_H
#define NON_LEAKY_RECTANGULAR_STRING_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define NON_LEAKY_RECTANGULAR_STRING_H_API __declspec(dllexport)
#else
#define NON_LEAKY_RECTANGULAR_STRING_H_API __declspec(dllimport)
#endif	 


#include <string>
//#include <vector>
#include <vector>
#include "rectangularStrings.h"
#include <map>
#include "structureDefinitions.h"


namespace COMM
{
	class NON_LEAKY_RECTANGULAR_STRING_H_API RECT_STRING;
	class NON_LEAKY_RECTANGULAR_STRING_H_API COMPILED_STRINGS;
	//if a window is resized (numTiles.x change):
	//	* the first row will be the first row of the top-most string 
	//		that is visible, even if is only partially visible

	//The RECT_STRINGs represent one "message"
	//
	class NON_LEAKY_RECTANGULAR_STRING_H_API RECT_STRING_HOLDER
	{
	public:
		RECT_STRING_HOLDER();
		~RECT_STRING_HOLDER();

		std::vector<RECT_STRING> RectStrings;
	};

	class NON_LEAKY_RECTANGULAR_STRING_H_API RECT_STRING_BUTTON_HOLDER
	{
	public:
		RECT_STRING_BUTTON_HOLDER() {}
		~RECT_STRING_BUTTON_HOLDER() {}

		
		std::vector<RECT_STRING> RectStrings;
	};



	class NON_LEAKY_RECTANGULAR_STRING_H_API RECT_STRING
	{
	public:
		RECT_STRING();
		~RECT_STRING();

		//All of the singular words/ pieces that make up the rectangular string
		std::vector<SINGULAR_WORD> Words;
		//
		std::map<int, COMPILED_STRINGS> CompiledStrings;
		//The most rows the the COMPILED_STRINGS has ever occupied, by width, for this RECT_STRING
		std::map<int, int> HighestRowsByWidth;

		virtual int getNumberOfRows(int surfaceTileWidth);
		virtual int getHighestNumberOfRows(int surfaceTileWidth);
		virtual std::string* getRow(int surfaceTileWidth, int rowIdx);
	};	 


	class NON_LEAKY_RECTANGULAR_STRING_H_API RECT_STRING_BUTTON
	{
	public:
		RECT_STRING_BUTTON();
		~RECT_STRING_BUTTON();

		RECT_STRING RectString;
	};


	class NON_LEAKY_RECTANGULAR_STRING_H_API COMPILED_STRINGS
	{
	public:
		COMPILED_STRINGS();
		~COMPILED_STRINGS();

		bool Set;
		int SurfaceTileWidth;
		std::vector<std::string> Row;

		int init(int surfaceTileWidth, std::vector<SINGULAR_WORD>* words
			, int paddingBegin = 0, int paddingEnd = 0);			
	};
}







#endif