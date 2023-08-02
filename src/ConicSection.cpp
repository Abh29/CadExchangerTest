#include "../include/ConicSection.h"

using namespace ft;
ConicSection::ConicSection() noexcept : Curve(), normal_(0.f, 0.f, 1.f) {}
ConicSection::ConicSection(const Vect3d &normal) : Curve(), normal_(normal) {
	if (normal.isNull())
		throw std::invalid_argument("the normal vector can not be null!");
}
ConicSection::ConicSection(const Vect3d &normal, const Vect3d &center) : Curve(center), normal_(normal){
	if (normal.isNull())
		throw std::invalid_argument("the normal vector can not be null!");
}

Vect3d ConicSection::getNormal() const noexcept {return normal_;}
void ConicSection::setNormal(const Vect3d &normal) noexcept {
	normal_[0] = normal.x();
	normal_[1] = normal.y();
	normal_[2] = normal.z();
}

