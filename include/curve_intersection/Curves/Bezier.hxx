#pragma once
#include "Base_Structures.hxx"
#include "ICurve.hxx"
#include <vector>

namespace CurveIntersection {

class Bezier : public ICurve {
public:
	Bezier(const std::vector<Point>& theControlPoints);
	virtual Range GetRange() const;
	virtual Point GetPoint(double t) const;

	Vector GetDerivative(double t) const;
	std::vector<Point> GetControlPoints() const;

	virtual std::string GetName() const;
	virtual bool EqualTo(const ICurve& theOther) const;
	bool IsValid() const;
private:

	double CalculateBinomialCoefficient(int i, int n) const;
	double CalculateBernsteinPolynom(size_t i, size_t n, double t) const;
	std::vector<Point> myControlPoints;
};
bool operator==(const Bezier& theFirst, const Bezier& theSecound);
}

