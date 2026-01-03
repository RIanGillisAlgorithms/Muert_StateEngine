//by ian.gillis
#pragma once
#ifndef GAME_STATE_CLEAN_UP_H
#define GAME_STATE_CLEAN_UP_H 

#ifdef MUERTENGINESTATESYS_EXPORTS
#define GAME_STATE_CLEAN_UP_H_API __declspec(dllexport)
#else
#define GAME_STATE_CLEAN_UP_H_API __declspec(dllimport)
#endif


#include "../MuertEngine.State/gameState.h"


namespace GAME
{

	//	gameState_INIT
	//	Loops through all INIT functions
	class GAMESTATE_CLEAN_UP : public GAMESTATE
	{
	public:

		enum cleanUpStages
		{
			Save,
			WriteStatistics,
			WriteLogs,
			UnloadObjects
		};

#pragma region CONSTRUCTORS

		GAMESTATE_CLEAN_UP();
		~GAMESTATE_CLEAN_UP();

#pragma endregion
#pragma region ATTRIBUTES

		cleanUpStages currentStage;
		
#pragma endregion
#pragma region FUNCTIONS

#pragma region OVERLOADED

		virtual bool Exec(double timeElapsed) override;
		virtual void PopCurrentState(bool propagateUp = false) override;

		virtual std::string getGameStateName() override { return "[Clean Up]"; }
		//no parentState
		virtual GAMESTATE* getParentState() override { return parentState; }
		//virtual GAMESTATE_QUIT* getParentState() override { return parentState; }
		virtual void setParentState(GAMESTATE* setter) override { parentState = setter; }
		virtual GAMESTATE* getNextState() override { return nextState; }
		virtual void setNextState(GAMESTATE* setter) override { nextState = setter; }
		virtual void HandleInputAction(std::string AreaAction, int button, int action, int mods) override {}
		virtual void HandleKeyboardAction(int Key, int Scancode, int Action, int Mods) override {};
		virtual void MouseScroll(double yoffset) override {};

		//virtual INIT::INITSYS * getInitSys() override { return this->init; }

#pragma endregion
#pragma region DECLARED

		virtual bool InitSubState(double timeElapsed);

#pragma endregion
#pragma endregion

	protected:
		//GAMESTATE_QUIT* parentState;
	};

	/// <summary>
	/// Creates and returns a new instance of GAMESTATE_CLEAN_UP for dynamic dll-loading.
	/// </summary>
	/// <returns>A pointer to a newly allocated GAMESTATE_CLEAN_UP object.</returns>
	extern "C" GAME_STATE_CLEAN_UP_H_API GAMESTATE_CLEAN_UP* create_GAMESTATE_CLEAN_UP()
	{
		return new GAMESTATE_CLEAN_UP();
	}

}

#endif