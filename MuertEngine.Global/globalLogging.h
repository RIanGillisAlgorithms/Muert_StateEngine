

//by ian.gillis
#pragma once
#ifndef GLOBAL_LOGGING_H
#define GLOBAL_LOGGING_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define GLOBAL_LOGGING_H_API __declspec(dllexport)
#else
#define GLOBAL_LOGGING_H_API __declspec(dllimport)
#endif

//#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <array>
#include <string>
#include <sstream>
#include "TimeWrapper.h"
#include <string_view>
#include "nonLeakyRectangularString_raw.h"
					
namespace GLOBAL
{
	class PROGRAMLOG;

	//global system log
	extern "C" GLOBAL_LOGGING_H_API void ResetLog();
	extern "C" GLOBAL_LOGGING_H_API void Log(const std::string szString, const std::string messageString);
	extern "C" GLOBAL_LOGGING_H_API void CloseLog();


	//global program log
	extern "C" GLOBAL_LOGGING_H_API void ResetLog_prg();
	extern "C" GLOBAL_LOGGING_H_API void Log_prg(const std::string szString, const std::string messageString);
	extern "C" GLOBAL_LOGGING_H_API void CloseLog_prg();

	class GLOBAL_LOGGING_H_API PROGRAMLOG
	{
	public:
		PROGRAMLOG();
		PROGRAMLOG(std::string LogFileName);
		~PROGRAMLOG();

		std::array<COMM::RECT_STRING_RAW, 250> szStrings;
		static const int maxLogs = 249;   
		std::array<COMM::RECT_STRING_RAW, 250> prevSzStrings;

		int curLog;
		void ResetLog();
		void WriteLogFile();
		void Log(const std::string szString, const std::string messageString);
		void Log(const std::string szString, std::ostream& messageString);				
		void CloseLog();


		//get global log static object
		static PROGRAMLOG*& getPrgLog();
		//get global program log static object
		static PROGRAMLOG*& getPrgLog_prg();
	
	private:
		std::string logFileName;
		std::stringstream cs;
	}; 
}

#endif
