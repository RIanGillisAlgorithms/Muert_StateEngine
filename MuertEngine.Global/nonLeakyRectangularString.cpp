#include "pch.h"
#include "nonLeakyRectangularString.h"
#include "structureDefinitions.h"


namespace COMM
{

	RECT_STRING_HOLDER::RECT_STRING_HOLDER()
	{
	}

	RECT_STRING_HOLDER::~RECT_STRING_HOLDER()
	{
	}


	RECT_STRING::RECT_STRING()
	{
	}

	RECT_STRING::~RECT_STRING()
	{
	}

	int RECT_STRING::getNumberOfRows(int surfaceTileWidth)
	{
		if (!this->CompiledStrings[surfaceTileWidth].Set)
		{
			this->CompiledStrings[surfaceTileWidth].init(surfaceTileWidth, &Words, 0, 0);
			if (this->HighestRowsByWidth[surfaceTileWidth] < this->CompiledStrings[surfaceTileWidth].Row.size())
			{
				this->HighestRowsByWidth[surfaceTileWidth] = this->CompiledStrings[surfaceTileWidth].Row.size();
			}
		}
		return this->CompiledStrings[surfaceTileWidth].Row.size();
	}

	int RECT_STRING::getHighestNumberOfRows(int surfaceTileWidth)
	{
		if (!this->CompiledStrings[surfaceTileWidth].Set)
		{
			this->CompiledStrings[surfaceTileWidth].init(surfaceTileWidth, &Words, 0, 0);
			if (this->HighestRowsByWidth[surfaceTileWidth] < this->CompiledStrings[surfaceTileWidth].Row.size())
			{
				this->HighestRowsByWidth[surfaceTileWidth] = this->CompiledStrings[surfaceTileWidth].Row.size();
			}
		}
		return this->HighestRowsByWidth[surfaceTileWidth];
	}

	std::string* RECT_STRING::getRow(int surfaceTileWidth, int rowIdx)
	{
		if (!this->CompiledStrings[surfaceTileWidth].Set)
		{
			this->CompiledStrings[surfaceTileWidth].init(surfaceTileWidth, &Words, 0, 0); 
			if (this->HighestRowsByWidth[surfaceTileWidth] < this->CompiledStrings[surfaceTileWidth].Row.size())
			{
				this->HighestRowsByWidth[surfaceTileWidth] = this->CompiledStrings[surfaceTileWidth].Row.size();
			}
		}
		return &CompiledStrings[surfaceTileWidth].Row[rowIdx];
	}


	COMPILED_STRINGS::COMPILED_STRINGS()
	{
		Set = false;
	}

	COMPILED_STRINGS::~COMPILED_STRINGS()
	{
	}

	int COMPILED_STRINGS::init(int surfaceTileWidth, std::vector<SINGULAR_WORD>* words
		, int paddingBegin, int paddingEnd)
	{
		this->SurfaceTileWidth = surfaceTileWidth;
		
		int curWord = 0;
		int curIdx = paddingBegin;
		std::string emptyString = std::string(surfaceTileWidth, ' ');
		std::string baseString = emptyString;
		bool baseStringHasBeenPushed = false;
		int useableSpace = surfaceTileWidth - (paddingBegin + paddingEnd);
		if (useableSpace <= 0)
		{
			return 0;
		}
		else if (useableSpace == 1)
		{
			//ToDo:Need to handle too-small strings
			for (int pix = 0; pix < words->size(); pix++)
			{
			}
		}	   
		//loop through all words
		for (int pix = 0; pix < words->size(); pix++)
		{
			//this is the beginning of a word
			//If we are not at idx = paddingBegin (the start of a row)
			// and the next wordtype is not punctuation then add a space
			if (curIdx != paddingBegin
				&& words->at(pix).WordType != WORD_TYPE::PUNCTUATION
				&& words->at(pix).WordType != WORD_TYPE::PUNCTUATION_NO_SPACE
				&& words->at(pix).WordType != WORD_TYPE::WORD_NO_SPACE
				&& words->at(pix).WordType != WORD_TYPE::NUMBER_NO_SPACE
				)
			{
				curIdx++;
			}
			if (curIdx > useableSpace)
			{
				Row.push_back(baseString);
				baseString = emptyString;
				curIdx = paddingBegin;
				baseStringHasBeenPushed = false;
				//subtract 1 from the index so we actually do this word!
				pix--;
			}
			else if (words->at(pix).Text.size() <= useableSpace - curIdx)
			{	 	
				baseStringHasBeenPushed = true;
				baseString.replace(curIdx, words->at(pix).Text.size(), words->at(pix).Text);
				curIdx += words->at(pix).Text.size();
			}
			else
			{
				if (words->at(pix).Text.size() < useableSpace)
				{
					//this row is done
					//move to the next line					
					Row.push_back(baseString);
					baseString = emptyString;
					curIdx = paddingBegin;
					baseStringHasBeenPushed = false;
					//subtract 1 from the index so we actually do this word!
					pix--;
				}
				else
				{	
					//handle this separately
					//chop up this word, I guess
					int lettersRemaining = words->at(pix).Text.size();
					bool wordFinished = false;
					while (lettersRemaining > 0)
					{
						int curWordIdx = words->at(pix).Text.size() - lettersRemaining;
						//reserve one space on the end for the dash
						int sizeToChop = (useableSpace - 1) - curIdx;
						if (sizeToChop > 0)
						{
							if (sizeToChop > lettersRemaining)
							{
								sizeToChop = lettersRemaining;
								wordFinished = true;
							}

							//replace with the substring
							baseString.replace(curIdx
								, sizeToChop
								, words->at(pix).Text.substr(curWordIdx, sizeToChop));

							lettersRemaining -= sizeToChop;
							curIdx += sizeToChop;
							if (!wordFinished)
							{
								baseString[curIdx] = '-';
								//go to the next row
								Row.push_back(baseString);
								baseString = emptyString;
								curIdx = paddingBegin;
								baseStringHasBeenPushed = false;
							}
						}
						else if (sizeToChop == 0 && useableSpace == 1)
						{
							sizeToChop = 1;

							if (sizeToChop > lettersRemaining)
							{
								sizeToChop = lettersRemaining;
								wordFinished = true;
							}
							baseString.replace(curIdx
								, sizeToChop
								, words->at(pix).Text.substr(curWordIdx, sizeToChop));

							lettersRemaining -= sizeToChop;
							curIdx += sizeToChop;

							if (!wordFinished)
							{
								//go to the next row
								Row.push_back(baseString);
								baseString = emptyString;
								curIdx = paddingBegin;
								baseStringHasBeenPushed = false;
							}
						}
						else
						{
							Row.push_back(baseString);
							baseString = emptyString;
							curIdx = paddingBegin;
						}
					}

				}
			}
		}
		//do we need to add another row?
		if (baseStringHasBeenPushed)
		{
			Row.push_back(baseString);
		}
		Set = true;
		return Row.size();
	}

}