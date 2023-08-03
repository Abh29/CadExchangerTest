#ifndef FT_VECT3D__
#define FT_VECT3D__

#include <stdexcept>
#include <ostream>
#include <cmath>


namespace ft {


	/*
	 * This class as the name suggests represents a 3D mathematical vector or point
	 * defined as (x, y, z) with x, y, z read numbers are the components of the vector
	 */
	class Vect3d {

	public:

		/*
		 * Standard Constructor, initializes the vector to (0, 0, 0).
		 */
		Vect3d() noexcept;

		/*
		 * @param xpos: the first component of the vector
		 * @param ypos: the second component of the vector
		 * @param zpos: the third component of the vector
		 *
		 * Initializes the vector to (xpos, ypos, zpos).
		 */
		Vect3d(double xpos, double ypos, double zpos = 0.f) noexcept;

		/*
		 * Default copy constructor.
		 */
		Vect3d(const Vect3d& other) noexcept;

		/*
		 * Default destructor.
		 */
		~Vect3d() = default;

		/*
		 * Default copy assign operator.
		 */
		Vect3d &operator= (const Vect3d& other) noexcept;

		/*
		 * Returns true if all the components of the vector are 0.0f
		 * i.e if the vector is equal to (0, 0, 0), false otherwise.
		 */
		[[nodiscard]]  bool isNull() const noexcept;

		/*
		 * @param vec: a 3D vector
		 *
		 * Returns true if all the components of the vector are 0.0f
		 * i.e if the vector is equal to (0, 0, 0), false otherwise.
		 */
		 static bool IsNull(const Vect3d& vec) noexcept;

		 /*
		  * Returns the first component of the vector.
		  */
		[[nodiscard]] double x() const noexcept;

		/*
		 * Returns the second component of the vector.
		 */
		[[nodiscard]] double y() const noexcept;

		/*
		 * Returns the third component of the vector.
		 */
		[[nodiscard]] double z() const noexcept;

		/*
		 * @param x: real number
		 * Sets the first component of the vector.
		 */
		 void setX(double x) noexcept;

		/*
		* @param y: real number
		* Sets the second component of the vector.
		*/
		 void setY(double y) noexcept;

		/*
		* @param z: real number
		* Sets the third component of the vector.
		*/
		 void setZ(double z) noexcept;

		 /*
		  * @param i: the index of the component
		  * Returns a reference to the component at position i
		  * throws invalid_argument if i < 0 or i > 2
		  */
		 double &operator[](int i);

		/*
		* @param i: the index of the component
		* Returns the component at position i
		* throws invalid_argument if i < 0 or i > 2 .
		*/
		 double operator[](int i) const;

		 /*
		  * Returns the magnitude of the vector defined
		  * mathematically as sqrt(x² + y² + z²).
		  */
		[[nodiscard]] double length() const noexcept;

		/*
		 * Returns the square of the magnitude of the vector defined
		 * mathematically as x² + y² + z².
		 */
		[[nodiscard]]  double lengthSquared() const noexcept;

		/*
		 * Returns a new normalized vector of from the current one.
		 */
		[[nodiscard]] Vect3d normalized() const noexcept;

		/*
		 * Normalizes the current vector.
		 */
		void normalize() noexcept;

		/*
		 * @param vector: 3D vector
		 * Adds the components of vector to the current one.
		 */
		 Vect3d &operator+=(const Vect3d& vector) noexcept;

		/*
		 * @param vector: 3D vector
		 * Subtracts the components of vector from the current one.
		 */
		 Vect3d &operator-=(const Vect3d& vector) noexcept;

		 /*
		  * @param factor: real number
		  * Multiplies each component of the current vector with
		  * factor.
		  */
		 Vect3d &operator*=(double factor) noexcept;

		/*
		 * @param vector: 3D vector
		 * Multiplies each component of the current vector with
		 * the analog component of vector i.e:
		 * (x*x', y*y', z*z') with x,y,z being the components of the
		 * current vector and x',y',z' of vector.
		 */
		 Vect3d &operator*=(const Vect3d& vector) noexcept;

		/*
		 * @param factor: real number
		 * Divides each component of the current vector by
		 * factor.
		 * throws invalid_argument exception if divisor is nil.
		 */
		 Vect3d &operator/=(double divisor);

		/*
		 * @param vector: 3D vector
		 * Divides each component of the current vector by
		 * the analog component of vector i.e:
		 * (x/x', y/y', z/z') with x,y,z being the components of the
		 * current vector and x',y',z' of vector.
		 * throws invalid_argument exception if one of the components is nil.
		 */
		Vect3d &operator/=(const Vect3d& vector);

		 /*
		  * @param v1: 3D vector
		  * @param v2: 3D vector
		  *
		  * Returns the dot Product of two vectors defined as
		  * v1.v2 .
		  */
		[[nodiscard]] static double dotProduct(const Vect3d& v1, const Vect3d& v2) noexcept;

		/*
		 * @param v1: 3D vector
		 * @param v2: 3D vector
		 *
		 * Returns the cross Product of two vectors defined as
		 * v1 x v2 .
		 */
		[[nodiscard]] static Vect3d crossProduct(const Vect3d& v1, const Vect3d& v2) noexcept;

	private:
		double v_[3];
	};

}

std::ostream& operator<<(std::ostream& os, const ft::Vect3d& vector);





#endif // FT_VECT3D