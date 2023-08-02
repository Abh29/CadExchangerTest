#ifndef FT_VECT3D__
#define FT_VECT3D__

#include <stdexcept>
#include <ostream>
#include <cmath>


namespace ft {

	class Vect3d {

	public:

		Vect3d() noexcept;
		Vect3d(double xpos, double ypos, double zpos = 0.f) noexcept;
		Vect3d(const Vect3d& other) noexcept;
		~Vect3d() = default;

		Vect3d &operator= (const Vect3d& other) noexcept;



		[[nodiscard]]  bool isNull() const noexcept;
		 static bool IsNull(const Vect3d& vec) noexcept;

		[[nodiscard]] double x() const noexcept;
		[[nodiscard]] double y() const noexcept;
		[[nodiscard]] double z() const noexcept;

		 void setX(double x) noexcept;
		 void setY(double y) noexcept;
		 void setZ(double z) noexcept;

		 double &operator[](int i);
		 double operator[](int i) const;

		[[nodiscard]] double length() const noexcept;
		[[nodiscard]]  double lengthSquared() const noexcept;

		[[nodiscard]] Vect3d normalized() const noexcept;
		void normalize() noexcept;

		 Vect3d &operator+=(const Vect3d& vector) noexcept;
		 Vect3d &operator-=(const Vect3d& vector) noexcept;
		 Vect3d &operator*=(double factor) noexcept;
		 Vect3d &operator*=(const Vect3d& vector) noexcept;
		 Vect3d &operator/=(double divisor);
		 Vect3d &operator/=(const Vect3d& vector);

		[[nodiscard]] static double dotProduct(const Vect3d& v1, const Vect3d& v2) noexcept;
		[[nodiscard]] static Vect3d crossProduct(const Vect3d& v1, const Vect3d& v2) noexcept;

	private:
		double v_[3];
	};

}

std::ostream& operator<<(std::ostream& os, const ft::Vect3d& vector);





#endif // FT_VECT3D