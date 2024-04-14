#include <iostream>
#include <cmath>
#include "complex.hpp"

int main(){
	Complex a;
	std::cout << "Default Constructor" << std::endl;
	a.Print();

	Complex b = Complex(4.5, 6.7);
	std::cout << "Personalized Constructor" << std::endl;
	b.Print();
	
	Complex c = a;
	c.Print();

	c = b;
	c.Print();		

	c.Norm();

	c.Conjugate();
	c.Print();

	return 0;
}
