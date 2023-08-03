#include "../include/GeneralCircle.h"

using namespace ft;

GeneralCircle::GeneralCircle() noexcept : ConicSection(), radius_(1.f) {}
GeneralCircle::GeneralCircle(const Vect3d& normal, const Vect3d& center, double radius) :
	ConicSection(normal, center), radius_(radius) {
	if (radius <= 0)
		throw std::invalid_argument("The radius must be positive!");
}


double GeneralCircle::getRadius() const {return radius_;}
void GeneralCircle::setRadius(double radius) {
	if (radius <= 0)
		throw std::invalid_argument("The radius must be positive!");
	radius_ = radius;
}
double GeneralCircle::getArea() const {return M_PI * radius_ * radius_;}
double GeneralCircle::getCircumference() const {return 2 * M_PI * radius_;}

Vect3d GeneralCircle::getPoint(double t) const {
	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	Vect3d V1 = Vect3d::crossProduct(normal_, {0.f, -1.f, 0.f});
	if (V1.isNull())
		V1 = Vect3d::crossProduct(normal_, {-1.f, 0.f, 0.f});
	Vect3d V2 = Vect3d::crossProduct(normal_, V1);

	V1.normalize();
	V2.normalize();

	return Vect3d( 	center_.x() + radius_ * cos * V1.x() + radius_ * sin * V2.x(),
	 				center_.y() + radius_ * cos * V1.y() + radius_ * sin * V2.y(),
					center_.z() + radius_ * cos * V1.z() + radius_ * sin * V2.z());
}

Vect3d GeneralCircle::getDerivative(double t) const {

	const double cos = std::abs(std::cos(t)) < FT_EPS ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < FT_EPS ? 0.f : std::sin(t);

	Vect3d V1 = Vect3d::crossProduct(normal_, {0.f, -1.f, 0.f});
	if (V1.isNull())
		V1 = Vect3d::crossProduct(normal_, {-1.f, 0.f, 0.f});
	Vect3d V2 = Vect3d::crossProduct(normal_, V1);

	V1.normalize();
	V2.normalize();

	return Vect3d(	-radius_ * sin * V1.x() + radius_ * cos * V2.x(),
					-radius_ * sin * V1.y() + radius_ * cos * V2.y(),
					-radius_ * sin * V1.z() + radius_ * cos * V2.z());
}
