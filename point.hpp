#ifndef point_hpp
#define point_hpp

#include <iostream>

struct point {
	std::size_t x, y;
	explicit point(std::size_t x = 0, std::size_t y = 0) : x(x), y(y) {}
	~point() = default;
	point &operator=(point const &p) = default;
	point &operator=(point &&p) noexcept = default;
	point(point const &p) = default;
	point(point &&p) noexcept = default;

	friend point operator*(std::size_t x, point p) {
		p.x *= x;
		p.y *= x;
		return p;
	}
	friend point operator-(point p1, point const &p2) {
		p1.x -= p2.x;
		p1.y -= p2.y;
		return p1;
	}
};

point get_point() {
	int x, y;
A:
	std::cin >> x >> y;
	if (x < 0 || y < 0) {
		std::cout << "Coordinates should be positive integers!\n";
		goto A;
	}
	return point(x, y);
}

#endif