
SRC = src/Vect3d.cpp src/Curve.cpp src/ConicSection.cpp src/GeneralCircle.cpp src/Circle.cpp \
 		src/GeneralEllipse.cpp src/Ellipse.cpp src/Helix.cpp	main.cpp

all:
	c++ -Werror -Wextra -Wall ${SRC} -o tst

run: all
	./tst

clean:
	rm *.o
	rm tst