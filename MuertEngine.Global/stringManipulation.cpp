#include "pch.h"
#include "stringManipulation.h"
#include <iomanip>
#include "nonLeakyRectangularString.h"

namespace s
{

	std::string stringToUppper(std::string inp)
	{

		const int length = inp.length();
		for (int i = 0; i != length; ++i)
		{
			inp[i] = std::toupper(inp[i]);
		}
		return inp;
	}
	int stringToInt(std::string inp)
	{

		int out = 0;
		std::stringstream stream;

		stream << inp;
		stream >> out;
		return out;

	}
	double stringTodouble(std::string inp)
	{
		double out;
		std::stringstream stream;

		stream << inp;
		stream >> out;

		//std::cout << "(" << inp << ":" << out << ")\n";

		return out;
	}

	bool stringContains(std::string s1, std::string s2)
	{
		if (s1.find(s2) != std::string::npos) {
			return true;
		}
		return false;
	}	  
	bool stringBeginsWith(std::string s1, std::string s2)
	{
		if (s1.rfind(s2, 0) == 0) { // pos=0 limits the search to the prefix
			return true;
		}
		return false;
	}

	//std::string stringToReversedRectangle_Alt(std::string inp, int numTilesWidth, int numTilesHeight, bool shouldOutline, bool hasEOL, char outlineCharacter, char eol)
	//{
	//	////Given an input:
	//	////"abcdefghijklmnopqrstuvwxyz"
	//	////and a width: (10)
	//	////flip the input, split on the width
	//	////resulting in:
	//	////uvwxyz    
	//	////klmnopqrst
	//	////abcdefghij
	//	int startingColumn = 0;
	//	int endingColumn = numTilesWidth-1;
	//	int startingRow = 0;
	//	int endingRow = numTilesHeight - 1;

	//	numTilesHeight-=2;
	//	numTilesWidth--;
	//	//numTilesWidth -= 2;

	//	if (numTilesWidth > inp.length())
	//	{
	//		return inp;
	//	}

	//	//ToDo: we need to handle things being too small
	//	if (shouldOutline && numTilesWidth >= 3 && numTilesHeight >= 3)
	//	{
	//		startingRow++;
	//		startingColumn++;
	//		endingRow--;
	//		endingColumn--;
	//	}

	//	//olive juice
	//	std::stringstream ttr;
	//	//first pad the end with spaces
	//	int totalTiles = numTilesWidth * numTilesHeight;
	//	int numTilesLeftOver = totalTiles - inp.length();
	//	int remainderTilesLeftOver = numTilesLeftOver % numTilesWidth;
	//	//do the first row, then do the rest in the loop
	//	//int endingCharacter = numTilesWidth - remainderTilesLeftOver;
	//	//int startingCharacter = 0;

	//	numTilesWidth--;
	//	

	//	int endingCharacter = inp.length()-1;
	//	int startingCharacter = endingCharacter - (numTilesWidth - remainderTilesLeftOver);
	//	
	//	std::string tempString = inp.substr(startingCharacter, endingCharacter);		
	//	//combine 
	//	ttr << std::string(numTilesLeftOver - remainderTilesLeftOver, ' ') 
	//		<< tempString << std::string(remainderTilesLeftOver, ' ')<< ' ';
	//	//ttr << std::string(remainderTilesLeftOver, ' ') << tempString;
	//	tempString = ttr.str();
	//	bool ended = false;
	//	for (int curRow = 1; !ended && curRow < numTilesHeight - 1; curRow++)
	//	{
	//		//startingCharacter = endingCharacter;
	//		//endingCharacter = startingCharacter + numTilesWidth;
	//		endingCharacter = startingCharacter;
	//		startingCharacter = startingCharacter - numTilesWidth;
	//		
	//		//if (endingCharacter >= inp.length())
	//		if(startingCharacter <= 0)
	//		{
	//			//endingCharacter = inp.length() - 1;
	//			startingCharacter = 0;
	//			ended = true;
	//		}
	//		ttr << inp.substr(startingCharacter, endingCharacter-startingCharacter) << ' ';
	//		tempString = ttr.str();
	//	}
	//	return tempString;
	//	
	//}



