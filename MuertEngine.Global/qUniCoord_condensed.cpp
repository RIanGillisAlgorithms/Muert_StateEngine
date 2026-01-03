#include "pch.h"
#include "qUniCoord_condensed.h"

namespace qUNI
{


	void qGMK_Coord::set(Point3D gigaParsec, Point3D megaParsec, Point3D kiloParsec)
	{
		x = (gigaParsec.x * 1000 * 1000) + (megaParsec.x * 1000) + kiloParsec.x;
		y = (gigaParsec.y * 1000 * 1000) + (megaParsec.y * 1000) + kiloParsec.y;
		z = (gigaParsec.z * 1000 * 1000) + (megaParsec.z * 1000) + kiloParsec.z;
	}

	void qGMK_Coord::setGiga(Point3D gigaParsec)
	{
		x = (gigaParsec.x * 1000 * 1000) + (toMX() * 1000) + toKX();
		y = (gigaParsec.y * 1000 * 1000) + (toMY() * 1000) + toKY();
		z = (gigaParsec.z * 1000 * 1000) + (toMZ() * 1000) + toKZ();
	}

	void qGMK_Coord::setMega(Point3D megaParsec)
	{
		x = (toGX() * 1000 * 1000) + (megaParsec.x * 1000) + toKX();
		y = (toGY() * 1000 * 1000) + (megaParsec.y * 1000) + toKY();
		z = (toGZ() * 1000 * 1000) + (megaParsec.z * 1000) + toKZ();
	}

	void qGMK_Coord::setKilo(Point3D kiloParsec)
	{
		x = (toGX() * 1000 * 1000) + (toKX() * 1000) + kiloParsec.x;
		y = (toGY() * 1000 * 1000) + (toKY() * 1000) + kiloParsec.y;
		z = (toGZ() * 1000 * 1000) + (toKZ() * 1000) + kiloParsec.z;
	}

	Point3D qGMK_Coord::toPoint3D()
	{
		Point3D p;
		p.x = x;
		p.y = y;
		p.z = z;
		return p;
	}

	//qUNI::qGigaParsecLoc qGMK_Coord::toGPLoc()
	//{
	//	qGigaParsecLoc p = qGigaParsecLoc(Point3D(toGX(), toGY(), toGZ()));
	//	return p;
	//}

	//qUNI::qMegaParsecLoc qGMK_Coord::toMPLoc()
	//{
	//	qMegaParsecLoc p = qMegaParsecLoc(toGPLoc(), Point3D(toMX(), toMY(), toMZ()));
	//	return p;
	//}

	//qUNI::qKiloParsecLoc qGMK_Coord::toKPLoc()
	//{
	//	qKiloParsecLoc p = qKiloParsecLoc(toMPLoc(), Point3D(toKX(), toKY(), toKZ()));
	//	return p;
	//}

	int qGMK_Coord::toGX()
	{
		return x / (mx * kx);
	}

	int qGMK_Coord::toGY()
	{
		return y / (my * ky);
	}

	int qGMK_Coord::toGZ()
	{
		return z / (mz * kz);
	}

	int qGMK_Coord::toMX()
	{
		return (x / (kx)) % 1000;
	}

	int qGMK_Coord::toMY()
	{
		return (y / (ky)) % 1000;
	}

	int qGMK_Coord::toMZ()
	{
		return (z / (kz)) % 1000;
	}

	int qGMK_Coord::toKX()
	{
		return x % 1000000;
	}

	int qGMK_Coord::toKY()
	{
		return y % 1000000;
	}

	int qGMK_Coord::toKZ()
	{
		return z % 1000000;
	}

	Point3D qGMK_Coord::toGPoint3D()
	{
		return Point3D(toGX(), toGY(), toGZ());
	}

	Point3D qGMK_Coord::toMPoint3D()
	{
		return Point3D(toMX(), toMY(), toMZ());
	}

	Point3D qGMK_Coord::toKPoint3D()
	{
		return Point3D(toKX(), toKY(), toKZ());
	}

