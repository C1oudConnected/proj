#include <iostream>
#include "CCurve.h"
#include <memory>
#include <vector>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

int main(){
	std::vector<std::shared_ptr<CCurve>> curves;

	curves.push_back(std::make_shared<CHelix>(3, 2));
	curves.push_back(std::make_shared<CCircle>(3));
	curves.push_back(std::make_shared<CCircle>(1));
	curves.push_back(std::make_shared<CHelix>(5, 1));
	curves.push_back(std::make_shared<CCircle>(11));
	curves.push_back(std::make_shared<CCircle>(6));
	curves.push_back(std::make_shared<CCircle>(10));
	curves.push_back(std::make_shared<CEllipse>(10, 20));
	curves.push_back(std::make_shared<CCircle>(8));
	curves.push_back(std::make_shared<CHelix>(10, 3));
	curves.push_back(std::make_shared<CEllipse>(4, 2));
	curves.push_back(std::make_shared<CCircle>(22));
	curves.push_back(std::make_shared<CCircle>(13));
	curves.push_back(std::make_shared<CHelix>(31, 2));
	curves.push_back(std::make_shared<CEllipse>(1, 2));
	curves.push_back(std::make_shared<CHelix>(1, 1));
	curves.push_back(std::make_shared<CCircle>(15));
	curves.push_back(std::make_shared<CEllipse>(3, 4));
	curves.push_back(std::make_shared<CEllipse>(11, 1));
	curves.push_back(std::make_shared<CCircle>(19));
	curves.push_back(std::make_shared<CCircle>(7));
	curves.push_back(std::make_shared<CHelix>(5, 2));

	double val = M_PI_4;

	for (const auto& a : curves) {
		Pt3D pt = a->getPt(val);
		Vect3D der = a->getDeriv(val);
		std::printf("PT = (%.3f, %.3f, %.3f); Derivative = (%.3f, %.3f, %.3f)\n", pt.x, pt.y, pt.z, der.x, der.y, der.z);
	}

	std::vector<std::shared_ptr<CCircle>> circles;

	for (const auto& a : curves) {
		if (std::dynamic_pointer_cast<CCircle>(a))
			circles.push_back(std::dynamic_pointer_cast<CCircle>(a));
	}

	std::sort(circles.begin(), circles.end(),
		[](const std::shared_ptr<CCircle>& lhs, const std::shared_ptr<CCircle>& rhs)
		-> auto {return lhs->m_rad < rhs->m_rad; });

	double rad_sum = 0;

	for (const auto& a : circles) {
		rad_sum += a->m_rad;
	}

	std::cout << std::endl << rad_sum;
}
