#include "pch.h"
#include "rectangularStrings.h"


namespace COMM
{






	//WORD_TYPE::SINGULAR_WORD()
	//{

	//}

	//WORD_TYPE::SINGULAR_WORD(std::string text, WORD_TYPE wordType)
	//{
	//	this->Text = text;
	//	this->WordType = wordType;
	//}

	//WORD_TYPE::~SINGULAR_WORD()
	//{

	//}

	//SINGULAR_STRING::SINGULAR_STRING()
	//{

	//}

	//SINGULAR_STRING::~SINGULAR_STRING()
	//{

	//}

	////parse the string toIns into multiple SINGULAR_WORDs
	//void SINGULAR_STRING::insertNewSingularString(std::string toIns, WORD_TYPE wordType)
	//{
	//	this->SingularWords.push_back(new SINGULAR_WORD(toIns,wordType));		
	//}

	//void SINGULAR_STRING::parseText()
	//{
	//	this->Text = "";
	//	for (int pix = 0; pix < this->SingularWords.size(); pix++)
	//	{
	//		if (pix > 0) {
	//			this->Text += " ";
	//		}
	//		this->Text += this->SingularWords[pix]->Text;
	//	}
	//}



	//SINGULAR_STRING_KEYVALUE::SINGULAR_STRING_KEYVALUE()
	//{

	//}

	//SINGULAR_STRING_KEYVALUE::~SINGULAR_STRING_KEYVALUE()
	//{

	//}

	//RECTANGULAR_STRING::RECTANGULAR_STRING()
	//{
	//	resetSingularStrings(1, 1, false, true, true);

	//}

	//RECTANGULAR_STRING::~RECTANGULAR_STRING()
	//{

	//}

	//int RECTANGULAR_STRING::getOutlineCharacter(int xpos, int ypos)
	//{
	//	return 1;
	//}

	//void RECTANGULAR_STRING::compileRectangularStringOutput()
	//{
	//	//insert top outline
	//	compiledRectangularStringOutput = "";
	//	int curSingularString = 0;
	//	int curSingularWord = 0;
	//	int curCharacter = 0;


	//	for (int piy = 0; piy < this->NumCharactersY; piy++)
	//	{
	//		if (piy > 0 && piy < this->NumCharactersY - 1)
	//		{
	//			//ttr << '#' << std::string(numTilesWidth - 2, ' ') << '#';
	//			//compiledOutput += 
	//			if (curSingularString < this->SingularStrings.size())
	//			{
	//				curSingularWord = 0;
	//				compiledRectangularStringOutput += "#";
	//				curCharacter++;
	//				for (int pix = 0; pix < this->SingularStrings[curSingularString]->SingularWords.size(); pix++)
	//				{
	//					if (this->SingularStrings[curSingularString]->SingularWords[pix]->Text.size() + curCharacter 
	//						>= this->NumCharactersX )
	//					{
	//						//this word goes to the next line
	//						int toPush = this->NumCharactersX - curCharacter;
	//						compiledRectangularStringOutput += std::string(" ", toPush);
	//						compiledRectangularStringOutput += "##";
	//						piy++;
	//						curCharacter = 1;
	//						//can we add the word to the next line?
	//						if (this->SingularStrings[curSingularString]->SingularWords[pix]->Text.size() + curCharacter 
	//							>= this->NumCharactersX - 1)
	//						{
	//							

	//						}
	//						else 
	//						{
	//							compiledRectangularStringOutput += this->SingularStrings[curSingularString]->SingularWords[pix]->Text;
	//							curCharacter += this->SingularStrings[curSingularString]->SingularWords[pix]->Text.size();
	//						}
	//					}
	//					else
	//					{
	//						if (curCharacter > 1)
	//						{
	//							compiledRectangularStringOutput += " ";
	//							curCharacter++;
	//						}
	//						//add it
	//						compiledRectangularStringOutput += this->SingularStrings[curSingularString]->SingularWords[pix]->Text;
	//						curCharacter += this->SingularStrings[curSingularString]->SingularWords[pix]->Text.size();
	//					}
	//				}	  
	//				compiledRectangularStringOutput += std::string((this->NumCharactersX) - curCharacter, ' ') + '#';
	//				curSingularString++;
	//				curCharacter = 0;
	//			}
	//			else
	//			{
	//				//insert spaces
	//				compiledRectangularStringOutput += '#' + std::string(this->NumCharactersX - 1, ' ') + '#';
	//			}

	//		}
	//		else
	//		{
	//			//for (int pix = 0; pix < numTilesWidth;pix++)
	//			//{
	//			//	ttr << cur;
	//			//	cur++;
	//			//}
	//			//ttr << std::string(numTilesWidth, '#');
	//			compiledRectangularStringOutput += std::string(NumCharactersX+1, '#');
	//		}
	//	}


