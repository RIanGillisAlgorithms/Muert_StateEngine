#include "pch.h"
#include "markover.h"
#include "RandomWrapper.h"
#include <sstream>
									  
//CHAR_LIST_OBJ_3 markov[20];

//MTRand mtrandW;

//WORD_STATS_OBJECT::WORD_STATS_OBJECT()
//{
//	//126 is start word
//	//127 is end word
//	this->dimensionsLeft = 0;
//	//for(int pip = 32; pip < 128; pip++)
//	//{
//	//	stat[pip] = 0.0;
//	//}
//}
//WORD_STATS_OBJECT::~WORD_STATS_OBJECT()
//{
//
//}
CHAR_LIST_OBJ_3::CHAR_LIST_OBJ_3()
{
	initialized = false;
	this->totalDimensions = 0;
	this->clearCharStat();

}
CHAR_LIST_OBJ_3::~CHAR_LIST_OBJ_3()
{

}
bool CHAR_LIST_OBJ_3::initMem(int Index)
{
	//if we have already been loaded then continue, else we need to attempt to load the [Index].txt file

	return false;
}
void CHAR_LIST_OBJ_3::clearCharStat()
{

	int pipX, pipY, pipZ;

	beginCount = 0;


	for(int pipX = 0; pipX < 128; pipX++)
	{

			beginStat[pipX] = 0.0;

	}

	for(pipX = 0; pipX < 128; pipX++)
	{
		for(pipY = 0; pipY < 128; pipY++)
		{
			charCount[pipX][pipY] = 0;
			endCount[pipX][pipY] = 0;
		}
	}

	for(pipX = 0; pipX < 128; pipX++)
	{
		for(pipY = 0; pipY < 128; pipY++)
		{
			for(pipZ = 0; pipZ < 128; pipZ++)
			{
				charStat[pipX][pipY][pipZ] = 0.0;
				endStat[pipX][pipY][pipZ] = 0.0;
			}
		}
	}

}
void CHAR_LIST_OBJ_3::printCharStat()
{
	for(int pipX = 0; pipX < 128; pipX++)
	{
		for(int pipY = 0; pipY < 128; pipY++)
		{
			for(int pipZ = 0; pipZ < 128; pipZ++)
			{
				std::cout<<charStat[pipX][pipY][pipZ];
			}
		}
	}
}

