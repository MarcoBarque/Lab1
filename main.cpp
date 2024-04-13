#include <iostream>
#include <cmath>
#include "complex.hpp"

int main(){
	Complex complejo(4.5,7.9);
	std::cout<<complejo.real<<"hola"<< complejo.imag<<std::endl;
	Complex m;
	std::cout<<m.real<<"hola"<< m.imag<<std::endl;
	Complex a=complejo;
	std::cout<<a.real<<"hola"<< a.imag<<std::endl;
	a=m;
	std::cout<<a.real<<"hola"<< a.imag<<std::endl;		

	return 0;
}
