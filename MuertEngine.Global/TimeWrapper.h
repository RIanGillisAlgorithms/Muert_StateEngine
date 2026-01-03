

//by ian.gillis
#pragma once
#ifndef TIME_WRAPPER_H
#define TIME_WRAPPER_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define TIME_WRAPPER_H_API __declspec(dllexport)
#else
#define TIME_WRAPPER_H_API __declspec(dllimport)
#endif


#include "IanTime.h"
namespace TIMER
{

	//GRANDMASTERTIMEKEEPER* glm;
	//extern "C" TIME_WRAPPER_H_API IANTIMER* mtim;


	extern "C" TIME_WRAPPER_H_API bool initTime();
	
	extern "C" TIME_WRAPPER_H_API double iterTime();
	//extern "C" TIME_WRAPPER_H_API double getCurrentTime();
	extern "C" TIME_WRAPPER_H_API double getElapsedTime();

	extern "C" TIME_WRAPPER_H_API double getTotalTime();
	extern "C" TIME_WRAPPER_H_API int getFPS();
	
	extern "C" TIME_WRAPPER_H_API std::string getStartTime();

	extern "C" TIME_WRAPPER_H_API std::string getEndTime();

	extern "C" TIME_WRAPPER_H_API int const getQuarter();

}
#endif


