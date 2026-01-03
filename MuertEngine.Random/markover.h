

//by ian.gillis
//	An ancient and rough markov-chain word generator
//	Usage example in NameGenerator.cpp
#pragma once
#ifndef MARKOVER_H
#define MARKVOER_H

#ifdef MUERTENGINERANDOM_EXPORTS
#define MARKVOER_H_API __declspec(dllexport)
#else
#define MARKVOER_H_API __declspec(dllimport)
#endif


#include <map>
#include <string>
#include <iostream>
#include <fstream>


class MARKVOER_H_API CHAR_LIST_OBJ_3;

//extern "C" MARKVOER_H_API CHAR_LIST_OBJ_3 markov[20];

//for random number generation
//#include "functs.h"





//need a word stats object
//contains x # of dimensions of doubles
//contains an int - # of dimensions left
//
//need a character list object
//containes a word state object
//contains an int total # of dimensions
//
//need an alphabet object
//contains a map of <string, character list object>
//
//you create your alphabet object - then create the stats for the different alphabets, sorted by their name (human-southerners, wind, elf-deep, etc.)

//create an alphabet object 
//open a text file and read in each line

//class WORD_STATS_OBJECT
//{
//public:
//	WORD_STATS_OBJECT();
//	~WORD_STATS_OBJECT();
//
//	int dimensionsLeft;	 
//
//	std::map <int, double> stat;
// 			//126 is start word
//			//127 is end word 	
//
//protected:
//};


class MARKVOER_H_API CHAR_LIST_OBJ_3
{
public:
	CHAR_LIST_OBJ_3();
	~CHAR_LIST_OBJ_3();

	int totalDimensions;
	bool initialized;

	//std::vector < std::vector < std::vector < std::vector < std::vector <double>>>>> charStat;
	double charStat[128][128][128];
	int charCount[128][128];
	double beginStat[128];
	int beginCount;

	double endStat[128][128][128];
	int endCount[128][128];

	bool initMem(int Index);


	//std::map <char, WORD_STATS_OBJECT>  charStat;
	void clearCharStat();
	void printCharStat();

	std::string genWord();

	bool readFile(char* fileName, int numDimensions);



protected:

};



class MARKVOER_H_API MARKOVER
{

public:

	MARKOVER();
	~MARKOVER();



	std::map <std::string, CHAR_LIST_OBJ_3> alphabet_3d;
	//std::map <std::string, CHAR_LIST_OBJ_4> 4d_alphabet;
	//pass in the name of the alphabet

	CHAR_LIST_OBJ_3* getAlphabet(std::string name);

	//pass in the name of the alphabet - e.g. the "A" in names_A.txt
	//it will prepend names_ and append .txt when opening the actual file
	bool loadAlphabet(std::string name);













protected:
	
	
};


//class MARKVOER_H_API MARKOV_HOLDER
//{
//public:
//	MARKOV_HOLDER();
//	~MARKOV_HOLDER();
//
//
//	private CHAR_LIST_OBJ_3 markov[20];
//
//};

extern "C" {
	//write access functions to access markov[20] and check for call init markov[20] if it has not been instantiated
	//CHAR_LIST_OBJ_3* getMarkov(int index)
	//{
	//	if (index < 0 || index > 19)
	//	{
	//		return nullptr;
	//	}
	//	else
	//	{
	//		if (!markov[index].initMem(index))
	//		{
	//			//failed to create/ load the markov library
	//			std::cout << "Markov[" << index << "] has not been initialized" << std::endl;
	//			return nullptr;
	//		}
	//		std::cout << "Markov[" << index << "] has been initialized" << std::endl;
	//		return &markov[index];
	//	}
	//}





}

#endif