#include "gtest/gtest.h"
#include "Curves/EllipseCurve.hxx"
#include "Vector.hxx"

using namespace CurveIntersection;

namespace {
static bool IsEqualPoints(const Point & p1, const Point & p2, double eps = NULL_TOL)
{
	return fabs(p1.x - p2.x) < eps && fabs(p1.y - p2.y) < eps;
}

static bool IsEqualVectors(const Vector & v1, const Vector & v2, double eps = NULL_TOL)
{
	return fabs(v1.x - v2.x) < eps && fabs(v1.y - v2.y) < eps;
}

}

TEST(Ellipse, Constructor)
{
	Point aCenter(0., 0.);
	double aR1 = 1.;
	double aR2 = 2.;
	double aAngle = 1.;
	EllipseCurve aEllipse(aCenter, aR1, aR2, aAngle);
	EXPECT_EQ(aCenter, aEllipse.GetCenter());
	EXPECT_DOUBLE_EQ(aR1, aEllipse.GetR1());
	EXPECT_DOUBLE_EQ(aR2, aEllipse.GetR2());
	EXPECT_DOUBLE_EQ(aAngle, aEllipse.GetAngle());
}

TEST(Ellipse, CopyConstructor)
{
	Point aCenter(2., 22.);
	double aR1 = 3.;
	double aR2 = 85.;
	double aAngle = 0.5;
	EllipseCurve aEllipse(aCenter, aR1, aR2, aAngle);
	EllipseCurve aCopy = aEllipse;
	EXPECT_DOUBLE_EQ(aR1, aCopy.GetR1());
	EXPECT_DOUBLE_EQ(aR2, aEllipse.GetR2());
	EXPECT_DOUBLE_EQ(aAngle, aEllipse.GetAngle());
}

TEST(Ellipse, Assigment)
{
	Point aCenter(55., 75.);
	double aR1 = 1.;
	double aR2 = 5.;
	double aAngle = 0.5;
	EllipseCurve aEllipse(aCenter, aR1, aR2, aAngle);
	EllipseCurve aCopy(Point(0., 0.), 0., 0., 0.);
	aCopy = aEllipse;
	EXPECT_DOUBLE_EQ(aR1, aCopy.GetR1());
	EXPECT_DOUBLE_EQ(aR2, aEllipse.GetR2());
	EXPECT_DOUBLE_EQ(aAngle, aEllipse.GetAngle());
}

TEST(Ellipse, GetPoint)
{
	const EllipseCurve aEllipse(Point(2., 1.), 1., 4., PI / 4.);
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(0.),
		Point(2.7071067811865475, 1.7071067811865475)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*2.),
		Point(2.7071067811865475, 1.7071067811865475)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI / 4.), Point(0.5, 3.5)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*9. / 4.), Point(0.5, 3.5)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI), Point(1.292893218813452, 0.29289321881345287)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*5. / 4.), Point(3.5, -1.5)));
}

TEST(Ellipse, GetPoint2)
{
	const EllipseCurve aEllipse(Point(2., 1.), Point(2.7071067811865475, 1.7071067811865475), Point(0.5, 3.5));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(0.),
		Point(2.7071067811865475, 1.7071067811865475)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*2.),
		Point(2.7071067811865475, 1.7071067811865475)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI / 4.), Point(0.5, 3.5)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*9. / 4.), Point(0.5, 3.5)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI), Point(1.292893218813452, 0.29289321881345287)));
	EXPECT_TRUE(IsEqualPoints(aEllipse.GetPoint(PI*5. / 4.), Point(3.5, -1.5)));
}

TEST(Ellipse, GetRange)
{
	const EllipseCurve aEllipse(Point(2., 1.), 1., 4., PI / 4.);
	const auto aRange = aEllipse.GetRange();
	EXPECT_DOUBLE_EQ(0., aRange.Begin);
	EXPECT_DOUBLE_EQ(PI*2., aRange.End);
}

TEST(Ellipse, GetR1)
{
	const EllipseCurve aEllipse(Point(2., 1.), 1., 4., PI / 4.);
	const auto aR1 = aEllipse.GetR1();
	EXPECT_DOUBLE_EQ(1., aR1);
}

TEST(Ellipse, GetR2)
{
	const EllipseCurve aEllipse(Point(2., 1.), 1., 4., PI / 4.);
	const auto aR2 = aEllipse.GetR2();
	EXPECT_DOUBLE_EQ(4., aR2);
}

TEST(Ellipse, GetAngle)
{
	const EllipseCurve aEllipse(Point(2., 1.), 1., 4., PI / 4.);
	const auto aAngle = aEllipse.GetAngle();
	EXPECT_DOUBLE_EQ(PI / 4, aAngle);
}

TEST(Ellipse, GetDerivative)
{
	const EllipseCurve ellipse(Point(2., 1.), 1., 4., PI / 4.);
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(0.), Vector(-2.82842712474619, 2.8284271247461903)));
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(PI*2.),
		Vector(-2.82842712474619, 2.8284271247461903)));
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(PI / 4.), Vector(-2.5, 1.5)));
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(PI*9. / 4.), Vector(-2.5, 1.5)));
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(PI),
		Vector(2.82842712474619, -2.8284271247461903)));
	EXPECT_TRUE(IsEqualVectors(ellipse.GetDerivative(PI*5. / 4.), Vector(2.5, -1.5)));
}