	bool qGMK_Coord::operator<(const qGMK_Coord& other) const
	{
		if (other.z < z)
		{
			return true;
		}
		else if (z < other.z)
		{
			return false;
		}
		else if (other.y < y)
		{
			return true;
		}
		else if (y < other.y)
		{
			return false;
		}
		else if (other.x < x)
		{
			return true;
		}
		else /* (gpCord.GetX() < other.gpCord.GetX()) */
		{
			return false;
		}

	}

	void qPAA_Coord::set(Point3D parsec, Point3D antiKilo, Point3D antiMega)
	{
		x = (parsec.x * 1000 * 1000) + (antiKilo.x * 1000) + antiMega.x;
		y = (parsec.y * 1000 * 1000) + (antiKilo.y * 1000) + antiMega.y;
		z = (parsec.z * 1000 * 1000) + (antiKilo.z * 1000) + antiMega.z;
	}

	void qPAA_Coord::setParsec(Point3D parsec)
	{
		x = (parsec.x * 1000 * 1000) + (toAKPX() * 1000) + toAMPX();
		y = (parsec.y * 1000 * 1000) + (toAKPY() * 1000) + toAMPY();
		z = (parsec.z * 1000 * 1000) + (toAKPZ() * 1000) + toAMPZ();
	}

	void qPAA_Coord::setAntiKilo(Point3D antiKilo)
	{
		x = (toPX() * 1000 * 1000) + (antiKilo.x * 1000) + toAMPX();
		y = (toPY() * 1000 * 1000) + (antiKilo.y * 1000) + toAMPY();
		z = (toPZ() * 1000 * 1000) + (antiKilo.z * 1000) + toAMPZ();
	}

	void qPAA_Coord::setAntiMega(Point3D antiMega)
	{
		x = (toPX() * 1000 * 1000) + (toAKPX() * 1000) + antiMega.x;
		y = (toPY() * 1000 * 1000) + (toAKPY() * 1000) + antiMega.y;
		z = (toPZ() * 1000 * 1000) + (toAKPZ() * 1000) + antiMega.z;
	}

	Point3D qPAA_Coord::toPoint3D()
	{
		Point3D p;
		p.x = x;
		p.y = y;
		p.z = z;
		return p;
	}

	//qUNI::qParsecLoc qPAA_Coord::toPLoc()
	//{
	//	qParsecLoc p = qParsecLoc(parentCoord.toKPLoc(), Point3D(toPX(), toPY(), toPZ()));
	//	return p;
	//}

	//qUNI::qAntiKiloParsecLoc qPAA_Coord::toAPLoc()
	//{
	//	qAntiKiloParsecLoc p = qAntiKiloParsecLoc(toPLoc(), Point3D(toAKPX(), toAKPY(), toAKPZ()));
	//	return p;
	//}

	//qUNI::qAntiMegaParsecLoc qPAA_Coord::toAAPLoc()
	//{
	//	qAntiMegaParsecLoc p = qAntiMegaParsecLoc(toAPLoc(), Point3D(toAMPX(), toAMPY(), toAMPZ()));
	//	return p;
	//}

	int qPAA_Coord::toPX()
	{
		return x / (ax * aax);
	}

	int qPAA_Coord::toPY()
	{
		return y / (ay * aay);
	}

	int qPAA_Coord::toPZ()
	{
		return z / (az * aaz);
	}

	int qPAA_Coord::toAKPX()
	{
		return (x / (aax)) % ax;
	}

	int qPAA_Coord::toAKPY()
	{
		return (y / (aay)) % ay;
	}

	int qPAA_Coord::toAKPZ()
	{
		return (z / (aaz)) % az;
	}

	int qPAA_Coord::toAMPX()
	{
		return x % (ax * aax);
	}

	int qPAA_Coord::toAMPY()
	{
		return y % (ay * aay);
	}

	int qPAA_Coord::toAMPZ()
	{
		return z % (az * aaz);
	}

	Point3D qPAA_Coord::toPPoint3D()
	{
		return Point3D(toPX(), toPY(), toPZ());
	}

	Point3D qPAA_Coord::toAKPPoint3D()
	{
		return Point3D(toAKPX(), toAKPY(), toAKPZ());
	}

	Point3D qPAA_Coord::toAMPPoint3D()
	{
		return Point3D(toAMPX(), toAMPY(), toAMPZ());
	}

