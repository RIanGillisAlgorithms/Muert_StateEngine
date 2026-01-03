// enum_array
// by ian.gillis
// date -1.2.25- 12:06:37 PM


//by ian.gillis
#pragma once
#ifndef enum_array_H
#define enum_array_H


/// <summary>
/// from:
///		https://stackoverflow.com/a/59674635/2367188
/// </summary>
/// <typeparam name="IndexType">An enum class that starts with 0 and defines STATE_COUNT as the "total number of entries"</typeparam>
/// <typeparam name="ValueType"></typeparam>
template <class IndexType, class ValueType>
class EnumArray {
public:
	ValueType& operator[](IndexType i) {
		return array_[static_cast<int>(i)];
	}

	const ValueType& operator[](IndexType i) const {
		return array_[static_cast<int>(i)];
	}

	int size() const { return size_; }

private:
	ValueType array_[static_cast<int>(IndexType::STATE_COUNT)];

	int size_ = static_cast<int>(IndexType::STATE_COUNT);
};


#endif