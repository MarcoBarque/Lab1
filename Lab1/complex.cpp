#include <iostream>
#include "complex.hpp"
#include <cmath>
#include <iomanip>

//Public
Complex::Complex(){
        real=0.0;
        imag=0.0;
	CalcNorm();
}  

Complex::Complex(double a,double b){
	real=a;
	imag=b;
	CalcNorm();
}

Complex::~Complex(){
	std::cout<<"Destructor invocked"<<std::endl;
}

Complex::Complex(const Complex &obj){
	std::cout << "Copy constructor invoked" << std::endl;

	real=obj.real;
	imag=obj.imag;
	norm=obj.norm;
}

Complex &Complex::operator=(const Complex &obj){
	std::cout <<"Assignment operator invoked"<<std::endl;

	real=obj.real;
	imag=obj.imag;
	norm=obj.norm;
	
	return *this; 
}

void Complex::Disp(){
	if (imag<0) {
	std::cout << std::fixed << std::setprecision(2) <<real << imag << "i" << std::endl;
	} else {
		std::cout << real << "+"  << imag << "i"  << std::endl;
	}
}

double Complex::Norm(){
	return norm;
}

void Complex::Conjugate(){
	imag= -imag;
}

Complex Complex::operator+(const Complex &obj){
	Complex temp = Complex(real+obj.real, imag+obj.imag);
	return temp;
}

Complex Complex::operator-(const Complex &obj){
        Complex temp = Complex(real-obj.real, imag-obj.imag);
        return temp;
}

Complex Complex::operator*(const Complex &obj){
        Complex temp = Complex(real*obj.real - imag*obj.imag, real*obj.imag + imag*obj.real);
        return temp;
}

Complex Complex::operator/(const Complex &obj){
	Complex temp = Complex((real*obj.real+imag*obj.imag)/(obj.real*obj.real+obj.imag*obj.imag),(obj.real*imag-real*obj.imag)/(obj.real*obj.real+obj.imag*obj.imag));
	return temp;
}

//Private
void Complex::CalcNorm(){
	norm=sqrt(real*real+imag*imag);
}
