#include <gtest/gtest.h>
#include "../include/Vect3d.h"
#include <cmath>

TEST(Vect3dTest, Default_Constructor) {
	ft::Vect3d v;
	EXPECT_EQ(v.x(), 0.0);
	EXPECT_EQ(v.y(), 0.0);
	EXPECT_EQ(v.z(), 0.0);
}

TEST(Vect3dTest, Constructor) {
	ft::Vect3d v(1.f, -2.f);
	EXPECT_DOUBLE_EQ(v.x(), 1.f);
	EXPECT_DOUBLE_EQ(v.y(), -2.f);
	EXPECT_DOUBLE_EQ(v.z(), 0.f);
}

TEST(Vect3dTest, Copy_Constructor) {
	ft::Vect3d v(1.f, -2.f);
	ft::Vect3d v2(v);

	EXPECT_DOUBLE_EQ(v2.x(), 1.f);
	EXPECT_DOUBLE_EQ(v2.y(), -2.f);
	EXPECT_DOUBLE_EQ(v2.z(), 0.f);
}

TEST(Vect3dTest, Copy_Assignment_Operator) {
	ft::Vect3d v{1.f, -2.f};
	ft::Vect3d v2{};
	v2 = v;

	EXPECT_DOUBLE_EQ(v2.x(), 1.f);
	EXPECT_DOUBLE_EQ(v2.y(), -2.f);
	EXPECT_DOUBLE_EQ(v2.z(), 0.f);
}

TEST(Vect3dTest, IsNULL) {
	ft::Vect3d v{1.f, -2.f};
	ft::Vect3d v2{};

	EXPECT_FALSE(v.isNull());
	EXPECT_TRUE(v2.isNull());
}

TEST(Vect3dTest, Static_IsNULL) {
	ft::Vect3d v{1.f, -2.f};
	ft::Vect3d v2{};

	EXPECT_FALSE(ft::Vect3d::IsNull(v));
	EXPECT_TRUE(ft::Vect3d::IsNull(v2));
}

TEST(Vect3dTest, Set_Get_X) {
	ft::Vect3d v{1.f, -2.f};

	EXPECT_DOUBLE_EQ(v.x(), 1);
	v.setX(42);
	EXPECT_DOUBLE_EQ(v.x(), 42);
	EXPECT_DOUBLE_EQ(v.y(), -2.f);
	EXPECT_DOUBLE_EQ(v.z(), 0.f);
}

TEST(Vect3dTest, Set_Get_Y) {
	ft::Vect3d v{1.f, -2.f};

	EXPECT_DOUBLE_EQ(v.y(), -2);
	v.setY(42);
	EXPECT_DOUBLE_EQ(v.x(), 1);
	EXPECT_DOUBLE_EQ(v.y(), 42);
	EXPECT_DOUBLE_EQ(v.z(), 0.f);
}

TEST(Vect3dTest, Set_Get_Z) {
	ft::Vect3d v{1.f, -2.f};

	EXPECT_DOUBLE_EQ(v.z(), 0);
	v.setZ(42);
	EXPECT_DOUBLE_EQ(v.x(), 1);
	EXPECT_DOUBLE_EQ(v.y(), -2);
	EXPECT_DOUBLE_EQ(v.z(), 42);
}

TEST(Vect3dTest, Operator_Brackets) {
	ft::Vect3d v{1.f, -2.f};

	EXPECT_DOUBLE_EQ(v[0], 1);
	EXPECT_DOUBLE_EQ(v[1], -2);
	EXPECT_DOUBLE_EQ(v[2], 0);

	EXPECT_THROW(v[-1], std::out_of_range);
	EXPECT_THROW(v[3], std::out_of_range);
}

TEST(Vect3dTest, Operator_Brackets_2) {
	ft::Vect3d v{1.f, -2.f};

	v[0] = 42;
	v[1] = 42;
	v[2] = 42;

	EXPECT_DOUBLE_EQ(v.x(), 42);
	EXPECT_DOUBLE_EQ(v.y(), 42);
	EXPECT_DOUBLE_EQ(v.z(), 42);

	EXPECT_THROW(v[-1] = 0, std::out_of_range);
	EXPECT_THROW(v[3] = 0, std::out_of_range);
}

TEST(Vect3dTest, Length) {
	ft::Vect3d v{};
	ft::Vect3d v2{1, -1, 1};
	ft::Vect3d v3{3, 4, 0};

	EXPECT_DOUBLE_EQ(v.length(), 0);
	EXPECT_DOUBLE_EQ(v2.length(), std::sqrt(3));
	EXPECT_DOUBLE_EQ(v3.length(), 5);
}

TEST(Vect3dTest, LengthSquared) {
	ft::Vect3d v{};
	ft::Vect3d v2{1, -1, 1};
	ft::Vect3d v3{3, 4, 0};

	EXPECT_DOUBLE_EQ(v.lengthSquared(), 0);
	EXPECT_DOUBLE_EQ(v2.lengthSquared(), 3);
	EXPECT_DOUBLE_EQ(v3.lengthSquared(), 25);
}

