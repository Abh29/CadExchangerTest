#ifndef FT_CURVE__
#define FT_CURVE__

#include "Vect3d.h"


namespace ft {

	class Vect3d;

	class Curve {

	public:
		Curve() noexcept;
		Curve(const Vect3d& center) noexcept;
		Curve(const Curve& other) noexcept = default;
		virtual ~Curve() = default;


		Vect3d getCenter() const;
		void setCenter(const Vect3d& center);

		virtual Vect3d getPoint(double t) const = 0;
		virtual Vect3d getDerivative(double t) const = 0;

	protected:
		Vect3d center_;

	};


}

#endif // FT_CURVE__
