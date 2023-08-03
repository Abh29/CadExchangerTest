#include <gtest/gtest.h>
#include "../include/Helix.h"
#include <cmath>


TEST(HelixTest, Default_Constructor) {
	ft::Helix h{};

	EXPECT_DOUBLE_EQ(h.getRadius(), 1);
	EXPECT_DOUBLE_EQ(h.getStep(), 1);
}


TEST(HelixTest, Constructor_Parameters) {
	ft::Helix h{42, 5};

	EXPECT_DOUBLE_EQ(h.getRadius(), 42);
	EXPECT_DOUBLE_EQ(h.getStep(), 5);

	EXPECT_THROW(ft::Helix h2(0, 0), std::invalid_argument);
	EXPECT_THROW(ft::Helix h2(-42, 0), std::invalid_argument);
	EXPECT_NO_THROW(ft::Helix h2(1, 0));
	EXPECT_NO_THROW(ft::Helix h2(1, -42));
}

TEST(HelixTest, Copy_Constructor) {
	ft::Helix h{42, 5};
	ft::Helix h2{h};

	EXPECT_DOUBLE_EQ(h2.getRadius(), 42);
	EXPECT_DOUBLE_EQ(h2.getStep(), 5);
}

TEST(HelixTest, Set_Get) {
	ft::Helix h{};
	EXPECT_DOUBLE_EQ(h.getRadius(), 1);
	EXPECT_DOUBLE_EQ(h.getStep(), 1);

	h.setRadius(42);
	EXPECT_DOUBLE_EQ(h.getRadius(), 42);
	EXPECT_DOUBLE_EQ(h.getStep(), 1);

	h.setStep(5);
	EXPECT_DOUBLE_EQ(h.getRadius(), 42);
	EXPECT_DOUBLE_EQ(h.getStep(), 5);
}

TEST(HelixTest, GetPoint) {
	ft::Helix h{};

	EXPECT_TRUE(h.getPoint(0) != h.getPoint(2 * M_PI));
	EXPECT_TRUE(h.getPoint(0).z() == h.getPoint(2 * M_PI).z() - h.getStep());
	EXPECT_TRUE(h.getPoint(0) == ft::Vect3d(1, 0, 0));
	EXPECT_TRUE(h.getPoint(M_PI / 2) == ft::Vect3d(0, 1, 1.0/4));
	EXPECT_TRUE(h.getPoint(M_PI / 4) == ft::Vect3d(std::cos(M_PI / 4), std::sin(M_PI / 4), 1.0/8));

	h.setRadius(3);
	EXPECT_TRUE(h.getPoint(0) != h.getPoint(2 * M_PI));
	EXPECT_TRUE(h.getPoint(0).z() == h.getPoint(2 * M_PI).z() - h.getStep());
	EXPECT_TRUE(h.getPoint(0) == ft::Vect3d(3, 0, 0));
	EXPECT_TRUE(h.getPoint(M_PI / 2) == ft::Vect3d(0, 3, 1.f/4));
	EXPECT_TRUE(h.getPoint(M_PI / 4) == ft::Vect3d(3 * std::cos(M_PI / 4), 3 * std::sin(M_PI / 4), 1.f/8));

}

TEST(HelixTest, GetDerivative) {
	ft::Helix h{};

	EXPECT_TRUE(h.getDerivative(0) == h.getDerivative(2 * M_PI));
	EXPECT_TRUE(h.getDerivative(0) == ft::Vect3d(0, 1, 0.5/M_PI ));
	EXPECT_TRUE(h.getDerivative(M_PI / 2) == ft::Vect3d(-1, 0, 0.5/M_PI));
	EXPECT_TRUE(h.getDerivative(M_PI / 4) == ft::Vect3d(-std::sin(M_PI / 4), std::cos(M_PI / 4), 1.0/(2*M_PI)));

	h.setRadius(3);
	EXPECT_TRUE(h.getDerivative(0) == h.getDerivative(2 * M_PI));
	EXPECT_TRUE(h.getDerivative(0) == ft::Vect3d(0, 3, 1.0/(2*M_PI)));
	EXPECT_TRUE(h.getDerivative(M_PI / 2) == ft::Vect3d(-3, 0, 1.0/(2*M_PI)));
	EXPECT_TRUE(h.getDerivative(M_PI / 4) == ft::Vect3d(-3 * std::sin(M_PI / 4), 3 * std::cos(M_PI / 4), 1.f/(2*M_PI)));

}

