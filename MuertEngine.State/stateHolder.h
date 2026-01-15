//by ian.gillis
#pragma once
#ifndef STATE_HOLDER_H
#define STATE_HOLDER_H

#ifdef MUERTENGINESTATE_EXPORTS
#define STATE_HOLDER_H_API __declspec(dllexport)
#else
#define STATE_HOLDER_H_API __declspec(dllimport)
#endif


#include <stack>
#include <string>

#include "../MuertEngine.Global/globalIncludes.h"
#include "../MuertEngine.Global/globalLogging.h"
#include "../MuertEngine.Global/TimeWrapper.h"
#include "../MuertEngine.Random/RandomWrapper.h"

#include "gameState.h"

namespace GAME
{
	//////////////////////////////////////////////////////////////////////////
	/*

			The STATEHOLDER class holds all GAMESTATE-derived classes
			Each GAMESTATE exists within a stack, which allows a sub-GAMESTATE
				to override the current GAMESTATE and then revert back when
				complete. e.g. In the case of user interface override, to
				select a specific tile


	*/
	//////////////////////////////////////////////////////////////////////////
	class STATE_HOLDER_H_API STATEHOLDER
	{
	public:
		STATEHOLDER();
		~STATEHOLDER();
		std::stack<GAMESTATE*> gs;

		GAMESTATE* curState;
		bool maintainState;

		int ProgramLoop();
		void pushState(GAMESTATE* stateToPush);
		void popState();

		GAMESTATE* loadStateFromDLL(const std::string& dllName, const std::string& createFuncName);

	protected:

		const std::string ClassName = "[State Holder]";
	};
}
#endif