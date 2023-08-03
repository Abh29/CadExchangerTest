# CadExchangerTest
    This is the implementation of a test in c++ given by CAD Exchanger

## The Test Requirements

Design a small program in C++ that would implement support of 3D curves hierarchy.
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
   definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
   vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
   random parameters.
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populate a second container that would contain only circles from the first container. Make sure the
   second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
   smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.
   (*) Additional optional requirements:
7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this
   library.
8. Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel
   TBB library).

Requirements to the implementation:

1. The implementation must use virtual methods.
2. Has neither explicit memory deallocation nor memory leaks.
3. Curves must be physically correct (e.g. radii must be positive).
4. Containers and sorting must be implemented using STL (C++ Standard Template Library).
5. The implementation may use constructs of C++11 or higher.
6. The code must compile with any compiler of your choice (gcc, Visual C++, etc).

Curve definitions:
- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in  
  parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) +
  {0, 0, step}.

## The Implementation 

- Vect3d.h contains the class Vect3D which represents a 3d vector/point of real numbers.
- Curve.h contains the base class Curve representing a regular curve with a center in 3D space.
- ConicSection.h contains the class ConicSection that inherits Curve representing as the name suggests  
    an intersection of a plane with known normal with a cone.
- GeneralCircle.h and GeneralEllipse.h contain the classes GeneralCircle and GeneralEllipse respectively  
    they represent a circle/ellipse in 3D space on a plane with a given norma vector and a center they both  
    inherit from ConicSection class
- Circle.h and Ellipse.h contain the classes Circle and Ellipse respectively they define a simple planar  
    circle/ellipse on the x°y plane with z being the normal they both inherit GeneralCircle/GeneralEllipse  
    respectively.
- Helix.h contains the class Helix that represents a simple helix centered at the origin with the normal z  
  with a given radius and a given step = 2 * PI * pitch. for a general helix it is better to calculate the  
  coordinates of a point on a simple helix and they apply the required geometric transformations.