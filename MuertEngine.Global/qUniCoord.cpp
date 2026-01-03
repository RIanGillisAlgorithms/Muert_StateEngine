#include "pch.h"
#include "qUniCoord.h"
#include "point2.h"
#include "coordFunctions.h"

namespace qUNI
{

	bool qUnfathomableLoc::operator==(const qUnfathomableLoc& other) const
	{
		return true;
	}

	qUnfathomableLoc::qUnfathomableLoc(Point3D UCord)
	{
		uCord.Set(0, 0, 0);
	}

	qUnfathomableLoc::qUnfathomableLoc()
	{
		uCord.Set(0, 0, 0);
	}

	qUnfathomableLoc::~qUnfathomableLoc()
	{

	}

	void qUnfathomableLoc::setCord(Point3D UCord)
	{
		uCord = UCord;
	}

	void qUnfathomableLoc::adjustX(int NumToAdjust)
	{
		uCord.SetX(uCord.GetX() + NumToAdjust);
	}

	int qUnfathomableLoc::GetX()
	{
		return uCord.GetX();
	}

	void qUnfathomableLoc::SetX(int Setter)
	{
		uCord.SetX(Setter);
	}

	void qUnfathomableLoc::adjustY(int NumToAdjust)
	{
		uCord.SetY(uCord.GetY() + NumToAdjust);
	}

	int qUnfathomableLoc::GetY()
	{
		return uCord.GetY();
	}

	void qUnfathomableLoc::SetY(int Setter)
	{
		uCord.SetY(Setter);
	}

	void qUnfathomableLoc::setAllX(qUnfathomableLoc GPCord)
	{
		return;
	}

	void qUnfathomableLoc::setAllY(qUnfathomableLoc GPCord)
	{
		return;
	}

	Point3D qUnfathomableLoc::getUCord()
	{
		return Point3D(0, 0, 0);
	}

	Point3D qUnfathomableLoc::getCord()
	{
		return Point3D(0, 0, 0);
	}

	Point3D qUnfathomableLoc::getLocalCord()
	{
		return Point3D(0, 0, 0);
	}

	bool qUnfathomableLoc::isWithinBotLeftTopRight(qUnfathomableLoc BotLeft, qUnfathomableLoc TopRight)
	{
		return true;
	}

	int qUnfathomableLoc::dirPointComparison(qUnfathomableLoc Loc)
	{
		return 5;
	}



	bool qGigaParsecLoc::operator==(const qGigaParsecLoc& other) const
	{
		if (other.gpCord == gpCord) {
			return true;
		}
		return false;
	}

	qGigaParsecLoc::qGigaParsecLoc(Point3D GPCord)
	{
		setCord(GPCord);
	}

	qGigaParsecLoc::qGigaParsecLoc()
	{
		setCord(Point3D(-1, -1, -1));
	}

	qGigaParsecLoc::~qGigaParsecLoc()
	{

	}

	void qGigaParsecLoc::setCord(Point3D GPCord)
	{
		gpCord = GPCord;
	}

	void qGigaParsecLoc::adjustX(int NumToAdjust)
	{
		gpCord.SetX(gpCord.GetX() + NumToAdjust);
	}

	int qGigaParsecLoc::GetX()
	{
		return gpCord.GetX();
	}

	void qGigaParsecLoc::SetX(int Setter)
	{
		gpCord.SetX(Setter);
	}

	void qGigaParsecLoc::adjustY(int NumToAdjust)
	{
		gpCord.SetY(gpCord.GetY() + NumToAdjust);
	}

	int qGigaParsecLoc::GetY()
	{
		return gpCord.GetY();
	}

	void qGigaParsecLoc::SetY(int Setter)
	{
		gpCord.SetY(Setter);
	}

	int qGigaParsecLoc::GetZ()
	{
		return gpCord.GetZ();
	}

	void qGigaParsecLoc::SetZ(int Setter)
	{
		gpCord.SetZ(Setter);
	}

	void qGigaParsecLoc::setAllX(qGigaParsecLoc GPCord)
	{
		gpCord.SetX(GPCord.gpCord.GetX());
	}

	void qGigaParsecLoc::setAllY(qGigaParsecLoc GPCord)
	{
		gpCord.SetY(GPCord.gpCord.GetY());
	}

	qUNI::qGigaParsecLoc qGigaParsecLoc::getGPCord()
	{
		return gpCord;
	}

	qUNI::qGigaParsecLoc qGigaParsecLoc::getCord()
	{
		return *this;
	}

	Point3D qGigaParsecLoc::getLocalCord()
	{
		return gpCord;
	}

	bool qGigaParsecLoc::isWithinBotLeftTopRight(qGigaParsecLoc BotLeft, qGigaParsecLoc TopRight)
	{
		if (gpCord.GetX() >= BotLeft.gpCord.GetX() && gpCord.GetX() <= TopRight.gpCord.GetX()
			&& gpCord.GetY() >= BotLeft.gpCord.GetY() && gpCord.GetY() <= TopRight.gpCord.GetY()
			&& gpCord.GetZ() >= BotLeft.gpCord.GetZ() && gpCord.GetZ() <= TopRight.gpCord.GetZ())
		{
			return true;
		}
		return false;
	}

	int qGigaParsecLoc::dirPointComparison(qGigaParsecLoc Loc)
	{

		if (Loc.gpCord.GetX() == gpCord.GetX() && Loc.gpCord.GetY() == gpCord.GetY())
		{
			return 5;
		}
		if (Loc.gpCord.GetX() == gpCord.GetX() && Loc.gpCord.GetY() > gpCord.GetY())
		{
			return 8;
		}
		if (Loc.gpCord.GetX() == gpCord.GetX() && Loc.gpCord.GetY() < gpCord.GetY())
		{
			return 2;
		}
		if (Loc.gpCord.GetX() > gpCord.GetX() && Loc.gpCord.GetY() == gpCord.GetY())
		{
			return 6;
		}
		if (Loc.gpCord.GetX() < gpCord.GetX() && Loc.gpCord.GetY() == gpCord.GetY())
		{
			return 4;
		}
		if (Loc.gpCord.GetX() > gpCord.GetX() && Loc.gpCord.GetY() > gpCord.GetY())
		{
			return 9;
		}
		if (Loc.gpCord.GetX() > gpCord.GetX() && Loc.gpCord.GetY() < gpCord.GetY())
		{
			return 3;
		}
		if (Loc.gpCord.GetX() < gpCord.GetX() && Loc.gpCord.GetY() > gpCord.GetY())
		{
			return 7;
		}
		if (Loc.gpCord.GetX() < gpCord.GetX() && Loc.gpCord.GetY() < gpCord.GetY())
		{
			return 1;
		}
	}

	bool qGigaParsecLoc::operator<(const qGigaParsecLoc& other) const
	{
		if (other.gpCord.GetZ() < gpCord.GetZ())
		{
			return true;
		}
		else if (gpCord.GetZ() < other.gpCord.GetZ())
		{
			return false;
		}
		else if (other.gpCord.GetY() < gpCord.GetY())
		{
			return true;
		}
		else if (gpCord.GetY() < other.gpCord.GetY())
		{
			return false;
		}
		else if (other.gpCord.GetX() < gpCord.GetX())
		{
			return true;
		}
		else /* (gpCord.GetX() < other.gpCord.GetX()) */
		{
			return false;
		}
	}

	qUNI::qGigaParsecLoc qGigaParsecLoc::operator+(const qGigaParsecLoc& other) const
	{
		return qGigaParsecLoc(gpCord + other.gpCord);
	}

	qUNI::qGigaParsecLoc& qGigaParsecLoc::operator+=(const qGigaParsecLoc& other)
	{
		gpCord += other.gpCord;
		return *this;
	}

	qUNI::qGigaParsecLoc qGigaParsecLoc::operator-(const qGigaParsecLoc& other) const
	{
		return qGigaParsecLoc(gpCord - other.gpCord);
	}

	qUNI::qGigaParsecLoc& qGigaParsecLoc::operator-=(const qGigaParsecLoc& other)
	{
		gpCord -= other.gpCord;
		return *this;
	}

