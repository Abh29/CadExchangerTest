#ifndef FT_CIRCLE__
#define FT_CIRCLE__

#include "Vect3d.h"
#include "GeneralCircle.h"

#ifndef FT_EPS
#define FT_EPS  1E-7
#endif


namespace ft {

	class Vect3d;
	class GeneralCircle;

	/*
	 * This class represents a planar circle centered at the origin
	 * o (0,0,0) and facing up with normal z (0,0,1) and vector units
	 * x (1,0,0) and y(0,1,0).
	 */

	class Circle : public GeneralCircle {

	public:
		/*
		 * Creates a circle with radius 1.
		 */
		Circle() noexcept;

		/*
		 * @param radius: positive non nil number
		 * Creates a circle with radius_ = radius
		 * throws invalid_argument if radius <= 0.
		 */
		Circle(double radius);

		/*
		 * Default copy constructor.
		 */
		Circle(const Circle& other) = default;

		/*
		 * Default destructor.
		 */
		~Circle() = default;

		/*
		 * @param t: read number represents the angle t in radian
		 *
		 * Returns the artesian coordinates of the point on the circle
		 * with the angle t in polar coordinates.
		 */
		Vect3d getPoint(double t) const override;

		/*
		 * @param t: read number represents the angle t in radian
		 *
		 * Returns the artesian coordinates of the derivative point on the circle
		 * with the angle t in polar coordinates.
		 */
		Vect3d getDerivative(double t) const override;


		/*
		 * The following methods are deleted because the plane
		 * and the origin of the circle are fixed by definition.
		 *
		 * Although this doesn't hide these methods completely but
		 * still it does not affect the behaviour of getPoint and
		 * getDerivative as they consider the normal and center to be
		 * fixed .
		 */
		void setNormal(const Vect3d& normal) noexcept = delete;
		void setCenter(const Vect3d& center) const = delete;

		/*
		 * @param other: another circle
		 *
		 * The following operators compares the radii of
		 * the two circles, so that a circle is greater of
		 * equal to another only and if only its radius is
		 * greater or equal to the second circle's radius.
		 */
		bool operator==(const Circle& other) const;
		bool operator!=(const Circle& other) const;
		bool operator<(const Circle& other) const;
		bool operator<=(const Circle& other) const;
		bool operator>(const Circle& other) const;
		bool operator>=(const Circle& other) const;

	};


}



#endif