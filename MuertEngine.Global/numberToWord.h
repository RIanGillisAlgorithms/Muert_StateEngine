

//by ian.gillis
#pragma once
#ifndef NUMBER_TO_WORD_H
#define NUMBER_TO_WORD_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define NUMBER_TO_WORD_H_API __declspec(dllexport)
#else
#define NUMBER_TO_WORD_H_API __declspec(dllimport)
#endif


#include <string>
#include <vector>

//taken from:
//https://stackoverflow.com/a/40253170


namespace s
{



	//std::string digitName(int digit);
	//std::string teenName(int number);
	//std::string tensName(int number);
	//std::string intName(int number);


	extern "C" NUMBER_TO_WORD_H_API std::string nameForNumber(long number);



}








#endif