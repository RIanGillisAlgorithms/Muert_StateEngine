#include "pch.h"
#include "point3_hash.h"

std::size_t Point3DHash::operator()(const Point3D& p) const
{
	// Simple hash function combining the coordinates using prime numbers
	std::size_t h1 = std::hash<int>{}(p.x);
	std::size_t h2 = std::hash<int>{}(p.y);
	std::size_t h3 = std::hash<int>{}(p.z);
	return h1 ^ (h2 << 1) ^ (h3 << 2);
}
