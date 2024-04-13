#include <iostream>
#include "complex.hpp"
#include <cmath>

Complex::Complex(){
        real=0.0;
        imag=0.0;
}  

Complex::Complex(double a,double b){
	real=a;
	imag=b;
}

Complex::~Complex(){
	std::cout<<"Destructor invocked"<<std::endl;
}

Complex::Complex(const Complex &obj){
	std::cout << "Copy constructor invoked" << std::endl;

	real=obj.real;
	imag=obj.imag;
}

Complex &Complex::operator=(const Complex &obj){
	std::cout <<"Assignment operator invoked"<<std::endl;

	real=obj.real;
	 imag=obj.imag;
	
	return *this; 
}

void Complex::Norm(){
	norm=sqrt(real*real+imag*imag);
	std::cout<<"The norm of the complex number is "<<norm<<"."<<std::endl;
}

void Complex::Conjugate(){
	imag= -imag;
}
