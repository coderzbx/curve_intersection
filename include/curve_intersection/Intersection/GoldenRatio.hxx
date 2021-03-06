#pragma once

#include "curve_intersection/Core/Range.hxx"
#include <functional>

namespace CurveIntersection {

class GoldenRatio {
public:
	GoldenRatio(std::function<double(double)> theFunc, Range theRange, double theEps) :
		myFunction(theFunc), myRange(theRange), myEps(theEps) {};
	double Run();
private:
	std::function<double(double)> myFunction;
	Range myRange;
	double myEps;

};
}
