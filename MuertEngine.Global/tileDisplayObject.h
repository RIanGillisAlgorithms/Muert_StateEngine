//by ian.gillis
#pragma once
#ifndef tileDisplayObject_H
#define tileDisplayObject_H
// tileDisplayObject.h
// by Ian

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define tileDisplayObject_H_API __declspec(dllexport)
#else
#define tileDisplayObject_H_API __declspec(dllimport)
#endif

#include "Int0To100Predicate.h"
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"


namespace DRAW
{

	
	/////////////////////////
	// 
	//	Template Not Used
	// 
	/////////////////////////
	//template <int _MaxLayers>
	//class TILE_DISPLAY_OBJECT
	//{
	//public:
	//	TILE_DISPLAY_OBJECT();;
	//	~TILE_DISPLAY_OBJECT();;

	//	const static int maxLayers = _MaxLayers;
	//	const static int layerLimit = 9;
	//	const static int globalDefault;

	//	Property <int, Int0To10403<ThrowError> > display[_MaxLayers];
	//	int numLayers;

	//	void set();		
	//	Property <int, Int0To10403<ThrowError> >  get(int Layer);

	//};

	//template <int _MaxLayers>
	//DRAW::TILE_DISPLAY_OBJECT<_MaxLayers>::TILE_DISPLAY_OBJECT()
	//{

	//}

	//template <int _MaxLayers>
	//DRAW::TILE_DISPLAY_OBJECT<_MaxLayers>::~TILE_DISPLAY_OBJECT()
	//{

	//}

	//template <int _MaxLayers>
	//void DRAW::TILE_DISPLAY_OBJECT<_MaxLayers>::set()
	//{

	//}

	//template <int _MaxLayers>
	//Property <int, Int0To10403<ThrowError> > DRAW::TILE_DISPLAY_OBJECT<_MaxLayers>::get(int Layer)
	//{
	//	if (Layer < _MaxLayers)
	//	{
	//		return display[Layer];
	//	}
	//	return
	//}





	//
	//class TILE_DISPLAY_OBJECT_2 : public TILE_DISPLAY_OBJECT<2>
	//{
	//public:
	//	TILE_DISPLAY_OBJECT_2();
	//	~TILE_DISPLAY_OBJECT_2();

	//	void set(int First, int Second);
	//};


