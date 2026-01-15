#include "main.h"
//#include "../MuertDraw/gameState_SETTINGS.h"

int main()
{

	//The stateHolder constructor inserts GAMESTATE_QUIT and GAMESTATE_CLEANUP by default
	//Once all of the other gameStates have been removed from the stack it will
	//go through all of the GAMESTATE_CLEANUP subStates in turn, pop itself off the stack
	//and then go through all of the GAMESTATE_QUIT subStates before exiting
	GAME::STATEHOLDER states;

	////////////////////////////////////////////////////////////////////////////////
	// 
	// Add the initial game state here
	// 
	//		a GAMESTATE #includes it's parentState and forward-declares any childStates
	// 
	////////////////////////////////////////////////////////////////////////////////

	//ProgramLoop starts at GAMESTATE_SETTINGS
	//states.pushState(new GAME::GAMESTATE_SETTINGS());

	//or load from DLL:
	//auto gsSettings = states.loadStateFromDLL("MuertEngine.State.Draw.dll", "create_GAMESTATE_SETTINGS");
	//states.pushState(gsSettings);


	return states.ProgramLoop();
}
