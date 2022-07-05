//—оздайте класс IntSet(множество целых) с операци€ми + , +=, -, -=, =, == , != , > , < , >= , <= , *, +(int)(добавить в множество),
//-(int)(исключени€ из множества).
#pragma once
#include<iostream>

class IntSet {
	int* set = NULL;
	int count = 0;
public:
	IntSet();
	IntSet(const IntSet& b);
	~IntSet();
	IntSet operator+(const IntSet& Z);
	IntSet operator+=(const IntSet& Z);
	IntSet operator-(const IntSet& Z);
	IntSet operator-=(const IntSet& Z);
	IntSet& operator=(const IntSet& Z); ///
	bool operator==(const IntSet& Z);///
	bool operator!=(const IntSet& Z);/// 
	bool operator>(const IntSet& Z);
	bool operator<(const IntSet& Z);
	bool operator>=(const IntSet& Z);
	bool operator <= (const IntSet& Z);
	IntSet operator *(const IntSet& Z);
	IntSet operator+(int k);  ///
	IntSet operator-(int k);  ///
	void Show();
	IntSet operator>>( int z);
	IntSet operator<<(int z);
	IntSet U(const IntSet& z, const IntSet& t);
	IntSet intrsect(const IntSet& z, const IntSet& This);
	IntSet nointrsect(const IntSet& z, const IntSet& t);
};

int compare(const void* i, const void* j);
