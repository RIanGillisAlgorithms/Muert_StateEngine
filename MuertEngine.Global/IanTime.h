

//by ian.gillis
#pragma once
#ifndef IAN_TIME_H
#define IAN_TIME_H


#ifdef MUERTENGINEGLOBAL_EXPORTS
#define IAN_TIME_H_API __declspec(dllexport)
#else
#define IAN_TIME_H_API __declspec(dllimport)
#endif


#include <type_traits>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>  
#include <time.h> 

namespace TIMER
{
	class IAN_TIME_H_API IANTIMER
	{
	public:


		static IANTIMER*& getMtim();

		IANTIMER();
		~IANTIMER();	

		double const getElapsed();
		double const getElapsedTotal();
		std::pair<double, double> const getElapsedPair();
		double iter();

		std::string getStartDesc();
		std::string getEndDesc();

		int curFPS;	
		//returns 0 if current tempTime is 0-250ms, 1 if 250-500ms, 2 if 500-750ms, 3 if 750-1000ms
		int const getCurrentSecondQuarter();
		
	private:
		char mbstr[32];

		std::chrono::time_point<std::chrono::system_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> cur;
		std::chrono::time_point<std::chrono::steady_clock> prev;
		std::chrono::time_point<std::chrono::system_clock> end;

		std::chrono::duration<double, std::milli> elapsedTime;
		std::chrono::duration<double, std::milli> tempTime;
		int tempTimeCounter;
		std::chrono::duration<double, std::milli> elapsedTotalTime;

		std::pair<double, double> elapsedPair;
		void setCurrentSecondQuarter();
		int currentSecondQuarter;

		errno_t err;
	};
}

#endif
