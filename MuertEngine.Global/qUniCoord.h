

//by ian.gillis
#pragma once
#ifndef qUniCoord_H
#define qUniCoord_H
// qUniverseCoord.h
// by Ian

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define qUniCoord_H_API __declspec(dllexport)
#else
#define qUniCoord_H_API __declspec(dllimport)
#endif

#include "point3.h"
#include "qUniCoord_condensed.h"


namespace qUNI
{	   

	//UnfathomableCord
	class qUniCoord_H_API qUnfathomableLoc
	{
	public:
		qUnfathomableLoc();;
		qUnfathomableLoc(Point3D UCord);;
		~qUnfathomableLoc();;
		
		Point3D uCord;

		void setCord(Point3D UCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void SetX(int Setter);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void SetY(int Setter);;
		void setAllX(qUnfathomableLoc GPCord);;
		void setAllY(qUnfathomableLoc GPCord);;
		Point3D getUCord();;
		Point3D getCord();;
		Point3D getLocalCord();;
		bool isWithinBotLeftTopRight(qUnfathomableLoc BotLeft, qUnfathomableLoc TopRight);;
		int dirPointComparison(qUnfathomableLoc Loc);;


		bool operator==(const qUnfathomableLoc& other) const;
		
	};

	class qUniCoord_H_API qGigaParsecLoc : public qUnfathomableLoc
	{
	public:
		qGigaParsecLoc();;
		qGigaParsecLoc(Point3D GPCord);;
		~qGigaParsecLoc();;

		static const int dims = 50;
		Point3D gpCord;

		void setCord(Point3D GPCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void SetX(int Setter);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void SetY(int Setter);;
		int GetZ();;
		void SetZ(int Setter);;
		void setAllX(qGigaParsecLoc GPCord);;
		void setAllY(qGigaParsecLoc GPCord);;
		qGigaParsecLoc getGPCord();;
		qGigaParsecLoc getCord();;
		Point3D getLocalCord();;	
		bool isWithinBotLeftTopRight(qGigaParsecLoc BotLeft, qGigaParsecLoc TopRight);;
		/// <summary>
		/// Returns 1-9
		/// If on the X-axis it will be 4 || 6
		/// If on the Y-axis it will be 2 || 8
		/// If equal it will be 5
		/// Otherwise it will be 1,3,7 or 9
		/// </summary>
		/// <param name="Loc"></param>
		/// <returns></returns>
		int dirPointComparison(qGigaParsecLoc Loc);;	

		qUNI::qGigaParsecLoc operator + (const qGigaParsecLoc& other) const;
		qUNI::qGigaParsecLoc& operator += (const qGigaParsecLoc& other);
		qUNI::qGigaParsecLoc operator - (const qGigaParsecLoc& other) const;
		qUNI::qGigaParsecLoc& operator -= (const qGigaParsecLoc& other);

		bool operator==(const qGigaParsecLoc& other) const;
		bool operator<(const qGigaParsecLoc& other) const;
	};

	class qUniCoord_H_API qMegaParsecLoc : public qGigaParsecLoc
	{
	public:
		qMegaParsecLoc();;
		qMegaParsecLoc(Point3D GPCord, Point3D MPCord);;
		qMegaParsecLoc(qGigaParsecLoc GPCord, Point3D MPCord);;
		~qMegaParsecLoc();;

		static const int dims = 1000;
		Point3D mpCord;

		void setCord(Point3D GPCord, Point3D MPCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void setAllX(qMegaParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qMegaParsecLoc Cord);;
		int GetZ();;
		qMegaParsecLoc getMPCord();;
		qMegaParsecLoc getCord();;
		Point3D getLocalCord();;
		bool isWithinBotLeftTopRight(qMegaParsecLoc BotLeft, qMegaParsecLoc TopRight);;
		int dirPointComparison(qMegaParsecLoc Loc);;
		int fixCords();

		//+, +=, -, -= overloads
		qUNI::qMegaParsecLoc operator + (const qMegaParsecLoc& other) const;
		qUNI::qMegaParsecLoc& operator += (const qMegaParsecLoc& other);
		qUNI::qMegaParsecLoc operator - (const qMegaParsecLoc& other) const;
		qUNI::qMegaParsecLoc& operator -= (const qMegaParsecLoc& other);		

		bool operator==(const qMegaParsecLoc& other) const;
	};

	class qUniCoord_H_API qKiloParsecLoc : public qMegaParsecLoc
	{
	public:
		qKiloParsecLoc();;
		qKiloParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord);;
		qKiloParsecLoc(qMegaParsecLoc MPCord, Point3D KPCord);;
		~qKiloParsecLoc();;

