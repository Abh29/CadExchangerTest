#include <gtest/gtest.h>
#include "../include/GeneralEllipse.h"
#include <cmath>

TEST(GeneralEllipseTest, Default_Constructor) {
	ft::GeneralEllipse ge{};

	EXPECT_TRUE(ge.getNormal() == ft::Vect3d(0, 0, 1));
	EXPECT_TRUE(ge.getCenter() == ft::Vect3d(0, 0, 0));
	EXPECT_DOUBLE_EQ(ge.getXRadius(), 1);
	EXPECT_DOUBLE_EQ(ge.getYRadius(), 1);
}

TEST(GeneralEllipseTest, Constructor_Parameters) {
	ft::GeneralEllipse ge{{1,1,1}, {0,0,1}};
	ft::GeneralEllipse ge2{{1,1,1}, {0,0,1}, 42, 5};

	EXPECT_TRUE(ge.getNormal() == ft::Vect3d(1, 1, 1));
	EXPECT_TRUE(ge.getCenter() == ft::Vect3d(0, 0, 1));
	EXPECT_DOUBLE_EQ(ge.getXRadius(), 1);
	EXPECT_DOUBLE_EQ(ge.getYRadius(), 1);
	EXPECT_DOUBLE_EQ(ge2.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(ge2.getYRadius(), 5);

	EXPECT_THROW(ft::GeneralEllipse gne({1,1,1}, {0,0,1}, 0, 1), std::invalid_argument);
	EXPECT_THROW(ft::GeneralEllipse gne({1,1,1}, {0,0,1}, 1, -1), std::invalid_argument);
}

TEST(GeneralEllipseTest, Copy_Constructor) {
	ft::GeneralEllipse ge{{1,1,1}, {0,0,1}, 42, 8};
	ft::GeneralEllipse ge2{ge};

	EXPECT_TRUE(ge2.getNormal() == ft::Vect3d(1, 1, 1));
	EXPECT_TRUE(ge2.getCenter() == ft::Vect3d(0, 0, 1));
	EXPECT_DOUBLE_EQ(ge2.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(ge2.getYRadius(), 8);
}

TEST(GeneralEllipseTest, Get_Set_Radius) {
	ft::GeneralEllipse ge{};
	ft::GeneralEllipse ge2{{1,1,1}, {0,0,1}, 42, 8};

	EXPECT_DOUBLE_EQ(ge.getXRadius(), 1);
	EXPECT_DOUBLE_EQ(ge.getYRadius(), 1);
	EXPECT_DOUBLE_EQ(ge2.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(ge2.getYRadius(), 8);

	ge.setXRadius(42);
	EXPECT_DOUBLE_EQ(ge.getXRadius(), 42);
	EXPECT_DOUBLE_EQ(ge.getYRadius(), 1);

	EXPECT_THROW(ge.setXRadius(0), std::invalid_argument);
	EXPECT_THROW(ge.setXRadius(-42), std::invalid_argument);
	EXPECT_THROW(ge.setYRadius(0), std::invalid_argument);
	EXPECT_THROW(ge.setYRadius(-8), std::invalid_argument);
}

TEST(GeneralEllipseTest, GetPoint) {
	ft::GeneralEllipse ge{};


	EXPECT_TRUE(ge.getPoint(0) == ge.getPoint(2 * M_PI));
	EXPECT_TRUE(ge.getPoint(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(ge.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));

	ge.setNormal({1, 0, 0});
	EXPECT_TRUE(ge.getPoint(0) == ge.getPoint(2 * M_PI));
	EXPECT_TRUE(ge.getPoint(0) == ft::Vect3d(0, 0, -1));
	EXPECT_TRUE(ge.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));

	ge.setXRadius(2);
	EXPECT_TRUE(ge.getPoint(0) == ge.getPoint(2 * M_PI));
	EXPECT_TRUE(ge.getPoint(0) == ft::Vect3d(0, 0, -2));
	EXPECT_TRUE(ge.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 0));

	ge.setNormal({0, -1, 0});
	ge.setXRadius(5);
	ge.setYRadius(3);
	EXPECT_TRUE(ge.getPoint(0) == ge.getPoint(2 * M_PI));
	EXPECT_TRUE(ge.getPoint(0) == ft::Vect3d(0, 0, -5));
	EXPECT_TRUE(ge.getPoint(M_PI / 2) == ft::Vect3d(3, 0, 0));

	auto v = ge.getPoint(M_PI / 4);
	EXPECT_DOUBLE_EQ(v.x(), 2.1213203435596424);
	EXPECT_DOUBLE_EQ(v.y(), 0);
	EXPECT_DOUBLE_EQ(v.z(), -3.5355339059327378);

	ge.setCenter({1,1,1});
	v = ge.getPoint(M_PI / 4);
	EXPECT_DOUBLE_EQ(v.x(), 3.1213203435596424);
	EXPECT_DOUBLE_EQ(v.y(), 1);
	EXPECT_DOUBLE_EQ(v.z(), -2.5355339059327378);
}

TEST(GeneralEllipseTest, GetDerivative) {
	ft::GeneralEllipse ge{};

	EXPECT_TRUE(ge.getDerivative(0) == ge.getDerivative(2 * M_PI));
	EXPECT_TRUE(ge.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(ge.getDerivative(M_PI / 2) == ft::Vect3d(-1, 0, 0));

	ge.setNormal({1, 0, 0});
	EXPECT_TRUE(ge.getDerivative(0) == ge.getDerivative(2 * M_PI));
	EXPECT_TRUE(ge.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(ge.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 1));


	ge.setXRadius(2);
	EXPECT_TRUE(ge.getDerivative(0) == ge.getDerivative(2 * M_PI));
	EXPECT_TRUE(ge.getDerivative(0) == ft::Vect3d(0, 1, 0));
	EXPECT_TRUE(ge.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 2));

	ge.setNormal({0, -1, 0});
	ge.setXRadius(5);
	ge.setYRadius(3);
	EXPECT_TRUE(ge.getDerivative(0) == ge.getDerivative(2 * M_PI));
	EXPECT_TRUE(ge.getDerivative(0) == ft::Vect3d(3, 0, 0));
	EXPECT_TRUE(ge.getDerivative(M_PI / 2) == ft::Vect3d(0, 0, 5));

	auto v = ge.getDerivative(M_PI / 4);
	EXPECT_DOUBLE_EQ(v.x(), 2.1213203435596424);
	EXPECT_DOUBLE_EQ(v.y(), 0);
	EXPECT_DOUBLE_EQ(v.z(), 3.5355339059327378);

	ge.setCenter({1,1,1});
	v = ge.getDerivative(M_PI / 4);
	EXPECT_DOUBLE_EQ(v.x(), 2.1213203435596428);
	EXPECT_DOUBLE_EQ(v.y(), 0);
	EXPECT_DOUBLE_EQ(v.z(), 3.5355339059327373);
}




