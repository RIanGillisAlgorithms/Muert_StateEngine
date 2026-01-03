#pragma once
#ifndef point_3d_hash_H
#define point_3d_hash_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define point_3d_hash_H_API __declspec(dllexport)
#else
#define point_3d_hash_H_API __declspec(dllimport)
#endif


#include "point3.h"


struct point_3d_hash_H_API Point3DHash {
	std::size_t operator()(const Point3D& p) const;
};

#endif
