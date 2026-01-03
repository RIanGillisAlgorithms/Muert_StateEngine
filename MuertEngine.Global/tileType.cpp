#include "pch.h"
#include "tileType.h"

namespace TILE
{

	TILEDEF::TILEDEF()
	{
		this->tileDefId = -1;
		this->tileSheetIndex = -1;
		this->tileName = "Unset";
	}

	TILEDEF::TILEDEF(std::string TileName, int TileIdx, int TileSheetIdx)
	{
		this->tileName = TileName;
		this->tileDefId = TileIdx;
		this->tileSheetIndex = TileSheetIdx;
	}

	TILEDEF::~TILEDEF()
	{

	}

	TILETYPE::TILETYPE()
	{
		this->tileTypeId = -1;
		this->tileTypeName = "Unset";
	}

	TILETYPE::TILETYPE(std::string TileTypeName, int TileTypeIdx)
	{
		this->tileTypeName = TileTypeName;
		this->tileTypeId = TileTypeIdx;
	}

	TILETYPE::~TILETYPE()
	{

	}

	int TILETYPE::AddTileIndexIfNotPresent(int tileIdx)
	{
		std::vector<int>::iterator it = std::find(this->tileIndex.begin(), this->tileIndex.end(), tileIdx);
		if (it == this->tileIndex.end()) {
			//was not found			
			this->tileIndex.push_back(tileIdx);
			return this->tileIndex.size();
		}
		//was found
		return std::distance(this->tileIndex.begin(), it);
	}

	TILECLASS::TILECLASS()
	{
		this->tileClassId = -1;
		this->tileClassName = "Unset";
	}

	TILECLASS::TILECLASS(std::string TileClassName, int TileClassIdx)
	{
		this->tileClassName = TileClassName;
		this->tileClassId = TileClassIdx;
	}

	TILECLASS::~TILECLASS()
	{

	}

	int TILECLASS::AddTypeIndexIfNotPresent(int tileTypeIdx)
	{
		std::vector<int>::iterator it = std::find(this->tileTypeIndex.begin(), this->tileTypeIndex.end(), tileTypeIdx);
		if (it == this->tileTypeIndex.end()) {
			//was not found			
			this->tileTypeIndex.push_back(tileTypeIdx);
			return this->tileTypeIndex.size();
		}
		//was found
		return std::distance(this->tileTypeIndex.begin(), it);
	}

	int TILECLASS::AddTileIndexIfNotPresent(int tileIdx)
	{
		std::vector<int>::iterator it = std::find(this->tileIndex.begin(), this->tileIndex.end(), tileIdx);
		if (it == this->tileIndex.end()) {
			//was not found			
			this->tileIndex.push_back(tileIdx);
			return this->tileIndex.size();
		}
		//was found
		return std::distance(this->tileIndex.begin(), it);
	}

	TILETYPES::TILETYPES()
	{

	}

	TILETYPES::~TILETYPES()
	{

	}
	void TILETYPES::AddNewTile(int tileIdx, std::string TileName, std::string TileType, std::string TileClass)
	{
		//does this Class exist?
		//Does this type exist?
		//is this tileIdx already occupied for this type/ class?

		int classIdx = FindClassAddIfDoesntExist(TileClass);
		//Does this type exist?
		int typeIdx = FindTypeAddIfDoesntExist(TileType);
		(*tileClasses[classIdx]).AddTypeIndexIfNotPresent(typeIdx);

		int tileDefIdx = FindTileAddIfDoesntExist(TileName, tileIdx);
		(*tileClasses[classIdx]).AddTileIndexIfNotPresent(tileDefIdx);
		(*tileTypes[typeIdx]).AddTileIndexIfNotPresent(tileDefIdx);
	}

	int TILETYPES::AddNewTile(std::string TileName, int TileSheetIdx)
	{
		int curSize = this->tiles.size();
		//The newly inserted TILECLASS will have an index of the current size of the vector
		this->tiles.push_back(new TILEDEF(TileName, curSize, TileSheetIdx));
		return curSize;
	}

