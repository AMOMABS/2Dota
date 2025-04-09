#pragma once
#include <map>

struct point {

	int x;
	int y;

	point(int x, int y):x(x),y(y) {};

	bool operator < (const point& b) const {
		return x < b.x;
	}

	bool operator == (const point& b) const {
		return x == b.x && y == b.y;
	}

	
};

