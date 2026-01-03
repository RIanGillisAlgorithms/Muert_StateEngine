#include "pch.h"
#include "TimeWrapper.h"
			
namespace TIMER
{	 
	//IANTIMER* mtim;

	bool initTime()
	{
		//mtim = new IANTIMER();
		return true;
	}
	double iterTime()
	{
		return IANTIMER::getMtim()->iter();
	}
	double getElapsedTime()
	{
		return IANTIMER::getMtim()->getElapsed();
	}	
	extern double getTotalTime()
	{
		return IANTIMER::getMtim()->getElapsedTotal();
	}  
	extern int getFPS()
	{
		return IANTIMER::getMtim()->curFPS;
	}	 
	std::string getStartTime()
	{
		return IANTIMER::getMtim()->getStartDesc();
	}
	std::string getEndTime()
	{
		return IANTIMER::getMtim()->getEndDesc();
	}

	extern int const getQuarter()
	{
		return IANTIMER::getMtim()->getCurrentSecondQuarter();
	}

}