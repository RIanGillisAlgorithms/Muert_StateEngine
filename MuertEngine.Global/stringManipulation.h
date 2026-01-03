

//by ian.gillis
#pragma once
#ifndef STRING_MANIPULATION_H
#define STRING_MANIPULATION_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define STRING_MANIPULATION_H_API __declspec(dllexport)
#else
#define STRING_MANIPULATION_H_API __declspec(dllimport)
#endif


#include <algorithm>
#include <string> 
//#include <map>
//#include <list>
//#include <fstream>
//#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
#include "nonLeakyRectangularString.h"

namespace s
{

	template<typename T/*, typename = std::enable_if_t<std::is_integral_v<T>>*/>
	std::string to_string_with_zero_padding(const T& value, std::size_t total_length)
	{
		auto str = std::to_string(value);
		if (str.length() < total_length)
			str.insert(str.front() == '-' ? 1 : 0, total_length - str.length(), '0');
		return str;
	}


	STRING_MANIPULATION_H_API std::string stringToUppper(std::string inp);
	STRING_MANIPULATION_H_API int stringToInt(std::string inp);
	STRING_MANIPULATION_H_API double stringTodouble(std::string inp);	 	
	//does s1 contain s2?
	STRING_MANIPULATION_H_API bool stringContains(std::string s1, std::string s2);

	STRING_MANIPULATION_H_API bool stringBeginsWith(std::string s1, std::string s2);

	STRING_MANIPULATION_H_API std::string stringToReversedRectangle_Alt(std::string inp, int numTilesWidth, int numTilesHeight
		, bool shouldOutline = false, bool hasEOL = false
		, char outlineCharacter = '#', char eol = '\n');

	//Give me a string and I will print it, backwards, on "a rectangle" (respecting width/ height) 
	//with empty space occupying the remainder
	//This assumes mono-spaced characters, sorry ttf fags
	STRING_MANIPULATION_H_API std::string stringToReversedRectangle(std::string inp, int w, int h, bool hasEOL, char eol = '\n');
		
	STRING_MANIPULATION_H_API std::vector<std::string> split(const std::string &s, char delim);
	STRING_MANIPULATION_H_API std::vector<std::vector<int>> CenterWords(std::string testInput, int maxWidth, int frontPad, int backPad);
	STRING_MANIPULATION_H_API void ConvertIntToReadbleString(int curi, int w, std::string &toSet);
	STRING_MANIPULATION_H_API void ConvertDoubleToReadableString(double curd, int w, std::string& toSet);


	STRING_MANIPULATION_H_API void WordifyText(std::string Text, COMM::RECT_STRING& RctString);



	STRING_MANIPULATION_H_API void padTo(std::string& str, size_t num, char paddingChar = '\0');

	

	STRING_MANIPULATION_H_API void unpad(std::string& str, char paddingChar = '\0');




}

#endif
