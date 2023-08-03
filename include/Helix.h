#ifndef FT_HELIX__
#define FT_HELIX__

#ifndef FT_EPS
#define FT_EPS  1E-7
#endif

#include "Curve.h"

namespace ft {

	class Curve;
	class Vect3d;


	/*
	 * This class represents a mathematical helix centered at the origin (0, 0, 0)
	 * with the normal (0, 0, 1) and the fixed pitch of turning step / 2PI.
	 */
	class Helix : public Curve {

	public:

		/*
		 * Constructs a helix with radius and step of 1.
		 */
		Helix() noexcept;

		/*
		 * @param radius: the radius of the helix
		 * @param step: the distance z component change in a full rotation
		 *
		 * Constructs a helix with radius and step
		 * throws invalid_argument if radius <= 0.
		 */
		Helix(double radius, double step);

		/*
		 * Default copy constructor.
		 */
		Helix(const Helix& other) noexcept = default;

		/*
		 * Default destructor.
		 */
		virtual ~Helix() = default;


		/*
		 * @param radius: the radius of the helix
		 * should be positive
		 * throws invalid_argument exception if radius <= 0.
		 */
		void setRadius(double radius);

		/*
		 * @param step: the distance z component change in a full rotation
		 * Sets step_ to step.
		 */
		void setStep(double step);

		/*
		 * Returns the radius of the helix.
		 */
		double getRadius() const;

		/*
		 * Returns the step of the helix.
		 */
		double getStep() const;


		/*
		 * @param t: then angle of rotation starting from x axis.
		 *
		 * Returns the point on the helix relating the a rotation of
		 * angle t in radian along the helix.
		 */
		[[nodiscard]] Vect3d getPoint(double t) const override;

		/*
		 * @param t: then angle of rotation starting from x axis.
		 *
		 * Returns the derivative point on the helix relating the a
		 * rotation of angle t in radian along the helix.
		 */
		[[nodiscard]] Vect3d getDerivative(double t) const override;


		/*
		 * This method is hidden as the definition of a simple helix is
		 * centered in the center (0,0,0)
		 * Changing this parameter center_ doesnt affect getPoint nor
		 * getDerivative as they consider the center to be fixed.
		 */
		void setCenter(const Vect3d& center) = delete;

	protected:
		double radius_;
		double step_;

	};

}


#endif