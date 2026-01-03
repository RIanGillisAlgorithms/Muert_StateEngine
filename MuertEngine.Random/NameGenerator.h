//by ian.gillis
#pragma once
#ifndef NAME_GENERATOR_H
#define NAME_GENERATOR_H

#ifdef MUERTENGINERANDOM_EXPORTS
#define NAME_GENERATOR_H_API __declspec(dllexport)
#else
#define NAME_GENERATOR_H_API __declspec(dllimport)
#endif


#include <string>
#include "RandomWrapper.h"	



/// <summary>
/// ToDo: should this be in ianUtil? Or RND?
/// </summary>
namespace ianUtil
{

	class NAME_GENERATOR_H_API NameGenerator
	{
	public:
		NameGenerator();
		~NameGenerator();

		std::string generateStellarStructureName();



		//		markov[0].readFile("names_A.txt", 3);

		//Second Gods

		//

		//markov[1].clearCharStat();
		//markov[1].readFile("names_B.txt", 3);

		////markov[2].clearCharStat();
		//markov[2].readFile("names_C.txt", 3);

		////markov[3].clearCharStat();
		//markov[3].readFile("names_D.txt", 3);

		////markov[4].clearCharStat();
		//markov[4].readFile("names_E.txt", 3);

		////markov[5].clearCharStat();
		//markov[5].readFile("names_F.txt", 3);

		////markov[6].clearCharStat();
		//markov[6].readFile("names_G.txt", 3);

		//markov[7].readFile("names_Stars.txt", 3);


		//markov[8].readFile("names_Connector.txt", 3);

		//markov[9].readFile("names_Suffix.txt", 3);


	};
	extern "C" NAME_GENERATOR_H_API NameGenerator nameGen;

}


#endif // 