		static const int dims = 1000;
		Point3D kpCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void setAllX(qKiloParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qKiloParsecLoc Cord);;
		int GetZ();;
		qKiloParsecLoc getKPCord();;
		qKiloParsecLoc getCord();;
		Point3D getLocalCord();;

		bool isWithinBotLeftTopRight(qKiloParsecLoc BotLeft, qKiloParsecLoc TopRight);;
		int dirPointComparison(qKiloParsecLoc Loc);;
		//void fixCords()
		//{
		//	qMegaParsecLoc::fixCords();
		//	while (kpCord.GetX() < 0)
		//	{
		//		kpCord.SetX(kpCord.GetX() + dims);
		//		mpCord.SetX(mpCord.GetX() - 1);
		//	}
		//	while (kpCord.GetX() >= dims)
		//	{
		//		kpCord.SetX(kpCord.GetX() - dims);
		//		mpCord.SetX(mpCord.GetX() + 1);
		//	}
		//	while (kpCord.GetY() < 0)
		//	{
		//		kpCord.SetY(kpCord.GetY() + dims);
		//		mpCord.SetY(mpCord.GetY() - 1);
		//	}
		//	while (kpCord.GetY() >= dims)
		//	{
		//		kpCord.SetY(kpCord.GetY() - dims);
		//		mpCord.SetY(mpCord.GetY() + 1);
		//	}
		//}
		int fixCords(bool initParent = false);


		//+, +=, -, -= overloads
		qUNI::qKiloParsecLoc operator + (const qKiloParsecLoc& other) const;
		qUNI::qKiloParsecLoc& operator += (const qKiloParsecLoc& other);
		qUNI::qKiloParsecLoc operator - (const qKiloParsecLoc& other) const;
		qUNI::qKiloParsecLoc& operator -= (const qKiloParsecLoc& other);

		bool operator==(const qKiloParsecLoc& other) const;
	};

	class qUniCoord_H_API qParsecLoc : public qKiloParsecLoc
	{
	public:
		qParsecLoc();;
		qParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord);;
		qParsecLoc(qKiloParsecLoc KPCord, Point3D PCord);;
		~qParsecLoc();;

		static const int dims = 1000;
		Point3D pCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void setAllX(qParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qParsecLoc Cord);;
		int GetZ();;
		qParsecLoc getPCord();;
		qParsecLoc getCord();;
		Point3D getLocalCord();;

		bool isWithinBotLeftTopRight(qParsecLoc BotLeft, qParsecLoc TopRight);;
		int dirPointComparison(qParsecLoc Loc);;
		int fixCords(bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qParsecLoc operator + (const qParsecLoc& other) const;
		qUNI::qParsecLoc& operator += (const qParsecLoc& other);
		qUNI::qParsecLoc operator - (const qParsecLoc& other) const;
		qUNI::qParsecLoc& operator -= (const qParsecLoc& other);

		bool operator==(const qParsecLoc& other) const;
	};

	class qUniCoord_H_API qAntiKiloParsecLoc : public qParsecLoc
	{
	public:
		qAntiKiloParsecLoc();;
		qAntiKiloParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord);;
		qAntiKiloParsecLoc(qParsecLoc PCord, Point3D AKPCord);;
		~qAntiKiloParsecLoc();;

		static const int dims = 1000;
		Point3D akpCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord);;
		void adjustX(int NumToAdjust);; 
		int GetX();;
		void setAllX(qAntiKiloParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qAntiKiloParsecLoc Cord);;
		int GetZ();;		
		qAntiKiloParsecLoc getAKPCord();;
		qAntiKiloParsecLoc getCord();;
		Point3D getLocalCord();;

		bool isWithinBotLeftTopRight(qAntiKiloParsecLoc BotLeft, qAntiKiloParsecLoc TopRight);;
		int dirPointComparison(qAntiKiloParsecLoc Loc);;
		int fixCords(bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qAntiKiloParsecLoc operator + (const qAntiKiloParsecLoc& other) const;
		qUNI::qAntiKiloParsecLoc& operator += (const qAntiKiloParsecLoc& other);
		qUNI::qAntiKiloParsecLoc operator - (const qAntiKiloParsecLoc& other) const;
		qUNI::qAntiKiloParsecLoc& operator -= (const qAntiKiloParsecLoc& other);

		bool operator==(const qAntiKiloParsecLoc& other) const;
	};