	bool qPAA_Coord::operator<(const qPAA_Coord& other) const
	{
		if (other.z < z)
		{
			return true;
		}
		else if (z < other.z)
		{
			return false;
		}
		else if (other.y < y)
		{
			return true;
		}
		else if (y < other.y)
		{
			return false;
		}
		else if (other.x < x)
		{
			return true;
		}
		else /* (gpCord.GetX() < other.gpCord.GetX()) */
		{
			return false;
		}

	}

	void qAgw_Coord::set(Point3D agp, Point3D god, Point3D world)
	{
		x = (agp.x * 1000 * 1000) + (god.x * 1000) + world.x;
		y = (agp.y * 1000 * 1000) + (god.y * 1000) + world.y;
		z = (agp.z * 1000 * 1000) + (god.z * 1000) + world.z;
	}

	void qAgw_Coord::setAGP(Point3D agp)
	{
		x = (agp.x * 1000 * 1000) + (toGodX() * 1000) + toWorldX();
		y = (agp.y * 1000 * 1000) + (toGodY() * 1000) + toWorldY();
		z = (agp.z * 1000 * 1000) + (toGodZ() * 1000) + toWorldZ();
	}

	void qAgw_Coord::setGod(Point3D god)
	{
		x = (toAGPX() * 1000 * 1000) + (god.x * 1000) + toWorldX();
		y = (toAGPY() * 1000 * 1000) + (god.y * 1000) + toWorldY();
		z = (toAGPZ() * 1000 * 1000) + (god.z * 1000) + toWorldZ();
	}

	void qAgw_Coord::setWorld(Point3D world)
	{
		x = (toAGPX() * 1000 * 1000) + (toGodX() * 1000) + world.x;
		y = (toAGPY() * 1000 * 1000) + (toGodY() * 1000) + world.y;
		z = (toAGPZ() * 1000 * 1000) + (toGodZ() * 1000) + world.z;
	}

	Point3D qAgw_Coord::toPoint3D()
	{
		Point3D p;
		p.x = x;
		p.y = y;
		p.z = z;
		return p;
	}

	//qUNI::qAntiGigaParsecLoc qAgw_Coord::toAGPLoc()
	//{
	//	qAntiGigaParsecLoc p = qAntiGigaParsecLoc(parentCoord.toAAPLoc(), Point3D(toAGPX(), toAGPY(), toAGPZ()));
	//	return p;
	//}

	//qUNI::qGodLoc qAgw_Coord::toGodLoc()
	//{
	//	qGodLoc p = qGodLoc(toAGPLoc(), Point3D(toGodX(), toGodY(), toGodZ()));
	//	return p;
	//}

	//qUNI::qWorldLoc qAgw_Coord::toWorldLoc()
	//{
	//	qWorldLoc p = qWorldLoc(toGodLoc(), Point3D(toWorldX(), toWorldY(), toWorldZ()));
	//	return p;
	//}

	int qAgw_Coord::toAGPX()
	{
		return x / (1000 * 1000);
	}

	int qAgw_Coord::toAGPY()
	{
		return y / (1000 * 1000);
	}

	int qAgw_Coord::toAGPZ()
	{
		return z / (1000 * 1000);
	}

	int qAgw_Coord::toGodX()
	{
		return (x / (1000)) % 1000;
	}

	int qAgw_Coord::toGodY()
	{
		return (y / (1000)) % 1000;
	}

	int qAgw_Coord::toGodZ()
	{
		return (z / (1000)) % 1000;
	}

	int qAgw_Coord::toWorldX()
	{
		return x % (1000 * 1000);
	}

	int qAgw_Coord::toWorldY()
	{
		return y % (1000 * 1000);
	}

	int qAgw_Coord::toWorldZ()
	{
		return z % (1000 * 1000);
	}

	Point3D qAgw_Coord::toAGPPoint3D()
	{
		return Point3D(toAGPX(), toAGPY(), toAGPZ());
	}

	Point3D qAgw_Coord::toGodPoint3D()
	{
		return Point3D(toGodX(), toGodY(), toGodZ());
	}

	Point3D qAgw_Coord::toWorldPoint3D()
	{
		return Point3D(toWorldX(), toWorldY(), toWorldZ());
	}

