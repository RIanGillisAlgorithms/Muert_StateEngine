//by ian.gillis
#pragma once
#ifndef TILE_TYPE_H
#define TILE_TYPE_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define TILE_TYPE_H_API __declspec(dllexport)
#else
#define TILE_TYPE_H_API __declspec(dllimport)
#endif


#include <string>
#include <sstream>
#include <vector>
#include "globalLogging.h"


namespace TILE
{
	class TILE_TYPE_H_API TILEDEF
	{
	public:
		TILEDEF();
		TILEDEF(std::string TileName, int TileIdx, int TileSheetIdx);
		~TILEDEF();
		int tileDefId;
		std::string tileName;
		int tileSheetIndex;
	};

	class TILE_TYPE_H_API TILETYPE
	{
	public:
		TILETYPE();
		TILETYPE(std::string TileTypeName, int TileTypeIdx);
		~TILETYPE();

		int tileTypeId;
		std::string tileTypeName;
		
		std::vector<int> tileIndex;	   

		int AddTileIndexIfNotPresent(int tileIdx);
	};

	class TILE_TYPE_H_API TILECLASS
	{
	public:
		TILECLASS();
		TILECLASS(std::string TileClassName, int TileClassIdx);
		~TILECLASS();

		int tileClassId;
		std::string tileClassName;
		std::vector<int> tileIndex;
		std::vector<int> tileTypeIndex;

		int AddTypeIndexIfNotPresent(int tileTypeIdx);
		int AddTileIndexIfNotPresent(int tileIdx);
	};

	class TILE_TYPE_H_API TILETYPES
	{
	public:
		TILETYPES();
		~TILETYPES();
		std::vector<TILEDEF*> tiles;
		std::vector<TILETYPE*> tileTypes;
		std::vector<TILECLASS*> tileClasses;
		//void loadTiles();

		void AddNewTile(int tileIdx, std::string TileName, std::string TileType, std::string TileClass);
		int FindClassAddIfDoesntExist(std::string TileClass);
		int AddNewClass(std::string TileClass);
		int FindTypeAddIfDoesntExist(std::string TileType);
		int AddNewType(std::string TileType);
		int FindTileAddIfDoesntExist(std::string TileName, int TileSheetIdx);
		int AddNewTile(std::string TileName, int TileSheetIdx);
		void LogAllTileDefs();



	};

}

#endif
