//by ian.gillis
#pragma once
#ifndef GAME_STATE_QUIT_H
#define GAME_STATE_QUIT_H

#ifdef MUERTENGINESTATESYS_EXPORTS
#define GAME_STATE_QUIT_H_API __declspec(dllexport)
#else
#define GAME_STATE_QUIT_H_API __declspec(dllimport)
#endif

#include "../MuertEngine.State/gameState.h"


namespace GAME
{

	//	gameState_INIT
	//	Loops through all INIT functions
	class GAMESTATE_QUIT : public GAMESTATE
	{
	public:

		enum quitStages
		{
			Quit
		};

#pragma region CONSTRUCTORS

		GAMESTATE_QUIT();
		~GAMESTATE_QUIT();

#pragma endregion
#pragma region ATTRIBUTES


#pragma endregion
#pragma region FUNCTIONS

#pragma region OVERLOADED

		virtual bool Exec(double timeElapsed) override;
		virtual void PopCurrentState(bool propagateUp = false) override;
		
		virtual std::string getGameStateName() override { return "[Quit]"; }
		//no parentState
		virtual GAMESTATE* getParentState() override { return nullptr; }
		virtual void setParentState(GAMESTATE* setter) override {}
		virtual GAMESTATE* getNextState() override { return nextState; }
		virtual void setNextState(GAMESTATE* setter) override { nextState = setter; }
		virtual bool InitSubState(double timeElapsed) override;
		virtual void HandleInputAction(std::string AreaAction, int button, int action, int mods) override {}
		virtual void HandleKeyboardAction(int Key, int Scancode, int Action, int Mods) override {};
		virtual void MouseScroll(double yoffset) override {};

		//virtual INIT::INITSYS * getInitSys() override { return this->init; }

#pragma endregion
#pragma region DECLARED

#pragma endregion
#pragma endregion

		





	};

	/// <summary>
	/// Creates and returns a new instance of GAMESTATE_QUIT for dynamic dll-loading.
	/// </summary>
	/// <returns>A pointer to a newly allocated GAMESTATE_QUIT object.</returns>
	extern "C" GAME_STATE_QUIT_H_API GAMESTATE_QUIT* create_GAMESTATE_QUIT()
	{
		return new GAMESTATE_QUIT();
	}

}

#endif