	//}

	//void RECTANGULAR_STRING::resetSingularStrings(int numTilesX, int numTilesY, bool doesHaveOutline, bool dontSplitStrings, bool dontSplitWords)
	//{
	//	this->DoesHaveOutline = doesHaveOutline;
	//	this->DontSplitStrings = dontSplitStrings;
	//	this->DontSplitWords = dontSplitWords;

	//	this->NumCharactersX = numTilesX;
	//	this->NumCharactersY = numTilesY;
	//	this->NumCharacters = numTilesX*numTilesY;

	//	this->SingularStrings.clear();
	//}

	//int RECTANGULAR_STRING::getNumberOfCharacters()
	//{
	//	return 1;
	//}

	//int RECTANGULAR_STRING::getNumberOfSingularWords()
	//{
	//	return 1;
	//}

	//int RECTANGULAR_STRING::getNumberOfSingularStrings()
	//{
	//	return 1;
	//}			

	//char RECTANGULAR_STRING::obtainCharacterByPosition(int pos)
	//{
	//	return 'a';
	//}

	//COMM::SINGULAR_WORD* RECTANGULAR_STRING::obtainSingularWordByPosition(int pos)
	//{
	//	return nullptr;
	//}

	//COMM::SINGULAR_STRING* RECTANGULAR_STRING::obtainSingularStringByPosition(int pos)
	//{
	//	return nullptr;
	//}






	SINGULAR_WORD::SINGULAR_WORD()
	{
	}

	SINGULAR_WORD::SINGULAR_WORD(std::string text, WORD_TYPE wordType)
	{
		this->Text = text;
		this->WordType = wordType;
	}

	SINGULAR_WORD::~SINGULAR_WORD()
	{	  
	}

	SINGULAR_STRING::SINGULAR_STRING()
	{
	}

	SINGULAR_STRING::~SINGULAR_STRING()
	{
		for (auto it = this->SingularWords.cbegin(); it != this->SingularWords.cend(); ++it)
		{
			delete* it;
		}
		//this->SingularWords.clear();
		std::vector<COMM::SINGULAR_WORD*>().swap(this->SingularWords);

	}

	void SINGULAR_STRING::insertNewSingularString(std::string toIns, WORD_TYPE wordType)
	{
		this->SingularWords.push_back(new SINGULAR_WORD(toIns, wordType));

	}

	void SINGULAR_STRING::parseText()
	{
		this->Text = "";
		for (int pix = 0; pix < this->SingularWords.size(); pix++)
		{
			if (pix > 0 && this->SingularWords[pix]->WordType != WORD_TYPE::PUNCTUATION)
			{
				this->Text += " ";
			}
			this->Text += this->SingularWords[pix]->Text;
		}
	}

