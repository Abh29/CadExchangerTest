#ifndef FT_CONICSECTION__
#define FT_CONICSECTION__

#include "Vect3d.h"
#include "Curve.h"

#ifndef FT_EPS
#define FT_EPS  1E-7
#endif


namespace ft {

	class Vect3d;
	class Curve;

	/*
	 * This class represents a Conical Section being a type of curve
	 * of center center_ and a normal vector of the plane intersecting
	 * the cone.
	 */

	class ConicSection : public Curve {

	public:

		/*
		 * Standard constructor
		 * Sets the center to the origin (0, 0, 0) with
		 * the normal vector (0, 0, 1).
		 */
		ConicSection() noexcept;

		/*
		 * @param normal: 3D vector representing the normal vector
		 * of the plane
		 *
		 * Constructs a ConicSection with center_ at the origin
		 * (0, 0, 0) and the normal_ vector normal.
		 */
		ConicSection(const Vect3d& normal);

		/*
		 * @param normal: 3D vector representing the normal vector
		 * @param center: 3D vector representing the center of point
		 *
		 * Constructs a ConicSection with the normal vector normal
		 * and the center point center.
		 */
		ConicSection(const Vect3d& normal, const Vect3d& center);

		/*
		 * Default copy constructor.
		 */
		ConicSection(const ConicSection& other) noexcept = default;

		/*
		 * Default destructor.
		 */
		virtual ~ConicSection() = default;

		/*
		 * Returns the normal vector of the plane
		 */
		[[nodiscard]] Vect3d getNormal() const noexcept;

		/*
		 * @param normal: 3D vector representing the normal
		 * Returns the normal vector of the plane of the cut.
		 */
		void setNormal(const Vect3d& normal) noexcept;


	protected:
		Vect3d normal_;
	};

}

#endif // FT_CONICSECTION__