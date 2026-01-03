//by ian.gillis
#pragma once
#ifndef DIRECTION_H
#define DIRECTION_H

#ifdef MUERTENGINEGLOBAL_EXPORTS
#define DIRECTION_H_API __declspec(dllexport)
#else
#define DIRECTION_H_API __declspec(dllimport)
#endif


#include "../MuertEngine.Enum/EnumClass_GlobalDefinitions.h"


namespace Spatial
{


	/// <summary>
	/// ToDo: utilize this for all dir usage
	/// </summary>
	class DIRECTION_H_API direction2d
	{
	public:
		direction2d();
		~direction2d();

		int getDirInt();


		static Spatial::dir getOppositeDirection(Spatial::dir egressDirection);


		static Spatial::dir getRandomDir2d(bool includeNoDirection = false);
		static int getRandomDir2dInt(bool includeNoDirection = false);

	private:


	};

	//a direction (1-9) and an z-orientation (fromBelow, fromAbove, level)
	class DIRECTION_H_API direction2d_orientation
	{
	public:
		direction2d_orientation();
		~direction2d_orientation();
		Spatial::dir direc;
		Spatial::z_orientation z_orient;
	};


	/// <summary>
	/// ToDo: utilize this for all dir3d usage
	/// </summary>
	class DIRECTION_H_API direction3d
	{
	public:
		direction3d();
		~direction3d();

		void setDir3d(Spatial::dir3d Dir);
		Spatial::dir3d getDir3d();

		static Spatial::dir3d getRandomDir3d(bool includeNoDirection = false);
		static int getRandomDir3dInt(bool includeNoDirection = false);
		/// <summary>
		/// returns n, ne, e, se, s, sw, w, nw
		/// </summary>
		/// <param name="includeNoDirection"></param>
		/// <returns></returns>
		static Spatial::dir3d getRandomDir2d(bool includeNoDirection = false);
		static int getRandomDir2dInt(bool includeNoDirection = false);


		static Spatial::dir3d getAdjacentDirection(Spatial::dir3d toReturn, int choice);
	private:
		Spatial::dir3d _dir3d;
	public:
		static Spatial::dir3d getOppositeDirection(Spatial::dir3d Direction);
		static Spatial::dir3d getNextClockwiseDir2d(Spatial::dir3d curDir);
		static Spatial::dir3d getNextCounterClockwiseDir2d(Spatial::dir3d curDir);
		static Spatial::dir3d getUpNextClockwiseDir2d(Spatial::dir3d curDir);
		static Spatial::dir3d getUpNextCounterClockwiseDir2d(Spatial::dir3d curDir);
		static Spatial::dir3d getDownNextClockwiseDir2d(Spatial::dir3d curDir);
		static Spatial::dir3d getDownNextCounterClockwiseDir2d(Spatial::dir3d curDir);
	};
}



#endif