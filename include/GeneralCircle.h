#ifndef FT_GENERAL_CIRCLE__
#define FT_GENERAL_CIRCLE__

#include "ConicSection.h"


namespace ft {

	class ConicSection;

	/*
	 * This class represents a general Circle in space being the intersection of a sphere with plane
	 * defined with its center center_ , radius_ of the sphere and the normal of the plane.
	 */

	class GeneralCircle : public ConicSection {

	public:

		/*
		 * Standard Constructor
		 * Initializes the center_ to the origin (0, 0, 0) and
		 * the normal to (0, 0, 1) with a radius_ = 1.
		 */
		GeneralCircle() noexcept;

		/*
		 * @param normal: 3D vector representing the norma of the plane
		 * @param center: a point in 3D space representing the center of the sphere
		 * @param radius: a real number representing the radius of the sphere
		 *
		 * Constructs a GeneralCircle with normal vector normal_ = normal, center_ = center
		 * and a radius_ = radius.
		 */
		GeneralCircle(const Vect3d& normal, const Vect3d& center, double radius = 1.f);

		/*
		 * Default copy constructor.
		 */
		GeneralCircle(const GeneralCircle& other) noexcept = default;

		/*
		 * Default destructor.
		 */
		virtual ~GeneralCircle() = default;

		/*
		 * Returns the radius of the sphere.
		 */
		double getRadius() const;

		/*
		 * @param radius: positive number, the radius of the sphere
		 *
		 * Sets the parameter radius_ to radius.
		 * throw invalid_argument exception if radius is negative or null.
		 */
		void setRadius(double radius);

		/*
		 * Returns the area of the disk inside the circle defined as PI * r² with
		 * r being the radius of the circle.
		 */
		double getArea() const;

		/*
		 * Returns the circumference of the circle defined as 2 * PI * r with r
		 * being the radius of the circle.
		 */
		double getCircumference() const;

		/*
		 * @param t: real number representing the an angle
		 *
		 * Returns the artesian coordinates of the point on circle with
		 * the angle t in polar coordinates with respect to two arbitrary
		 * perpendicular unit vectors of the plane.
		 */
		virtual Vect3d getPoint(double t) const override;

		/*
		 * @param t: real number representing the an angle
		 *
		 * Returns derivatives of the components of the point on the circle
		 * with the angle t in polar coordinates wih respect to two arbitrary
		 * perpendicular unit vectors of the plane.
		 */
		virtual Vect3d getDerivative(double t) const override;

	protected:
		double radius_;


	};





}


#endif // FT_GENERAL_CIRCLE__