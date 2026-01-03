// Int0To100Predicate.h
// by ian.gillis
#pragma once
#ifndef Int0To100Predicate_H
#define Int0To100Predicate_H

/////////////////////////////////////
//
// Header-Only Default Predicate Class Definitions
//
/////////////////////////////////////


#include <iostream>
#include <sstream>
#include "DefaultPredicate.h"


class NoErrorHandler
{
public:
	static void SignalError(const char *const error)
	{
	}
};

class LogError
{
public:
	static void SignalError(const char *const error)
	{
		std::cout << error << std::endl;
	}
};

class Exception
{
public:
	Exception(const char *const message) :
		m_message(message)
	{
	}

	Exception(std::string message) :
		m_message(message.c_str())
	{
	}

	operator const char *const ()
	{
		return m_message;
	}

private:
	const char
		*const m_message;
};

class ThrowError
{
public:
	static void SignalError(const char *const error)
	{
		throw new Exception(error);
	}
};



#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To5 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 0 || rhs > 5)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 5";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To50 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 0 || rhs > 50)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 50";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To100 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 0 || rhs > 100)
		{
			std::stringstream ss;
			ss << "Value ["<<rhs<<"] out of range. Should be >= 0 and <= 100";		
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To254 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 254)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 254";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To10000 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 0 || rhs > 10000)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 10000";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

/*
Our tile Ids go from 0 - 10403 (102 * 102)
*/
#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To10403 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 0 || rhs > 10403)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 10403";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

/*
This was because I decided to make the maximum # of days in one Season some high #
*/
#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int1To10404 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 1 || rhs > 10404)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 1 and <= 10404";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

/*
This was because I decided to make the maximum # of days in one Season some high #
*/
#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int1To104 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 1 || rhs > 104)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 1 and <= 104";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class IntNeg5ToPos5 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 5 || rhs > 5)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= -5 and <= 5";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class IntNeg10ToPos10 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < 10 || rhs > 10)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= -10 and <= 10";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class IntNeg200ToPos200 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool
			setter_ok = true;

		if (rhs < -200 || rhs > 200)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= -200 and <= 200";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int1To255 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs <= 0 || rhs > 255)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be > 0 and <= 255";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int1To4 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs <= 0 || rhs > 4)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be > 0 and <= 4";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int1To10 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs <= 0 || rhs > 10)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be > 0 and <= 10";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To7 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 7)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 7";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To8 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 8)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 8";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
class Int0To9 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 9)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 9";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


/**************************************************************
			Season/ Day/ Time related


***************************************************************/
#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
//There are 86,400,000 milliseconds in 1 24-hour period
class Int0To86399999 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs >= 86400000)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and < 86400000";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};

#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
//There are 86,400 seconds in 1 24-hour period
class Int0To86399 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs >= 86400)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and < 86400";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
//There are 0-739,840 volume units within 1 qTileCubeVolume level. 
//there can be up to 7 qTileCubeVolume levels in a TileCube, so the maximum volume units in a TileCube is 5,178,400
class Int0To739840 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 739840)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 739840";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#if defined _DEBUG
template <class ErrorHandler = ThrowError>
#else
template <class ErrorHandler = NoErrorHandler>
#endif
//Pressure units range from 0-2,000,000,000
//Pressure values operate in steps of .01, from 0 pressure all the way up to 20,000,000 atmospheres
//multiply the atmosphere value by 100.0 to get the pressure unit
class Int0To2000000000 : public DefaultPredicate <int>
{
public:
	static bool CheckSetter(int rhs)
	{
		bool setter_ok = true;

		if (rhs < 0 || rhs > 2000000000)
		{
			std::stringstream ss;
			ss << "Value [" << rhs << "] out of range. Should be >= 0 and <= 2,000,000,000";
			ErrorHandler::SignalError(ss.str().c_str());
			setter_ok = false;
		}

		return setter_ok;
	}
};


#endif