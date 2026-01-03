#include "pch.h" 
#include "IanTime.h"

namespace TIMER
{
	IANTIMER*& IANTIMER::getMtim()
	{
		static IANTIMER* ok = new IANTIMER();
		return ok;
	}
	IANTIMER::IANTIMER()
	{
		//init the start time
		start = std::chrono::system_clock::now();
		//why is cur handled differently than start?
		cur = std::chrono::high_resolution_clock::now();
		//init prev
		prev = cur;
		//no time has elapsed, as of yet
		elapsedTime = cur - prev;
		//the total time since start
		elapsedTotalTime = elapsedTime;
		//init fps
		curFPS = 0;
		//init tempTime (for measuring # of calls/ refresh per second) to 0
		tempTime = tempTime.zero();
	}
	IANTIMER::~IANTIMER()
	{
			  
	}
	double const IANTIMER::getElapsed()
	{
		//the amount of time that has passed since the previous call
		return elapsedPair.first;
	}
	double const IANTIMER::getElapsedTotal()
	{
		//the total amount of time that has passed since the timer started
		return elapsedPair.second;
	}
	std::pair<double, double> const IANTIMER::getElapsedPair()
	{
		return elapsedPair;
	}
	double IANTIMER::iter()
	{
		prev = cur;
		cur = std::chrono::high_resolution_clock::now();
		elapsedTime = cur - prev;
		tempTime += elapsedTime;
		tempTimeCounter++;
		elapsedTotalTime += elapsedTime;
		if (tempTime.count() >= 1000)
		{
			tempTime = tempTime.zero();
			curFPS = tempTimeCounter;
			tempTimeCounter = 0;
		}
		elapsedPair = std::pair<double, double>(elapsedTime.count(), elapsedTotalTime.count());
		setCurrentSecondQuarter();

		return elapsedTime.count();
	}
	std::string IANTIMER::getStartDesc()
	{
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(start.time_since_epoch());
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(ms);
		std::time_t t = s.count();
		std::tm tempTimeStruct;
		err = localtime_s(&tempTimeStruct, &t); // Use localtime_s directly
		if (err != 0)
		{
			// error
			return "TimeError";
		}
		std::strftime(mbstr, 32, "%F[%T]", &tempTimeStruct);
		return mbstr;
	}
	std::string IANTIMER::getEndDesc()
	{
		end = std::chrono::system_clock::now();
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(end.time_since_epoch());
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(ms);
		std::time_t t = s.count();
		std::tm tempTimeStruct;
		err = localtime_s(&tempTimeStruct, &t); // Use localtime_s directly
		if (err != 0)
		{
			// error
			return "TimeError";
		}
		std::strftime(mbstr, 32, "%F[%T]", &tempTimeStruct);
		return mbstr;
	}

	int const IANTIMER::getCurrentSecondQuarter()
	{
		return currentSecondQuarter;
	}

	void IANTIMER::setCurrentSecondQuarter()
	{
		if (tempTime.count() >= 750)
		{
			currentSecondQuarter = 3;
		}
		else if (tempTime.count() >= 500)
		{
			currentSecondQuarter = 2;
		}
		else if (tempTime.count() >= 250)
		{
			currentSecondQuarter = 1;
		}
		else if (tempTime.count() >= 0)
		{
			currentSecondQuarter = 0;
		}
		//else
		//{
		//	currentSecondQuarter = 0;
		//}
	}
}