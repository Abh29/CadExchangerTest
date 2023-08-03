#ifndef FT_ELLIPSE__
#define FT_ELLIPSE__

#include "GeneralEllipse.h"


namespace ft {


	class ConicSection;

	/*
	 * This class represents a simple ellipse centered at the origin (0,0,0) on the xy plane
	 * with the normal z(0,0,1) defined with two foci.
	 */
	class Ellipse : public GeneralEllipse {

	public:

		/*
		 * Creates an ellipse with both foci = 1, i.e a circle
		 */
		Ellipse() noexcept;

		/*
		 * @param x_radius: the distance to the focus on the x axis
		 * @param y_radius: the distance to the focus on the y axes
		 *
		 * Creates an ellipse with given foci x_radius and y_radius
		 * both radii should be positive
		 * Throws invalid_argument exception if one radius is negative or null.
		 */
		Ellipse(double x_radius, double y_radius);

		/*
		 * Default copy constructor.
		 */
		Ellipse(const Ellipse& other) = default;

		/*
		 * Default destructor.
		 */
		virtual ~Ellipse() = default;

		/*
		 * @param t: the angle with respect to x axis.
		 *
		 * Returns the cartesian coordinates of the point on the ellipse
		 * with the angle t in polar coordinates.
		 */
		virtual Vect3d getPoint(double t) const override;

		/*
		 * @param t: the angle with respect to x axis.
		 *
		 * Returns the cartesian coordinates of the derivative
		 * point on the ellipse with the angle t in polar coordinates.
		 */
		virtual Vect3d getDerivative(double t) const override;

		/*
		 * The following methods are hidden as the difinition of the ellipse
		 * is simple with a fixed center and normal.
		 * Although this don't hide them completely but the methods
		 * getPoint and getDerivative are not affected
		 */
		void setNormal(const Vect3d& normal) noexcept = delete;
		void setCenter(const Vect3d& center) const = delete;

	};


}



#endif