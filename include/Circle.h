#ifndef FT_CIRCLE__
#define FT_CIRCLE__

#include "Vect3d.h"
#include "GeneralCircle.h"


namespace ft {

	class Vect3d;
	class GeneralCircle;

	class Circle : public GeneralCircle {

	public:
		Circle() noexcept;
		Circle(double radius);
		Circle(const Circle& other) = default;
		~Circle() = default;

		Vect3d getPoint(double t) const override;
		Vect3d getDerivative(double t) const override;

		void setNormal(const Vect3d& normal) noexcept = delete;
		void setCenter(const Vect3d& center) const = delete;

	};


}



#endif