

//by ian.gillis
#pragma once
#ifndef TYPE_COMBOS_H
#define TYPE_COMBOS_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define TYPE_COMBOS_H_API __declspec(dllexport)
#else
#define TYPE_COMBOS_H_API __declspec(dllimport)
#endif


#include "qUniCoord.h"
#include "tileDisplayObject.h"
#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"


struct TYPE_COMBOS_H_API DOUBLEBOOL
{
public:
	DOUBLEBOOL();
	~DOUBLEBOOL();

	bool tf;
	double dbl;
};
struct TYPE_COMBOS_H_API INTBOOL
{
public:
	INTBOOL();
	INTBOOL(bool TF, int N);
	~INTBOOL();

	bool tf;
	int n;
};
struct TYPE_COMBOS_H_API INTINT
{
	int first;
	int second;
};
struct TYPE_COMBOS_H_API INTINTINT
{
	int first;
	int second;
	int third;
};
struct TYPE_COMBOS_H_API qAntiMegaParsecLoc_DisplayObject3
{	   
public:
	qAntiMegaParsecLoc_DisplayObject3();
	qAntiMegaParsecLoc_DisplayObject3(qUNI::qAntiMegaParsecLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qAntiMegaParsecLoc_DisplayObject3();

	qUNI::qAntiMegaParsecLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qAntiMegaParsecLoc_DisplayObject9
{
public:
	qAntiMegaParsecLoc_DisplayObject9();
	qAntiMegaParsecLoc_DisplayObject9(qUNI::qAntiMegaParsecLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qAntiMegaParsecLoc_DisplayObject9();

	qUNI::qAntiMegaParsecLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};
struct TYPE_COMBOS_H_API qAntiGigaParsecLoc_DisplayObject3
{
public:
	qAntiGigaParsecLoc_DisplayObject3();
	qAntiGigaParsecLoc_DisplayObject3(qUNI::qAntiGigaParsecLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qAntiGigaParsecLoc_DisplayObject3();

	qUNI::qAntiGigaParsecLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qAntiGigaParsecLoc_DisplayObject9
{
public:
	qAntiGigaParsecLoc_DisplayObject9();
	qAntiGigaParsecLoc_DisplayObject9(qUNI::qAntiGigaParsecLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qAntiGigaParsecLoc_DisplayObject9();

	qUNI::qAntiGigaParsecLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};


struct TYPE_COMBOS_H_API qGodLoc_DisplayObject3
{
public:
	qGodLoc_DisplayObject3();
	qGodLoc_DisplayObject3(qUNI::qGodLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qGodLoc_DisplayObject3();

	qUNI::qGodLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qGodLoc_DisplayObject9
{
public:
	qGodLoc_DisplayObject9();
	qGodLoc_DisplayObject9(qUNI::qGodLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qGodLoc_DisplayObject9();

	qUNI::qGodLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};


struct TYPE_COMBOS_H_API qWorldLoc_DisplayObject3
{
public:
	qWorldLoc_DisplayObject3();
	qWorldLoc_DisplayObject3(qUNI::qWorldLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qWorldLoc_DisplayObject3();

	qUNI::qWorldLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qWorldLoc_DisplayObject9
{
public:
	qWorldLoc_DisplayObject9();
	qWorldLoc_DisplayObject9(qUNI::qWorldLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qWorldLoc_DisplayObject9();

	qUNI::qWorldLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};


struct TYPE_COMBOS_H_API qAreaLoc_DisplayObject3
{
public:
	qAreaLoc_DisplayObject3();
	qAreaLoc_DisplayObject3(qUNI::qAreaLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qAreaLoc_DisplayObject3();

	qUNI::qAreaLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qAreaLoc_DisplayObject9
{
public:
	qAreaLoc_DisplayObject9();
	qAreaLoc_DisplayObject9(qUNI::qAreaLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qAreaLoc_DisplayObject9();

	qUNI::qAreaLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};

struct TYPE_COMBOS_H_API qRegionLoc_DisplayObject3
{
public:
	qRegionLoc_DisplayObject3();
	qRegionLoc_DisplayObject3(qUNI::qRegionLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qRegionLoc_DisplayObject3();

	qUNI::qRegionLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};
struct TYPE_COMBOS_H_API qRegionLoc_DisplayObject9
{
public:
	qRegionLoc_DisplayObject9();
	qRegionLoc_DisplayObject9(qUNI::qRegionLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	~qRegionLoc_DisplayObject9();

	qUNI::qRegionLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};

struct TYPE_COMBOS_H_API qLocalLoc_DisplayObject3
{
public:
	qLocalLoc_DisplayObject3();
	qLocalLoc_DisplayObject3(qUNI::qLocalLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qLocalLoc_DisplayObject3();

	qUNI::qLocalLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_3 disp;
};

struct TYPE_COMBOS_H_API qLocalLoc_DisplayObject9
{
public:
	qLocalLoc_DisplayObject9();
	qLocalLoc_DisplayObject9(qUNI::qLocalLoc Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	qLocalLoc_DisplayObject9(qUNI::qLocalLoc Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~qLocalLoc_DisplayObject9();

	qUNI::qLocalLoc loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};

struct TYPE_COMBOS_H_API Point3D_DisplayObject9
{
public:
	Point3D_DisplayObject9();
	Point3D_DisplayObject9(Point3D Loc, DRAW::TILE_DISPLAY_OBJECT_9 Disp);
	Point3D_DisplayObject9(Point3D Loc, DRAW::TILE_DISPLAY_OBJECT_3 Disp);
	~Point3D_DisplayObject9();

	Point3D loc;
	DRAW::TILE_DISPLAY_OBJECT_9 disp;
};

class TYPE_COMBOS_H_API Point3D_BOOL
{
public:
	Point3D_BOOL();
	Point3D_BOOL(Point3D Point, bool TF);
	~Point3D_BOOL();

	Point3D point;
	bool tf;
};


#endif
