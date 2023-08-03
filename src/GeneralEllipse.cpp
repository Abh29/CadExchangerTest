#include "../include/GeneralEllipse.h"

using namespace ft;

GeneralEllipse::GeneralEllipse() noexcept : ConicSection(), x_radius_(1.f), y_radius_(1.f) {}
GeneralEllipse::GeneralEllipse(const Vect3d &normal, const Vect3d& center, double x_radius, double y_radius) :
ConicSection(normal, center), x_radius_(x_radius), y_radius_(y_radius){
	if (x_radius <= 0 || y_radius <= 0)
		throw std::invalid_argument("radii can not be negative of null !");
}


double GeneralEllipse::getXRadius() const {return x_radius_;}
double GeneralEllipse::getYRadius() const {return y_radius_;}

void GeneralEllipse::setXRadius(double radius) {
	if (radius <= 0)
		throw std::invalid_argument("radius can not be negative or null !");
	x_radius_ = radius;
}

void GeneralEllipse::setYRadius(double radius) {
	if (radius <= 0)
		throw std::invalid_argument("radius can not be negative or null !");
	y_radius_ = radius;
}

GeneralEllipse &GeneralEllipse::operator=(const GeneralEllipse &other) noexcept {
	if (&other == this)
		return *this;
	x_radius_ = other.x_radius_;
	y_radius_ = other.y_radius_;
	normal_ = other.normal_;
	center_ = other.center_;
	return *this;
}

Vect3d GeneralEllipse::getPoint(double t) const {

	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	Vect3d V1 = Vect3d::crossProduct(normal_, {0.f, -1.f, 0.f});
	if (V1.isNull())
		V1 = Vect3d::crossProduct(normal_, {-1.f, 0.f, 0.f});
	Vect3d V2 = Vect3d::crossProduct(normal_, V1);

	V1.normalize();
	V2.normalize();

	return {center_.x() + x_radius_ * cos * V1.x() + y_radius_ * sin * V2.x(),
			center_.y() + x_radius_ * cos * V1.y() + y_radius_ * sin * V2.y(),
			center_.z() + x_radius_ * cos * V1.z() + y_radius_ * sin * V2.z()};
}

Vect3d GeneralEllipse::getDerivative(double t) const {

	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	Vect3d V1 = Vect3d::crossProduct(normal_, {0.f, -1.f, 0.f});
	if (V1.isNull())
		V1 = Vect3d::crossProduct(normal_, {-1.f, 0.f, 0.f});
	Vect3d V2 = Vect3d::crossProduct(normal_, V1);

	V1.normalize();
	V2.normalize();

	return {-x_radius_ * sin * V1.x() + y_radius_ * cos * V2.x(),
			-x_radius_ * sin * V1.y() + y_radius_ * cos * V2.y(),
			-x_radius_ * sin * V1.z() + y_radius_ * cos * V2.z()};
}
