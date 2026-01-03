#include "pch.h"
#include "globalLogging.h"	  

namespace GLOBAL
{
	//PROGRAMLOG PrgLog;

	PROGRAMLOG::PROGRAMLOG()
	{
	}
	PROGRAMLOG::PROGRAMLOG(std::string LogFileName)
	{
		curLog = 0;
		logFileName = LogFileName;
		ResetLog();
	}
	PROGRAMLOG::~PROGRAMLOG()
	{
		//CloseLog();
	}

	void PROGRAMLOG::ResetLog()
	{
		FILE* pFile;
		errno_t err;
		if (err = fopen_s(&pFile, logFileName.c_str(), "w") != 0)
		{
			throw std::runtime_error("Error opening log file");
		}
		fclose(pFile);
	}

	void PROGRAMLOG::WriteLogFile()
	{
		FILE* pFile; 
		errno_t err;
		if ((err = fopen_s(&pFile, logFileName.c_str(), "a")) != 0)
		{
			throw std::runtime_error("Error opening log file");
		}
		else
		{
			for (int forCnt = 0; forCnt < curLog; forCnt++)
			{
				fprintf(pFile, "%s\n", szStrings[forCnt].getRawString().c_str());
			}
			fclose(pFile);

			prevSzStrings = szStrings;
		}
	}	
	void PROGRAMLOG::Log(const std::string szString, const std::string messageString)
	{
		//szStrings[curLog] = szString;
		cs <<"--====" << szString << ":" << TIMER::getElapsedTime() <<":["<<TIMER::getTotalTime()<<"]====--\n"<<messageString;
		this->szStrings[curLog] = cs.str();
		cs.str("");
		curLog++;
		if (curLog > maxLogs)
		{
			WriteLogFile();
			curLog = 0;
		}
	}
	//check out:
	//https://stackoverflow.com/questions/6280149/stdstringstream-as-parameter
	//or:
	//http://www.cplusplus.com/forum/general/58048/
	void PROGRAMLOG::Log(const std::string szString, std::ostream& messageString)
	{
		//szStrings[curLog] = szString;
		cs << "--====" << szString << ":" << TIMER::getElapsedTime() << ":[" << TIMER::getTotalTime() << "]====--\n";
		this->szStrings[curLog].setRawString(cs.str() + dynamic_cast<std::ostringstream&>(messageString).str());
		cs.str("");
		curLog++;
		if (curLog > maxLogs)
		{
			WriteLogFile();
			curLog = 0;
		}
	}

	void PROGRAMLOG::CloseLog()
	{
		cs << "--====[Close Log]:" << TIMER::getElapsedTime() << ":[" << TIMER::getTotalTime() << "]====--\nEnd Time: " << TIMER::getEndTime();
		this->szStrings[curLog].setRawString(cs.str());
		cs.str("");
		curLog++;
		WriteLogFile();
		curLog = 0;
	}
	PROGRAMLOG*& PROGRAMLOG::getPrgLog()
	{
		static PROGRAMLOG* ok = new PROGRAMLOG("logFile.txt");
		return ok;
	}

	PROGRAMLOG*& PROGRAMLOG::getPrgLog_prg()
	{
		static PROGRAMLOG* ok_prg = new PROGRAMLOG("muertLog.txt");
		return ok_prg;
	}

#pragma region Exported Functions

	void ResetLog()
	{
		PROGRAMLOG::getPrgLog()->ResetLog();
	}
	void Log(const std::string szString, const std::string messageString)
	{
		PROGRAMLOG::getPrgLog()->Log(szString, messageString);		
	}
	void CloseLog()
	{
		PROGRAMLOG::getPrgLog()->CloseLog();
	}

	void ResetLog_prg()
	{
		PROGRAMLOG::getPrgLog_prg()->ResetLog();
	}
	void Log_prg(const std::string szString, const std::string messageString)
	{
		PROGRAMLOG::getPrgLog_prg()->Log(szString, messageString);
	}
	void CloseLog_prg()
	{
		PROGRAMLOG::getPrgLog_prg()->CloseLog();
	}

#pragma endregion

}
