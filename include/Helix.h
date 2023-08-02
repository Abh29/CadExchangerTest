#ifndef FT_HELIX__
#define FT_HELIX__

#ifndef FT_EPS
#define FT_EPS 1e-7
#endif

#include "Curve.h"

namespace ft {

	class Curve;
	class Vect3d;


	class Helix : public Curve {

	public:
		Helix() noexcept;
		Helix(double radius, double step);
		Helix(const Helix& other) noexcept;
		virtual ~Helix() = default;


		void setRadius(double radius);
		void setStep(double step);
		double getRadius() const;
		double getStep() const;


		[[nodiscard]] Vect3d getPoint(double t) const override;
		[[nodiscard]] Vect3d getDerivative(double t) const override;

		void setCenter(const Vect3d& center) = delete;

	protected:
		double radius_;
		double step_;

	};

}


#endif