#include "../include/Ellipse.h"

using namespace ft;

Ellipse::Ellipse() noexcept : GeneralEllipse(){}
Ellipse::Ellipse(double x_radius, double y_radius) :
	GeneralEllipse(Vect3d(0.f, 0.f, 1.f), Vect3d(0.f, 0.f, 0.f), x_radius, y_radius){}

Vect3d Ellipse::getPoint(double t) const {

	const double cos = std::abs(std::cos(t)) < 1e-7 ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < 1e-7 ? 0.f : std::sin(t);

	return {x_radius_ * cos,
			y_radius_ * sin};
}

Vect3d Ellipse::getDerivative(double t) const {
	const double cos = std::abs(std::cos(t)) < 1e-7 ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < 1e-7 ? 0.f : std::sin(t);

	return {-x_radius_ * sin,
			y_radius_ * cos};
}
