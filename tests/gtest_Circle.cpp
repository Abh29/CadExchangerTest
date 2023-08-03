#include <gtest/gtest.h>
#include "../include/Circle.h"
#include <cmath>

TEST(CircleTest, Default_Constructor) {
	ft::Circle c{};

	EXPECT_TRUE(c.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(c.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(c.getRadius(), 1);
}

TEST(CircleTest, Constructor_Parameters) {
	ft::Circle c{42};

	EXPECT_TRUE(c.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(c.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(c.getRadius(), 42);

	EXPECT_THROW(ft::Circle c2(0), std::invalid_argument);
	EXPECT_THROW(ft::Circle c2(-1), std::invalid_argument);
}

TEST(CircleTest, Copy_Constructor) {
	ft::Circle c{42};
	ft::Circle c2{c};

	EXPECT_TRUE(c2.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(c2.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(c2.getRadius(), 42);
}

TEST(CircleTest, GetPoint) {
	ft::Circle c{};

	EXPECT_TRUE(c.getPoint(0) == c.getPoint(2 * M_PI));
	EXPECT_TRUE(c.getPoint(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(c.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(c.getPoint(M_PI / 4) == ft::Vect3d(std::cos(M_PI / 4), std::sin(M_PI / 4), 0));

	c.setRadius(3);
	EXPECT_TRUE(c.getPoint(0) == c.getPoint(2 * M_PI));
	EXPECT_TRUE(c.getPoint(0) == ft::Vect3d(3, 0, 0));
	EXPECT_TRUE(c.getPoint(M_PI / 2) == ft::Vect3d(0, 3, 0));
	EXPECT_TRUE(c.getPoint(M_PI / 4) == ft::Vect3d(3 * std::cos(M_PI / 4), 3 * std::sin(M_PI / 4), 0));

}

TEST(CircleTest, GetDerivative) {
	ft::Circle c{};

	EXPECT_TRUE(c.getDerivative(0) == c.getDerivative(2 * M_PI));
	EXPECT_TRUE(c.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(c.getDerivative(M_PI / 2) == ft::Vect3d(-1, 0, 0));
	EXPECT_TRUE(c.getDerivative(M_PI / 4) == ft::Vect3d(-std::sin(M_PI / 4), std::cos(M_PI / 4), 0));

	c.setRadius(3);
	EXPECT_TRUE(c.getDerivative(0) == c.getDerivative(2 * M_PI));
	EXPECT_TRUE(c.getDerivative(0) == ft::Vect3d(0, 3, 0));
	EXPECT_TRUE(c.getDerivative(M_PI / 2) == ft::Vect3d(-3, 0, 0));
	EXPECT_TRUE(c.getDerivative(M_PI / 4) == ft::Vect3d(-3 * std::sin(M_PI / 4), 3 * std::cos(M_PI / 4), 0));

}
TEST(CircleTest, Comparators) {
	ft::Circle c{};
	ft::Circle c2{c};

	EXPECT_TRUE(c == c2);
	EXPECT_TRUE(c >= c2);
	EXPECT_TRUE(c <= c2);
	EXPECT_FALSE(c < c2);
	EXPECT_FALSE(c > c2);
	EXPECT_FALSE(c != c2);

	c2.setRadius(42);
	EXPECT_FALSE(c == c2);
	EXPECT_TRUE(c != c2);
	EXPECT_TRUE(c < c2);
	EXPECT_TRUE(c <= c2);
	EXPECT_FALSE(c > c2);
	EXPECT_FALSE(c >= c2);

}
