#include "../include/Vect3d.h"

using namespace ft;

Vect3d::Vect3d() noexcept : v_{0.f, 0.f, 0.f} {}
Vect3d::Vect3d(double xpos, double ypos, double zpos) noexcept : v_{xpos, ypos, zpos} {}
Vect3d::Vect3d(const Vect3d& other) noexcept : v_{other.v_[0], other.v_[1], other.v_[2]} {}


Vect3d &Vect3d::operator=(const Vect3d &other) noexcept {
	if (&other == this)
		return *this;
	v_[0] = other.v_[0];
	v_[1] = other.v_[1];
	v_[2] = other.v_[2];
	return *this;
}


inline bool Vect3d::isNull() const noexcept { return v_[0] == 0.f && v_[1] == 0.f && v_[2] == 0.f;}

inline double Vect3d::x() const noexcept {return v_[0];}
inline double Vect3d::y() const noexcept {return v_[1];}
inline double Vect3d::z() const noexcept {return v_[2];}



void Vect3d::setX(double x) noexcept { v_[0] = x;}
void Vect3d::setY(double y) noexcept { v_[1] = y;}
void Vect3d::setZ(double z) noexcept { v_[2] = z;}

double &Vect3d::operator[](int i) {
	if (i < 0 || i > 2)
		throw std::out_of_range("Index out of bound !");
	return v_[i];
}
double Vect3d::operator[](int i) const {
	if (i < 0 || i > 2)
		throw std::out_of_range("Index out of bound !");
	return v_[i];
}

double Vect3d::length() const noexcept {return std::hypot(v_[0], v_[1], v_[2]);}
double Vect3d::lengthSquared() const noexcept { return v_[0] * v_[0] + v_[1] * v_[1] + v_[2] * v_[2];}

Vect3d Vect3d::normalized() const {
	const double len = length();
	if (std::abs(len) < FT_EPS)
		throw std::invalid_argument("the current vector is null !");
	if (std::abs(len - 1.0f) < FT_EPS) {
		return *this;
	}
	return {v_[0] / len, v_[1] / len, v_[2] / len };

}
void Vect3d::normalize(){
	const double len = length();
	if (std::abs(len) < FT_EPS)
		throw std::invalid_argument("the current vector is null !");
	if (std::abs(len - 1.0f) < FT_EPS)
		return;

	v_[0] /= len;
	v_[1] /= len;
	v_[2] /= len;
}

Vect3d &Vect3d::operator+=(const Vect3d& vector) noexcept {
	v_[0] += vector.x();
	v_[1] += vector.y();
	v_[2] += vector.z();
	return *this;
}
Vect3d &Vect3d::operator-=(const Vect3d& vector) noexcept {
	v_[0] -= vector.x();
	v_[1] -= vector.y();
	v_[2] -= vector.z();
	return *this;
}
Vect3d &Vect3d::operator*=(double factor) noexcept {
	v_[0] *= factor;
	v_[1] *= factor;
	v_[2] *= factor;
	return *this;
}
Vect3d &Vect3d::operator*=(const Vect3d& vector) noexcept {
	v_[0] *= vector.v_[0];
	v_[1] *= vector.v_[1];
	v_[2] *= vector.v_[2];
	return *this;
}
Vect3d &Vect3d::operator/=(double divisor) {
	if (std::abs(divisor) < FT_EPS)
		throw std::invalid_argument("Can not divide by 0!");
	v_[0] /= divisor;
	v_[1] /= divisor;
	v_[2] /= divisor;
	return *this;
}
 Vect3d &Vect3d::operator/=(const Vect3d& vector) {
	if (std::abs(vector.x()) < FT_EPS ||
		std::abs(vector.y()) < FT_EPS ||
		std::abs(vector.z()) < FT_EPS )
		throw std::invalid_argument("Can not divide by 0!");
	v_[0] /= vector.x();
	v_[1] /= vector.y();
	v_[2] /= vector.z();
	return *this;
}

double Vect3d::dotProduct(const Vect3d& v1, const Vect3d& v2) noexcept {
	return v1.v_[0] * v2.v_[0] + v1.v_[1] * v2.v_[1] + v1.v_[2] * v2.v_[2];
}

Vect3d Vect3d::crossProduct(const Vect3d& v1, const Vect3d& v2) {
	if (std::abs(v1.length()) < FT_EPS || std::abs(v2.length()) < FT_EPS)
		throw std::invalid_argument("crossProduct is not defined for null vector!");
	return {v1.v_[1] * v2.v_[2] - v1.v_[2] * v2.v_[1],
			v1.v_[2] * v2.v_[0] - v1.v_[0] * v2.v_[2],
			v1.v_[0] * v2.v_[1] - v1.v_[1] * v2.v_[0]};
}


std::ostream& operator<<(std::ostream& os, const Vect3d& vector) {
	os << "( " << vector.x() << ", " << vector.y() << ", " << vector.z() << " )";
	return os;
}

bool operator==(const ft::Vect3d& lhs, const ft::Vect3d& rhs) {
	return std::hypot(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z()) < FT_EPS;
}

bool operator!=(const ft::Vect3d& lhs, const ft::Vect3d& rhs) {
	return !(lhs == rhs);
}


 bool Vect3d::IsNull(const Vect3d &vec) noexcept {
	return vec.isNull();
}
