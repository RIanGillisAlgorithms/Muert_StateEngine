#include "pch.h"
#include "gameState_CLEAN_UP.h"
#include "../MuertEngine.Global/globalIncludes.h"
#include "../MuertEngine.Global/globalLogging.h"

namespace GAME
{
	GAMESTATE_CLEAN_UP::GAMESTATE_CLEAN_UP()
	{
		this->currentStage = cleanUpStages::Save;
	}

	GAMESTATE_CLEAN_UP::~GAMESTATE_CLEAN_UP()
	{

	} 

	bool GAMESTATE_CLEAN_UP::Exec(double timeElapsed)
	{	
		return InitSubState(timeElapsed);
		return false;
	}

	bool GAMESTATE_CLEAN_UP::InitSubState(double timeElapsed)
	{
		if (this->currentStage == cleanUpStages::Save)
		{
			GLOBAL::Log(getGameStateName(), "Save");
			//save everything
			this->currentStage = cleanUpStages::WriteStatistics;
			return true;
		}
		else if (this->currentStage == cleanUpStages::WriteStatistics)
		{
			GLOBAL::Log(getGameStateName(), "Write Statistics");
			//output and close all statistics
			this->currentStage = cleanUpStages::WriteLogs;
			return true;
		}
		else if (this->currentStage == cleanUpStages::WriteLogs)
		{
			//output and close all logs
			GLOBAL::Log(getGameStateName(), "Write Logs");
			GLOBAL::CloseLog();
			this->currentStage = cleanUpStages::UnloadObjects;
			return true;
		}
		else if (this->currentStage == cleanUpStages::UnloadObjects)
		{
			//The logs are already closed.... :( 
			//that kind of ruins that structural strategy
			//GLOBAL::Log("gameState Clean Up.Unload Objects");
			//Unload all objects that are still alive then quit
			glfwTerminate();
			return false;
		}
		return false;
	}

	void GAMESTATE_CLEAN_UP::PopCurrentState(bool propagateUp)
	{
		
		return;
	}
}
