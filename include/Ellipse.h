#ifndef FT_ELLIPSE__
#define FT_ELLIPSE__

#include "GeneralEllipse.h"


namespace ft {


	class ConicSection;

	class Ellipse : public GeneralEllipse {

	public:
		Ellipse() noexcept;
		Ellipse(double x_radius, double y_radius);
		Ellipse(const Ellipse& other) = default;
		virtual ~Ellipse() = default;


		virtual Vect3d getPoint(double t) const override;
		virtual Vect3d getDerivative(double t) const override;

		void setNormal(const Vect3d& normal) noexcept = delete;
		void setCenter(const Vect3d& center) const = delete;

	};


}



#endif