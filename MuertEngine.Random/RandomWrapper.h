

//by ian.gillis
#pragma once
#ifndef RANDOM_WRAPPER_H
#define RANDOM_WRAPPER_H

#ifdef MUERTENGINERANDOM_EXPORTS
#define RANDOM_WRAPPER_H_API __declspec(dllexport)
#else
#define RANDOM_WRAPPER_H_API __declspec(dllimport)
#endif


#include "MersenneTwister.h"
#include <vector>	
#include <chrono>
//#include <random>

namespace RND
{
	class RANDOM_WRAPPER_H_API RandomMersenneTwisterWrapper;
	extern "C" RANDOM_WRAPPER_H_API RandomMersenneTwisterWrapper rnd;
	////extern MTRand* rnd;
	////std::mt19937 rng(seed);
	////std::uniform_int_distribution<int> gen(min, max); // uniform, unbiased

	//extern std::random_device rd;
	//extern std::mt19937 re(rd());
	//extern std::uniform_int_distribution<int> oneTo500(1, 500);
	//extern std::uniform_int_distribution<int> zeroTo180(0, 179);
	class RANDOM_WRAPPER_H_API RandomMersenneTwisterWrapper
	{
	public:
		RandomMersenneTwisterWrapper();
		RandomMersenneTwisterWrapper(uint32_t initialSeed);
		~RandomMersenneTwisterWrapper();

		MTRand* mainR;
		uint32_t mainSeed;
		std::vector<MTRand*> subR;
		std::vector<uint32_t> subSeeds;
		int numSubR;

		int intRand();
		//This returns a number, inclusive, between [startRange - endRange]
		int intRand(const int& startRange, const int& endRange);

		double doubleRand();	
		double doubleRand(const double& startRange, const double& endRange);
		int newSubRand();
		int newSubRand(uint32_t initialSeed);

		int dirRand();

		uint32_t newSeed();


		int rollD6(int numTimes);
		int rollZeroToFive(int numTimes);
	
	};
}
#endif