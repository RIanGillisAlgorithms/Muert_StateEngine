// DefaultPredicate.h
// by ian.gillis
//	Source: https://stackoverflow.com/a/3634540

#pragma once
#ifndef DefaultPredicate_H
#define DefaultPredicate_H

/////////////////////////////////////
//
// Header-Only Default Predicate Class
//
/////////////////////////////////////


template <class T>
class DefaultPredicate
{
public:
	static bool CheckSetter(T value)
	{
		return true;
	}
	static void CheckGetter(T value)
	{
	}
};

template <class T, class Predicate = DefaultPredicate <T>>
class Property
{
public:
	operator T ()
	{
		Predicate::CheckGetter(m_storage);
		return m_storage;
	}
	Property <T, Predicate> &operator = (T rhs)
	{
		if (Predicate::CheckSetter(rhs))
		{
			m_storage = rhs;
		}
		return *this;
	}
private:
	T m_storage;
};


#endif