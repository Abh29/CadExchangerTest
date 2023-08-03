#include <gtest/gtest.h>
#include "../include/GeneralCircle.h"
#include <cmath>

TEST(GeneralCircleTest, Default_Constructor) {
	ft::GeneralCircle gc{};

	EXPECT_TRUE(gc.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(gc.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(gc.getRadius(), 1);
}

TEST(GeneralCircleTest, Constructor_Parameters) {
	ft::GeneralCircle gc{{1,1,1}, {0,0,1}};
	ft::GeneralCircle gc2{{1,1,1}, {0,0,1}, 5};

	EXPECT_TRUE(gc.getNormal() == ft::Vect3d(1, 1, 1));
	EXPECT_TRUE(gc.getCenter() == ft::Vect3d(0, 0, 1));
	EXPECT_DOUBLE_EQ(gc.getRadius(), 1);
	EXPECT_DOUBLE_EQ(gc2.getRadius(), 5);

	EXPECT_THROW(ft::GeneralCircle gc({1,1,1}, {0,0,1}, 0), std::invalid_argument);
	EXPECT_THROW(ft::GeneralCircle gc({1,1,1}, {0,0,1}, -1), std::invalid_argument);
}

TEST(GeneralCircleTest, Copy_Constructor) {
	ft::GeneralCircle gc{{1,1,1}, {0,0,1}};
	ft::GeneralCircle gc2{gc};

	EXPECT_TRUE(gc2.getNormal() == ft::Vect3d(1, 1, 1));
	EXPECT_TRUE(gc2.getCenter() == ft::Vect3d(0, 0, 1));
	EXPECT_DOUBLE_EQ(gc.getRadius(), 1);
}

TEST(GeneralCircleTest, Get_Set_Radius) {
	ft::GeneralCircle gc{};
	ft::GeneralCircle gc2{{1,1,1}, {0,0,1}, 5};

	EXPECT_DOUBLE_EQ(gc.getRadius(), 1);
	EXPECT_DOUBLE_EQ(gc2.getRadius(), 5);

	gc2.setRadius(42);
	EXPECT_DOUBLE_EQ(gc2.getRadius(), 42);

	EXPECT_THROW(gc.setRadius(0), std::invalid_argument);
	EXPECT_THROW(gc.setRadius(-3), std::invalid_argument);
}

TEST(GeneralCircleTest, GetArea) {
	ft::GeneralCircle gc{};

	EXPECT_DOUBLE_EQ(gc.getArea(), M_PI);

	gc.setRadius(5);
	EXPECT_DOUBLE_EQ(gc.getArea(), 25 * M_PI);

	gc.setRadius(42);
	EXPECT_DOUBLE_EQ(gc.getArea(), 42 * 42 * M_PI);
}

TEST(GeneralCircleTest, GetCircumfrence) {
	ft::GeneralCircle gc{};

	EXPECT_DOUBLE_EQ(gc.getCircumference(), 2 * M_PI);

	gc.setRadius(5);
	EXPECT_DOUBLE_EQ(gc.getCircumference(), 10 * M_PI);

	gc.setRadius(42);
	EXPECT_DOUBLE_EQ(gc.getCircumference(), 84 * M_PI);
}

TEST(GeneralCircleTest, GetPoint) {
	ft::GeneralCircle gc{};

	EXPECT_TRUE(gc.getPoint(0) == gc.getPoint(2 * M_PI));
	EXPECT_TRUE(gc.getPoint(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(gc.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));

	gc.setNormal({1, 0, 0});
	EXPECT_TRUE(gc.getPoint(0) == gc.getPoint(2 * M_PI));
	EXPECT_TRUE(gc.getPoint(0) == ft::Vect3d(0, 0, -1));
	EXPECT_TRUE(gc.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));

	gc.setRadius(3);
	EXPECT_TRUE(gc.getPoint(0) == gc.getPoint(2 * M_PI));
	EXPECT_TRUE(gc.getPoint(0) == ft::Vect3d(0, 0, -3));
	EXPECT_TRUE(gc.getPoint(M_PI / 2) == ft::Vect3d(0, 3, 0));

	gc.setNormal({0, -1, 0});
	gc.setRadius(1);
	EXPECT_TRUE(gc.getPoint(0) == gc.getPoint(2 * M_PI));
	EXPECT_TRUE(gc.getPoint(0) == ft::Vect3d(0, 0, -1));
	EXPECT_TRUE(gc.getPoint(M_PI / 2) == ft::Vect3d(1, 0, 0));

	gc.setCenter({1,1,1});
	EXPECT_TRUE(gc.getPoint(0) == gc.getPoint(2 * M_PI));
	EXPECT_TRUE(gc.getPoint(0) == ft::Vect3d(1, 1, 0));
	EXPECT_TRUE(gc.getPoint(M_PI / 2) == ft::Vect3d(2, 1, 1));

}

TEST(GeneralCircleTest, GetDerivative) {
	ft::GeneralCircle gc{};

	EXPECT_TRUE(gc.getDerivative(0) == gc.getDerivative(2 * M_PI));
	EXPECT_TRUE(gc.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(gc.getDerivative(M_PI / 2) == ft::Vect3d(-1, 0, 0));

	gc.setNormal({1, 0, 0});
	EXPECT_TRUE(gc.getDerivative(0) == gc.getDerivative(2 * M_PI));
	EXPECT_TRUE(gc.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(gc.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 1));

	gc.setRadius(3);
	EXPECT_TRUE(gc.getDerivative(0) == gc.getDerivative(2 * M_PI));
	EXPECT_TRUE(gc.getDerivative(0) == ft::Vect3d(0, 3, 0));
	EXPECT_TRUE(gc.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 3));

	gc.setNormal({0, -1, 0});
	gc.setRadius(1);
	EXPECT_TRUE(gc.getDerivative(0) == gc.getDerivative(2 * M_PI));
	EXPECT_TRUE(gc.getDerivative(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(gc.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 1));

	gc.setCenter({1,1,1});
	EXPECT_TRUE(gc.getDerivative(0) == gc.getDerivative(2 * M_PI));
	EXPECT_TRUE(gc.getDerivative(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(gc.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 1));

}




