#include <iostream> 
#include <cmath>
#include <algorithm>

using namespace std;

struct Vector {
	double x, y;
	Vector(int x, int y):x(x), y(y){}
	Vector(){}
	double operator ^ (const Vector &v) const {
		return x * v.y - y * v.x;
	}
};

struct str {
	double x, y;
};

Vector operator - (const Vector &p1, const Vector &p2) {
	return Vector(p1.x - p2.x, p1.y - p2.y);
}

bool operator < (const Vector &p1, const Vector &p2) {
	return (Vector(p2 - Vector(0, 0)) ^ Vector(p1 - Vector(0, 0))) > 0;
} 

double point_distance (str pot1, str pot2) {
	return sqrt((pot1.y - pot2.y) * (pot1.y - pot2.y) + (pot1.x - pot2.x) * (pot1.x - pot2.x));
}

double area(str po1, str po2, str po3) {
	double a, b, c, s;
	a = point_distance(po1, po2);
	b = point_distance(po2, po3);
	c = point_distance(po1, po3);
	s = 0.5 * (a + b + c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

Vector ps[60];
str point[60];

int main() {
	int n;
	while (cin >> ps[n].x >> ps[n].y) {
		++n;
		if (n == 3) break;
	}
	sort(ps + 1, ps + n);
	for (int i = n - 1; i >= 0; --i) {
		point[i].x = ps[i].x;
		point[i].y = ps[i].y;
	}
	double a = area(point[0], point[1], point[2]);
	if (a > 0) {
		cout << a << endl;
	} else {
		cout << "The three points entered cannot form a triangle." << endl;
	}
	return 0;
}