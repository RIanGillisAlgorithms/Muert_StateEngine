

//by ian.gillis
#pragma once
#ifndef qUniCoord_Condensed_H
#define qUniCoord_Condensed_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define qUniCoord_Condensed_H_API __declspec(dllexport)
#else
#define qUniCoord_Condensed_H_API __declspec(dllimport)
#endif


#include "point3.h"
//#include "qUniCoord.h"


namespace qUNI
{

	struct qUniCoord_Condensed_H_API qGMK_Coord
	{
	public:
		int x;
		int y;
		int z;

		static const int gx = 50;
		static const int gy = 50;
		static const int gz = 50;
		static const int mx = 1000;
		static const int my = 1000;
		static const int mz = 1000;
		static const int kx = 1000;
		static const int ky = 1000;
		static const int kz = 1000;

		void set(Point3D gigaParsec, Point3D megaParsec, Point3D kiloParsec);

		void setGiga(Point3D gigaParsec);

		void setMega(Point3D megaParsec);

		void setKilo(Point3D kiloParsec);


		Point3D toPoint3D();

		//qGigaParsecLoc toGPLoc();

		//qMegaParsecLoc toMPLoc();

		//qKiloParsecLoc toKPLoc();


		int toGX();
		int toGY();
		int toGZ();


		int toMX();
		int toMY();
		int toMZ();

		int toKX();
		int toKY();
		int toKZ();
	

		Point3D toGPoint3D();
		Point3D toMPoint3D();
		Point3D toKPoint3D();


		bool operator<(const qGMK_Coord& other) const;

	};

	struct qUniCoord_Condensed_H_API qPAA_Coord 
	{
	public:	 
		qGMK_Coord parentCoord;
		int x;
		int y;
		int z;

		static const int px = 1000;
		static const int py = 1000;
		static const int pz = 1000;
		static const int ax = 1000;
		static const int ay = 1000;
		static const int az = 1000;
		static const int aax = 1000;
		static const int aay = 1000;
		static const int aaz = 1000;

		void set(Point3D parsec, Point3D antiKilo, Point3D antiMega);

		void setParsec(Point3D parsec);

		void setAntiKilo(Point3D antiKilo);

		void setAntiMega(Point3D antiMega);

		Point3D toPoint3D();

		//qParsecLoc toPLoc();

		//qAntiKiloParsecLoc toAPLoc();

		//qAntiMegaParsecLoc toAAPLoc();


		int toPX();
		int toPY();
		int toPZ();


		int toAKPX();
		int toAKPY();
		int toAKPZ();

		int toAMPX();
		int toAMPY();
		int toAMPZ();


		Point3D toPPoint3D();
		Point3D toAKPPoint3D();
		Point3D toAMPPoint3D();


		bool operator<(const qPAA_Coord& other) const;


	};

	struct qUniCoord_Condensed_H_API qAgw_Coord
	{
	public:
		qPAA_Coord parentCoord;
		int x;
		int y;
		int z;

		static const int ax = 1000;
		static const int ay = 1000;
		static const int az = 1000;
		static const int gx = 100;
		static const int gy = 100;
		static const int gz = 100;
		static const int Wx = 33;
		static const int Wy = 33;
		static const int Wz = 33;

		void set(Point3D agp, Point3D god, Point3D world);
		void setAGP(Point3D agp);
		void setGod(Point3D god);
		void setWorld(Point3D world);

		Point3D toPoint3D();

		//qAntiGigaParsecLoc toAGPLoc();

		//qGodLoc toGodLoc();

		//qWorldLoc toWorldLoc();

		int toAGPX();		 
		int toAGPY();
		int toAGPZ();

		int toGodX();
		int toGodY();
		int toGodZ();
		int toWorldX();
		int toWorldY();
		int toWorldZ();

		Point3D toAGPPoint3D();
		Point3D toGodPoint3D();
		Point3D toWorldPoint3D();

		bool operator<(const qAgw_Coord& other) const;


	};

	struct qUniCoord_Condensed_H_API qarl_Coord
	{
	public:
		qAgw_Coord parentCoord;
		int x;
		int y;
		int z;

		static const int ax = 33;
		static const int ay = 33;
		static const int az = 33;
		static const int rx = 33;
		static const int ry = 33;
		static const int rz = 33;
		static const int lx = 9;
		static const int ly = 9;
		static const int lz = 9;

		void set(Point3D area, Point3D region, Point3D local);
		void setArea(Point3D area);
		void setRegion(Point3D region);
		void setLocal(Point3D local);


		Point3D toPoint3D();

		//qAreaLoc toAreaLoc();

		//qRegionLoc toRegionLoc();

		//qLocalLoc toLocalLoc();

		int toAreaX();
		int toAreaY();
		int toAreaZ();

		int toRegionX();
		int toRegionY();
		int toRegionZ();
		int toLocalX();
		int toLocalY();
		int toLocalZ();

		bool operator<(const qarl_Coord& other) const;


	};

}

#endif // !1