	void SINGULAR_STRING::parseRectangularText(int curWidth, int curHeight, std::vector<std::string>& rectangularLines)
	{
		//ToDo: Rename RectangularWords to RectangularLines
		RectangularWords.clear();
		std::string toIns = "";
		std::string subToIns = "";

		bool finishedPostingWords = false;
		int currentWordCharacterIndex = 0;
		int currentCharacterIndex = 0;
		int currentLine = 0;
		//loop around.
		for (int curWord = 0; curWord < this->SingularWords.size(); curWord++)
		{
			//		Go to next word
			//			set currentWordCharacterIndex = 0
			currentWordCharacterIndex = 0;
			//is this word a punctuation? or is this the last character in the line?
			if (curWord == 0
				|| this->SingularWords[curWord]->WordType == WORD_TYPE::PUNCTUATION
				|| currentCharacterIndex == curWidth)
			{
				//don't add a space
			}
			else
			{
				//else
				//add a space
				subToIns += ' ';
				currentCharacterIndex++;
			}

			//Is the length of this word (word.length - currentWordCharacterIndex) longer than (lineWidth - currentCharacterIndex)?
			if ((this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex) 
				> (curWidth - currentCharacterIndex))
			{
				bool currentWordHasBeenPosted = false;
				//Yes:
				//		Loop this until the current word has been posted
				while (!currentWordHasBeenPosted)
				{

					if ((this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex) 
						< (curWidth - currentCharacterIndex))
					{
						//post the rest of the word
						subToIns += this->SingularWords[curWord]->Text.substr(currentWordCharacterIndex
							, (this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex));
						currentWordHasBeenPosted = true;
						//			set currentCharacterIndex = 0
						currentCharacterIndex += (this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex);



						//			set currentWordCharacterIndex += (lineWidth - currentCharacterIndex) - 1
						currentWordCharacterIndex = 0;
						//			set currentLine += 1
						//currentLine += 1;
					}
					else
					{
						//		Is the currentCharacterIndex = 0 Or
						//			Is the (word.length - currentWordCharacterIndex) > lineWidth && (linewidth - currentCharacterIndex) > 3
						if (currentCharacterIndex == 0 ||
							(
								//(this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex) > curWidth && 
							(curWidth - currentCharacterIndex) > 3)
							)
						{
							//		Yes:
							//			Cut up the word and post the currentWordCharacterIndex for length ((lineWidth - currentCharacterIndex) - 1)
							if ((this->SingularWords[curWord]->Text.length() - currentWordCharacterIndex) 
								< (curWidth - currentCharacterIndex) - 1)
							{
								subToIns += this->SingularWords[curWord]->Text.substr(currentWordCharacterIndex, (this->SingularWords[curWord]->Text.length() - currentCharacterIndex));
								currentWordHasBeenPosted = true;
								currentWordCharacterIndex = 0;
							}
							else
							{
								subToIns += this->SingularWords[curWord]->Text.substr(currentWordCharacterIndex, (curWidth - currentCharacterIndex) - 1);
								//			Add a "-"
								subToIns += "-";
								//			set currentWordCharacterIndex += (lineWidth - currentCharacterIndex) - 1
								currentWordCharacterIndex += (curWidth - currentCharacterIndex) - 1;
							}
							//			set currentCharacterIndex = 0
							currentCharacterIndex = 0;
							//			set currentLine += 1
							currentLine += 1;
							toIns += subToIns;
							RectangularWords.push_back(subToIns);
							(&rectangularLines)->push_back(subToIns);
							subToIns = "";
							//	
						}
						else
						{
							//		No:
							//			Try to put the word on a new line
							//				Fill the remaining current line with (lineWidth - currentCharacterIndex) of spaces
							subToIns += std::string((curWidth - currentCharacterIndex), ' ');
							//				set currentCharacterIndex = 0
							currentCharacterIndex = 0;
							//				set currentLine += 1
							currentLine += 1;
							toIns += subToIns;
							RectangularWords.push_back(subToIns);
							(&rectangularLines)->push_back(subToIns);
							subToIns = "";
							//Loop

						}
					}
				}
			}
			else
			{
				//No: 
				//		Insert the word
				subToIns += this->SingularWords[curWord]->Text;
				//		Set currentCharacterIndex += word.length
				currentCharacterIndex += this->SingularWords[curWord]->Text.length();
				//		Go to next word
				//			set currentWordCharacterIndex = 0

			}
		}
		//when done with the words, fill the remaining (lineWidth - currentCharacterIndex) with " "
		subToIns += std::string(curWidth - currentCharacterIndex, ' ');
		toIns += subToIns;
		RectangularWords.push_back(subToIns);
		(&rectangularLines)->push_back(subToIns);
		subToIns = "";


		this->ParsedRectangularWords = toIns;



		//RectangularWords.clear();

		//std::string toIns = "";
		//int thisLineWidth = 0;
		////this->Text = "";
		//for (int pix = 0; pix < this->SingularWords.size(); pix++)
		//{
		//	if (pix > 0 
		//		&& thisLineWidth != 0
		//		&& thisLineWidth + 1 <= curWidth
		//		&& this->SingularWords[pix]->WordType != WORD_TYPE::PUNCTUATION) {
		//		toIns += " ";
		//		thisLineWidth++;
		//	}
		//	if (thisLineWidth >= curWidth)
		//	{
		//		thisLineWidth = 0;
		//	}
		//	int curLen = (this->SingularWords[pix])->Text.length();
		//	if (thisLineWidth > 0 && thisLineWidth + curLen < curWidth)
		//	{
		//		toIns += this->SingularWords[pix]->Text;
		//		thisLineWidth += this->SingularWords[pix]->Text.length();
		//	}
		//	else if (thisLineWidth == 0)
		//	{
		//		//the word is bigger than the whole line!!!
		//		int lastSubWordIndex = 0;
		//		while (thisLineWidth == 0)
		//		{
		//			if (thisLineWidth + this->SingularWords[pix]->Text.substr(lastSubWordIndex).length() > curWidth)
		//			{
		//				toIns += this->SingularWords[pix]->Text.substr(lastSubWordIndex, curWidth - 1);
		//				lastSubWordIndex = curWidth - 1;
		//				thisLineWidth = 0;
		//			}
		//			else
		//			{
		//				toIns += this->SingularWords[pix]->Text.substr(lastSubWordIndex, curWidth - 1);
		//				thisLineWidth = (this->SingularWords[pix]->Text.substr(lastSubWordIndex, curWidth - 1)).length();
		//			}	  
		//		}																   
		//	}
		//	else
		//	{
		//		//fill in the rest with spaces
		//		toIns += std::string((curWidth)-(thisLineWidth),' ');
		//		thisLineWidth = 0;
		//	}
		//}

		////fill in the rest with spaces
		//toIns += std::string(((curWidth) - thisLineWidth),' ');
		//thisLineWidth = 0;
		//this->ParsedRectangularWords = toIns;

	}

