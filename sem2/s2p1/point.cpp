#include <iostream>
#include "point.h"
#include <cmath>
using namespace std;

void point::Init(double X, double Y)
{
	_x = X;
	_y = Y;
}

void point::Read()
{
	cout << "X: ";
	cin >> _x;
	cout << "Y: ";
	cin >> _y;
}

void point::Show()
{
	cout << "X: " << _x << endl;
	cout << "Y: " << _y << endl;
}

double point::Distance(double x1, double y1)
{
	return sqrt(powf(x1 - _x, 2) + powf(y1 - _y, 2));
}