	class qUniCoord_H_API qAntiMegaParsecLoc : public qAntiKiloParsecLoc
	{
	public:
		qAntiMegaParsecLoc();;
		qAntiMegaParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord);;
		qAntiMegaParsecLoc(qAntiKiloParsecLoc AKPCord, Point3D AMPCord);;
		~qAntiMegaParsecLoc();;

		static const int dims = 1000;
		Point3D ampCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void setAllX(qAntiMegaParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qAntiMegaParsecLoc Cord);;
		int GetZ();;
		qAntiMegaParsecLoc getAMPCord();;
		qAntiMegaParsecLoc getCord();;
		Point3D getLocalCord();;

		bool isWithinBotLeftTopRight(qAntiMegaParsecLoc BotLeft, qAntiMegaParsecLoc TopRight);;
		int dirPointComparison(qAntiMegaParsecLoc Loc);;
		int fixCords(bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qAntiMegaParsecLoc operator + (const qAntiMegaParsecLoc& other) const;
		qUNI::qAntiMegaParsecLoc& operator += (const qAntiMegaParsecLoc& other);
		qUNI::qAntiMegaParsecLoc operator - (const qAntiMegaParsecLoc& other) const;
		qUNI::qAntiMegaParsecLoc& operator -= (const qAntiMegaParsecLoc& other);

		bool operator==(const qAntiMegaParsecLoc& other) const;
	};

	class qUniCoord_H_API qAntiGigaParsecLoc : public qAntiMegaParsecLoc
	{
	public:
		qAntiGigaParsecLoc();;
		qAntiGigaParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord);;
		qAntiGigaParsecLoc(qAntiMegaParsecLoc AMPCord, Point3D AGPCord);;
		~qAntiGigaParsecLoc();;

		static const int dims = 1000;
		Point3D agpCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord);;
		void adjustX(int NumToAdjust);;
		int GetX();;
		void setAllX(qAntiGigaParsecLoc Cord);;
		void adjustY(int NumToAdjust);;
		int GetY();;
		void setAllY(qAntiGigaParsecLoc Cord);;
		int GetZ();;
		qAntiGigaParsecLoc getAGPCord();;
		qAntiGigaParsecLoc getCord();;
		Point3D getLocalCord();;
		int dirPointComparison(qAntiGigaParsecLoc Loc);;
		int fixCords(bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qAntiGigaParsecLoc operator + (const qAntiGigaParsecLoc& other) const;
		qUNI::qAntiGigaParsecLoc& operator += (const qAntiGigaParsecLoc& other);
		qUNI::qAntiGigaParsecLoc operator - (const qAntiGigaParsecLoc& other) const;
		qUNI::qAntiGigaParsecLoc& operator -= (const qAntiGigaParsecLoc& other);

		bool operator==(const qAntiGigaParsecLoc& other) const;
	};

	class qUniCoord_H_API qGodLoc : public qAntiGigaParsecLoc
	{
	public:
		qGodLoc();
		qGodLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord);
		qGodLoc(qAntiGigaParsecLoc AGPCord, Point3D GodCord);
		~qGodLoc();

