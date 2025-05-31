#pragma once
#include <map>

struct point {

	int x;
	int y;

	point(int x, int y):x(x),y(y) {};

	bool operator < (const point& b) const {
		return (y < b.y);
	}

	bool operator > (const point& b) const {
		return (y > b.y);
	}

	bool operator <= (const point& b) const {
		return (y  <= b.y);
	}

	bool operator >= (const point& b) const {
		return (y >= b.y);
	}

	bool operator == (const point& b) const {
		return (y == b.y);
	}

	point operator - (const point& b) const {
		return point{ x - b.x,y - b.y };
	}

	
};