bool CHAR_LIST_OBJ_3::readFile(char* fileName, int numDimensions)
{	  
	this->totalDimensions = numDimensions;
	

	//open the file!					  
	std::ifstream lider(fileName);

	std::stringstream ss;
	ss<< "dump_alph_" << fileName << ".txt";
	std::ofstream ouder(ss.str());

	//ok! start 
	std::string line = "";
	int stringLength= 0;
	int curLine = 0;
	int curDim = 0;

			
	bool ended = false;

	if (!lider.is_open())
	{
		return false;
	}
	while(!lider.eof())
	{
 		std::getline(lider,line);
		stringLength = line.size();

		if(stringLength <= 0 || (line[0] == '/' && line[1] == '/'))
		{
			//return false;
		}
		else
		{
			//do the beginning 
			//for(int pip = 0; pip < numDimensions; pip++)
			//{
				//this->charStat[126][line[0]][line[1]] += 1;
				//this->charCount[126][line[0]] += 1;
			//std::cout<<"beginning: '"<<line[0]<<"'\n";
			ouder<<"beginning: '"<<line[0]<<"'\n";
				beginStat[line[0]] += 1;
				beginCount += 1;

				//std::cout<<"begin + count now: "<<beginCount<<"\n";
				ouder<<"begin + count now: "<<beginCount<<"\n";


				//std::cout<<"adding: 126,'"<<line[0]<<"','"<<line[1]<<"'\n";
				ouder<<"adding: 126,'"<<line[0]<<"','"<<line[1]<<"'\n";
				this->charStat[126][line[0]][line[1]] += 1;	

				this->charCount[126][line[0]] += 1;
				//std::cout<<"count now: "<<charCount[126][line[0]]<<"\n";
				ouder<<"count now: "<<charCount[126][line[0]]<<"\n";



			//}
			
			//go through this
			

			ended = false;
			int pip;
			for(pip = 0;!ended && pip < stringLength - 3 ; pip++)
			{
				if(pip + 3 > stringLength || (line[pip+2] == 127 || line[pip+2] == 33 || line[pip+2] <= 0))
				{
					//this->charStat[(int)line[pip]][(int)line[pip+1]][(int)line[pip+2]] += 1;	
					//ouder<<"adding: '"<<line[pip]<<"','"<<line[pip+1]<<"','"<<line[pip+2]<<"'\n";
					//this->charCount[(int)line[pip]][(int)line[pip+1]] += 1;
					//ouder<<"count now: "<<this->charCount[(int)line[pip]][(int)line[pip+1]]<<"\n";
					ended = true;
				}
				else
				{
					this->charStat[(int)line[pip]][(int)line[pip+1]][(int)line[pip+2]] += 1;	
					ouder<<"adding: '"<<line[pip]<<"','"<<line[pip+1]<<"','"<<line[pip+2]<<"'\n";
					this->charCount[(int)line[pip]][(int)line[pip+1]] += 1;
					ouder<<"count now: "<<this->charCount[(int)line[pip]][(int)line[pip+1]]<<"\n";
				}
			}
			//if we have done any processing, move to the next letter
			//if not, this is a two-letter word, so we should staty where we are
			if (pip > 0)
			{
				pip++;
			}
			//do ending!
			int first = line[pip];
			int second = line[pip + 1];
			if(this->charStat[first][second][127] <= 0)
			{
				ouder<<"adding: '"<<line[pip]<<"','"<<line[pip+1]<<"','127'\n";
				this->charStat[(int)line[pip]][(int)line[pip+1]][127] = 1;
				this->charCount[(int)line[pip]][(int)line[pip+1]] += 1;
				ouder<<"count now: "<<this->charCount[(int)line[pip]][(int)line[pip+1]]<<"\n";

			}
					//this->charStat[(int)line[pip]][(int)line[pip+1]][127] += 1;	
					//ouder<<"adding: '"<<line[pip]<<"','"<<line[pip+1]<<"','127'\n";
					//this->charCount[(int)line[pip]][(int)line[pip+1]] += 1;
					//ouder<<"count now: "<<this->charCount[(int)line[pip]][(int)line[pip+1]]<<"\n";

			


//			//convert all lowercase letters to uppercase - 
//			//line = stringToUppper(line);
//
//			//ok - switch through your various config file schemes at this point
//
//			if(line == "[ELEMENT_INFO]")
//			{
///////////////////////////////////////////////////CONFIG//////////////////
//				//////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///////////////////////////////////////////////////////////////////////////
//				//config!!!
//
//				while(!lider.eof())
//				{
//					std::getline(lider,line);
//					stringLength = line.size();
//
//					if(stringLength > 0 && line[0] == '[')
//					{
//						//split!
//						startPos = 1;
//						endPos = line.find(":",0);
//						if(endPos == -1 || endPos == 0)
//						{
//							return -1;
//						}
//						else
//						{
//							ended = false;
//						
//							subLineA = line.substr(1,(endPos - startPos));
//
//							num = stringToInt(subLineA);
//
//							//do this num!
//							
//							
//
//							//element_data[num].num = num;
//
//							
//							startPos = endPos + 1;
//							endPos = line.find(":",startPos);
//							subLineB = line.substr(startPos,endPos - startPos);
//
//
//
//							element_data[subLineB].name = subLineB;
//							num_element.push_back(subLineB);
//
//							while(line[0] != ']')
//							{
//								
//								std::getline(lider,line);
//								stringLength = line.size();	
//
//								if(line[0] == '[')
//								{
//									startPos = 1;
//									endPos = line.find(":",0);	
//									subLineA = line.substr(1,(endPos - startPos));
//
//									if(subLineA == "ADJ")
//									{
//										//time to do some adjectives!
//										startPos = endPos + 1;
//										endPos = line.find(":",startPos);
//										subLineA = line.substr(startPos,endPos - startPos);
//
//										if(subLineA == "POS")
//										{
//											//positive!
//											startPos = endPos + 1;
//											endPos = line.find("]",startPos);
//											subLineA = line.substr(startPos,endPos - startPos);
//											element_data[subLineB].posAdj[element_data[subLineB].numPosAdj] = subLineA;
//
//											element_data[subLineB].numPosAdj++;
//										}
//										else if(subLineA == "NEU")
//										{
//											startPos = endPos + 1;
//											endPos = line.find("]",startPos);
//											subLineA = line.substr(startPos,endPos - startPos);
//											element_data[subLineB].neuAdj[element_data[subLineB].numNeuAdj] = subLineA;
//
//											element_data[subLineB].numNeuAdj++;
//										}
//										else if(subLineA == "NEG")
//										{
//											startPos = endPos + 1;
//											endPos = line.find("]",startPos);
//											subLineA = line.substr(startPos,endPos - startPos);
//											element_data[subLineB].negAdj[element_data[subLineB].numNegAdj] = subLineA;
//
//											element_data[subLineB].numNegAdj++;
//										}
//
//
//									}	
//
//								}
//
//							}
//
//									//std::getline(lider,line);
//									//stringLength = line.size();
//
//						}
//							
//							  	
//					}
//				}
//			}

		}

	}

	//dump
	int counter = 0;
	ouder<<"126-------\n";
	for(int pip = 0; pip < 128, counter < charCount[126]['b']; pip++)
	{		
		//ouder<<(char)pip<<"-"<<counter<<"\n";
		counter += charStat[126]['b'][pip];	
	}
	ouder<<"total: "<<counter;
	counter = 0;
	ouder<<"127-------\n";
	for(int pip = 0; pip < 128, counter < charCount[127]['b']; pip++)
	{		
		//ouder<<(char)pip<<"-"<<counter<<"\n";
		counter += charStat[127]['b'][pip];	
	}
	ouder<<"total: "<<counter;

	counter = 0;
	ouder<<"127+++++++\n";
	for(int pipX = 0; pipX < 128; pipX++)
	{		
		for(int pipY = 0; pipY < 128; pipY++)
		{	
			//ouder<<(char)pip<<"-"<<counter<<"\n";
			counter += charStat[pipX][pipY][127];	
		}
	}
	ouder<<"total: "<<counter;

	ouder.close();

	
	

		return false;
}
std::string CHAR_LIST_OBJ_3::genWord()
{
	std::string outter = "                                        ";

	std::ofstream ouder("dump_alph.txt", std::fstream::out|std::fstream::trunc);
	//start on 126!
	int finder = //mtrandW.rand(beginCount);
		RND::rnd.intRand(0, beginCount);
	int pip = 0;
	int pipX = 0;
	int pipY = 0;
	int pipZ = 0;
	int counter = 0;
	//std::cout<<beginCount<<"-"<<finder<<"\n";
	bool found = false;


	//we use finder = mtrandW.rand(beginCount) to determine which 
	//letter we will stop on. Then we travel through the statistics, 
	//adding all of the beginStat[letterToCheck] together until we 
	//are > than finder. That is the letter we choose to begin.
	//
	//pip is	

		for(pipX = 20; !found && pipX < 128; pipX++)
		{
			//std::cout<<"\nOn: "<<(char)pipX<<"-"<<pip<<" + "<<beginStat[pipX]<<" = ";
			ouder<<"\nOn: "<<(char)pipX<<"-"<<pip<<" + "<<beginStat[pipX]<<" = ";
			pip += beginStat[pipX];
			if(pip > finder)
			{
				outter[counter] = pipX;
				found = true;
			}
		}

		
		//the first letter has been found. Let's go on the the rest!
		//set finder = mtrandW.rand(charCount[126 (begin)]
		//[pipX (the letter we started with])
		//Then we travel through all the letters at:
		//charStat[126 (begin)][pipX (1st letter)][pipY], incrementing pipY as we go
		//until pip > finder



		counter++;
		found = false;
		pipX--;

		//finder = mtrandW.rand(charCount[126][pipX]);
		finder = RND::rnd.intRand(0,charCount[126][pipX]);
		//std::cout<<"\n"<<charCount[126][pipX]<<"-"<<finder<<"("<<pipX<<")\n";
		ouder<<"\n"<<charCount[126][pipX]<<"-"<<finder<<"("<<pipX<<")\n";
		pip = 0;

		//for(pipX = 0; pip < finder && pipX < 128; pipX++)
		//{
		//std::cout<<"("<<outter<<")checking: [126]["<<pipX<<"]("<<charCount[126][pipX]<<")\n";
		ouder<<"("<<outter<<")checking: [126]["<<pipX<<"]("<<charCount[126][pipX]<<")\n";
			for(pipY = 20; !found && pipY < 128; pipY++)
			{
				//for(int pipZ = 0; pip < finder &&  pipZ < 128; pipZ++)
				//{
				//std::cout<<"\nOn: "<<(char)pipY<<"-"<<pip<<" + "<<charStat[126][pipX][pipY]<<" = ";
				ouder<<"\nOn: "<<(char)pipY<<"-"<<pip<<" + "<<charStat[126][pipX][pipY]<<" = ";
					pip += charStat[126][pipX][pipY];
					//std::cout<<pip;
					if(pip > finder)
					{
							outter[counter] = pipY;
							found = true;
					}
					//pipY--;
				//}
			}




		
		//now we repeat the steps, except use [pipX][pipY][pipZ] with pipZ
		//being incremented.
		//We do this until we reach numberOfLettersInWord

		counter++;
		found = false;
		pipY--;

		//finder = mtrandW.rand(charCount[pipX][pipY]);
		finder = RND::rnd.intRand(0, charCount[pipX][pipY]);
		//std::cout<<"\n"<<charCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
		ouder<<"\n"<<charCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
		pip = 0;

		//std::cout<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<charCount[pipX][pipY]<<")\n";
		ouder<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<charCount[pipX][pipY]<<")\n";
		//for(pipX = 0; pip < finder && pipX < 128; pipX++)
		//{
			for(pipZ = 20; !found && pipZ < 128; pipZ++)
			{
				//for(int pipZ = 0; pip < finder &&  pipZ < 128; pipZ++)
				//{
				//std::cout<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<charStat[pipX][pipY][pipZ]<<" = ";
				ouder<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<charStat[pipX][pipY][pipZ]<<" = ";
					pip += charStat[pipX][pipY][pipZ];
					//std::cout<<pip;
					if(pip > finder)
					{
							outter[counter] = pipZ;
							found = true;
					}
					//pipY--;
				//}
			}


			bool ended = false;
			
			//int dink = mtrandW.rand(14);
			//int dink = RND::rnd.intRand(5, 14);
			int dink = outter.length()-1;

			for(int pop = 0;  pop < dink; pop++)
			{
				counter++;
				found = false;
				pipZ--;

				pipX = pipY;
				pipY = pipZ;
				pipZ = 0;

			//	finder = mtrandW.rand(charCount[pipX][pipY]);
			 	finder = RND::rnd.intRand(0, charCount[pipX][pipY]);
				//std::cout<<"\n"<<charCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
				ouder<<"\n"<<charCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
				pip = 0;

				//std::cout<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<charCount[pipX][pipY]<<")\n";
				ouder<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<charCount[pipX][pipY]<<")\n";
				//for(pipX = 0; pip < finder && pipX < 128; pipX++)
				//{
					for(pipZ = 20; !found && pipZ < 128; pipZ++)
					{
						//for(int pipZ = 0; pip < finder &&  pipZ < 128; pipZ++)
						//{
						//std::cout<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<charStat[pipX][pipY][pipZ]<<" = ";
						ouder<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<charStat[pipX][pipY][pipZ]<<" = ";
							pip += charStat[pipX][pipY][pipZ];
							//std::cout<<pip;
							if(pip > finder && pipZ != 0 && pipZ != 128 && pipZ != 127)
							{
									outter[counter] = pipZ;
									found = true;
							}
							if(pipZ == 127 || pipZ == 128 || pipZ == 33 || pipY == 127 || pipY == 128 || pipY == 33)
							{
								//found = true;
								ended = true;
							}
							//pipY--;
						//}
					}
			}


			//fix the string and remove the white space!

			dink = 0;
			found = false;
			int pol;
			
			for(pol = 0;!found && pol < outter.length(); pol++)
			{
				if(outter[pol] >= 126 || outter[pol] < 33)
				{
					//end it here!
					found = true;				
				}			   
			}
			
			outter.resize(pol-1);


			////do the last letter now! 
			////from endCount & endStats
			//	counter++;
			//	found = false;
			//	pipZ--;

			//	pipX = pipY;
			//	pipY = pipZ;
			//	pipZ = 0;

			//	finder = mtrandW.rand(endCount[pipX][pipY]);
			//	//std::cout<<"\n"<<charCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
			//	ouder<<"\nEND:"<<endCount[pipX][pipY]<<"-"<<finder<<"("<<pipX<<","<<pipY<<")\n";
			//	pip = 0;

			//	//std::cout<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<charCount[pipX][pipY]<<")\n";
			//	ouder<<"("<<outter<<")checking: ["<<pipX<<"]["<<pipY<<"]("<<endCount[pipX][pipY]<<")\n";
			//	//for(pipX = 0; pip < finder && pipX < 128; pipX++)
			//	//{
			//		for(pipZ = 20; !found && pipZ < 128; pipZ++)
			//		{
			//			//for(int pipZ = 0; pip < finder &&  pipZ < 128; pipZ++)
			//			//{
			//			//std::cout<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<charStat[pipX][pipY][pipZ]<<" = ";
			//			ouder<<"\nOn: "<<(char)pipZ<<"-"<<pip<<" + "<<endStat[pipX][pipY][pipZ]<<" = ";
			//				pip += endStat[pipX][pipY][pipZ];
			//				//std::cout<<pip;
			//				if(pip > finder && pipZ < 128)
			//				{
			//						outter[counter] = pipZ;
			//						found = true;
			//				}
			//				//if(pipZ == 127 || pipZ == 128 || pipZ == 33)
			//				//{

			//				//	ended = true;
			//				//}
			//				//pipY--;
			//			//}
			//		}

	return outter;
}
MARKOVER::MARKOVER()
{
	

}
MARKOVER::~MARKOVER()
{

}

CHAR_LIST_OBJ_3* MARKOVER::getAlphabet(std::string name)
{
	auto it = alphabet_3d.find(name);
	if (it != alphabet_3d.end())
	{
		return &it->second;
	}
	else
	{
		std::cout << "alphabet not found" << std::endl;
		//attempt to load it
		if (loadAlphabet("names_" + name + ".txt"))
		{
			return &alphabet_3d[name];
		}

		return nullptr;
	}
}

bool MARKOVER::loadAlphabet(std::string name)
{
	//std::string fileName = "alphabet/" + name + ".txt";
	//std::string fileName = "alphabet/" + name + ".txt";
	CHAR_LIST_OBJ_3 temp;
	if (temp.readFile((char*)name.c_str(), 3))
	{
		alphabet_3d[name] = temp;
		return true;
	}
	else
	{
		std::cout << "failed to load alphabet: " << name << std::endl;
	}
	return false;
}
