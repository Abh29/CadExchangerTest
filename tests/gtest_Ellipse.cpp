#include <gtest/gtest.h>
#include "../include/Ellipse.h"
#include <cmath>

TEST(EllipseTest, Default_Constructor) {
	ft::Ellipse e{};

	EXPECT_TRUE(e.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(e.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(e.getXRadius(), 1);
	EXPECT_DOUBLE_EQ(e.getYRadius(), 1);
}

TEST(EllipseTest, Constructor_Parameters) {
	ft::Ellipse e{42, 8};

	EXPECT_TRUE(e.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(e.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(e.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(e.getYRadius(), 8);

	EXPECT_THROW(ft::Ellipse e2(0, 1), std::invalid_argument);
	EXPECT_THROW(ft::Ellipse e2(-1, 1), std::invalid_argument);
	EXPECT_THROW(ft::Ellipse e2(1, 0), std::invalid_argument);
	EXPECT_THROW(ft::Ellipse e2(1, -1), std::invalid_argument);
}

TEST(EllipseTest, Copy_Constructor) {
	ft::Ellipse e{42, 8};
	ft::Ellipse e2{e};

	EXPECT_TRUE(e2.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(e2.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(e2.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(e2.getYRadius(), 8);
}

TEST(EllipseTest, GetPoint) {
	ft::Ellipse e{};

	EXPECT_TRUE(e.getPoint(0) == e.getPoint(2 * M_PI));
	EXPECT_TRUE(e.getPoint(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(e.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(e.getPoint(M_PI / 4) == ft::Vect3d(std::cos(M_PI / 4), std::sin(M_PI / 4), 0));

	e.setXRadius(5);
	e.setYRadius(3);
	EXPECT_TRUE(e.getPoint(0) == e.getPoint(2 * M_PI));
	EXPECT_TRUE(e.getPoint(0) == ft::Vect3d(5, 0, 0));
	EXPECT_TRUE(e.getPoint(M_PI / 2) == ft::Vect3d(0, 3, 0));
	EXPECT_TRUE(e.getPoint(M_PI / 4) == ft::Vect3d(5 * std::cos(M_PI / 4), 3 * std::sin(M_PI / 4), 0));

}

TEST(EllipseTest, GetDerivative) {
	ft::Ellipse e{};

	EXPECT_TRUE(e.getDerivative(0) == e.getDerivative(2 * M_PI));
	EXPECT_TRUE(e.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(e.getDerivative(M_PI / 2) == ft::Vect3d(-1, 0, 0));
	EXPECT_TRUE(e.getDerivative(M_PI / 4) == ft::Vect3d(-std::sin(M_PI / 4), std::cos(M_PI / 4), 0));

	e.setXRadius(5);
	e.setYRadius(3);
	EXPECT_TRUE(e.getDerivative(0) == e.getDerivative(2 * M_PI));
	EXPECT_TRUE(e.getDerivative(0) == ft::Vect3d(0, 3, 0));
	EXPECT_TRUE(e.getDerivative(M_PI / 2) == ft::Vect3d(-5, 0, 0));
	EXPECT_TRUE(e.getDerivative(M_PI / 4) == ft::Vect3d(-5 * std::sin(M_PI / 4), 3 * std::cos(M_PI / 4), 0));

}