#include "../include/Circle.h"

using namespace ft;

Circle::Circle() noexcept : GeneralCircle(){}
Circle::Circle(double radius) :
GeneralCircle(Vect3d(0.f, 0.f, 1.f), Vect3d(0.f, 0.f, 0.f), radius) {}

Vect3d Circle::getPoint(double t) const {
	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	return {radius_ * cos,
			radius_ * sin};
}


Vect3d Circle::getDerivative(double t) const {
	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	return { -radius_ * sin,
			radius_ * cos};
}

bool Circle::operator<(const Circle &other) const {
	return radius_ < other.radius_;
}

bool Circle::operator==(const Circle &other) const {
	return radius_ == other.radius_;
}

bool Circle::operator!=(const Circle &other) const {
	return radius_ != other.radius_;
}

bool Circle::operator<=(const Circle &other) const {
	return radius_ <= other.radius_;
}

bool Circle::operator>(const Circle &other) const {
	return radius_ > other.radius_;
}

bool Circle::operator>=(const Circle &other) const {
	return radius_ >= other.radius_;
}