	class TILE_DISPLAY_OBJECT_2;
	class TILE_DISPLAY_OBJECT_3;
	class TILE_DISPLAY_OBJECT_4;
	class TILE_DISPLAY_OBJECT_5;
	class TILE_DISPLAY_OBJECT_6;
	class TILE_DISPLAY_OBJECT_7;
	class TILE_DISPLAY_OBJECT_8;
	class TILE_DISPLAY_OBJECT_9;



	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_1
	{
	public:
		TILE_DISPLAY_OBJECT_1();
		TILE_DISPLAY_OBJECT_1(int First);
		~TILE_DISPLAY_OBJECT_1();
		void set(int First);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[1];
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();
	};

	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_2
	{
	public:
		TILE_DISPLAY_OBJECT_2();
		TILE_DISPLAY_OBJECT_2(int First);
		TILE_DISPLAY_OBJECT_2(int First, int Second);
		~TILE_DISPLAY_OBJECT_2();
		void set(int First);
		void set(int First, int Second);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[2];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();
	};

	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_3
	{
	public:
		TILE_DISPLAY_OBJECT_3();;
		TILE_DISPLAY_OBJECT_3(int First);;
		TILE_DISPLAY_OBJECT_3(int First, int Second);;
		TILE_DISPLAY_OBJECT_3(int First, int Second, int Third);;
		~TILE_DISPLAY_OBJECT_3();;


		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void clear();
		int getNumLayers();

		Property <int, Int0To10403<ThrowError> > display[3];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();

		void addToTopOfDisplay(int First, bool WillDropLastDisplayIfNeeded = false);
		TILE_DISPLAY_OBJECT_3 tempAddToTopOfDisplayAndReturn(int First, bool WillDropLastDisplayIfNeeded = false);
		void addToBottomOfDisplay(int First, bool WillReplaceLastDisplayIfNeeded = false);
		TILE_DISPLAY_OBJECT_3 tempAddToBottomOfDisplayAndReturn(int First, bool WillReplaceLastDisplayIfNeeded = false);


		//DRAW::TILE_DISPLAY_OBJECT_4 ToTileDisplayObject4();

#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();
	};

	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_4
	{
	public:
		TILE_DISPLAY_OBJECT_4();
		TILE_DISPLAY_OBJECT_4(int First);
		TILE_DISPLAY_OBJECT_4(int First, int Second);
		TILE_DISPLAY_OBJECT_4(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_4(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_4(TILE_DISPLAY_OBJECT_3 Inp);;
		~TILE_DISPLAY_OBJECT_4();;


		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void set(int First, int Second, int Third, int Fourth);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[4];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();


#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();

	};

	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_5
	{
	public:
		TILE_DISPLAY_OBJECT_5();
		TILE_DISPLAY_OBJECT_5(int First);
		TILE_DISPLAY_OBJECT_5(int First, int Second);
		TILE_DISPLAY_OBJECT_5(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_5(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_5(int First, int Second, int Third, int Fourth, int Fifth);
		TILE_DISPLAY_OBJECT_5(TILE_DISPLAY_OBJECT_3 Inp);;
		~TILE_DISPLAY_OBJECT_5();;


		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void set(int First, int Second, int Third, int Fourth);
		void set(int First, int Second, int Third, int Fourth, int Fifth);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[5];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();


#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();

	};


	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_6
	{
	public:
		TILE_DISPLAY_OBJECT_6();
		TILE_DISPLAY_OBJECT_6(int First);
		TILE_DISPLAY_OBJECT_6(int First, int Second);
		TILE_DISPLAY_OBJECT_6(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth, int Fifth);
		TILE_DISPLAY_OBJECT_6(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		TILE_DISPLAY_OBJECT_6(TILE_DISPLAY_OBJECT_3 Inp);;
		~TILE_DISPLAY_OBJECT_6();;


		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void set(int First, int Second, int Third, int Fourth);
		void set(int First, int Second, int Third, int Fourth, int Fifth);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[6];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();


#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();

	};

	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_7
	{
	public:
		TILE_DISPLAY_OBJECT_7();
		TILE_DISPLAY_OBJECT_7(int First);
		TILE_DISPLAY_OBJECT_7(int First, int Second);
		TILE_DISPLAY_OBJECT_7(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth);
		TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		TILE_DISPLAY_OBJECT_7(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh);
		TILE_DISPLAY_OBJECT_7(TILE_DISPLAY_OBJECT_3 Inp);;
		~TILE_DISPLAY_OBJECT_7();;

		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void set(int First, int Second, int Third, int Fourth);
		void set(int First, int Second, int Third, int Fourth, int Fifth);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[7];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_8 toTDO8();
		TILE_DISPLAY_OBJECT_9 toTDO9();

#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();
	};


	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_8
	{
	public:
		TILE_DISPLAY_OBJECT_8();
		TILE_DISPLAY_OBJECT_8(int First);
		TILE_DISPLAY_OBJECT_8(int First, int Second);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh);
		TILE_DISPLAY_OBJECT_8(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth);
		TILE_DISPLAY_OBJECT_8(TILE_DISPLAY_OBJECT_3 Inp);;
		~TILE_DISPLAY_OBJECT_8();;


		void set(int First);
		void set(int First, int Second);
		void set(int First, int Second, int Third);
		void set(int First, int Second, int Third, int Fourth);
		void set(int First, int Second, int Third, int Fourth, int Fifth);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh);
		void set(int First, int Second, int Third, int Fourth, int Fifth, int Sixth, int Seventh, int Eighth);
		void clear();
		int getNumLayers();
		Property <int, Int0To10403<ThrowError> > display[8];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_9 toTDO9();


#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();

	};




	class tileDisplayObject_H_API TILE_DISPLAY_OBJECT_9
	{
	public:
#pragma region CONSTRUCTORS
		TILE_DISPLAY_OBJECT_9();
		TILE_DISPLAY_OBJECT_9(int First);
		TILE_DISPLAY_OBJECT_9(int First, int Second);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth
			, int Fifth);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth
			, int Fifth, int Sixth);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth
			, int Fifth, int Sixth, int Seventh);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth
			, int Fifth, int Sixth, int Seventh, int Eighth);
		TILE_DISPLAY_OBJECT_9(int First, int Second, int Third, int Fourth
		, int Fifth, int Sixth, int Seventh, int Eighth
		, int Ninth);
#pragma endregion
#pragma region CopyConstructors
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_1& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_2& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_3& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_4& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_5& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_6& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_7& Setter);
		TILE_DISPLAY_OBJECT_9(TILE_DISPLAY_OBJECT_8& Setter);