	bool qAgw_Coord::operator<(const qAgw_Coord& other) const
	{

		if (other.z < z)
		{
			return true;
		}
		else if (z < other.z)
		{
			return false;
		}
		else if (other.y < y)
		{
			return true;
		}
		else if (y < other.y)
		{
			return false;
		}
		else if (other.x < x)
		{
			return true;
		}
		else /* (gpCord.GetX() < other.gpCord.GetX()) */
		{
			return false;
		}
	}

	void qarl_Coord::set(Point3D area, Point3D region, Point3D local)
	{
		x = (area.x * 1000 * 1000) + (region.x * 1000) + local.x;
		y = (area.y * 1000 * 1000) + (region.y * 1000) + local.y;
		z = (area.z * 1000 * 1000) + (region.z * 1000) + local.z;
	}

	void qarl_Coord::setArea(Point3D area)
	{
		x = (area.x * 1000 * 1000) + (toRegionX() * 1000) + toLocalX();
		y = (area.y * 1000 * 1000) + (toRegionY() * 1000) + toLocalY();
		z = (area.z * 1000 * 1000) + (toRegionZ() * 1000) + toLocalZ();
	}

	void qarl_Coord::setRegion(Point3D region)
	{
		x = (toAreaX() * 1000 * 1000) + (region.x * 1000) + toLocalX();
		y = (toAreaY() * 1000 * 1000) + (region.y * 1000) + toLocalY();
		z = (toAreaZ() * 1000 * 1000) + (region.z * 1000) + toLocalZ();
	}

	void qarl_Coord::setLocal(Point3D local)
	{
		x = (toAreaX() * 1000 * 1000) + (toRegionX() * 1000) + local.x;
		y = (toAreaY() * 1000 * 1000) + (toRegionY() * 1000) + local.y;
		z = (toAreaZ() * 1000 * 1000) + (toRegionZ() * 1000) + local.z;
	}

	Point3D qarl_Coord::toPoint3D()
	{
		Point3D p;
		p.x = x;
		p.y = y;
		p.z = z;
		return p;
	}

	//qUNI::qAreaLoc qarl_Coord::toAreaLoc()
	//{
	//	qAreaLoc p = qAreaLoc(parentCoord.toWorldLoc(), Point3D(toAreaX(), toAreaY(), toAreaZ()));
	//	return p;
	//}

	//qUNI::qRegionLoc qarl_Coord::toRegionLoc()
	//{
	//	qRegionLoc p = qRegionLoc(toAreaLoc(), Point3D(toRegionX(), toRegionY(), toRegionZ()));
	//	return p;
	//}

	//qUNI::qLocalLoc qarl_Coord::toLocalLoc()
	//{
	//	qLocalLoc p = qLocalLoc(toRegionLoc(), Point3D(toLocalX(), toLocalY(), toLocalZ()));
	//	return p;
	//}

	int qarl_Coord::toAreaX()
	{
		return x / (1000 * 1000);
	}

	int qarl_Coord::toAreaY()
	{
		return y / (1000 * 1000);
	}

	int qarl_Coord::toAreaZ()
	{
		return z / (1000 * 1000);
	}

	int qarl_Coord::toRegionX()
	{
		return (x / (1000)) % 1000;
	}

	int qarl_Coord::toRegionY()
	{
		return (y / (1000)) % 1000;
	}

	int qarl_Coord::toRegionZ()
	{
		return (z / (1000)) % 1000;
	}

	int qarl_Coord::toLocalX()
	{
		return x % (1000 * 1000);
	}

	int qarl_Coord::toLocalY()
	{
		return y % (1000 * 1000);
	}

	int qarl_Coord::toLocalZ()
	{
		return z % (1000 * 1000);
	}

	bool qarl_Coord::operator<(const qarl_Coord& other) const
	{
		if (other.z < z)
		{
			return true;
		}
		else if (z < other.z)
		{
			return false;
		}
		else if (other.y < y)
		{
			return true;
		}
		else if (y < other.y)
		{
			return false;
		}
		else if (other.x < x)
		{
			return true;
		}
		else /* (gpCord.GetX() < other.gpCord.GetX()) */
		{
			return false;
		}

	}

}

