#include "pch.h"
#include "tileAtlas.h"

namespace DRAW
{		  		  

	TILE_ATLAS::TILE_ATLAS()
	{
		this->tileTypes = new TILE::TILETYPES();
	}

	TILE_ATLAS::TILE_ATLAS(int TileAtlasId, int BaseTilSizX, int BaseTilSizY, int BasePixelOffsetX, int BasePixelOffsetY, int NumTilX, int NumTilY)
	{
		this->tileAtlasId = TileAtlasId;
		this->baseTilSizX = BaseTilSizX;
		this->baseTilSizY = BaseTilSizY;
		this->basePixelOffsetX = BasePixelOffsetX;
		this->basePixelOffsetY = BasePixelOffsetY;
		this->numTilX = NumTilX;
		this->numTilY = NumTilY;

		this->tileTypes = new TILE::TILETYPES();   	  

		//black
		this->definedColors[0][0] = 12;
		this->definedColors[0][1] = 12;
		this->definedColors[0][2] = 12;

		//dark_blue
		this->definedColors[1][0] = 0;
		this->definedColors[1][1] = 55;
		this->definedColors[1][2] = 218;

		//dark_green
		this->definedColors[2][0] = 19;
		this->definedColors[2][1] = 161;
		this->definedColors[2][2] = 14;

		//dark_cyan
		this->definedColors[3][0] = 58;
		this->definedColors[3][1] = 150;
		this->definedColors[3][2] = 221;

		//dark_red
		this->definedColors[4][0] = 197;
		this->definedColors[4][1] = 15;
		this->definedColors[4][2] = 31;

		//dark_magenta
		this->definedColors[5][0] = 136;
		this->definedColors[5][1] = 23;
		this->definedColors[5][2] = 152;

		//dark_yellow
		this->definedColors[6][0] = 193;
		this->definedColors[6][1] = 156;
		this->definedColors[6][2] = 0;

		//dark_white
		this->definedColors[7][0] = 204;
		this->definedColors[7][1] = 204;
		this->definedColors[7][2] = 204;

		//bright_black
		this->definedColors[8][0] = 118;
		this->definedColors[8][1] = 118;
		this->definedColors[8][2] = 118;

		//bright_blue
		this->definedColors[9][0] = 59;
		this->definedColors[9][1] = 120;
		this->definedColors[9][2] = 255;

		//bright_green
		this->definedColors[10][0] = 22;
		this->definedColors[10][1] = 198;
		this->definedColors[10][2] = 12;

		//bright_cyan
		this->definedColors[11][0] = 97;
		this->definedColors[11][1] = 214;
		this->definedColors[11][2] = 214;

		//bright_red
		this->definedColors[12][0] = 231;
		this->definedColors[12][1] = 72;
		this->definedColors[12][2] = 86;

		//bright_magenta
		this->definedColors[13][0] = 180;
		this->definedColors[13][1] = 0;
		this->definedColors[13][2] = 158;

		//bright_yellow
		this->definedColors[14][0] = 249;
		this->definedColors[14][1] = 241;
		this->definedColors[14][2] = 165;

		//white
		this->definedColors[15][0] = 242;
		this->definedColors[15][1] = 242;
		this->definedColors[15][2] = 242;
	}

	TILE_ATLAS::~TILE_ATLAS()
	{
		delete this->tileTypes;
	}

}