#pragma endregion

		~TILE_DISPLAY_OBJECT_9();;


		void set(int First );
		void set(int First ,int Second );
		void set(int First ,int Second ,int Third );
		void set(int First ,int Second ,int Third ,int Fourth );
		void set(int First ,int Second ,int Third ,int Fourth 
			, int Fifth );
		void set(int First ,int Second ,int Third ,int Fourth 
			, int Fifth ,int Sixth );
		void set(int First ,int Second ,int Third ,int Fourth 
			, int Fifth ,int Sixth ,int Seventh );
		void set(int First ,int Second ,int Third ,int Fourth
			, int Fifth ,int Sixth ,int Seventh ,int Eighth );
		void set(int First ,int Second ,int Third ,int Fourth
			, int Fifth ,int Sixth ,int Seventh ,int Eighth 
			, int Ninth );
		void clear();
		int getNumLayers();

		Property <int, Int0To10403<ThrowError> > display[9];
		TILE_DISPLAY_OBJECT_1 toTDO1();
		TILE_DISPLAY_OBJECT_2 toTDO2();
		TILE_DISPLAY_OBJECT_3 toTDO3();
		TILE_DISPLAY_OBJECT_4 toTDO4();
		TILE_DISPLAY_OBJECT_5 toTDO5();
		TILE_DISPLAY_OBJECT_6 toTDO6();
		TILE_DISPLAY_OBJECT_7 toTDO7();
		TILE_DISPLAY_OBJECT_8 toTDO8();

		void combine(TILE_DISPLAY_OBJECT_1 td);
		void combine(TILE_DISPLAY_OBJECT_2 td);
		void combine(TILE_DISPLAY_OBJECT_3 td);
		void combine(TILE_DISPLAY_OBJECT_4 td);

		void addToTopOfDisplay(int First, bool WillDropLastDisplayIfNeeded = false);
		void addToTopOfDisplay(TILE_DISPLAY_OBJECT_9 InsertBeforeFirst, bool WillDropLastDisplayIfNeeded = false);
		TILE_DISPLAY_OBJECT_9 tempAddToTopOfDisplayAndReturn(int First, bool WillDropLastDisplayIfNeeded = false);
		void addToBottomOfDisplay(int First, bool WillReplaceLastDisplayIfNeeded = false);
		void addToBottomOfDisplay(TILE_DISPLAY_OBJECT_9 InsertAfterLast, bool WillReplaceFirstDisplayIfNeeded = false);
		TILE_DISPLAY_OBJECT_9 tempAddToBottomOfDisplayAndReturn(int First, bool WillReplaceLastDisplayIfNeeded = false);


#pragma endregion

	protected:
		int numLayers;
		//deprecated
		int numDisplayLayers();

	};



	class tileDisplayObject_H_API CHAR_CONSOLECOLOR
	{
	public:
		CHAR_CONSOLECOLOR();
		CHAR_CONSOLECOLOR(char def, DRAW::CONSOLE_COLOR foreColor, DRAW::CONSOLE_COLOR backColor);
		~CHAR_CONSOLECOLOR();

		char disp;
		DRAW::CONSOLE_COLOR foreColor;
		DRAW::CONSOLE_COLOR backColor;
	};
}



#endif