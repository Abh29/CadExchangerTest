#ifndef FT_GENERAL_ELLIPSE__
#define FT_GENERAL_ELLIPSE__

#ifndef FT_EPS
#define FT_EPS  1E-7
#endif

#include "ConicSection.h"

namespace ft {

	class ConicSection;

	/*
	 * This class represents a general ellipse in space centered at a given point
	 * with a normal of plane on which the ellipse is defined and two foci x_radius and
	 * y_radius each according to a unit vector of the plane.
	 */
	class GeneralEllipse : public ConicSection {


	public:

		/*
		 * Creates a GeneralEllipse centered at the origin
		 * o (0,0,0) with normal z(0,0,1) and both foci equal 1
		 * essentially a circle.
		 */
		GeneralEllipse() noexcept;

		/*
		 * @param norma: 3D vector representing the normal of the plane
		 * @param center: 3D point representing the center of the ellipse
		 * @param x_radius: positive number representing the focal on the major axis
		 * @param y_radius: positive number representing the focal on the minor axis
		 *
		 * Creates a GeneralEllipse with a given center and normal
		 * and foci.
		 * Throws invalid_argument exception if one of the radii is negative or null.
		 */
		GeneralEllipse(const Vect3d& normal, const Vect3d& center, double x_radius = 1.f, double y_radius = 1.f);

		/*
		 * Default copy constructor.
		 */
		GeneralEllipse(const GeneralEllipse& other) noexcept = default;

		/*
		 * Default destructor.
		 */
		virtual ~GeneralEllipse() = default;

		/*
		 * Default copy assign operator.
		 */
		GeneralEllipse& operator=(const GeneralEllipse& other) noexcept;

		/*
		 * Returns the distance to the focus on the major axis.
		 */
		[[nodiscard]] double getXRadius() const;

		/*
		 * Returns the distance to the focal on the minor axis.
		 */
		[[nodiscard]] double getYRadius() const;

		/*
		 * @param radius: positive real number
		 * Sets the focus on the major axis.
		 * Throws invalid_argument if radius <= 0.
		 */
		void setXRadius(double radius);

		/*
		 * @param radius: positive real number
		 * Sets the focus on the minor axis.
		 * Throws invalid_argument if radius <= 0.
		 */
		void setYRadius(double radius);

		/*
		 * @param t; real number
		 * Returns the coordinates of the point corresponding to the angle t
		 * with respect two arbitrary perpendicular unit vectors of the plane.
		 */
		[[nodiscard]] Vect3d getPoint(double t) const override;

		/*
		 * @param t; real number
		 * Returns the coordinates of the derivative point corresponding to
		 * the angle t with respect to two arbitrary perpendicular unit
		 * vectors of the plane.
		 */
		[[nodiscard]] Vect3d getDerivative(double t) const override;

	protected:
		double x_radius_;
		double y_radius_;

	};
}


#endif // FT_GENERAL_ELLIPSE__