	bool qMegaParsecLoc::operator==(const qMegaParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord) {
			return true;
		}
		return false;
	}

	qMegaParsecLoc::qMegaParsecLoc(qGigaParsecLoc GPCord, Point3D MPCord)
	{
		setCord(GPCord.gpCord, MPCord);
	}

	qMegaParsecLoc::qMegaParsecLoc(Point3D GPCord, Point3D MPCord)
	{
		setCord(GPCord, MPCord);
	}

	qMegaParsecLoc::qMegaParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qMegaParsecLoc::~qMegaParsecLoc()
	{

	}

	void qMegaParsecLoc::setCord(Point3D GPCord, Point3D MPCord)
	{
		gpCord = GPCord; mpCord = MPCord;
	}

	void qMegaParsecLoc::adjustX(int NumToAdjust)
	{
		mpCord.SetX(mpCord.GetX() + NumToAdjust); fixCords();
	}

	int qMegaParsecLoc::GetX()
	{
		return mpCord.GetX();
	}

	void qMegaParsecLoc::setAllX(qMegaParsecLoc Cord)
	{
		qGigaParsecLoc::setAllX(Cord.gpCord); mpCord.SetX(Cord.mpCord.GetX());
	}

	void qMegaParsecLoc::adjustY(int NumToAdjust)
	{
		mpCord.SetY(mpCord.GetY() + NumToAdjust); fixCords();
	}

	int qMegaParsecLoc::GetY()
	{
		return mpCord.GetY();
	}

	void qMegaParsecLoc::setAllY(qMegaParsecLoc Cord)
	{
		qGigaParsecLoc::setAllY(Cord.gpCord); mpCord.SetY(Cord.mpCord.GetY());
	}

	int qMegaParsecLoc::GetZ()
	{
		return mpCord.GetZ();
	}

	qUNI::qMegaParsecLoc qMegaParsecLoc::getMPCord()
	{
		return qMegaParsecLoc(gpCord, mpCord);
	}

	qUNI::qMegaParsecLoc qMegaParsecLoc::getCord()
	{
		return *this;
	}

	Point3D qMegaParsecLoc::getLocalCord()
	{
		return mpCord;
	}

	bool qMegaParsecLoc::isWithinBotLeftTopRight(qMegaParsecLoc BotLeft, qMegaParsecLoc TopRight)
	{
		if (qGigaParsecLoc::isWithinBotLeftTopRight(BotLeft, TopRight))
		{
			if (mpCord.GetX() >= BotLeft.mpCord.GetX() && mpCord.GetX() <= TopRight.mpCord.GetX()
				&& mpCord.GetY() >= BotLeft.mpCord.GetY() && mpCord.GetY() <= TopRight.mpCord.GetY()
				&& mpCord.GetZ() >= BotLeft.mpCord.GetZ() && mpCord.GetZ() <= TopRight.mpCord.GetZ())
			{
				return true;
			}
		}
		return false;
	}

	int qMegaParsecLoc::dirPointComparison(qMegaParsecLoc Loc)
	{
		int toReturn = qGigaParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.mpCord.GetX() == mpCord.GetX() && Loc.mpCord.GetY() == mpCord.GetY())
		{
			return 5;
		}
		if (Loc.mpCord.GetX() == mpCord.GetX() && Loc.mpCord.GetY() > mpCord.GetY())
		{
			return 8;
		}
		if (Loc.mpCord.GetX() == mpCord.GetX() && Loc.mpCord.GetY() < mpCord.GetY())
		{
			return 2;
		}
		if (Loc.mpCord.GetX() > mpCord.GetX() && Loc.mpCord.GetY() == mpCord.GetY())
		{
			return 6;
		}
		if (Loc.mpCord.GetX() < mpCord.GetX() && Loc.mpCord.GetY() == mpCord.GetY())
		{
			return 4;
		}
		if (Loc.mpCord.GetX() > mpCord.GetX() && Loc.mpCord.GetY() > mpCord.GetY())
		{
			return 9;
		}
		if (Loc.mpCord.GetX() > mpCord.GetX() && Loc.mpCord.GetY() < mpCord.GetY())
		{
			return 3;
		}
		if (Loc.mpCord.GetX() < mpCord.GetX() && Loc.mpCord.GetY() > mpCord.GetY())
		{
			return 7;
		}
		if (Loc.mpCord.GetX() < mpCord.GetX() && Loc.mpCord.GetY() < mpCord.GetY())
		{
			return 1;
		}
	}

	int qMegaParsecLoc::fixCords()
	{

		int toReturn = 5;

		if (mpCord.GetX() >= 0 && mpCord.GetX() < dims
			&& mpCord.GetY() >= 0 && mpCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (mpCord.GetX() < 0 && mpCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (mpCord.GetX() >= dims && mpCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (mpCord.GetX() < dims && mpCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (mpCord.GetX() >= dims && mpCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (mpCord.GetX() >= dims && mpCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (mpCord.GetX() < 0 && mpCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (mpCord.GetX() < dims && mpCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (mpCord.GetX() < 0 && mpCord.GetY() < dims)
		{
			toReturn = 4;
		}

		while (mpCord.GetX() < 0)
		{
			mpCord.SetX(mpCord.GetX() + dims);
			gpCord.SetX(gpCord.GetX() - 1);
		}
		while (mpCord.GetX() >= dims)
		{
			mpCord.SetX(mpCord.GetX() - dims);
			gpCord.SetX(gpCord.GetX() + 1);
		}
		while (mpCord.GetY() < 0)
		{
			mpCord.SetY(mpCord.GetY() + dims);
			gpCord.SetY(gpCord.GetY() - 1);
		}
		while (mpCord.GetY() >= dims)
		{
			mpCord.SetY(mpCord.GetY() - dims);
			gpCord.SetY(gpCord.GetY() + 1);
		}
		while (mpCord.GetZ() < 0)
		{
			mpCord.SetZ(mpCord.GetZ() + dims);
			gpCord.SetZ(gpCord.GetZ() - 1);
		}
		while (mpCord.GetZ() >= dims)
		{
			mpCord.SetZ(mpCord.GetZ() - dims);
			gpCord.SetZ(gpCord.GetZ() + 1);
		}
		return toReturn;
	}

	qUNI::qMegaParsecLoc qMegaParsecLoc::operator+(const qMegaParsecLoc& other) const
	{
		qUNI::qMegaParsecLoc toReturn = qMegaParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord);
		return toReturn;
	}

	qUNI::qMegaParsecLoc& qMegaParsecLoc::operator+=(const qMegaParsecLoc& other)
	{
		gpCord += other.gpCord; 
		mpCord += other.mpCord;
		return *this;
	}

	qUNI::qMegaParsecLoc qMegaParsecLoc::operator-(const qMegaParsecLoc& other) const
	{
		qUNI::qMegaParsecLoc toReturn = qMegaParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord);
		return toReturn;
	}

	qUNI::qMegaParsecLoc& qMegaParsecLoc::operator-=(const qMegaParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		return *this;
	}

	bool qKiloParsecLoc::operator==(const qKiloParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord) {
			return true;
		}
		return false;
	}

	qKiloParsecLoc::qKiloParsecLoc(qMegaParsecLoc MPCord, Point3D KPCord)
	{
		setCord(MPCord.gpCord, MPCord.mpCord, KPCord);
	}

	qKiloParsecLoc::qKiloParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord)
	{
		setCord(GPCord, MPCord, KPCord);
	}

	qKiloParsecLoc::qKiloParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qKiloParsecLoc::~qKiloParsecLoc()
	{

	}

	void qKiloParsecLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord;
	}

	void qKiloParsecLoc::adjustX(int NumToAdjust)
	{
		kpCord.SetX(kpCord.GetX() + NumToAdjust); fixCords();
	}

	int qKiloParsecLoc::GetX()
	{
		return kpCord.GetX();
	}

	void qKiloParsecLoc::setAllX(qKiloParsecLoc Cord)
	{
		qMegaParsecLoc::setAllX(Cord.getMPCord()); kpCord.SetX(Cord.kpCord.GetX());
	}

	void qKiloParsecLoc::adjustY(int NumToAdjust)
	{
		kpCord.SetY(kpCord.GetY() + NumToAdjust); fixCords();
	}

	int qKiloParsecLoc::GetY()
	{
		return kpCord.GetY();
	}

	void qKiloParsecLoc::setAllY(qKiloParsecLoc Cord)
	{
		qMegaParsecLoc::setAllY(Cord.getMPCord()); kpCord.SetY(Cord.kpCord.GetY());
	}

	int qKiloParsecLoc::GetZ()
	{
		return kpCord.GetZ();
	}

	qUNI::qKiloParsecLoc qKiloParsecLoc::getKPCord()
	{
		return qKiloParsecLoc(gpCord, mpCord, kpCord);
	}

	qUNI::qKiloParsecLoc qKiloParsecLoc::getCord()
	{
		return *this;
	}

	Point3D qKiloParsecLoc::getLocalCord()
	{
		return kpCord;
	}

	bool qKiloParsecLoc::isWithinBotLeftTopRight(qKiloParsecLoc BotLeft, qKiloParsecLoc TopRight)
	{
		if (qMegaParsecLoc::isWithinBotLeftTopRight(BotLeft, TopRight))
		{
			if (kpCord.GetX() >= BotLeft.kpCord.GetX() && kpCord.GetX() <= TopRight.kpCord.GetX()
				&& kpCord.GetY() >= BotLeft.kpCord.GetY() && kpCord.GetY() <= TopRight.kpCord.GetY()
				&& kpCord.GetZ() >= BotLeft.kpCord.GetZ() && kpCord.GetZ() <= TopRight.kpCord.GetZ())
			{
				return true;
			}
		}
		return false;
	}

	int qKiloParsecLoc::dirPointComparison(qKiloParsecLoc Loc)
	{
		int toReturn = qMegaParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.kpCord.GetX() == kpCord.GetX() && Loc.kpCord.GetY() == kpCord.GetY())
		{
			return 5;
		}
		if (Loc.kpCord.GetX() == kpCord.GetX() && Loc.kpCord.GetY() > kpCord.GetY())
		{
			return 8;
		}
		if (Loc.kpCord.GetX() == kpCord.GetX() && Loc.kpCord.GetY() < kpCord.GetY())
		{
			return 2;
		}
		if (Loc.kpCord.GetX() > kpCord.GetX() && Loc.kpCord.GetY() == kpCord.GetY())
		{
			return 6;
		}
		if (Loc.kpCord.GetX() < kpCord.GetX() && Loc.kpCord.GetY() == kpCord.GetY())
		{
			return 4;
		}
		if (Loc.kpCord.GetX() > kpCord.GetX() && Loc.kpCord.GetY() > kpCord.GetY())
		{
			return 9;
		}
		if (Loc.kpCord.GetX() > kpCord.GetX() && Loc.kpCord.GetY() < kpCord.GetY())
		{
			return 3;
		}
		if (Loc.kpCord.GetX() < kpCord.GetX() && Loc.kpCord.GetY() > kpCord.GetY())
		{
			return 7;
		}
		if (Loc.kpCord.GetX() < kpCord.GetX() && Loc.kpCord.GetY() < kpCord.GetY())
		{
			return 1;
		}
	}

	int qKiloParsecLoc::fixCords(bool initParent /*= false*/)
	{
		int toReturn = 5;

		if (kpCord.GetX() >= 0 && kpCord.GetX() < dims
			&& kpCord.GetY() >= 0 && kpCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (kpCord.GetX() < 0 && kpCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (kpCord.GetX() >= dims && kpCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (kpCord.GetX() < dims && kpCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (kpCord.GetX() >= dims && kpCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (kpCord.GetX() >= dims && kpCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (kpCord.GetX() < 0 && kpCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (kpCord.GetX() < dims && kpCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (kpCord.GetX() < 0 && kpCord.GetY() < dims)
		{
			toReturn = 4;
		}

		while (kpCord.GetX() < 0)
		{
			kpCord.SetX(kpCord.GetX() + dims);
			mpCord.SetX(mpCord.GetX() - 1);
			initParent = true;
		}
		while (kpCord.GetX() >= dims)
		{
			kpCord.SetX(kpCord.GetX() - dims);
			mpCord.SetX(mpCord.GetX() + 1);
			initParent = true;
		}
		while (kpCord.GetY() < 0)
		{
			kpCord.SetY(kpCord.GetY() + dims);
			mpCord.SetY(mpCord.GetY() - 1);
			initParent = true;
		}
		while (kpCord.GetY() >= dims)
		{
			kpCord.SetY(kpCord.GetY() - dims);
			mpCord.SetY(mpCord.GetY() + 1);
			initParent = true;
		}
		while (kpCord.GetZ() < 0)
		{
			kpCord.SetZ(kpCord.GetZ() + dims);
			mpCord.SetZ(mpCord.GetZ() - 1);
			initParent = true;
		}
		while (kpCord.GetZ() >= dims)
		{
			kpCord.SetZ(kpCord.GetZ() - dims);
			mpCord.SetZ(mpCord.GetZ() + 1);
			initParent = true;
		}
		if (initParent)
		{
			qMegaParsecLoc::fixCords();
		}
		return toReturn;
	}

	qUNI::qKiloParsecLoc& qKiloParsecLoc::operator-=(const qKiloParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		return *this;
	}

	qUNI::qKiloParsecLoc qKiloParsecLoc::operator-(const qKiloParsecLoc& other) const
	{
		return qKiloParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord, kpCord - other.kpCord);
	}

	qUNI::qKiloParsecLoc& qKiloParsecLoc::operator+=(const qKiloParsecLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		return *this;
	}

	qUNI::qKiloParsecLoc qKiloParsecLoc::operator+(const qKiloParsecLoc& other) const
	{
		return qKiloParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord, kpCord + other.kpCord);
	}

	bool qParsecLoc::operator==(const qParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord) {
			return true;
		}
		return false;
	}

	qParsecLoc::qParsecLoc(qKiloParsecLoc KPCord, Point3D PCord)
	{
		setCord(KPCord.gpCord, KPCord.mpCord, KPCord.kpCord, PCord);
	}

	qParsecLoc::qParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord);
	}

	qParsecLoc::qParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qParsecLoc::~qParsecLoc()
	{

	}

	void qParsecLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord;
	}

	void qParsecLoc::adjustX(int NumToAdjust)
	{
		pCord.SetX(pCord.GetX() + NumToAdjust); fixCords();
	}

	int qParsecLoc::GetX()
	{
		return pCord.GetX();
	}

	void qParsecLoc::setAllX(qParsecLoc Cord)
	{
		qKiloParsecLoc::setAllX(Cord.getKPCord()); pCord.SetX(Cord.pCord.GetX());
	}

	void qParsecLoc::adjustY(int NumToAdjust)
	{
		pCord.SetY(pCord.GetY() + NumToAdjust); fixCords();
	}

	int qParsecLoc::GetY()
	{
		return pCord.GetY();
	}

	void qParsecLoc::setAllY(qParsecLoc Cord)
	{
		qKiloParsecLoc::setAllY(Cord.getKPCord()); pCord.SetY(Cord.pCord.GetY());
	}

	int qParsecLoc::GetZ()
	{
		return pCord.GetZ();
	}

	qUNI::qParsecLoc qParsecLoc::getPCord()
	{
		return qParsecLoc(gpCord, mpCord, kpCord, pCord);
	}

	qUNI::qParsecLoc qParsecLoc::getCord()
	{
		return *this;
	}

	Point3D qParsecLoc::getLocalCord()
	{
		return pCord;
	}

	bool qParsecLoc::isWithinBotLeftTopRight(qParsecLoc BotLeft, qParsecLoc TopRight)
	{
		if (qKiloParsecLoc::isWithinBotLeftTopRight(BotLeft, TopRight))
		{
			if (pCord.GetX() >= BotLeft.pCord.GetX() && pCord.GetX() <= TopRight.pCord.GetX()
				&& pCord.GetY() >= BotLeft.pCord.GetY() && pCord.GetY() <= TopRight.pCord.GetY()
				&& pCord.GetZ() >= BotLeft.pCord.GetZ() && pCord.GetZ() <= TopRight.pCord.GetZ())
			{
				return true;
			}
		}
		return false;
	}

	int qParsecLoc::dirPointComparison(qParsecLoc Loc)
	{
		int toReturn = qKiloParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.pCord.GetX() == pCord.GetX() && Loc.pCord.GetY() == pCord.GetY())
		{
			return 5;
		}
		if (Loc.pCord.GetX() == pCord.GetX() && Loc.pCord.GetY() > pCord.GetY())
		{
			return 8;
		}
		if (Loc.pCord.GetX() == pCord.GetX() && Loc.pCord.GetY() < pCord.GetY())
		{
			return 2;
		}
		if (Loc.pCord.GetX() > pCord.GetX() && Loc.pCord.GetY() == pCord.GetY())
		{
			return 6;
		}
		if (Loc.pCord.GetX() < pCord.GetX() && Loc.pCord.GetY() == pCord.GetY())
		{
			return 4;
		}
		if (Loc.pCord.GetX() > pCord.GetX() && Loc.pCord.GetY() > pCord.GetY())
		{
			return 9;
		}
		if (Loc.pCord.GetX() > pCord.GetX() && Loc.pCord.GetY() < pCord.GetY())
		{
			return 3;
		}
		if (Loc.pCord.GetX() < pCord.GetX() && Loc.pCord.GetY() > pCord.GetY())
		{
			return 7;
		}
		if (Loc.pCord.GetX() < pCord.GetX() && Loc.pCord.GetY() < pCord.GetY())
		{
			return 1;
		}
	}

	int qParsecLoc::fixCords(bool initParent /*= false*/)
	{
		int toReturn = 5;

		if (pCord.GetX() >= 0 && pCord.GetX() < dims
			&& pCord.GetY() >= 0 && pCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (pCord.GetX() < 0 && pCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (pCord.GetX() >= dims && pCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (pCord.GetX() < dims && pCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (pCord.GetX() >= dims && pCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (pCord.GetX() >= dims && pCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (pCord.GetX() < 0 && pCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (pCord.GetX() < dims && pCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (pCord.GetX() < 0 && pCord.GetY() < dims)
		{
			toReturn = 4;
		}

		//qKiloParsecLoc::fixCords();
		while (pCord.GetX() < 0)
		{
			pCord.SetX(pCord.GetX() + dims);
			kpCord.SetX(kpCord.GetX() - 1);
			initParent = true;
		}
		while (pCord.GetX() >= dims)
		{
			pCord.SetX(pCord.GetX() - dims);
			kpCord.SetX(kpCord.GetX() + 1);
			initParent = true;
		}
		while (pCord.GetY() < 0)
		{
			pCord.SetY(pCord.GetY() + dims);
			kpCord.SetY(kpCord.GetY() - 1);
			initParent = true;
		}
		while (pCord.GetY() >= dims)
		{
			pCord.SetY(pCord.GetY() - dims);
			kpCord.SetY(kpCord.GetY() + 1);
			initParent = true;
		}
		while (pCord.GetZ() < 0)
		{
			pCord.SetZ(pCord.GetZ() + dims);
			kpCord.SetZ(kpCord.GetZ() - 1);
			initParent = true;
		}
		while (pCord.GetZ() >= dims)
		{
			pCord.SetZ(pCord.GetZ() - dims);
			kpCord.SetZ(kpCord.GetZ() + 1);
			initParent = true;
		}
		if (initParent)
		{
			qKiloParsecLoc::fixCords();
		}
		return toReturn;
	}

	qUNI::qParsecLoc& qParsecLoc::operator-=(const qParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		return *this;
	}

	qUNI::qParsecLoc qParsecLoc::operator-(const qParsecLoc& other) const
	{
		return qParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord, kpCord - other.kpCord, pCord - other.pCord);
	}

	qUNI::qParsecLoc& qParsecLoc::operator+=(const qParsecLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		return *this;
	}

	qUNI::qParsecLoc qParsecLoc::operator+(const qParsecLoc& other) const
	{
		return qParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord, kpCord + other.kpCord, pCord + other.pCord);

	}

	bool qAntiKiloParsecLoc::operator==(const qAntiKiloParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord) {
			return true;
		}
		return false;
	}

	qAntiKiloParsecLoc::qAntiKiloParsecLoc(qParsecLoc PCord, Point3D AKPCord)
	{
		setCord(PCord.gpCord, PCord.mpCord, PCord.kpCord, PCord.pCord, AKPCord);
	}

	qAntiKiloParsecLoc::qAntiKiloParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord);
	}

	qAntiKiloParsecLoc::qAntiKiloParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qAntiKiloParsecLoc::~qAntiKiloParsecLoc()
	{

	}

	void qAntiKiloParsecLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord;
	}

	void qAntiKiloParsecLoc::adjustX(int NumToAdjust)
	{
		akpCord.SetX(akpCord.GetX() + NumToAdjust); fixCords();
	}

	int qAntiKiloParsecLoc::GetX()
	{
		return akpCord.GetX();
	}

	void qAntiKiloParsecLoc::setAllX(qAntiKiloParsecLoc Cord)
	{
		qParsecLoc::setAllX(Cord.getPCord()); akpCord.SetX(Cord.akpCord.GetX());
	}

	void qAntiKiloParsecLoc::adjustY(int NumToAdjust)
	{
		akpCord.SetY(akpCord.GetY() + NumToAdjust); fixCords();
	}

	int qAntiKiloParsecLoc::GetY()
	{
		return akpCord.GetY();
	}

	void qAntiKiloParsecLoc::setAllY(qAntiKiloParsecLoc Cord)
	{
		qParsecLoc::setAllY(Cord.getPCord()); akpCord.SetY(Cord.akpCord.GetY());
	}

	int qAntiKiloParsecLoc::GetZ()
	{
		return akpCord.GetZ();
	}

	qUNI::qAntiKiloParsecLoc qAntiKiloParsecLoc::getAKPCord()
	{
		return qAntiKiloParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord);
	}

	qUNI::qAntiKiloParsecLoc qAntiKiloParsecLoc::getCord()
	{
		return qAntiKiloParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord);
	}

	Point3D qAntiKiloParsecLoc::getLocalCord()
	{
		return akpCord;
	}

	bool qAntiKiloParsecLoc::isWithinBotLeftTopRight(qAntiKiloParsecLoc BotLeft, qAntiKiloParsecLoc TopRight)
	{
		if (qParsecLoc::isWithinBotLeftTopRight(BotLeft, TopRight))
		{
			if (akpCord.GetX() >= BotLeft.akpCord.GetX() && akpCord.GetX() <= TopRight.akpCord.GetX()
				&& akpCord.GetY() >= BotLeft.akpCord.GetY() && akpCord.GetY() <= TopRight.akpCord.GetY()
				&& akpCord.GetZ() >= BotLeft.akpCord.GetZ() && akpCord.GetZ() <= TopRight.akpCord.GetZ())
			{
				return true;
			}
		}
		return false;
	}

	int qAntiKiloParsecLoc::dirPointComparison(qAntiKiloParsecLoc Loc)
	{
		int toReturn = qParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.akpCord.GetX() == akpCord.GetX() && Loc.akpCord.GetY() == akpCord.GetY())
		{
			return 5;
		}
		if (Loc.akpCord.GetX() == akpCord.GetX() && Loc.akpCord.GetY() > akpCord.GetY())
		{
			return 8;
		}
		if (Loc.akpCord.GetX() == akpCord.GetX() && Loc.akpCord.GetY() < akpCord.GetY())
		{
			return 2;
		}
		if (Loc.akpCord.GetX() > akpCord.GetX() && Loc.akpCord.GetY() == akpCord.GetY())
		{
			return 6;
		}
		if (Loc.akpCord.GetX() < akpCord.GetX() && Loc.akpCord.GetY() == akpCord.GetY())
		{
			return 4;
		}
		if (Loc.akpCord.GetX() > akpCord.GetX() && Loc.akpCord.GetY() > akpCord.GetY())
		{
			return 9;
		}
		if (Loc.akpCord.GetX() > akpCord.GetX() && Loc.akpCord.GetY() < akpCord.GetY())
		{
			return 3;
		}
		if (Loc.akpCord.GetX() < akpCord.GetX() && Loc.akpCord.GetY() > akpCord.GetY())
		{
			return 7;
		}
		if (Loc.akpCord.GetX() < akpCord.GetX() && Loc.akpCord.GetY() < akpCord.GetY())
		{
			return 1;
		}
	}

	int qAntiKiloParsecLoc::fixCords(bool initParent /*= false*/)
	{
		int toReturn = 5;

		if (akpCord.GetX() >= 0 && akpCord.GetX() < dims
			&& akpCord.GetY() >= 0 && akpCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (akpCord.GetX() < 0 && akpCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (akpCord.GetX() >= dims && akpCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (akpCord.GetX() < dims && akpCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (akpCord.GetX() >= dims && akpCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (akpCord.GetX() >= dims && akpCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (akpCord.GetX() < 0 && akpCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (akpCord.GetX() < dims && akpCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (akpCord.GetX() < 0 && akpCord.GetY() < dims)
		{
			toReturn = 4;
		}



		while (akpCord.GetX() < 0)
		{
			akpCord.SetX(akpCord.GetX() + dims);
			pCord.SetX(pCord.GetX() - 1);
			initParent = true;
		}
		while (akpCord.GetX() >= dims)
		{
			akpCord.SetX(akpCord.GetX() - dims);
			pCord.SetX(pCord.GetX() + 1);
			initParent = true;
		}
		while (akpCord.GetY() < 0)
		{
			akpCord.SetY(akpCord.GetY() + dims);
			pCord.SetY(pCord.GetY() - 1);
			initParent = true;
		}
		while (akpCord.GetY() >= dims)
		{
			akpCord.SetY(akpCord.GetY() - dims);
			pCord.SetY(pCord.GetY() + 1);
			initParent = true;
		}
		while (akpCord.GetZ() < 0)
		{
			akpCord.SetZ(akpCord.GetZ() + dims);
			pCord.SetZ(pCord.GetZ() - 1);
			initParent = true;
		}
		while (akpCord.GetZ() >= dims)
		{
			akpCord.SetZ(akpCord.GetZ() - dims);
			pCord.SetZ(pCord.GetZ() + 1);
			initParent = true;
		}
		if (initParent)
		{
			qParsecLoc::fixCords();
		}
		return toReturn;
	}

	qUNI::qAntiKiloParsecLoc& qAntiKiloParsecLoc::operator-=(const qAntiKiloParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		return *this;
	}

	qUNI::qAntiKiloParsecLoc qAntiKiloParsecLoc::operator-(const qAntiKiloParsecLoc& other) const
	{
		return qAntiKiloParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord);
	}

	qUNI::qAntiKiloParsecLoc& qAntiKiloParsecLoc::operator+=(const qAntiKiloParsecLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		return *this;
	}

	qUNI::qAntiKiloParsecLoc qAntiKiloParsecLoc::operator+(const qAntiKiloParsecLoc& other) const
	{
		return qAntiKiloParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord);
	}

	bool qAntiMegaParsecLoc::operator==(const qAntiMegaParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord) {
			return true;
		}
		return false;
	}

	qAntiMegaParsecLoc::qAntiMegaParsecLoc(qAntiKiloParsecLoc AKPCord, Point3D AMPCord)
	{
		setCord(AKPCord.gpCord, AKPCord.mpCord, AKPCord.kpCord, AKPCord.pCord, AKPCord.akpCord, AMPCord);
	}

	qAntiMegaParsecLoc::qAntiMegaParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord);
	}

	qAntiMegaParsecLoc::qAntiMegaParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qAntiMegaParsecLoc::~qAntiMegaParsecLoc()
	{

	}

	void qAntiMegaParsecLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord;
	}

	void qAntiMegaParsecLoc::adjustX(int NumToAdjust)
	{
		ampCord.SetX(ampCord.GetX() + NumToAdjust); fixCords();
	}

	int qAntiMegaParsecLoc::GetX()
	{
		return ampCord.GetX();
	}

	void qAntiMegaParsecLoc::setAllX(qAntiMegaParsecLoc Cord)
	{
		qAntiKiloParsecLoc::setAllX(Cord.getAKPCord()); ampCord.SetX(Cord.ampCord.GetX());
	}

	void qAntiMegaParsecLoc::adjustY(int NumToAdjust)
	{
		ampCord.SetY(ampCord.GetY() + NumToAdjust); fixCords();
	}

	int qAntiMegaParsecLoc::GetY()
	{
		return ampCord.GetY();
	}

	void qAntiMegaParsecLoc::setAllY(qAntiMegaParsecLoc Cord)
	{
		qAntiKiloParsecLoc::setAllY(Cord.getAKPCord()); ampCord.SetY(Cord.ampCord.GetY());
	}

	int qAntiMegaParsecLoc::GetZ()
	{
		return ampCord.GetZ();
	}

	qUNI::qAntiMegaParsecLoc qAntiMegaParsecLoc::getAMPCord()
	{
		return qAntiMegaParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord);
	}

	qUNI::qAntiMegaParsecLoc qAntiMegaParsecLoc::getCord()
	{
		return qAntiMegaParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord);
	}

	Point3D qAntiMegaParsecLoc::getLocalCord()
	{
		return ampCord;
	}

	bool qAntiMegaParsecLoc::isWithinBotLeftTopRight(qAntiMegaParsecLoc BotLeft, qAntiMegaParsecLoc TopRight)
	{
		if (qAntiKiloParsecLoc::isWithinBotLeftTopRight(BotLeft, TopRight))
		{
			if (ampCord.GetX() >= BotLeft.ampCord.GetX() && ampCord.GetX() <= TopRight.ampCord.GetX()
				&& ampCord.GetY() >= BotLeft.ampCord.GetY() && ampCord.GetY() <= TopRight.ampCord.GetY()
				&& ampCord.GetZ() >= BotLeft.ampCord.GetZ() && ampCord.GetZ() <= TopRight.ampCord.GetZ())
			{
				return true;
			}
		}
		return false;
	}

	int qAntiMegaParsecLoc::dirPointComparison(qAntiMegaParsecLoc Loc)
	{
		int toReturn = qAntiKiloParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.ampCord.GetX() == ampCord.GetX() && Loc.ampCord.GetY() == ampCord.GetY())
		{
			return 5;
		}
		if (Loc.ampCord.GetX() == ampCord.GetX() && Loc.ampCord.GetY() > ampCord.GetY())
		{
			return 8;
		}
		if (Loc.ampCord.GetX() == ampCord.GetX() && Loc.ampCord.GetY() < ampCord.GetY())
		{
			return 2;
		}
		if (Loc.ampCord.GetX() > ampCord.GetX() && Loc.ampCord.GetY() == ampCord.GetY())
		{
			return 6;
		}
		if (Loc.ampCord.GetX() < ampCord.GetX() && Loc.ampCord.GetY() == ampCord.GetY())
		{
			return 4;
		}
		if (Loc.ampCord.GetX() > ampCord.GetX() && Loc.ampCord.GetY() > ampCord.GetY())
		{
			return 9;
		}
		if (Loc.ampCord.GetX() > ampCord.GetX() && Loc.ampCord.GetY() < ampCord.GetY())
		{
			return 3;
		}
		if (Loc.ampCord.GetX() < ampCord.GetX() && Loc.ampCord.GetY() > ampCord.GetY())
		{
			return 7;
		}
		if (Loc.ampCord.GetX() < ampCord.GetX() && Loc.ampCord.GetY() < ampCord.GetY())
		{
			return 1;
		}
	}

	int qAntiMegaParsecLoc::fixCords(bool initParent /*= false*/)
	{
		int toReturn = 5;

		if (ampCord.GetX() >= 0 && ampCord.GetX() < dims
			&& ampCord.GetY() >= 0 && ampCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (ampCord.GetX() < 0 && ampCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (ampCord.GetX() >= dims && ampCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (ampCord.GetX() < dims && ampCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (ampCord.GetX() >= dims && ampCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (ampCord.GetX() >= dims && ampCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (ampCord.GetX() < 0 && ampCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (ampCord.GetX() < dims && ampCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (ampCord.GetX() < 0 && ampCord.GetY() < dims)
		{
			toReturn = 4;
		}

		while (ampCord.GetX() < 0)
		{
			ampCord.SetX(ampCord.GetX() + dims);
			akpCord.SetX(akpCord.GetX() - 1);
			initParent = true;
		}
		while (ampCord.GetX() >= dims)
		{
			ampCord.SetX(ampCord.GetX() - dims);
			akpCord.SetX(akpCord.GetX() + 1);
			initParent = true;
		}
		while (ampCord.GetY() < 0)
		{
			ampCord.SetY(ampCord.GetY() + dims);
			akpCord.SetY(akpCord.GetY() - 1);
			initParent = true;
		}
		while (ampCord.GetY() >= dims)
		{
			ampCord.SetY(ampCord.GetY() - dims);
			akpCord.SetY(akpCord.GetY() + 1);
			initParent = true;
		}
		while (ampCord.GetZ() < 0)
		{
			ampCord.SetZ(ampCord.GetZ() + dims);
			akpCord.SetZ(akpCord.GetZ() - 1);
			initParent = true;
		}
		while (ampCord.GetZ() >= dims)
		{
			ampCord.SetZ(ampCord.GetZ() - dims);
			akpCord.SetZ(akpCord.GetZ() + 1);
			initParent = true;
		}
		if (initParent)
		{
			qAntiKiloParsecLoc::fixCords();
		}
		return toReturn;
	}

	qUNI::qAntiMegaParsecLoc& qAntiMegaParsecLoc::operator-=(const qAntiMegaParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		return *this;		
	}

	qUNI::qAntiMegaParsecLoc qAntiMegaParsecLoc::operator-(const qAntiMegaParsecLoc& other) const
	{
		return qAntiMegaParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord);

	}

	qUNI::qAntiMegaParsecLoc& qAntiMegaParsecLoc::operator+=(const qAntiMegaParsecLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		return *this;
	}

	qUNI::qAntiMegaParsecLoc qAntiMegaParsecLoc::operator+(const qAntiMegaParsecLoc& other) const
	{
		return qAntiMegaParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord);
	}

	bool qAntiGigaParsecLoc::operator==(const qAntiGigaParsecLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord) {
			return true;
		}
		return false;
	}

	qAntiGigaParsecLoc::qAntiGigaParsecLoc(qAntiMegaParsecLoc AMPCord, Point3D AGPCord)
	{
		setCord(AMPCord.gpCord, AMPCord.mpCord, AMPCord.kpCord, AMPCord.pCord, AMPCord.akpCord, AMPCord.ampCord, AGPCord);
	}

	qAntiGigaParsecLoc::qAntiGigaParsecLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord);
	}

	qAntiGigaParsecLoc::qAntiGigaParsecLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qAntiGigaParsecLoc::~qAntiGigaParsecLoc()
	{

	}

	void qAntiGigaParsecLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord;
	}

	void qAntiGigaParsecLoc::adjustX(int NumToAdjust)
	{
		agpCord.SetX(agpCord.GetX() + NumToAdjust); fixCords();
	}

	int qAntiGigaParsecLoc::GetX()
	{
		return agpCord.GetX();
	}

	void qAntiGigaParsecLoc::setAllX(qAntiGigaParsecLoc Cord)
	{
		qAntiMegaParsecLoc::setAllX(Cord.getAMPCord()); agpCord.SetX(Cord.agpCord.GetX());
	}

	void qAntiGigaParsecLoc::adjustY(int NumToAdjust)
	{
		agpCord.SetY(agpCord.GetY() + NumToAdjust); fixCords();
	}

	int qAntiGigaParsecLoc::GetY()
	{
		return agpCord.GetY();
	}

	void qAntiGigaParsecLoc::setAllY(qAntiGigaParsecLoc Cord)
	{
		qAntiMegaParsecLoc::setAllY(Cord.getAMPCord()); agpCord.SetY(Cord.agpCord.GetY());
	}

	int qAntiGigaParsecLoc::GetZ()
	{
		return agpCord.GetZ();
	}

	qUNI::qAntiGigaParsecLoc qAntiGigaParsecLoc::getAGPCord()
	{
		return qAntiGigaParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord);
	}

	qUNI::qAntiGigaParsecLoc qAntiGigaParsecLoc::getCord()
	{
		return qAntiGigaParsecLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord);
	}

	Point3D qAntiGigaParsecLoc::getLocalCord()
	{
		return agpCord;
	}

	int qAntiGigaParsecLoc::dirPointComparison(qAntiGigaParsecLoc Loc)
	{
		int toReturn = qAntiMegaParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.agpCord.GetX() == agpCord.GetX() && Loc.agpCord.GetY() == agpCord.GetY())
		{
			return 5;
		}
		if (Loc.agpCord.GetX() == agpCord.GetX() && Loc.agpCord.GetY() > agpCord.GetY())
		{
			return 8;
		}
		if (Loc.agpCord.GetX() == agpCord.GetX() && Loc.agpCord.GetY() < agpCord.GetY())
		{
			return 2;
		}
		if (Loc.agpCord.GetX() > agpCord.GetX() && Loc.agpCord.GetY() == agpCord.GetY())
		{
			return 6;
		}
		if (Loc.agpCord.GetX() < agpCord.GetX() && Loc.agpCord.GetY() == agpCord.GetY())
		{
			return 4;
		}
		if (Loc.agpCord.GetX() > agpCord.GetX() && Loc.agpCord.GetY() > agpCord.GetY())
		{
			return 9;
		}
		if (Loc.agpCord.GetX() > agpCord.GetX() && Loc.agpCord.GetY() < agpCord.GetY())
		{
			return 3;
		}
		if (Loc.agpCord.GetX() < agpCord.GetX() && Loc.agpCord.GetY() > agpCord.GetY())
		{
			return 7;
		}
		if (Loc.agpCord.GetX() < agpCord.GetX() && Loc.agpCord.GetY() < agpCord.GetY())
		{
			return 1;
		}
	}

	int qAntiGigaParsecLoc::fixCords(bool initParent /*= false*/)
	{
		int toReturn = 5;

		if (agpCord.GetX() >= 0 && agpCord.GetX() < dims
			&& agpCord.GetY() >= 0 && agpCord.GetY() < dims)
		{
			//toReturn is already 5
		}
		else if (agpCord.GetX() < 0 && agpCord.GetY() < 0)
		{
			toReturn = 1;
		}
		else if (agpCord.GetX() >= dims && agpCord.GetY() < 0)
		{
			toReturn = 3;
		}
		else if (agpCord.GetX() < dims && agpCord.GetY() < 0)
		{
			toReturn = 2;
		}
		else if (agpCord.GetX() >= dims && agpCord.GetY() >= dims)
		{
			toReturn = 9;
		}
		else if (agpCord.GetX() >= dims && agpCord.GetY() < dims)
		{
			toReturn = 6;
		}
		else if (agpCord.GetX() < 0 && agpCord.GetY() >= dims)
		{
			toReturn = 7;
		}
		else if (agpCord.GetX() < dims && agpCord.GetY() >= dims)
		{
			toReturn = 8;
		}
		else if (agpCord.GetX() < 0 && agpCord.GetY() < dims)
		{
			toReturn = 4;
		}


		while (agpCord.GetX() < 0)
		{
			agpCord.SetX(agpCord.GetX() + dims);
			ampCord.SetX(ampCord.GetX() - 1);
			initParent = true;
		}
		while (agpCord.GetX() >= dims)
		{
			agpCord.SetX(agpCord.GetX() - dims);
			ampCord.SetX(ampCord.GetX() + 1);
			initParent = true;
		}
		while (agpCord.GetY() < 0)
		{
			agpCord.SetY(agpCord.GetY() + dims);
			ampCord.SetY(ampCord.GetY() - 1);
			initParent = true;
		}
		while (agpCord.GetY() >= dims)
		{
			agpCord.SetY(agpCord.GetY() - dims);
			ampCord.SetY(ampCord.GetY() + 1);
			initParent = true;
		}
		while (agpCord.GetZ() < 0)
		{
			agpCord.SetZ(agpCord.GetZ() + dims);
			ampCord.SetZ(ampCord.GetZ() - 1);
			initParent = true;
		}
		while (agpCord.GetZ() >= dims)
		{
			agpCord.SetZ(agpCord.GetZ() - dims);
			ampCord.SetZ(ampCord.GetZ() + 1);
			initParent = true;
		}
		if (initParent)
		{
			qAntiMegaParsecLoc::fixCords();
		}
		return toReturn;
	}



	qUNI::qAntiGigaParsecLoc& qAntiGigaParsecLoc::operator-=(const qAntiGigaParsecLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		return *this;
	}

	qUNI::qAntiGigaParsecLoc qAntiGigaParsecLoc::operator-(const qAntiGigaParsecLoc& other) const
	{
		return qAntiGigaParsecLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord);
	}

	qUNI::qAntiGigaParsecLoc& qAntiGigaParsecLoc::operator+=(const qAntiGigaParsecLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		return *this;
	}

	qUNI::qAntiGigaParsecLoc qAntiGigaParsecLoc::operator+(const qAntiGigaParsecLoc& other) const
	{
		return qAntiGigaParsecLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord);
	}

	bool qGodLoc::operator==(const qGodLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord
			&& other.godCord == godCord) {
			return true;
		}
		return false;
	}

	qGodLoc::qGodLoc(qAntiGigaParsecLoc AGPCord, Point3D GodCord)
	{
		setCord(AGPCord.gpCord, AGPCord.mpCord, AGPCord.kpCord, AGPCord.pCord, AGPCord.akpCord, AGPCord.ampCord, AGPCord.agpCord, GodCord);
	}

	qGodLoc::qGodLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord, GodCord);
	}

	qGodLoc::qGodLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qGodLoc::~qGodLoc()
	{

	}

	void qGodLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord; godCord = GodCord;
	}

	void qGodLoc::adjustX(int NumToAdjust)
	{
		godCord.SetX(godCord.GetX() + NumToAdjust); 
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qGodLoc::GetX()
	{
		return godCord.GetX();
	}

	void qGodLoc::setAllX(qGodLoc Cord)
	{
		qAntiGigaParsecLoc::setAllX(Cord.getAGPCord()); godCord.SetX(Cord.godCord.GetX());
	}

	void qGodLoc::adjustY(int NumToAdjust)
	{
		godCord.SetY(godCord.GetY() + NumToAdjust); 

		Point3D throwaway;
		fixCords(throwaway);
	}

	int qGodLoc::GetY()
	{
		return godCord.GetY();
	}

	void qGodLoc::setAllY(qGodLoc Cord)
	{
		qAntiGigaParsecLoc::setAllY(Cord.getAGPCord()); godCord.SetY(Cord.godCord.GetY());
	}

	int qGodLoc::GetZ()
	{
		return godCord.GetZ();
	}

	qUNI::qGodLoc qGodLoc::getGodCord()
	{
		return qGodLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord);
	}

	qUNI::qGodLoc qGodLoc::getCord()
	{
		return qGodLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord);
	}

	Point3D qGodLoc::getLocalCord()
	{
		return godCord;
	}

	int qGodLoc::dirPointComparison(qGodLoc Loc)
	{
		int toReturn = qAntiGigaParsecLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.godCord.GetX() == godCord.GetX() && Loc.godCord.GetY() == godCord.GetY())
		{
			return 5;
		}
		if (Loc.godCord.GetX() == godCord.GetX() && Loc.godCord.GetY() > godCord.GetY())
		{
			return 8;
		}
		if (Loc.godCord.GetX() == godCord.GetX() && Loc.godCord.GetY() < godCord.GetY())
		{
			return 2;
		}
		if (Loc.godCord.GetX() > godCord.GetX() && Loc.godCord.GetY() == godCord.GetY())
		{
			return 6;
		}
		if (Loc.godCord.GetX() < godCord.GetX() && Loc.godCord.GetY() == godCord.GetY())
		{
			return 4;
		}
		if (Loc.godCord.GetX() > godCord.GetX() && Loc.godCord.GetY() > godCord.GetY())
		{
			return 9;
		}
		if (Loc.godCord.GetX() > godCord.GetX() && Loc.godCord.GetY() < godCord.GetY())
		{
			return 3;
		}
		if (Loc.godCord.GetX() < godCord.GetX() && Loc.godCord.GetY() > godCord.GetY())
		{
			return 7;
		}
		if (Loc.godCord.GetX() < godCord.GetX() && Loc.godCord.GetY() < godCord.GetY())
		{
			return 1;
		}
	}

	int qGodLoc::fixCords(Point3D& offset, bool initParent /* = false */)
	{

		offset = Point3D(0, 0, 0);
		while (godCord.GetX() < 0)
		{
			godCord.SetX(godCord.GetX() + dims);
			agpCord.SetX(agpCord.GetX() - 1);
			offset.x--;
			initParent = true;
		}
		while (godCord.GetX() >= dims)
		{
			godCord.SetX(godCord.GetX() - dims);
			agpCord.SetX(agpCord.GetX() + 1);
			offset.x++;
			initParent = true;
		}
		while (godCord.GetY() < 0)
		{
			godCord.SetY(godCord.GetY() + dims);
			agpCord.SetY(agpCord.GetY() - 1);
			offset.y--;
			initParent = true;
		}
		while (godCord.GetY() >= dims)
		{
			godCord.SetY(godCord.GetY() - dims);
			agpCord.SetY(agpCord.GetY() + 1);
			offset.y++;
			initParent = true;
		}
		while (godCord.GetZ() < 0)
		{
			godCord.SetZ(godCord.GetZ() + dims);
			agpCord.SetZ(agpCord.GetZ() - 1);
			offset.z++;
			initParent = true;
		}
		while (godCord.GetZ() >= dims)
		{
			godCord.SetZ(godCord.GetZ() - dims);
			agpCord.SetZ(agpCord.GetZ() + 1);
			offset.z--;
			initParent = true;
		}
		int toReturn = CORDFUNC::coordOffset2dToSpiralIndex(offset);
		toReturn++;
		if(initParent)
		{
			qAntiGigaParsecLoc::fixCords();
		}
		return toReturn;
	}

	qUNI::qGodLoc& qGodLoc::operator-=(const qGodLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		godCord -= other.godCord;
		return *this;
	}

	qUNI::qGodLoc qGodLoc::operator-(const qGodLoc& other) const
	{
		return qGodLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord
			, godCord - other.godCord);

	}

	qUNI::qGodLoc& qGodLoc::operator+=(const qGodLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		godCord += other.godCord;
		return *this;
	}

	qUNI::qGodLoc qGodLoc::operator+(const qGodLoc& other) const
	{
		return qGodLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord
			, godCord + other.godCord);
	}

	bool qWorldLoc::operator==(const qWorldLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord
			&& other.godCord == godCord
			&& other.worldCord == worldCord) {
			return true;
		}
		return false;
	}

	qWorldLoc::qWorldLoc(qGodLoc GodCord, Point3D WorldCord)
	{
		setCord(GodCord.gpCord, GodCord.mpCord, GodCord.kpCord, GodCord.pCord, GodCord.akpCord, GodCord.ampCord, GodCord.agpCord, GodCord.godCord, WorldCord);
	}

	qWorldLoc::qWorldLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord, GodCord, WorldCord);
	}

	qWorldLoc::qWorldLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qWorldLoc::~qWorldLoc()
	{

	}

	void qWorldLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord; godCord = GodCord; worldCord = WorldCord;
	}

	void qWorldLoc::adjustX(int NumToAdjust)
	{
		worldCord.SetX(worldCord.GetX() + NumToAdjust);
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qWorldLoc::GetX()
	{
		return worldCord.GetX();
	}

	void qWorldLoc::setAllX(qWorldLoc Cord)
	{
		qGodLoc::setAllX(Cord.getGodCord()); worldCord.SetX(Cord.worldCord.GetX());
	}

	void qWorldLoc::adjustY(int NumToAdjust)
	{
		worldCord.SetY(worldCord.GetY() + NumToAdjust); 
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qWorldLoc::GetY()
	{
		return worldCord.GetY();
	}

	void qWorldLoc::setAllY(qWorldLoc Cord)
	{
		qGodLoc::setAllY(Cord.getGodCord()); worldCord.SetY(Cord.worldCord.GetY());
	}

	int qWorldLoc::GetZ()
	{
		return worldCord.GetZ();
	}

	qUNI::qWorldLoc qWorldLoc::getWorldCord()
	{
		return qWorldLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord);
	}

	qUNI::qWorldLoc qWorldLoc::getCord()
	{
		return qWorldLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord);
	}

	Point3D qWorldLoc::getLocalCord()
	{
		return worldCord;
	}

	int qWorldLoc::dirPointComparison(qWorldLoc Loc)
	{
		int toReturn = qGodLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.worldCord.GetX() == worldCord.GetX() && Loc.worldCord.GetY() == worldCord.GetY())
		{
			return 5;
		}
		if (Loc.worldCord.GetX() == worldCord.GetX() && Loc.worldCord.GetY() > worldCord.GetY())
		{
			return 8;
		}
		if (Loc.worldCord.GetX() == worldCord.GetX() && Loc.worldCord.GetY() < worldCord.GetY())
		{
			return 2;
		}
		if (Loc.worldCord.GetX() > worldCord.GetX() && Loc.worldCord.GetY() == worldCord.GetY())
		{
			return 6;
		}
		if (Loc.worldCord.GetX() < worldCord.GetX() && Loc.worldCord.GetY() == worldCord.GetY())
		{
			return 4;
		}
		if (Loc.worldCord.GetX() > worldCord.GetX() && Loc.worldCord.GetY() > worldCord.GetY())
		{
			return 9;
		}
		if (Loc.worldCord.GetX() > worldCord.GetX() && Loc.worldCord.GetY() < worldCord.GetY())
		{
			return 3;
		}
		if (Loc.worldCord.GetX() < worldCord.GetX() && Loc.worldCord.GetY() > worldCord.GetY())
		{
			return 7;
		}
		if (Loc.worldCord.GetX() < worldCord.GetX() && Loc.worldCord.GetY() < worldCord.GetY())
		{
			return 1;
		}
	}

	int qWorldLoc::fixCords(Point3D& offset, bool initParent /* = false */)
	{
		offset = Point3D(0, 0, 0);
		while (worldCord.GetX() < 0)
		{
			worldCord.SetX(worldCord.GetX() + dims);
			godCord.SetX(godCord.GetX() - 1);
			offset.x--;
			initParent = true;
		}
		while (worldCord.GetX() >= dims)
		{
			worldCord.SetX(worldCord.GetX() - dims);
			godCord.SetX(godCord.GetX() + 1);
			offset.x++;
			initParent = true;
		}
		while (worldCord.GetY() < 0)
		{
			worldCord.SetY(worldCord.GetY() + dims);
			godCord.SetY(godCord.GetY() - 1);
			offset.y--;
			initParent = true;
		}
		while (worldCord.GetY() >= dims)
		{
			worldCord.SetY(worldCord.GetY() - dims);
			godCord.SetY(godCord.GetY() + 1);
			offset.y++;
			initParent = true;
		}
		while (worldCord.GetZ() < 0)
		{
			worldCord.SetZ(worldCord.GetZ() + dims);
			godCord.SetZ(godCord.GetZ() - 1);
			offset.z++;
			initParent = true;
		}
		while (worldCord.GetZ() >= dims)
		{
			worldCord.SetZ(worldCord.GetZ() - dims);
			godCord.SetZ(godCord.GetZ() + 1);
			offset.z--;
			initParent = true;
		}

		int toReturn = CORDFUNC::coordOffset2dToSpiralIndex(offset);
		toReturn++;
		if (initParent)
		{
			Point3D throwaway;
			qGodLoc::fixCords(throwaway);
		}

		return toReturn;
	}

	qUNI::qWorldLoc& qWorldLoc::operator-=(const qWorldLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		godCord -= other.godCord;
		worldCord -= other.worldCord;
		return *this;
	}

	qUNI::qWorldLoc qWorldLoc::operator-(const qWorldLoc& other) const
	{
		return qWorldLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord
			, godCord - other.godCord
			, worldCord - other.worldCord);

	}

	qUNI::qWorldLoc& qWorldLoc::operator+=(const qWorldLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		godCord += other.godCord;
		worldCord += other.worldCord;
		return *this;
	}

	qUNI::qWorldLoc qWorldLoc::operator+(const qWorldLoc& other) const
	{
		return qWorldLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord
			, godCord + other.godCord
			, worldCord + other.worldCord);
	}

	bool qAreaLoc::operator==(const qAreaLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord
			&& other.godCord == godCord
			&& other.worldCord == worldCord
			&& other.areaCord == areaCord) {
			return true;
		}
		return false;
	}

	qAreaLoc::qAreaLoc(qWorldLoc WorldCord, Point3D AreaCord)
	{
		setCord(WorldCord.gpCord, WorldCord.mpCord, WorldCord.kpCord, WorldCord.pCord, WorldCord.akpCord, WorldCord.ampCord, WorldCord.agpCord, WorldCord.godCord, WorldCord.worldCord, AreaCord);
	}

	qAreaLoc::qAreaLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord, GodCord, WorldCord, AreaCord);
	}

	qAreaLoc::qAreaLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qAreaLoc::~qAreaLoc()
	{

	}

	void qAreaLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord; godCord = GodCord; worldCord = WorldCord; areaCord = AreaCord;
	}

	void qAreaLoc::adjustX(int NumToAdjust)
	{
		areaCord.SetX(areaCord.GetX() + NumToAdjust); 
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qAreaLoc::GetX()
	{
		return areaCord.GetX();
	}

	void qAreaLoc::setAllX(qAreaLoc Cord)
	{
		qWorldLoc::setAllX(Cord.getWorldCord()); areaCord.SetX(Cord.areaCord.GetX());
	}

	void qAreaLoc::adjustY(int NumToAdjust)
	{
		areaCord.SetY(areaCord.GetY() + NumToAdjust); 
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qAreaLoc::GetY()
	{
		return areaCord.GetY();
	}

	void qAreaLoc::setAllY(qAreaLoc Cord)
	{
		qWorldLoc::setAllY(Cord.getWorldCord()); areaCord.SetY(Cord.areaCord.GetY());
	}

	int qAreaLoc::GetZ()
	{
		return areaCord.GetZ();
	}

	qUNI::qAreaLoc qAreaLoc::getAreaCord()
	{
		return qAreaLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord);
	}

	qUNI::qAreaLoc qAreaLoc::getCord()
	{
		return qAreaLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord);
	}

	Point3D qAreaLoc::getLocalCord()
	{
		return areaCord;
	}

	int qAreaLoc::dirPointComparison(qAreaLoc Loc)
	{
		int toReturn = qWorldLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.areaCord.GetX() == areaCord.GetX() && Loc.areaCord.GetY() == areaCord.GetY())
		{
			return 5;
		}
		if (Loc.areaCord.GetX() == areaCord.GetX() && Loc.areaCord.GetY() > areaCord.GetY())
		{
			return 8;
		}
		if (Loc.areaCord.GetX() == areaCord.GetX() && Loc.areaCord.GetY() < areaCord.GetY())
		{
			return 2;
		}
		if (Loc.areaCord.GetX() > areaCord.GetX() && Loc.areaCord.GetY() == areaCord.GetY())
		{
			return 6;
		}
		if (Loc.areaCord.GetX() < areaCord.GetX() && Loc.areaCord.GetY() == areaCord.GetY())
		{
			return 4;
		}
		if (Loc.areaCord.GetX() > areaCord.GetX() && Loc.areaCord.GetY() > areaCord.GetY())
		{
			return 9;
		}
		if (Loc.areaCord.GetX() > areaCord.GetX() && Loc.areaCord.GetY() < areaCord.GetY())
		{
			return 3;
		}
		if (Loc.areaCord.GetX() < areaCord.GetX() && Loc.areaCord.GetY() > areaCord.GetY())
		{
			return 7;
		}
		if (Loc.areaCord.GetX() < areaCord.GetX() && Loc.areaCord.GetY() < areaCord.GetY())
		{
			return 1;
		}
	}

	int qAreaLoc::fixCords(Point3D& offset, bool initParent /* = false */)
	{
		if (areaCord.GetX() >= 0 && areaCord.GetX() < dims
			&& areaCord.GetY() >= 0 && areaCord.GetY() < dims)
		{
			//toReturn is already 5
		}

		offset = Point3D(0, 0, 0);

		while (areaCord.GetX() < 0)
		{
			areaCord.SetX(areaCord.GetX() + dims);
			worldCord.SetX(worldCord.GetX() - 1);
			offset.x--;
			initParent = true;
		}
		while (areaCord.GetX() >= dims)
		{
			areaCord.SetX(areaCord.GetX() - dims);
			worldCord.SetX(worldCord.GetX() + 1);
			offset.x++;
			initParent = true;
		}
		while (areaCord.GetY() < 0)
		{
			areaCord.SetY(areaCord.GetY() + dims);
			worldCord.SetY(worldCord.GetY() - 1);
			offset.y--;
			initParent = true;
		}
		while (areaCord.GetY() >= dims)
		{
			areaCord.SetY(areaCord.GetY() - dims);
			worldCord.SetY(worldCord.GetY() + 1);
			offset.y++;
			initParent = true;
		}
		while (areaCord.GetZ() < 0)
		{
			areaCord.SetZ(areaCord.GetZ() + dims);
			worldCord.SetZ(worldCord.GetZ() - 1);
			offset.z++;
			initParent = true;
		}
		while (areaCord.GetZ() >= dims)
		{
			areaCord.SetZ(areaCord.GetZ() - dims);
			worldCord.SetZ(worldCord.GetZ() + 1);
			offset.z--;
			initParent = true;
		}


		int toReturn = CORDFUNC::coordOffset2dToSpiralIndex(offset);
		toReturn++;
		if (initParent)
		{
			Point3D throwaway;
			qWorldLoc::fixCords(throwaway);
		}

		return toReturn;
	}

	qUNI::qAreaLoc& qAreaLoc::operator-=(const qAreaLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		godCord -= other.godCord;
		worldCord -= other.worldCord;
		areaCord -= other.areaCord;
		return *this;
	}

	qUNI::qAreaLoc qAreaLoc::operator-(const qAreaLoc& other) const
	{
		return qAreaLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord
			, godCord - other.godCord
			, worldCord - other.worldCord
			, areaCord - other.areaCord);
	}

	qUNI::qAreaLoc& qAreaLoc::operator+=(const qAreaLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		godCord += other.godCord;
		worldCord += other.worldCord;
		areaCord += other.areaCord;
		return *this;
	}

	qUNI::qAreaLoc qAreaLoc::operator+(const qAreaLoc& other) const
	{  
		return qAreaLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord
			, godCord + other.godCord
			, worldCord + other.worldCord
			, areaCord + other.areaCord);
	}

	bool qRegionLoc::operator==(const qRegionLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord
			&& other.godCord == godCord
			&& other.worldCord == worldCord
			&& other.areaCord == areaCord
			&& other.regionCord == regionCord) {
			return true;
		}
		return false;
	}

	qRegionLoc::qRegionLoc(qAreaLoc AreaCord, Point3D RegionCord)
	{
		setCord(AreaCord.gpCord, AreaCord.mpCord, AreaCord.kpCord, AreaCord.pCord, AreaCord.akpCord, AreaCord.ampCord, AreaCord.agpCord, AreaCord.godCord, AreaCord.worldCord, AreaCord.areaCord, RegionCord);
	}

	qRegionLoc::qRegionLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord, GodCord, WorldCord, AreaCord, RegionCord);
	}

	qRegionLoc::qRegionLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qRegionLoc::~qRegionLoc()
	{

	}

	void qRegionLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord; godCord = GodCord; worldCord = WorldCord; areaCord = AreaCord; regionCord = RegionCord;
	}

	void qRegionLoc::adjustX(int NumToAdjust)
	{
		regionCord.SetX(regionCord.GetX() + NumToAdjust); 
		Point3D throwaway;
		fixCords(throwaway);
	}

	int qRegionLoc::GetX()
	{
		return regionCord.GetX();
	}

	void qRegionLoc::setAllX(qRegionLoc Cord)
	{
		qAreaLoc::setAllX(Cord.getAreaCord()); regionCord.SetX(Cord.regionCord.GetX());
	}

	void qRegionLoc::adjustY(int NumToAdjust)
	{
		regionCord.SetY(regionCord.GetY() + NumToAdjust); 

		Point3D throwaway;
		fixCords(throwaway);
	}

	int qRegionLoc::GetY()
	{
		return regionCord.GetY();
	}

	void qRegionLoc::setAllY(qRegionLoc Cord)
	{
		qAreaLoc::setAllY(Cord.getAreaCord()); regionCord.SetY(Cord.regionCord.GetY());
	}

	int qRegionLoc::GetZ()
	{
		return regionCord.GetZ();
	}

	qUNI::qRegionLoc qRegionLoc::getRegionCord()
	{
		return qRegionLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord, regionCord);
	}

	qUNI::qRegionLoc qRegionLoc::getCord()
	{
		return qRegionLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord, regionCord);
	}

	Point3D qRegionLoc::getLocalCord()
	{
		return regionCord;
	}

	int qRegionLoc::dirPointComparison(qRegionLoc Loc)
	{
		int toReturn = qAreaLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.regionCord.GetX() == regionCord.GetX() && Loc.regionCord.GetY() == regionCord.GetY())
		{
			return 5;
		}
		if (Loc.regionCord.GetX() == regionCord.GetX() && Loc.regionCord.GetY() > regionCord.GetY())
		{
			return 8;
		}
		if (Loc.regionCord.GetX() == regionCord.GetX() && Loc.regionCord.GetY() < regionCord.GetY())
		{
			return 2;
		}
		if (Loc.regionCord.GetX() > regionCord.GetX() && Loc.regionCord.GetY() == regionCord.GetY())
		{
			return 6;
		}
		if (Loc.regionCord.GetX() < regionCord.GetX() && Loc.regionCord.GetY() == regionCord.GetY())
		{
			return 4;
		}
		if (Loc.regionCord.GetX() > regionCord.GetX() && Loc.regionCord.GetY() > regionCord.GetY())
		{
			return 9;
		}
		if (Loc.regionCord.GetX() > regionCord.GetX() && Loc.regionCord.GetY() < regionCord.GetY())
		{
			return 3;
		}
		if (Loc.regionCord.GetX() < regionCord.GetX() && Loc.regionCord.GetY() > regionCord.GetY())
		{
			return 7;
		}
		if (Loc.regionCord.GetX() < regionCord.GetX() && Loc.regionCord.GetY() < regionCord.GetY())
		{
			return 1;
		}
	}

	int qRegionLoc::fixCords(Point3D& offset, bool initParent /* = false */)
	{
		offset = Point3D(0, 0, 0);
		while (regionCord.GetX() < 0)
		{
			regionCord.SetX(regionCord.GetX() + dims);
			areaCord.SetX(areaCord.GetX() - 1);
			offset.x--;
			initParent = true;
		}
		while (regionCord.GetX() >= dims)
		{
			regionCord.SetX(regionCord.GetX() - dims);
			areaCord.SetX(areaCord.GetX() + 1);
			offset.x++;
			initParent = true;
		}
		while (regionCord.GetY() < 0)
		{
			regionCord.SetY(regionCord.GetY() + dims);
			areaCord.SetY(areaCord.GetY() - 1);
			offset.y--;
			initParent = true;
		}
		while (regionCord.GetY() >= dims)
		{
			regionCord.SetY(regionCord.GetY() - dims);
			areaCord.SetY(areaCord.GetY() + 1);
			offset.y++;
			initParent = true;
		}
		while (regionCord.GetZ() < 0)
		{
			regionCord.SetZ(regionCord.GetZ() + dims);
			areaCord.SetZ(areaCord.GetZ() - 1);
			offset.z++;
			initParent = true;
		}
		while (regionCord.GetZ() >= dims)
		{
			regionCord.SetZ(regionCord.GetZ() - dims);
			areaCord.SetZ(areaCord.GetZ() + 1);
			offset.z--;
			initParent = true;
		}
		int toReturn = CORDFUNC::coordOffset2dToSpiralIndex(offset);
		toReturn++;
		if (initParent)
		{
			Point3D throwaway;
			qAreaLoc::fixCords(throwaway);
		}

		return toReturn;
	}

	qUNI::qRegionLoc qRegionLoc::operator-(const qRegionLoc& other) const
	{
		return qRegionLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord
			, godCord - other.godCord
			, worldCord - other.worldCord
			, areaCord - other.areaCord
			, regionCord - other.regionCord);
	}

	qUNI::qRegionLoc& qRegionLoc::operator+=(const qRegionLoc& other)
	{		  
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		godCord += other.godCord;
		worldCord += other.worldCord;
		areaCord += other.areaCord;
		regionCord += other.regionCord;
		return *this;
	}

	qUNI::qRegionLoc qRegionLoc::operator+(const qRegionLoc& other) const
	{
		return qRegionLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord
			, godCord + other.godCord
			, worldCord + other.worldCord
			, areaCord + other.areaCord
			, regionCord + other.regionCord);
	}

	qUNI::qRegionLoc& qRegionLoc::operator-=(const qRegionLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		godCord -= other.godCord;
		worldCord -= other.worldCord;
		areaCord -= other.areaCord;
		regionCord -= other.regionCord;
		return *this;
	}

	qUNI::qAreaLoc qRegionLoc::asAreaMap()
	{
		return qAreaLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord);
	}

	bool qLocalLoc::operator==(const qLocalLoc& other) const
	{
		if (other.gpCord == gpCord
			&& other.mpCord == mpCord
			&& other.kpCord == kpCord
			&& other.pCord == pCord
			&& other.akpCord == akpCord
			&& other.ampCord == ampCord
			&& other.agpCord == agpCord
			&& other.godCord == godCord
			&& other.worldCord == worldCord
			&& other.areaCord == areaCord
			&& other.regionCord == regionCord
			&& other.localCord == localCord) {
			return true;
		}
		return false;
	}

	qLocalLoc::qLocalLoc(qRegionLoc RegionCord, Point3D LocalCord)
	{
		setCord(RegionCord.gpCord, RegionCord.mpCord, RegionCord.kpCord, RegionCord.pCord, RegionCord.akpCord, RegionCord.ampCord, RegionCord.agpCord, RegionCord.godCord, RegionCord.worldCord, RegionCord.areaCord, RegionCord.regionCord, LocalCord);
	}

	qLocalLoc::qLocalLoc(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord, Point3D LocalCord)
	{
		setCord(GPCord, MPCord, KPCord, PCord, AKPCord, AMPCord, AGPCord, GodCord, WorldCord, AreaCord, RegionCord, LocalCord);
	}

	qLocalLoc::qLocalLoc()
	{
		setCord(Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1), Point3D(-1, -1, -1));
	}

	qLocalLoc::~qLocalLoc()
	{

	}

	void qLocalLoc::setCord(Point3D GPCord, Point3D MPCord, Point3D KPCord, Point3D PCord, Point3D AKPCord, Point3D AMPCord, Point3D AGPCord, Point3D GodCord, Point3D WorldCord, Point3D AreaCord, Point3D RegionCord, Point3D LocalCord)
	{
		gpCord = GPCord; mpCord = MPCord; kpCord = KPCord; pCord = PCord; akpCord = AKPCord; ampCord = AMPCord; agpCord = AGPCord; godCord = GodCord; worldCord = WorldCord; areaCord = AreaCord; regionCord = RegionCord; localCord = LocalCord;
	}

	void qLocalLoc::adjustX(int NumToAdjust)
	{
		Point3D offset;
		localCord.SetX(localCord.GetX() + NumToAdjust); 
		fixCords(offset);
	}

	int qLocalLoc::GetX()
	{
		return localCord.GetX();
	}

	void qLocalLoc::setAllX(qLocalLoc Cord)
	{
		qRegionLoc::setAllX(Cord.getRegionCord()); localCord.SetX(Cord.localCord.GetX());
	}

	void qLocalLoc::adjustY(int NumToAdjust)
	{
		Point3D offset;
		localCord.SetY(localCord.GetY() + NumToAdjust); 
		fixCords(offset);
	}

	int qLocalLoc::GetY()
	{
		return localCord.GetY();
	}

	void qLocalLoc::setAllY(qLocalLoc Cord)
	{
		qRegionLoc::setAllY(Cord.getRegionCord()); localCord.SetY(Cord.localCord.GetY());
	}

	int qLocalLoc::GetZ()
	{
		return localCord.GetZ();
	}

	qUNI::qLocalLoc qLocalLoc::getCord()
	{
		return qLocalLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord, regionCord, localCord);
	}

	Point3D qLocalLoc::getLocalCord()
	{
		return localCord;
	}

	int qLocalLoc::dirPointComparison(qLocalLoc Loc)
	{
		int toReturn = qRegionLoc::dirPointComparison(Loc);
		if (toReturn != 5)
		{
			return toReturn;
		}
		if (Loc.localCord.GetX() == localCord.GetX() && Loc.localCord.GetY() == localCord.GetY())
		{
			return 5;
		}
		if (Loc.localCord.GetX() == localCord.GetX() && Loc.localCord.GetY() > localCord.GetY())
		{
			return 8;
		}
		if (Loc.localCord.GetX() == localCord.GetX() && Loc.localCord.GetY() < localCord.GetY())
		{
			return 2;
		}
		if (Loc.localCord.GetX() > localCord.GetX() && Loc.localCord.GetY() == localCord.GetY())
		{
			return 6;
		}
		if (Loc.localCord.GetX() < localCord.GetX() && Loc.localCord.GetY() == localCord.GetY())
		{
			return 4;
		}
		if (Loc.localCord.GetX() > localCord.GetX() && Loc.localCord.GetY() > localCord.GetY())
		{
			return 9;
		}
		if (Loc.localCord.GetX() > localCord.GetX() && Loc.localCord.GetY() < localCord.GetY())
		{
			return 3;
		}
		if (Loc.localCord.GetX() < localCord.GetX() && Loc.localCord.GetY() > localCord.GetY())
		{
			return 7;
		}
		if (Loc.localCord.GetX() < localCord.GetX() && Loc.localCord.GetY() < localCord.GetY())
		{
			return 1;
		}
	}

	int qLocalLoc::fixCords(Point3D& offset, bool initParent /* = false */ )
	{
		offset = Point3D(0, 0, 0);
		while (localCord.GetX() < 0)
		{
			localCord.SetX(localCord.GetX() + dims);
			regionCord.SetX(regionCord.GetX() - 1);
			offset.x--;
			initParent = true;
		}
		while (localCord.GetX() >= dims)
		{
			localCord.SetX(localCord.GetX() - dims);
			regionCord.SetX(regionCord.GetX() + 1);
			offset.x++;
			initParent = true;
		}
		while (localCord.GetY() < 0)
		{
			localCord.SetY(localCord.GetY() + dims);
			regionCord.SetY(regionCord.GetY() - 1);
			offset.y--;
			initParent = true;
		}
		while (localCord.GetY() >= dims)
		{
			localCord.SetY(localCord.GetY() - dims);
			regionCord.SetY(regionCord.GetY() + 1);
			offset.y++;
			initParent = true;
		}
		while (localCord.GetZ() < 0)
		{
			localCord.SetZ(localCord.GetZ() + dims);
			regionCord.SetZ(regionCord.GetZ() - 1);
			offset.z++;
			initParent = true;
		}
		while (localCord.GetZ() >= dims)
		{
			localCord.SetZ(localCord.GetZ() - dims);
			regionCord.SetZ(regionCord.GetZ() + 1);
			offset.z--;
			initParent = true;
		}
		int toReturn = CORDFUNC::coordOffset2dToSpiralIndex(offset);
		toReturn++;
		if (initParent)
		{
			Point3D throwaway;
			qRegionLoc::fixCords(throwaway);
		}

		return toReturn;
	}

	qUNI::qLocalLoc qLocalLoc::operator-(const qLocalLoc& other) const
	{
		return qLocalLoc(gpCord - other.gpCord, mpCord - other.mpCord
			, kpCord - other.kpCord, pCord - other.pCord, akpCord - other.akpCord
			, ampCord - other.ampCord, agpCord - other.agpCord
			, godCord - other.godCord
			, worldCord - other.worldCord
			, areaCord - other.areaCord
			, regionCord - other.regionCord
			, localCord - other.localCord);
	}

	qUNI::qLocalLoc& qLocalLoc::operator+=(const qLocalLoc& other)
	{
		gpCord += other.gpCord;
		mpCord += other.mpCord;
		kpCord += other.kpCord;
		pCord += other.pCord;
		akpCord += other.akpCord;
		ampCord += other.ampCord;
		agpCord += other.agpCord;
		godCord += other.godCord;
		worldCord += other.worldCord;
		areaCord += other.areaCord;
		regionCord += other.regionCord;
		localCord += other.localCord;
		return *this;
	}

	qUNI::qLocalLoc qLocalLoc::operator+(const qLocalLoc& other) const
	{
		return qLocalLoc(gpCord + other.gpCord, mpCord + other.mpCord
			, kpCord + other.kpCord, pCord + other.pCord, akpCord + other.akpCord
			, ampCord + other.ampCord, agpCord + other.agpCord
			, godCord + other.godCord
			, worldCord + other.worldCord
			, areaCord + other.areaCord
			, regionCord + other.regionCord
			, localCord + other.localCord);
	}

	qUNI::qLocalLoc& qLocalLoc::operator-=(const qLocalLoc& other)
	{
		gpCord -= other.gpCord;
		mpCord -= other.mpCord;
		kpCord -= other.kpCord;
		pCord -= other.pCord;
		akpCord -= other.akpCord;
		ampCord -= other.ampCord;
		agpCord -= other.agpCord;
		godCord -= other.godCord;
		worldCord -= other.worldCord;
		areaCord -= other.areaCord;
		regionCord -= other.regionCord;
		localCord -= other.localCord;
		return *this;
	}

	//basically the opposite of fixCords
	void qLocalLoc::unFixToMapFocus(qUNI::qLocalLoc MapFocusLoc)
	{
		if (MapFocusLoc.regionCord != regionCord)
		{
			Point3D offset = Point3D(regionCord.GetX() - MapFocusLoc.regionCord.GetX()
				, regionCord.GetY() - MapFocusLoc.regionCord.GetY()
				, regionCord.GetZ() - MapFocusLoc.regionCord.GetZ());
			localCord.SetX(localCord.GetX() + offset.GetX() * dims);
			localCord.SetY(localCord.GetY() + offset.GetY() * dims);
			localCord.SetZ(localCord.GetZ() + offset.GetZ() * dims);
			regionCord = MapFocusLoc.regionCord;
		}
		//if (MapFocusLoc.areaCord != areaCord)
		//{
		//	Point3D offset = Point3D(areaCord.GetX() - MapFocusLoc.areaCord.GetX()
		//		, areaCord.GetY() - MapFocusLoc.areaCord.GetY()
		//		, areaCord.GetZ() - MapFocusLoc.areaCord.GetZ());
		//	localCord.SetX(localCord.GetX() + offset.GetX() * dims * qRegionLoc::dims);
		//	localCord.SetY(localCord.GetY() + offset.GetY() * dims * qRegionLoc::dims);
		//	localCord.SetZ(localCord.GetZ() + offset.GetZ() * dims * qRegionLoc::dims);
		//	areaCord = MapFocusLoc.areaCord;
		//}
		//if (MapFocusLoc.worldCord != worldCord)
		//{
		//	Point3D offset = Point3D(worldCord.GetX() - MapFocusLoc.worldCord.GetX()
		//		, worldCord.GetY() - MapFocusLoc.worldCord.GetY()
		//		, worldCord.GetZ() - MapFocusLoc.worldCord.GetZ());
		//	localCord.SetX(localCord.GetX() + offset.GetX() * dims * qRegionLoc::dims * qAreaLoc::dims);
		//	localCord.SetY(localCord.GetY() + offset.GetY() * dims * qRegionLoc::dims * qAreaLoc::dims);
		//	localCord.SetZ(localCord.GetZ() + offset.GetZ() * dims * qRegionLoc::dims * qAreaLoc::dims);
		//	worldCord = MapFocusLoc.worldCord;
		//}
		//if (MapFocusLoc.godCord != godCord)
		//{
		//	Point3D offset = Point3D(godCord.GetX() - MapFocusLoc.godCord.GetX()
		//		, godCord.GetY() - MapFocusLoc.godCord.GetY()
		//		, godCord.GetZ() - MapFocusLoc.godCord.GetZ());
		//	localCord.SetX(localCord.GetX() + offset.GetX() * dims * qRegionLoc::dims * qAreaLoc::dims * qWorldLoc::dims);
		//	localCord.SetY(localCord.GetY() + offset.GetY() * dims * qRegionLoc::dims * qAreaLoc::dims * qWorldLoc::dims);
		//	localCord.SetZ(localCord.GetZ() + offset.GetZ() * dims * qRegionLoc::dims * qAreaLoc::dims * qWorldLoc::dims);
		//	godCord = MapFocusLoc.godCord;
		//}
	}

	qUNI::qAreaLoc qLocalLoc::asAreaMap()
	{
		return qUNI::qAreaLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord);		
	}

	qUNI::qRegionLoc qLocalLoc::asRegionMap()
	{
		return qUNI::qRegionLoc(gpCord, mpCord, kpCord, pCord, akpCord, ampCord, agpCord, godCord, worldCord, areaCord, regionCord);
	}

	qUNI::qGMK_Coord qLocalLoc::get_GMK_Coord()
	{
		qGMK_Coord toReturn;
		toReturn.set(gpCord, mpCord, kpCord);
		return toReturn;
	}

	qUNI::qPAA_Coord qLocalLoc::get_PAA_Coord()
	{
		qPAA_Coord toReturn;
		toReturn.set(pCord, akpCord, ampCord);
		return toReturn;
	}

	qUNI::qAgw_Coord qLocalLoc::get_Agw_Coord()
	{
		qAgw_Coord toReturn;
		toReturn.set(agpCord, godCord, worldCord);
		return toReturn;
	}

	qUNI::qarl_Coord qLocalLoc::get_arl_Coord()
	{
		qarl_Coord toReturn;
		toReturn.set(areaCord, regionCord, localCord);
		return toReturn;
	}

}

