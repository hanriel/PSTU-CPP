#pragma once
#include <iostream>

using namespace std;

class Money
{
	long rub;
	int cheers;

public:
	Money() { rub = 0; cheers = 0; };
	Money(long r, int c) { rub = r; cheers = c; };
	Money(const Money& m) { rub = m.rub; cheers = m.cheers; };
	~Money() {};
	long getRub() { return rub; };
	int getCheers() { return cheers; };
	void setRub(long r) { rub = r;  };
	void setCheers(long c) { cheers = c; };

	Money& operator-(long);

	
};

