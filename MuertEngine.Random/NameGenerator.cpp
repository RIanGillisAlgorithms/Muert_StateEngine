#include "pch.h"
#include "NameGenerator.h"
#include "markover.h"

namespace ianUtil
{
	NameGenerator nameGen;


	NameGenerator::NameGenerator()
	{

	}

	NameGenerator::~NameGenerator()
	{

	}

	std::string NameGenerator::generateStellarStructureName()
	{
		//ToDo: move this declaration to some central location
		MARKOVER mkv;

		std::string namer = mkv.getAlphabet("Stars")->genWord();
		int nameGenCount = 0;
		while (namer.length() < 3 || nameGenCount < 10)
		{
			namer = mkv.getAlphabet("Stars")->genWord();
			nameGenCount++;
		}
		int rndd = RND::rnd.intRand(0, 5);
		int rndd2 = RND::rnd.intRand(0, 6);

		bool hasPrefix = (RND::rnd.intRand(0, 6) == 0);
		hasPrefix = true;
		//has 20% chance, so only on 0
		bool hasSuffix = (RND::rnd.intRand(0, 4) == 0);
		hasSuffix = true;
		bool hasConnector = false;
		bool connectorHasDash = false;
		bool suffixHasDash = false;
		if (hasSuffix)
		{
			suffixHasDash = (RND::rnd.intRand(0, 4) == 0);
			hasConnector = (RND::rnd.intRand(0, 4) == 0);
		}
		hasConnector = true;

		if (hasConnector)
		{
			connectorHasDash = (RND::rnd.intRand(0, 4) == 0);

			connectorHasDash = true;
			suffixHasDash = true;
			std::string connector = mkv.getAlphabet("Connector")->genWord();
			std::string suffix = mkv.getAlphabet("Suffix")->genWord();
			if (connector.length() > 1 && suffix.length() > 2)
			{
				if (connectorHasDash && suffixHasDash)
				{
					namer = namer + "-" + connector + "-" + suffix;
				}
				else if (connectorHasDash)
				{
					namer = namer + "-" + connector + " " + suffix;
				}
				else if (suffixHasDash)
				{
					namer = namer + " " + connector + "-" + suffix;
				}
				else
				{
					namer = namer + " " + connector + " " + suffix;
				}
			}
		}
		else if (hasSuffix)
		{
			std::string suffix = mkv.getAlphabet("Suffix")->genWord();
			if (suffix.length() > 2)
			{
				if (suffixHasDash)
				{
					namer = namer + "-" + suffix;
				}
				else
				{
					namer = namer + " " + suffix;
				}
			}
		}
		return namer;
	}

}