TEST(Vect3dTest, Normalized) {
	ft::Vect3d v{};
	ft::Vect3d v2{1, -1, 1};
	ft::Vect3d v3{-1, 0, 0};

	ft::Vect3d n;
	EXPECT_THROW((n = v.normalized()), std::invalid_argument);

	ft::Vect3d vn2 = v2.normalized();
	EXPECT_DOUBLE_EQ(vn2.x(), 1.f / std::sqrt(3));
	EXPECT_DOUBLE_EQ(vn2.y(), -1.f / std::sqrt(3));
	EXPECT_DOUBLE_EQ(vn2.z(), 1.f / std::sqrt(3));

	ft::Vect3d vn3 = v3.normalized();
	EXPECT_DOUBLE_EQ(vn3.x(), -1);
	EXPECT_DOUBLE_EQ(vn3.y(), 0);
	EXPECT_DOUBLE_EQ(vn3.z(), 0);

}

TEST(Vect3dTest, Plus_Equal_Operator) {
	ft::Vect3d v{1, -1, 1};
	ft::Vect3d v2{3, 4, 0};

	v += v2;

	EXPECT_DOUBLE_EQ(v.x(), 4);
	EXPECT_DOUBLE_EQ(v.y(), 3);
	EXPECT_DOUBLE_EQ(v.z(), 1);

}

TEST(Vect3dTest, Minus_Equal_Operator) {
	ft::Vect3d v{1, -1, 1};
	ft::Vect3d v2{3, 4, 0};

	v -= v2;

	EXPECT_DOUBLE_EQ(v.x(), -2);
	EXPECT_DOUBLE_EQ(v.y(), -5);
	EXPECT_DOUBLE_EQ(v.z(), 1);

}

TEST(Vect3dTest, Mult_Equal_Operator) {
	ft::Vect3d v{1, -1, 1};
	ft::Vect3d v2{3, 4, 0};

	v *= v2;

	EXPECT_DOUBLE_EQ(v.x(), 3);
	EXPECT_DOUBLE_EQ(v.y(), -4);
	EXPECT_DOUBLE_EQ(v.z(), 0);

}

TEST(Vect3dTest, Mult_Equal_Operator_factor) {
	ft::Vect3d v{3, -4, 0};

	v *= 42;

	EXPECT_DOUBLE_EQ(v.x(), 126);
	EXPECT_DOUBLE_EQ(v.y(), -168);
	EXPECT_DOUBLE_EQ(v.z(), 0);

}

TEST(Vect3dTest, Div_Equal_Operator) {
	ft::Vect3d v{13, -4.5, 0};

	v /= 42;

	EXPECT_DOUBLE_EQ(v.x(), 13.0 / 42);
	EXPECT_DOUBLE_EQ(v.y(), -4.5 / 42);
	EXPECT_DOUBLE_EQ(v.z(), 0);

	EXPECT_THROW(v /= 0, std::invalid_argument);

}

TEST(Vect3dTest, Div_Equal_Operator_factor) {
	ft::Vect3d v{13, -4.5, 0};
	ft::Vect3d v2{1, 25, -12};

	EXPECT_THROW(v2 /= v, std::invalid_argument);

	EXPECT_DOUBLE_EQ(v2.x(), 1.0);
	EXPECT_DOUBLE_EQ(v2.y(), 25);
	EXPECT_DOUBLE_EQ(v2.z(), -12);

	v /= v2;

	EXPECT_DOUBLE_EQ(v.x(), 13.0);
	EXPECT_DOUBLE_EQ(v.y(), -4.5 / 25);
	EXPECT_DOUBLE_EQ(v.z(), 0);

}

TEST(Vect3dTest, DotProduct) {
	double dot;
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({}, {1,1,1})), 0);
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({1,0,0}, {0,1,0})), 0);
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({1,1,0}, {-1,1,0})), 0);
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({1,1,1}, {1,1,1})), 3);
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({1,1,1}, {-1,-1,-1})), -3);
	EXPECT_DOUBLE_EQ((dot = ft::Vect3d::dotProduct({1,1,1}, {2,2,2})), 6);
}

TEST(Vect3dTest, CrossProduct) {

	ft::Vect3d v = ft::Vect3d::crossProduct({1,1,1}, {2, 2, 2});
	EXPECT_DOUBLE_EQ(v.x(), 0.0);
	EXPECT_DOUBLE_EQ(v.y(), 0.0);
	EXPECT_DOUBLE_EQ(v.z(), 0.0);

	EXPECT_THROW((v = ft::Vect3d::crossProduct(v, {1,1,1})), std::invalid_argument);

	v = ft::Vect3d::crossProduct({13,-31,17}, {6, 8, -4});
	EXPECT_DOUBLE_EQ(v.x(), -12.0);
	EXPECT_DOUBLE_EQ(v.y(), 154.0);
	EXPECT_DOUBLE_EQ(v.z(), 290.0);

}