	std::string stringToReversedRectangle_Alt(std::string inp, int numTilesWidth, int numTilesHeight
		, bool shouldOutline, bool hasEOL
		, char outlineCharacter, char eol)
	{
		//numTilesWidth-=2;
		//numTilesHeight--;
		std::stringstream ttr;
		//for (int piy = 0; piy < numTilesHeight; piy++)
		//{
		//	for (int pix = 0; pix <= numTilesWidth; pix++)
		//	{
		//		if (pix == 0 
		//			|| (piy == 0 && pix <= numTilesWidth - 1) 
		//			|| pix == numTilesWidth 
		//			|| (piy == numTilesHeight-1 && pix <= numTilesWidth-1))
		//		{
		//			ttr << '#';
		//		}
		//		else 
		//		{
		//			ttr << ' ';
		//		}
		//	}
		//}
		//char cur = (char)0;
		for (int piy = 0; piy < numTilesHeight; piy++)
		{
			if (piy > 0 && piy < numTilesHeight-2 )
			{
				ttr << '#' << std::string(numTilesWidth - 2, ' ') << '#';
			}
			else
			{
				//for (int pix = 0; pix < numTilesWidth;pix++)
				//{
				//	ttr << cur;
				//	cur++;
				//}
				ttr << std::string(numTilesWidth , '#');
			}



		}
		return ttr.str();
	}

