#include "../include/Curve.h"

using namespace ft;

Curve::Curve() noexcept : center_() {}
Curve::Curve(const Vect3d& center) noexcept : center_(center) {}

Vect3d Curve::getCenter() const {return Vect3d(center_);}

void Curve::setCenter(const Vect3d &center) {
	center_ = center;
}

