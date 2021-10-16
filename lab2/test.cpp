#include "pch.h"
#include "gtest\gtest.h"
#include "...lab2\spiral.h"
#include "...lab2\spiral.cpp"


TEST(SpiralConstructor, DefaultConstructor)
{
	Prog2::Spiral s1;
	ASSERT_EQ(0, s1.getK());
	ASSERT_EQ(0, s1.getF());
}

TEST(SpiralConstructor, Setters)
{
	Prog2::Spiral s2;
	s2.setK(3.00);
	s2.setF(23);
	ASSERT_EQ(3.00, s2.getK());
	ASSERT_EQ(23, s2.getF());
	ASSERT_ANY_THROW(s2.setK(-40.00));
	ASSERT_ANY_THROW(s2.setF(-120.0));
}

TEST(SpiralMethods, Parameters)
{
	Prog2::Spiral s1;
	s1.setK(1.0);
	s1.setF(5.0);
	const double PI = 3.14159, err = 0.3;
	ASSERT_NEAR(184.231, s1.area_fig(2), err);
	ASSERT_NEAR(496.098, s1.area_circle(2), err);
	ASSERT_NEAR(13.9038, s1.len(), err);
	ASSERT_NEAR(5.09902, s1.rad(), err);
	ASSERT_NEAR(2.5, s1.distance(2), err);
}
int _tmain(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
