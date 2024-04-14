#include <iostream>
#include <cmath>
#include "complex.hpp"

int main(){
	Complex a;
	std::cout << "Default Constructor" << std::endl;
	a.Disp();

	Complex b = Complex(4.5, 6.7);
	std::cout << "Personalized Constructor" << std::endl;
	b.Disp();
	
	Complex c = a;
	c.Disp();

	c = Complex(3.0,2.0);
	c.Disp();		

	std::cout << "The complex's norm is " << c.Norm() << std::endl;

	std::cout << "By conjugating we get: " <<std::endl;
	c.Conjugate();
	c.Disp();

	Complex d = b + c;
	std::cout << "Sum(+) of complexes" << std::endl;
	d.Disp();

	Complex e = b - c;
        std::cout << "Substraction(-) of complexes" << std::endl;
        e.Disp();

        Complex f  = b * c;
        std::cout << "Multiplication(*) of complexes" << std::endl;
        f.Disp();


	return 0;
}