	void TILETYPES::LogAllTileDefs()
	{

		std::stringstream sbd;
		std::vector<TILECLASS*>::iterator itrClass = tileClasses.begin();
		int numClasses = tileClasses.size();
		int ctr = 0;
		for (; itrClass != tileClasses.end(); itrClass++)
		{
			ctr++;
			sbd.str("");
			sbd << "Class:[" << ctr << " of " << numClasses << "]"
				<< (*itrClass)->tileClassId << ":" << (*itrClass)->tileClassName
				<< ":Num Types:" << (*itrClass)->tileTypeIndex.size() << ":Num Tiles:" << (*itrClass)->tileIndex.size();
			GLOBAL::Log("Tile Definition Dump", sbd.str());
		}

		std::vector<TILETYPE*>::iterator itrType = tileTypes.begin();
		int numTypes = tileTypes.size();
		ctr = 0;
		for (; itrType != tileTypes.end(); itrType++)
		{
			ctr++;
			sbd.str("");
			sbd << "Type:[" << ctr << " of " << numTypes << "]"
				<< (*itrType)->tileTypeId << ":" << (*itrType)->tileTypeName
				<< ":Num Tiles:" << (*itrType)->tileIndex.size();
			GLOBAL::Log("Tile Definition Dump", sbd.str());
		}
		std::vector<TILEDEF*>::iterator itrTile = tiles.begin();
		int numTiles = tiles.size();
		ctr = 0;
		for (; itrTile != tiles.end(); itrTile++)
		{
			ctr++;
			sbd.str("");
			sbd << "Tile:[" << ctr << " of " << numTiles << "]"
				<< (*itrTile)->tileDefId << ":" << (*itrTile)->tileName << ":Index:" << (*itrTile)->tileSheetIndex;
			GLOBAL::Log("Tile Definition Dump", sbd.str());
		}

	}

	int TILETYPES::FindTypeAddIfDoesntExist(std::string TileType)
	{
		int typeIdx;
		std::vector<TILETYPE*>::iterator itrType = tileTypes.begin();
		bool foundType = false;
		for (; !foundType && itrType != tileTypes.end(); itrType++)
		{
			if ((*itrType)->tileTypeName == TileType)
			{
				foundType = true;
				typeIdx = (*itrType)->tileTypeId;
			}
		}
		//If Type does not exist, create it
		if (!foundType)
		{
			foundType = true;
			typeIdx = this->AddNewType(TileType);
		}
		return typeIdx;
	}

	int TILETYPES::FindClassAddIfDoesntExist(std::string TileClass)
	{
		int classIdx;
		//does this Class exist?
		std::vector<TILECLASS*>::iterator itrClass = tileClasses.begin();
		bool foundClass = false;
		for (; !foundClass && itrClass != tileClasses.end(); itrClass++)
		{
			if ((*itrClass)->tileClassName == TileClass)
			{
				foundClass = true;
				classIdx = (*itrClass)->tileClassId;
			}
		}
		//If Class does not exist, create it
		if (!foundClass)
		{
			foundClass = true;
			classIdx = this->AddNewClass(TileClass);
		}
		return classIdx;
	}

	int TILETYPES::AddNewClass(std::string TileClass)
	{
		int curSize = this->tileClasses.size();
		//The newly inserted TILECLASS will have an index of the current size of the vector
		this->tileClasses.push_back(new TILECLASS(TileClass, curSize));
		return curSize;
	}

	int TILETYPES::AddNewType(std::string TileType)
	{
		int curSize = this->tileTypes.size();
		//The newly inserted TILECLASS will have an index of the current size of the vector
		this->tileTypes.push_back(new TILETYPE(TileType, curSize));
		return curSize;
	}

	int TILETYPES::FindTileAddIfDoesntExist(std::string TileName, int TileSheetIdx)
	{
		int tileIdx;
		std::vector<TILEDEF*>::iterator itrTile = tiles.begin();
		bool foundType = false;
		for (; !foundType && itrTile != tiles.end(); itrTile++)
		{
			if ((*itrTile)->tileName == TileName)
			{
				foundType = true;
				tileIdx = (*itrTile)->tileDefId;
			}
		}
		//If Type does not exist, create it
		if (!foundType)
		{
			foundType = true;
			tileIdx = this->AddNewTile(TileName, TileSheetIdx);
		}
		return tileIdx;
	}

}


