

//by ian.gillis
#pragma once
#ifndef RECTANGULAR_STRINGS_H
#define RECTANGULAR_STRINGS_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define RECTANGULAR_STRINGS_H_API __declspec(dllexport)
#else
#define RECTANGULAR_STRINGS_H_API __declspec(dllimport)
#endif


#include <string>
//#include <vector>
#include <vector>
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"


namespace COMM
{



	class RECTANGULAR_STRINGS_H_API SINGULAR_WORD
	{
	public:

		SINGULAR_WORD();
		SINGULAR_WORD(std::string text, WORD_TYPE wordType);
		~SINGULAR_WORD();


		std::string Text;
		WORD_TYPE WordType;

	};

	class RECTANGULAR_STRINGS_H_API SINGULAR_STRING
	{
	public:
		SINGULAR_STRING();
		~SINGULAR_STRING();

		std::string Text;
		std::vector<SINGULAR_WORD*> SingularWords;

		std::vector<std::string> RectangularWords;
		std::string ParsedRectangularWords;

		void insertNewSingularString(std::string toIns, WORD_TYPE wordType);
		void parseText();

		void parseRectangularText(int curWidth, int curHeight, std::vector<std::string>& rectangularLines);

	};




	//All SINGULAR_STRINGs that are controlled by the SINGULAR_STRING_QUEUE are contained within
	//a SINGULAR_STRING_WRAPPER - this is to facilitate the unloading/ loading of them etc.
	class RECTANGULAR_STRINGS_H_API SINGULAR_STRING_WRAPPER
	{
	public:
		SINGULAR_STRING_WRAPPER();
		~SINGULAR_STRING_WRAPPER();


		int WrapperId;
		bool IsLoaded;
		//bool IsParsed;

		//int ParsedAtTileDimensionsX;
		//int ParsedAtTileDimensionsY;
		SINGULAR_STRING* SingularString;

	};
	//All SINGULAR_STRINGs are controlled by this queue
	class RECTANGULAR_STRINGS_H_API SINGULAR_STRING_QUEUE
	{
	public:
		SINGULAR_STRING_QUEUE();
		~SINGULAR_STRING_QUEUE();

		std::vector<SINGULAR_STRING_WRAPPER*> SingularStrings;
		//the top-most SINGULAR_STRING to be displayed
		int CurrentIndex;
		//the top-most SINGULAR_STRING's first SINGULAR_WORD to be displayed
		//	When resizing the GL_SURFACE, the only thing that needs to be ensured is that 
		//	the SINGULAR_WORD indicated by the CurrentSubIndex is displayed on the CurrentIndex line
		int CurrentSubIndex;


		//returns the index
		int pushNewSingularString();

		void unloadChunk(int startIndex, int endIndex);
		void loadChunk(int startIndex, int endIndex);

		void generateRectangularText(int curWidth, int curHeight);
		void generateRectangularText(int curWidth, int curHeight, int currentIndex, int currentSubIndex);

		int CurWidth;
		int CurHeight;
		std::string RectangularText;
		std::vector<std::string> RectangularLines;


	};


}





#endif

