#ifndef FT_CONICSECTION__
#define FT_CONICSECTION__

#include "Vect3d.h"
#include "Curve.h"

namespace ft {

	class Vect3d;
	class Curve;

	class ConicSection : public Curve {

	public:

		ConicSection() noexcept;
		ConicSection(const Vect3d& normal);
		ConicSection(const Vect3d& normal, const Vect3d& center);
		ConicSection(const ConicSection& other) noexcept = default;
		virtual ~ConicSection() = default;


		[[nodiscard]] Vect3d getNormal() const noexcept;
		void setNormal(const Vect3d& normal) noexcept;


	protected:
		Vect3d normal_;
	};

}

#endif // FT_CONICSECTION__