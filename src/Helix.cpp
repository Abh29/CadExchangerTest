#include "../include/Helix.h"

using namespace ft;

Helix::Helix() noexcept : Curve(), radius_(1.f), step_(1.f) {}
Helix::Helix(double radius, double step) : Curve() , radius_(radius), step_(step) {}

Vect3d Helix::getPoint(double t) const {
	const double cos = std::abs(std::cos(t)) < 1e-7 ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < 1e-7 ? 0.f : std::sin(t);
	const double pitch = step_ / (2 * M_PI);

	return {radius_ * cos,
			radius_ * sin,
			pitch * t};
}

Vect3d Helix::getDerivative(double t) const {

	const double cos = std::abs(std::cos(t)) < 1e-7 ? 0.f : std::cos(t);
	const double sin = std::abs(std::sin(t)) < 1e-7 ? 0.f : std::sin(t);
	const double pitch = step_ / (2 * M_PI);

	return {-radius_ * sin,
			radius_ *  cos,
			pitch};
}

void Helix::setRadius(double radius) {radius_ = radius;}
void Helix::setStep(double step) {step_ = step;}
double Helix::getStep() const {return step_;}
double Helix::getRadius() const {return radius_;}