	SINGULAR_STRING_WRAPPER::SINGULAR_STRING_WRAPPER()
	{
		this->IsLoaded = true;
		this->WrapperId = 0;
		this->SingularString = new SINGULAR_STRING();
	}

	SINGULAR_STRING_WRAPPER::~SINGULAR_STRING_WRAPPER()
	{				   				
		if (SingularString != nullptr)
		{
			for (auto it = this->SingularString->SingularWords.cbegin(); it != this->SingularString->SingularWords.cend(); ++it)
			{
				delete* it;
			}
			std::vector<COMM::SINGULAR_WORD*>().swap(this->SingularString->SingularWords);
		}		
		//this->SingularString->SingularWords.clear();
	}

	SINGULAR_STRING_QUEUE::SINGULAR_STRING_QUEUE()
	{
		this->CurrentIndex = 0;
		this->CurrentSubIndex = 0;
	}

	SINGULAR_STRING_QUEUE::~SINGULAR_STRING_QUEUE()
	{
		for (auto it = SingularStrings.cbegin(); it != SingularStrings.cend(); ++it)
		{
			for (auto itp = (*(it))->SingularString->SingularWords.cbegin()
				; itp != (*(it))->SingularString->SingularWords.cend(); ++itp)
			{
				delete *itp;
			}
			std::vector<COMM::SINGULAR_WORD*>().swap((*(it))->SingularString->SingularWords);
			//(*(it))->SingularString->SingularWords.clear();
			delete((*(it))->SingularString);
		}
	}

	int SINGULAR_STRING_QUEUE::pushNewSingularString()
	{
		this->SingularStrings.push_back(new SINGULAR_STRING_WRAPPER());
		return this->SingularStrings.size() - 1;
	}

	void SINGULAR_STRING_QUEUE::unloadChunk(int startIndex, int endIndex)
	{
	}

	void SINGULAR_STRING_QUEUE::loadChunk(int startIndex, int endIndex)
	{
	}

	//loop around.
	//Is the length of this word (word.length - currentWordCharacterIndex) longer than (lineWidth - currentCharacterIndex)?
	//No: 
	//		Insert the word
	//		Set currentCharacterIndex += word.length
	//
	//		Go to next word
	//			set currentWordCharacterIndex = 0
	//Yes:
	//		Loop this until the current word has been posted
	//		Is the currentCharacterIndex = 0 Or
	//			Is the (word.length - currentWordCharacterIndex) > lineWidth && (linewidth - currentCharacterIndex) > 3
	//		No:
	//			Try to put the word on a new line
	//				Fill the remaining current line with (lineWidth - currentCharacterIndex) of spaces
	//				set currentCharacterIndex = 0
	//				set currentLine += 1
	//				Loop
	//		Yes:
	//			Cut up the word and post the currentWordCharacterIndex for length ((lineWidth - currentCharacterIndex) - 1)
	//			Add a "-"
	//			set currentWordCharacterIndex += (lineWidth - currentCharacterIndex) - 1
	//			set currentCharacterIndex = 0
	//			set currentLine += 1
	//	
	//when done with the words, fill the remaining (lineWidth - currentCharacterIndex) with " "

	void SINGULAR_STRING_QUEUE::generateRectangularText(int curWidth, int curHeight)
	{
		RectangularLines.clear();
		//use the currentIndex, currentSubIndex
		CurWidth = curWidth;
		CurHeight = curHeight;
		//now generate!

		//parse the [CurrentIndex] SingularString
		//the first line is the line that includes the [CurrentSubIndex] SingularWord
		std::vector<COMM::SINGULAR_STRING_WRAPPER*>::iterator itr = SingularStrings.begin();
		for (; itr != SingularStrings.end(); itr++)
		{
			(*itr)->SingularString->parseRectangularText(curWidth, curHeight, RectangularLines);
			this->RectangularText += (*itr)->SingularString->ParsedRectangularWords;
		}
	}

	void SINGULAR_STRING_QUEUE::generateRectangularText(int curWidth, int curHeight, int currentIndex, int currentSubIndex)
	{
		CurrentIndex = currentIndex;
		CurrentSubIndex = currentSubIndex;
		generateRectangularText(curWidth, curHeight);
	}
}