		static const int dims = 100;
		Point3D godCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord);
		void adjustX(int NumToAdjust);
		int GetX();
		void setAllX(qGodLoc Cord);
		void adjustY(int NumToAdjust);
		int GetY();
		void setAllY(qGodLoc Cord);
		int GetZ();

		qGodLoc getGodCord();
		qGodLoc getCord();
		Point3D getLocalCord();
		int dirPointComparison(qGodLoc Loc);
		int fixCords(Point3D& offset, bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qGodLoc operator + (const qGodLoc& other) const;
		qUNI::qGodLoc& operator += (const qGodLoc& other);
		qUNI::qGodLoc operator - (const qGodLoc& other) const;
		qUNI::qGodLoc& operator -= (const qGodLoc& other);

		bool operator==(const qGodLoc& other) const;
	};

	class qUniCoord_H_API qWorldLoc : public qGodLoc
	{
	public:
		qWorldLoc();
		qWorldLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord);
		qWorldLoc(qGodLoc GodCord, Point3D WorldCord);
		~qWorldLoc();

		static const int dims = 33;
		Point3D worldCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord);
		void adjustX(int NumToAdjust);
		int GetX();
		void setAllX(qWorldLoc Cord);
		void adjustY(int NumToAdjust);
		int GetY();
		void setAllY(qWorldLoc Cord);
		int GetZ();

		qWorldLoc getWorldCord();
		qWorldLoc getCord();
		Point3D getLocalCord();
		int dirPointComparison(qWorldLoc Loc);
		int fixCords(Point3D& offset, bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qWorldLoc operator + (const qWorldLoc& other) const;
		qUNI::qWorldLoc& operator += (const qWorldLoc& other);
		qUNI::qWorldLoc operator - (const qWorldLoc& other) const;
		qUNI::qWorldLoc& operator -= (const qWorldLoc& other);

		bool operator==(const qWorldLoc& other) const;
	};

	class qUniCoord_H_API qAreaLoc : public qWorldLoc
	{
	public:
		qAreaLoc();
		qAreaLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord);
		qAreaLoc(qWorldLoc WorldCord, Point3D AreaCord);
		~qAreaLoc();

		static const int dims = 33;
		Point3D areaCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord);
		void adjustX(int NumToAdjust);
		int GetX();
		void setAllX(qAreaLoc Cord);
		void adjustY(int NumToAdjust);
		int GetY();
		void setAllY(qAreaLoc Cord);
		int GetZ();

		qAreaLoc getAreaCord();
		qAreaLoc getCord();
		Point3D getLocalCord();
		int dirPointComparison(qAreaLoc Loc);
		int fixCords(Point3D& offset, bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qAreaLoc operator + (const qAreaLoc& other) const;
		qUNI::qAreaLoc& operator += (const qAreaLoc& other);
		qUNI::qAreaLoc operator - (const qAreaLoc& other) const;
		qUNI::qAreaLoc& operator -= (const qAreaLoc& other);

		bool operator==(const qAreaLoc& other) const;
	};

	class qUniCoord_H_API qRegionLoc : public qAreaLoc
	{
	public:
		qRegionLoc();
		qRegionLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord);
		qRegionLoc(qAreaLoc AreaCord, Point3D RegionCord);
		~qRegionLoc();

		static const int dims = 33;
		Point3D regionCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord);
		void adjustX(int NumToAdjust);
		int GetX();
		void setAllX(qRegionLoc Cord);
		void adjustY(int NumToAdjust);
		int GetY();
		void setAllY(qRegionLoc Cord);
		int GetZ();

		qRegionLoc getRegionCord();
		qRegionLoc getCord();
		Point3D getLocalCord();
		int dirPointComparison(qRegionLoc Loc);
		int fixCords(Point3D& offset, bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qRegionLoc operator + (const qRegionLoc& other) const;
		qUNI::qRegionLoc& operator += (const qRegionLoc& other);
		qUNI::qRegionLoc operator - (const qRegionLoc& other) const;
		qUNI::qRegionLoc& operator -= (const qRegionLoc& other);

		bool operator==(const qRegionLoc& other) const;


		qUNI::qAreaLoc asAreaMap();
	};

	class qUniCoord_H_API qLocalLoc : public qRegionLoc
	{
	public:
		qLocalLoc();
		qLocalLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord, Point3D LocalCord);
		qLocalLoc(qRegionLoc RegionCord, Point3D LocalCord);
		~qLocalLoc();

		static const int dims = 9;
		Point3D localCord;

		void setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord, Point3D LocalCord);
		void adjustX(int NumToAdjust);
		int GetX();
		void setAllX(qLocalLoc Cord);
		void adjustY(int NumToAdjust);
		int GetY();
		void setAllY(qLocalLoc Cord);
		int GetZ();

		//qLocalLoc getLocalCord() { return qLocalLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord, regionCord, localCord); };
		qLocalLoc getCord();
		Point3D getLocalCord();
		int dirPointComparison(qLocalLoc Loc);
		int fixCords(Point3D& offset, bool initParent = false);

		//+, +=, -, -= overloads
		qUNI::qLocalLoc operator + (const qLocalLoc& other) const;
		qUNI::qLocalLoc& operator += (const qLocalLoc& other);
		qUNI::qLocalLoc operator - (const qLocalLoc& other) const;
		qUNI::qLocalLoc& operator -= (const qLocalLoc& other);

		bool operator==(const qLocalLoc& other) const;
		void unFixToMapFocus(qUNI::qLocalLoc MapFocusLoc);
		qUNI::qAreaLoc asAreaMap();
		qUNI::qRegionLoc asRegionMap();

		qUNI::qGMK_Coord get_GMK_Coord();
		qUNI::qPAA_Coord get_PAA_Coord();
		qUNI::qAgw_Coord get_Agw_Coord();
		qUNI::qarl_Coord get_arl_Coord();
	};


}
#endif