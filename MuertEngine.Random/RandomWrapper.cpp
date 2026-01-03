#include "pch.h"
#include "RandomWrapper.h"
namespace RND
{
	RandomMersenneTwisterWrapper rnd;
	//std::random_device rd;
	//std::mt19937 re(rd());
	//std::uniform_int_distribution<int> oneTo500(1, 500);
	//std::uniform_int_distribution<int> zeroTo180(0, 179);
	//MTRand* rnd;

	RandomMersenneTwisterWrapper::RandomMersenneTwisterWrapper()
	{
		numSubR = 0;
		mainSeed = newSeed();
		this->mainR = new MTRand(mainSeed);
	}

	RandomMersenneTwisterWrapper::RandomMersenneTwisterWrapper(uint32_t initialSeed)
	{
		numSubR = 0;
		mainSeed = initialSeed;
		this->mainR = new MTRand(mainSeed);
	}

	RandomMersenneTwisterWrapper::~RandomMersenneTwisterWrapper()
	{
		delete mainR;
		for (std::vector< MTRand* >::iterator it = subR.begin(); it != subR.end(); ++it)
		{
			delete (*it);
		}
		subR.clear();		
	}

	int RandomMersenneTwisterWrapper::intRand()
	{
		return this->mainR->randInt();
	}

	int RandomMersenneTwisterWrapper::intRand(const int& startRange, const int& endRange)
	{
		return (this->mainR->randInt(endRange - startRange)) + startRange;
	}

	double RandomMersenneTwisterWrapper::doubleRand()
	{
		return this->mainR->rand();
	}

	double RandomMersenneTwisterWrapper::doubleRand(const double& startRange, const double& endRange)
	{
		return (this->mainR->rand(endRange - startRange)) + startRange;
	}

	int RandomMersenneTwisterWrapper::newSubRand()
	{
		this->subSeeds.push_back(newSeed());
		//we use the current numSubR and then add one to it after we are finished
		this->subR.push_back(new MTRand(this->subSeeds[numSubR]));
		numSubR++;
		return (numSubR - 1);
	}

	int RandomMersenneTwisterWrapper::newSubRand(uint32_t initialSeed)
	{			
		this->subSeeds.push_back(initialSeed);
		this->subR.push_back(new MTRand(initialSeed));
		numSubR++;
		return (numSubR - 1);
	}

	int RandomMersenneTwisterWrapper::dirRand()
	{
		int toReturn = intRand(1, 8);
		if (toReturn == 5)
		{
			toReturn = 9;
		}
		return toReturn;
	}

	uint32_t RandomMersenneTwisterWrapper::newSeed()
	{
		return std::chrono::high_resolution_clock::now().time_since_epoch().count();
	}	

	int RandomMersenneTwisterWrapper::rollD6(int numTimes)
	{	  
		int res = 0;
		for (int pix = 0; pix < numTimes; pix++) 
		{
			res += intRand(1, 6);
		}
		return res;
	}

	int RandomMersenneTwisterWrapper::rollZeroToFive(int numTimes)
	{
		int res = 0;
		for (int pix = 0; pix < numTimes; pix++)
		{
			res += intRand(0, 5);
		}
		return res;
	}

}