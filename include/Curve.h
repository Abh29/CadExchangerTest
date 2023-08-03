#ifndef FT_CURVE__
#define FT_CURVE__

#include "Vect3d.h"


namespace ft {

	class Vect3d;

	/*
	 * This is an interface defining a general curve in 3D space
	 * a curve has a center point around which the curve is defined
	 */

	class Curve {

	public:

		/*
		 * Standard constructor
		 * Creates a curve with the center point at (0, 0, 0)
		 */
		Curve() noexcept;

		/*
		 * @param center: the center of the curve
		 * Creates a curve with the center point center
		 */
		Curve(const Vect3d& center) noexcept;

		/*
		 * Default copy constructor
		 */
		Curve(const Curve& other) noexcept = default;

		/*
		 * Default destructor
		 */
		virtual ~Curve() = default;

		/*
		 * Returns the center point of the curve
		 */
		Vect3d getCenter() const;

		/*
		 * @param center: the center point of the curve
		 * Sets the center_ point of the curve to center
		 */
		void setCenter(const Vect3d& center);

		/*
		 * @param t: the angle upon which the coordenates of
		 * the point are calculated in polar coordinates
		 *
		 * Returns a vector containing the coordinates of the point
		 */
		virtual Vect3d getPoint(double t) const = 0;

		/*
		 * @param t: the angle upon which the derivative
		 * is calculated in polar coordinates
		 *
		 * Returns a vector containing the components of the derivative
		 */
		virtual Vect3d getDerivative(double t) const = 0;

	protected:
		Vect3d center_;

	};


}

#endif // FT_CURVE__
