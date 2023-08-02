#ifndef FT_GENERAL_ELLIPSE__
#define FT_GENERAL_ELLIPSE__

#ifndef FT_EPS
#define FT_EPS 1e-7
#endif


#include "ConicSection.h"

namespace ft {

	class ConicSection;

	class GeneralEllipse : public ConicSection {


	public:

		GeneralEllipse() noexcept;
		GeneralEllipse(const Vect3d& normal, const Vect3d& center, double x_radius = 1.f, double y_radius = 1.f);
		GeneralEllipse(const GeneralEllipse& other) noexcept = default;
		virtual ~GeneralEllipse() = default;

		GeneralEllipse& operator=(const GeneralEllipse& other) noexcept;

		[[nodiscard]] double getXRadius() const;
		[[nodiscard]] double getYRadius() const;
		void setXRadius(double radius);
		void setYRadius(double radius);


		[[nodiscard]] Vect3d getPoint(double t) const override;
		[[nodiscard]] Vect3d getDerivative(double t) const override;

	protected:
		double x_radius_;
		double y_radius_;

	};
}


#endif // FT_GENERAL_ELLIPSE__