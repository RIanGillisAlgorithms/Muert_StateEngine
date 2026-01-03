#include "pch.h"
#include "gameState_QUIT.h"

namespace GAME
{
	GAMESTATE_QUIT::GAMESTATE_QUIT()
	{
		//gameStateName = "[Quit]";
	}
	GAMESTATE_QUIT::~GAMESTATE_QUIT()
	{

	}
	bool GAMESTATE_QUIT::Exec(double timeElapsed)
	{
		//let's not do anything for now.
		//just return false, so this current gameState is popped out
		//and the program exits.
		//GLOBAL::Log("Quit");
		return false;
	}

	void GAMESTATE_QUIT::PopCurrentState(bool propagateUp)
	{
		
	}

	bool GAMESTATE_QUIT::InitSubState(double timeElapsed)
	{
		return true;
	}
}
