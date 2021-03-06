#include "gtest/gtest.h"
#include "curve_intersection/Curves/CircleCurve.hxx"
#include "curve_intersection/Core/Vector.hxx"

using namespace CurveIntersection;

TEST(Circle, ConstructorFromTwoCenterAndRadius)
{
	Point aCenter(0, 0);
	double aRadius = 777.;
	const CircleCurve aCircle(aCenter, aRadius);
	EXPECT_EQ(aCenter, aCircle.GetCenter());
	EXPECT_EQ(777., aCircle.GetRadius());
}

TEST(Circle, CopyConstructor)
{
	const CircleCurve aCircle(Point(0.,7.), 555.);
	CircleCurve aCopy = aCircle;
	EXPECT_EQ(aCircle.GetCenter(), aCopy.GetCenter());
	EXPECT_EQ(aCircle.GetRadius(), aCopy.GetRadius());
	EXPECT_EQ(aCircle.GetRange(), aCopy.GetRange());
}

TEST(Circle, Assigment)
{
	const CircleCurve aCircle(Point(8.,8.), 55.);
	CircleCurve aCopy(Point(0., 0.), 7.);
	aCopy = aCircle;
	EXPECT_EQ(aCircle.GetCenter(), aCopy.GetCenter());
	EXPECT_EQ(aCircle.GetRadius(), aCopy.GetRadius());
	EXPECT_EQ(aCircle.GetRange(), aCopy.GetRange());
}


TEST(Circle, GetPoint)
{
	const CircleCurve circle(Point(1., 1.), 2.);
	EXPECT_TRUE(IsEqual(circle.GetPoint(0.), Point(3., 1.)));
	EXPECT_TRUE(IsEqual(circle.GetPoint(PI*2.), Point(3., 1.)));
	EXPECT_TRUE(IsEqual(circle.GetPoint(PI / 4.), Point(1. + sqrt(2.), 1. + sqrt(2.))));
	EXPECT_TRUE(IsEqual(circle.GetPoint(PI), Point(-1., 1.)));
	EXPECT_TRUE(IsEqual(circle.GetPoint(PI*5. / 4.), Point(1. - sqrt(2.), 1. - sqrt(2.))));
}

TEST(Circle, GetRange)
{
	const CircleCurve circle(Point(1., 1.), 2.);
	const auto range = circle.GetRange();
	EXPECT_NEAR(range.Begin, 0., NULL_TOL);
	EXPECT_NEAR(range.End, PI*2., NULL_TOL);
}

TEST(Circle, GetDerivative)
{
	const CircleCurve circle(Point(1., 1.), 2.);
	EXPECT_TRUE(IsEqual(circle.GetDerivative(0.), Vector(0., 2.)));
	EXPECT_TRUE(IsEqual(circle.GetDerivative(PI*2.), Vector(0., 2.)));
	EXPECT_TRUE(IsEqual(circle.GetDerivative(PI / 4.), Vector(-sqrt(2.), sqrt(2.))));
	EXPECT_TRUE(IsEqual(circle.GetDerivative(PI*9. / 4.), Vector(-sqrt(2.), sqrt(2.))));
	EXPECT_TRUE(IsEqual(circle.GetDerivative(PI), Vector(0., -2.)));
	EXPECT_TRUE(IsEqual(circle.GetDerivative(PI*5. / 4.), Vector(sqrt(2.), -sqrt(2.))));
}

TEST(Circle, InvalidConstructor)
{
	try {
		CircleCurve aCircle(Point(5., 5.), -1.);
		FAIL() << "Expected std::invalid_argument";
	}
	catch (const std::invalid_argument&)  {
		GTEST_SUCCEED();
	}
	catch (...) {
		FAIL() << "Expected std::invalid_argument";
	}
}
