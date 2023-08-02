#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <omp.h>
#include "include/ftCad.h"

#define SAMPLE_SIZE 10


bool compC(const std::shared_ptr<ft::Circle>& p1, const std::shared_ptr<ft::Circle>& p2) {
	return *p1 < *p2;
}

void populateVector(std::vector<std::shared_ptr<ft::Curve>>& v, int size) {
	// set the randomizers
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution index(0, 2);
	std::uniform_real_distribution<double> radius(0.1, 40);

	// populate the vector according to a random index
	for (int i = 0; i < size; ++i) {
		switch (index(gen)) {
			case 0:
				v.push_back(std::make_shared<ft::Circle>(ft::Circle(radius(gen))));
				break;
			case 1:
				v.push_back(std::make_shared<ft::Ellipse>(ft::Ellipse(radius(gen), radius(gen))));
				break;
			default:
				v.push_back(std::make_shared<ft::Helix>(ft::Helix(radius(gen), radius(gen))));
		}
	}

}

void printCoordinates(std::vector<std::shared_ptr<ft::Curve>>& v, double t) {

	for(const auto& p : v) {

		ft::Circle* pCircle;
		ft::Ellipse* pEllipse;
		ft::Helix* pHelix;

		if ((pCircle = dynamic_cast<ft::Circle*>(p.get())) != nullptr) {
			std::cout << "Circle with radius: " << pCircle->getRadius() << std::endl;
		} else if ((pEllipse = dynamic_cast<ft::Ellipse*> (p.get())) != nullptr) {
			std::cout << "Ellipse with Xradius: " << pEllipse->getXRadius() << ", Yradius: " << pEllipse->getYRadius() << std::endl;
		} else if ((pHelix = dynamic_cast<ft::Helix*>(p.get())) != nullptr) {
			std::cout << "Helix with radius: " << pHelix->getRadius() << ", and step: " << pHelix->getStep() << std::endl;
		}
		std::cout << " point at PI/4 : " << p->getPoint(t) << ", with derivative: " << p->getDerivative(t) << std::endl << std::endl;
	}
}

auto getCirclesOnly(std::vector<std::shared_ptr<ft::Curve>>&v) {
	std::vector<std::shared_ptr<ft::Circle>> v2;

	for(const auto& p : v) {
		if (dynamic_cast<ft::Circle*>(p.get()) != nullptr)
			v2.push_back(std::dynamic_pointer_cast<ft::Circle>(p));
	}
	return v2;
}

void printSortedRadii(std::vector<std::shared_ptr<ft::Circle>>& v) {
	std::sort(v.begin(), v.end(), compC);
	for(const auto& p: v)
		std::cout << "radius: " << p->getRadius() << std::endl;
}

double calculateSum(std::vector<std::shared_ptr<ft::Circle>>& v) {
	double sum{};

	#pragma omp parallel for reduction(+:sum)
	for (size_t i = 0; i < v.size(); ++i) {
		sum += v[i]->getRadius();
	}
	return sum;
}


int main() {

	// create a vector an initial size and populate it
	std::vector<std::shared_ptr<ft::Curve>> v;
	v.reserve(SAMPLE_SIZE);
	populateVector(v, SAMPLE_SIZE);


	// loop over the vector and print the coordinates of the point and derivative at PI / 4
	printCoordinates(v, M_PI / 4);

	// get a vector of circles only
	std::vector<std::shared_ptr<ft::Circle>> v2 = getCirclesOnly(v);

	// sort the vector of circles according to the radius and print the radii
	printSortedRadii(v2);

	// calculating the sum
	std::cout << "the sum of radii is : " << calculateSum(v2) << std::endl;


	return 0;
}
