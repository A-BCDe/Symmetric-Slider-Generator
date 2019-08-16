#include <iostream>
#include <vector>

/// classes
#include "point.hpp"


int main() {
	std::cout << "Total number of slider points : ";
	std::size_t sliderpoint_cnt;
	std::cin >> sliderpoint_cnt;

	std::vector<point> points;
	points.reserve(sliderpoint_cnt);

	for (std::size_t i = 0; i < sliderpoint_cnt / 2; i++) {
	A:
		std::cout << "Enter the coordinate of slider point number " << i + 1 << " : ";
		points.emplace_back(get_point());
	}
	
	std::cout << "Set a point to flip those points : ";
	auto const center = get_point();
	if (sliderpoint_cnt & 1) points.emplace_back(center);

	for (std::size_t i = (sliderpoint_cnt + 1) / 2; i < sliderpoint_cnt; i++) {
		points.emplace_back(2 * center - points[sliderpoint_cnt - i - 1]);
	}

	std::cout << "Resulting points are :\n";
	for (auto p : points) {
		std::cout << '(' << p.x << ", " << p.y << "), ";
	}
}