	std::string stringToReversedRectangle(std::string inp, int w, int h, bool hasEOL, char eol /*= '\n'*/)
	{												  
		////Given an input:
		////"abcdefghijklmnopqrstuvwxyz"
		////and a width: (10)
		////flip the input, split on the width
		////resulting in:
		////uvwxyz    
		////klmnopqrst
		////abcdefghij

		////"uvwxyz    klmnopqrstabcdefghij"

		//std::string inpp = "abcdefghijklmnopqrstuvwxyz";
		//int width = 10;
		//std::string result = "";
		////add one to numRows so we have at least one
		//int numRows = (inpp.length() / width) + 1;
		//for (int pix = 0; pix < numRows; pix++)
		//{
		//	int startLoc = (numRows - (pix + 1)) * width;
		//	int endLoc = ((numRows - (pix + 1)) * width) + width;
		//	
		//	if (endLoc > inpp.length())
		//	{
		//		endLoc = inpp.length();
		//	}
		//	int distToEnd = endLoc - startLoc;
		//	result +=
		//		inpp.substr(startLoc, distToEnd);
		//	if (distToEnd < width)
		//	{
		//		result += std::string((width - distToEnd), ' ');
		//	}
		//}
		//std::string result2 = result;
		if (w <= 1 || h <= 0)
		{
			return "";
		}
		//ToDo: this is not used, remove it
		int newW = w + 1;
		//The desired width
		int width = w;
		//If the width is not already less then our max length then start processing. Else return
		if (inp.length() > w)
		{
			//How many rows will we need to generate? 
			//Lets generate 1 extra row, past what we need to fit everything. (But why?)
			int numRows = (inp.length() / width) + 1;
			if (numRows <= h)
			{
				//fill empty lower rows with spaces
				//toReturn will be the string we return
				//we make the string w * h but subtract any rows over h height
				std::string toReturn(w*(h - (numRows > h ? 0 : numRows)), ' ');
				//add one more row of empty space to handle the additional row of data off-screen
				toReturn +=
					std::string(w, ' ');

				//Provide some padding for the off-screen column
				width--;

				//loop through each row and transpose the string
				for (int pix = 0; pix < numRows; pix++)
				{
					int startLoc = (numRows - (pix + 1)) * width;
					int endLoc = ((numRows - (pix + 1)) * width) + width;

					if (endLoc > inp.length())
					{
						endLoc = inp.length();
					}
					int distToEnd = endLoc - startLoc;
					toReturn +=
						inp.substr(startLoc, distToEnd);
					//if this is the last character and we are not yet to the end of the row add some padding
					if (distToEnd < width)
					{
						toReturn += std::string((width - distToEnd), ' ');
					}
					toReturn += ' ';
				}
				return toReturn;
			}
			else
			{
				//fill empty lower rows with spaces
				std::string toReturn = "";
				//(w*(h - (numRows > h ? 0 : numRows)), ' ');
				//add one more row of empty space to handle the additional row of data off-screen
				toReturn +=
					std::string(w, ' ');

				//Provide some padding for the off-screen column
				width--;

				int pix = (numRows ) - h;

				//loop through each row and transpose the string
				for (; pix < numRows; pix++)
				{
					int startLoc = (numRows - (pix + 1)) * width;
					int endLoc = ((numRows - (pix + 1)) * width) + width;

					if (endLoc > inp.length())
					{
						endLoc = inp.length();
					}
					int distToEnd = endLoc - startLoc;
					toReturn +=
						inp.substr(startLoc, distToEnd);
					if (distToEnd < width)
					{
						toReturn += std::string((width - distToEnd), ' ');
					}
					toReturn += ' ';
				}
				return toReturn;
			}
			
		}
		else
		{
			//this fits on one line.
			//make the string the entire space - row
			std::string toReturn(w*(h - 1), ' ');
			toReturn += inp + std::string(w - inp.length(), ' ');
			return toReturn;
		}							
	}


	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			*(result++) = item;
		}
	}

	std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, std::back_inserter(elems));
		return elems;
	}

	std::vector<std::vector<int>> CenterWords(std::string testInput, int maxWidth, int frontPad, int backPad)
	{
		std::vector<std::string> splitWords = split(testInput, ' ');

		std::vector<std::vector<int>> finalOutput;
		bool stringFinished = false;
		while (!stringFinished)
		{
			int numSpacesUsed = 0;
			int numWordsClaimed = 0;
			std::string toIns = "";
			for (int pix = 0; pix < splitWords.size(); pix++)
			{
				if (numWordsClaimed == 0 && splitWords[pix].length() >= maxWidth)
				{
					//this word is longer then the width
					toIns = splitWords[pix].substr(0, maxWidth);
					numSpacesUsed = 0;
					numWordsClaimed = 0;
					std::vector<int> toInsInt;
					toInsInt.push_back(frontPad);
					for (int piz = 0; piz < toIns.length(); piz++)
					{
						toInsInt.push_back(toIns[piz]);
					}
					toInsInt.push_back(backPad);
					finalOutput.push_back(toInsInt);
					//finalOutput.push_back(frontPad + toIns + backPad);
					toIns = "";
					splitWords[pix] = splitWords[pix].substr(maxWidth, splitWords[pix].length() - (maxWidth));
					pix--;
				}
				else if (numSpacesUsed + splitWords[pix].length() + (numWordsClaimed > 0 ? 1 : 0) > maxWidth)
				{
					//too long
					if (numWordsClaimed == 0)
					{
						//split this word
						for (int piy = 0; piy < maxWidth; piy++)
						{
							toIns += splitWords[pix][piy];
							numSpacesUsed = 0;
							numWordsClaimed = 0;
							toIns = "";
						}
					}
					else
					{
						//grab the past numWordsClaimed words
						int numSpacesRemaining = maxWidth;
						while (numWordsClaimed > 0)
						{
							for (int piy = 0; piy < numWordsClaimed; piy++)
							{
								toIns += splitWords[pix - numWordsClaimed];
								numSpacesRemaining -= splitWords[pix - numWordsClaimed].length();
								numWordsClaimed--;
								if (numWordsClaimed > 0)
								{
									toIns += ' ';
									numSpacesRemaining--;
								}
							}
						}
						while (numSpacesRemaining / 2 > 0)
						{
							toIns = " " + toIns + " ";
							numSpacesRemaining -= 2;
						}
						if (numSpacesRemaining == 1)
						{
							toIns = toIns + " ";
						}
						std::vector<int> toInsInt;
						toInsInt.push_back(frontPad);
						for (int piz = 0; piz < toIns.length(); piz++)
						{
							toInsInt.push_back(toIns[piz]);
						}
						toInsInt.push_back(backPad);
						finalOutput.push_back(toInsInt);
						//finalOutput.push_back(frontPad + toIns + backPad);
						numSpacesUsed = 0;
						numWordsClaimed = 0;
						toIns = "";
						pix--;
					}
				}
				else
				{
					//use this word
					numSpacesUsed += splitWords[pix].length() + (numWordsClaimed > 0 ? 1 : 0);
					numWordsClaimed++;
				}
			}
			if (numWordsClaimed > 0)
			{
				int numSpacesRemaining = maxWidth;
				while (numWordsClaimed > 0)
				{
					for (int piy = 0; piy < numWordsClaimed; piy++)
					{
						toIns += splitWords[splitWords.size() - numWordsClaimed];
						numSpacesRemaining -= splitWords[splitWords.size() - numWordsClaimed].length();
						numWordsClaimed--;
						if (numWordsClaimed > 0)
						{
							toIns += ' ';
							numSpacesRemaining--;
						}
					}
				}
				while (numSpacesRemaining / 2 > 0)
				{
					toIns = " " + toIns + " ";
					numSpacesRemaining -= 2;
				}
				if (numSpacesRemaining == 1)
				{
					toIns = toIns + " ";
				}
				std::vector<int> toInsInt;
				toInsInt.push_back(frontPad);
				for (int piz = 0; piz < toIns.length(); piz++)
				{
					toInsInt.push_back(toIns[piz]);
				}
				toInsInt.push_back(backPad);
				finalOutput.push_back(toInsInt);
				//finalOutput.push_back(frontPad + toIns + backPad);
			}
			stringFinished = true;
		}
		return finalOutput;
	}

	void ConvertIntToReadbleString(int curi, int w, std::string &toSet)
	{
		std::stringstream tmp;
		if (curi >= 0)
		{
			if (w >= 6)
			{
				//0.52352					
				tmp << curi;
				toSet = tmp.str();
			}
			else if (w >= 4 && curi > 999)
			{
				curi = curi > 99999 && curi <= 999999 ?
					(curi * .001) :
					curi > 9999 && curi <= 99999 ?
					(curi * .01) :
					curi <= 9999 ?
					(curi) : curi;
				tmp << std::setprecision(4) << std::fixed << curi << "k";
				toSet = tmp.str();
			}
			else if (w >= 4)
			{
				tmp << curi;
				toSet = tmp.str();
			}
			//else if (w >= 5)
			//{
			//	tmp << std::setprecision(3) << std::fixed << curi;
			//	toSet = tmp.str();
			//}
			//else if (w >= 4)
			//{
			//	tmp << std::setprecision(2) << std::fixed << curi;
			//	toSet = tmp.str();
			//}
		}
		else
		{
			//negative
			if (w >= 7)
			{
				//0.52352					
				tmp << curi;
				toSet = tmp.str();
			}
			else if (w >= 5 && curi < -999)
			{
				curi = curi < -99999 && curi >= -999999 ?
					(curi * .001) :
					curi < -9999 && curi >= -99999 ?
					(curi * .01) :
					curi >= -9999 ?
					(curi) : curi;
				tmp << std::setprecision(4) << std::fixed << curi << "k";
				toSet = tmp.str();
			}
			else if (w >= 5)
			{
				tmp << curi;
				toSet = tmp.str();
			}
		}
	}
	void ConvertDoubleToReadableString(double curd, int w, std::string &toSet)
	{
		std::stringstream tmp;
		if (curd >= 0)
		{
			if (w >= 7)
			{
				//0.52352					
				tmp << std::setprecision(5) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 6)
			{
				tmp << std::setprecision(4) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 5)
			{
				tmp << std::setprecision(3) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 4)
			{
				tmp << std::setprecision(2) << std::fixed << curd;
				toSet = tmp.str();
			}
		}
		else
		{
			//negative
			if (w >= 8)
			{
				//0.52352					
				tmp << std::setprecision(5) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 7)
			{
				tmp << std::setprecision(4) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 6)
			{
				tmp << std::setprecision(3) << std::fixed << curd;
				toSet = tmp.str();
			}
			else if (w >= 5)
			{
				tmp << std::setprecision(2) << std::fixed << curd;
				toSet = tmp.str();
			}
		}
	}

	void WordifyText(std::string Text, COMM::RECT_STRING& RctString)
	{
		bool nextIsNoSpace = false;

		int curChar = 0;
		int curWordIndex = 0;
		std::string curWord = "";
		while (curChar < Text.size())
		{
			if (Text[curChar] == '-')
			{
				nextIsNoSpace = true;
				if (RctString.Words.size() <= curWordIndex)
				{
					RctString.Words.push_back(COMM::SINGULAR_WORD("-"
						, COMM::WORD_TYPE::WORD_NO_SPACE));
				}
				else
				{
					RctString.Words[curWordIndex] = COMM::SINGULAR_WORD("-"
						, COMM::WORD_TYPE::WORD_NO_SPACE);
				}
				curWordIndex++;
				curChar++;
				curWord = "";
			}
			while (Text[curChar] != ' '
				&& Text[curChar] != '-'
				&& curChar < Text.size())
			{
				curWord += Text[curChar];
				curChar++;
			}
			if (curWord == "" && Text[curChar] == ' ')
			{
				curChar++;
			}
			if (curWord != "")
			{
				if (RctString.Words.size() <= curWordIndex)
				{
					RctString.Words.push_back(COMM::SINGULAR_WORD(curWord
						, nextIsNoSpace ? COMM::WORD_TYPE::WORD_NO_SPACE : COMM::WORD_TYPE::WORD));
				}
				else
				{
					RctString.Words[curWordIndex] = COMM::SINGULAR_WORD(curWord
						, nextIsNoSpace ? COMM::WORD_TYPE::WORD_NO_SPACE : COMM::WORD_TYPE::WORD);
				}
				nextIsNoSpace = false;
				if (Text[curChar] != '-')
				{
					curChar++;
				}
				curWordIndex++;
				curWord = "";
			}
		}
		//now clear the RectString.Words down to curWordIndex size
		if (RctString.Words.size() > curWordIndex)
		{
			RctString.Words.resize(curWordIndex);
		}
	}

	void padTo(std::string& str, size_t num, char paddingChar /*= '\0'*/)
	{
		str.append(num - str.length() % num, paddingChar);
	}

	void unpad(std::string& str, char paddingChar /*= '\0'*/)
	{
		size_t n = str.length();
		while (n != 0 && str[n - 1] == paddingChar)
			n--;
		str.resize(n);
	}

}

