#include <iostream>
#include <cmath>
#include "complex.hpp"
#include <iomanip>

int main(){
	Complex a;
	std::cout << "Default Constructor" << std::endl;
	a.Disp();

	std::cout<< std::endl;
	double real;
	double imag;
	std::cout<< "Enter the real part of the complex number wanted: ";
	std::cin >> real;
	std::cout<< "Enter the imaginary part of the complex number wanted: ";
	std::cin >> imag;

	Complex b = Complex(real, imag);
	std::cout << "Personalized Constructor" << std::endl;
	b.Disp();
	
	std::cout<< std::endl;
	Complex c = a;
	c.Disp();

	std::cout<< std::endl;
	c = Complex(3.0,2.0);
	c.Disp();		

	std::cout << "The complex's norm is " << std::fixed << std::setprecision(2) << c.Norm() << std::endl;

	std::cout<< std::endl;
	std::cout << "By conjugating we get: " <<std::endl;
	c.Conjugate();
	c.Disp();

	std::cout<< std::endl;
	Complex d = b + c;
	std::cout << "Sum(+) of complexes" << std::endl;
	d.Disp();

	std::cout<< std::endl;
	Complex e = b - c;
        std::cout << "Substraction(-) of complexes" << std::endl;
        e.Disp();

	std::cout<< std::endl;
	Complex f  = b * c;
        std::cout << "Multiplication(*) of complexes" << std::endl;
        f.Disp();

	std::cout<<std::endl;
	Complex g = b/c;
	std::cout << "Division(/) of complexes" << std::endl;
	g.Disp();

	return 0;
}
