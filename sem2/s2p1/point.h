#pragma once

struct point {
	double _x; 
	double _y;
	void Init(double, double);
	void Read();
	void Show();
	double Distance(double, double);
};