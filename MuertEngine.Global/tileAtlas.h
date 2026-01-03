//by ian.gillis
#pragma once
#ifndef TILEATLAS_H
#define TILEATLAS_H


#ifdef MUERTENGINEGLOBAL_EXPORTS
#define TILEATLAS_H_API __declspec(dllexport)
#else
#define TILEATLAS_H_API __declspec(dllimport)
#endif

#include "globalIncludes.h"
#include "tileType.h"

namespace DRAW
{

	class TILEATLAS_H_API TILE_ATLAS
	{
	public:
		enum CONSOLE_COLOR
		{
			BLACK
			, DARK_BLUE
			, DARK_GREEN
			, DARK_CYAN
			, DARK_RED
			, DARK_MAGENTA
			, DARK_YELLOW
			, DARK_WHITE
			, BRIGHT_BLACK
			, BRIGHT_BLUE
			, BRIGHT_GREEN
			, BRIGHT_CYAN
			, BRIGHT_RED
			, BRIGHT_MAGENTA
			, BRIGHT_YELLOW
			, WHITE
		};

		TILE_ATLAS();
		TILE_ATLAS(int TileAtlasId, int BaseTilSizX, int BaseTilSizY, int BasePixelOffsetX, int BasePixelOffsetY, int NumTilX, int NumTilY);
		~TILE_ATLAS();

		int tileAtlasId;
		//ImgDatVector is only used to store texture data that needs to be updated.
		//As opposed to the texture indicated by tileMapTexture, which will never be adjusted.
		//ImgDatVector mappedData[3];
		//ImgDatVector

		GLuint tileMapTexture;

		//each tile in the tileMapTexture is a square (or maybe not)
		//its dimensions are defined by WINDOW.baseTilSiz
		int baseTilSizX;
		int baseTilSizY;

		//the X,Y offset of the texture to the first tile
		int basePixelOffsetX;
		int basePixelOffsetY;

		//the number of rows and columns
		int numTilX;
		int numTilY;

		//the 0-10 different types of fragment/ pixel shader we use to display 
		//the data encoded within the texture map texture.
		int fragmentId;

		TILE::TILETYPES* tileTypes;


		int definedColors[16][3];



		//adjusting the memory-size etc.
		int multX;
		int multY;
		int multMemX;
		int multMemY;
	};





	class TILEATLAS_H_API TILE_ATLAS_VP_MAIN : TILE_ATLAS
	{
		const int fragmentId = 0;
	};






}


#endif



