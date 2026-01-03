#include "pch.h"
#include "stateHolder.h"
#include "dlfcn.hpp"
namespace GAME
{
	STATEHOLDER::STATEHOLDER()
	{
		curState = nullptr;
		//Add gameState_QUIT
		//and gameState_CLEAN_UP (in that order)
		//so they will execute in that order (first in, last out)
		//once all of the other gameStates have finished executing
		//(i.e. the quit button has been pressed)
		auto quitState = loadStateFromDLL("MuertEngine.State.Sys.dll", "create_GAMESTATE_QUIT");
		pushState(quitState);
		auto cleanUpState = loadStateFromDLL("MuertEngine.State.Sys.dll", "create_GAMESTATE_CLEAN_UP");
		pushState(cleanUpState);
		maintainState = true;
	}
	STATEHOLDER::~STATEHOLDER()
	{
		//delete whatever
		while (!this->gs.empty())
		{
			//no states should exist by this point anyways...
			popState();
		}
	}
	//The main Program Loop
	//Once this quits, the program exits completely.
	int STATEHOLDER::ProgramLoop()
	{
		//while there are still gameStates
		while (!gs.empty())
		{
			//reset maintainState every time the curState changes
			maintainState = true;
			//reset dt every time the curState changes
			double dt = 0;
			//keep calling curState->Exec until it returns false
			while (maintainState)
			{
				//call the curState's Exec function
				//pass in the results from iterTime	(the time elapsed between state executions)
				maintainState = (curState)->Exec(TIMER::iterTime());
			}
			//the curState->Exec() function returned false.
			//The current state is finished and the
			//stateHolder should revert to the prior state
			GLOBAL::Log(ClassName, "maintainState==false");
			//does the curState have a nextState queued up and ready to go?
			if ((curState)->getNextState() == nullptr)
			{
				//There is no next state queued up. 
				//Pop the current gameState and revert to the previous one in the stack.
				GLOBAL::Log(ClassName, "No next State in queue");
				popState();
			}
			else
			{
				//There is another state queued up.
				//Push the state onto the top of the stack.
				GLOBAL::Log(ClassName, "Next State: " + (curState)->getNextState()->getGameStateName());
				pushState((curState)->getNextState());
			}
		}
		//The program has completed.
		return -1;
	}
	void STATEHOLDER::pushState(GAMESTATE* stateToPush)
	{
		//remove the nextState from the curState if it exists
		if (curState != nullptr)
		{
			(curState)->setNextState(nullptr);
		}
		gs.push(stateToPush);
		curState = gs.top();
	}
	void STATEHOLDER::popState()
	{
		delete this->gs.top();
		this->gs.pop();
		if (!gs.empty())
		{
			//do not exit yet
			curState = gs.top();
		}
	}

	GAME::GAMESTATE* STATEHOLDER::loadStateFromDLL(const std::string& dllName, const std::string& createFuncName)
	{
		// Load the DLL
		void* handle = dlopen(dllName.c_str(), RTLD_NOW);
		if (!handle)
		{
			GLOBAL::Log(ClassName, "Failed to load DLL: " + dllName);
			throw;
			//return nullptr;
		}

		// Get the create function
		using CreateFunc = GAMESTATE* (*)();
		CreateFunc createFunc = (CreateFunc)dlsym(handle, createFuncName.c_str());
		if (!createFunc)
		{
			GLOBAL::Log(ClassName, "Failed to find create function in DLL: " + dllName);
			dlclose(handle);
			throw;
			return nullptr;
		}

		// Create the game state
		GAMESTATE* newState = createFunc();

		// Close the DLL
		//dlclose(handle);

		return newState;
	}

}
