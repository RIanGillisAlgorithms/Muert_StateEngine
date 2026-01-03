//by ian.gillis
#pragma once
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>

#include "../MuertEngine.Global/globalIncludes.h" 
#include "../MuertEngine.Random/RandomWrapper.h"


namespace GAME
{
	/// <summary>
	/// Represents an abstract base class for a game state, providing an interface for state management, input handling, and state transitions.
	/// </summary>
	class GAMESTATE
	{
	public:
		GAMESTATE() {}
		~GAMESTATE() {}


		virtual bool Exec(double timeElapsed) = 0;
		virtual void PopCurrentState(bool propagateUp = false) = 0;

		virtual bool InitSubState(double timeElapsed) = 0;
		virtual std::string getGameStateName() = 0;
		virtual GAMESTATE* getParentState() = 0;
		virtual void setParentState(GAMESTATE* setter) = 0;
		virtual GAMESTATE* getNextState() = 0;
		virtual void setNextState(GAMESTATE* setter) = 0;

		virtual void HandleInputAction(std::string AreaAction, int button, int action, int mods) = 0;
		virtual void HandleKeyboardAction(int Key, int Scancode, int Action, int Mods) = 0;

		virtual void MouseScroll(double yoffset) = 0;



		bool canDraw;
		bool shortCircuitExecution;

		GAMESTATE* parentState;
		GAMESTATE* nextState;
		GAMESTATE* childState;

	};

}


#endif
