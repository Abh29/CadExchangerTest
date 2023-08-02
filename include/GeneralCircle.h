#ifndef FT_GENERAL_CIRCLE__
#define FT_GENERAL_CIRCLE__

#include "ConicSection.h"


namespace ft {

	class ConicSection;

	class GeneralCircle : public ConicSection {

	public:

		GeneralCircle() noexcept;
		GeneralCircle(const Vect3d& normal, const Vect3d& center, double radius = 1.f);
		GeneralCircle(const GeneralCircle& other) noexcept = default;
		virtual ~GeneralCircle() = default;

		double getRadius() const;
		void setRadius(double radius);


		double getArea() const;
		double getCircumference() const;

		virtual Vect3d getPoint(double t) const override;
		virtual Vect3d getDerivative(double t) const override;

	protected:
		double radius_;


	};





}


#endif // FT_GENERAL_CIRCLE__