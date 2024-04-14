#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
	public:
		//Methods
		Complex(); //Default Constructor
		Complex(double a, double b); //Personalized Constructor
		Complex(const Complex &obj);
                Complex &operator=(const Complex &obj);
		~Complex();
		void Print();
		void Norm();
		void Conjugate();

	private:
		//Variables
		double real;
		double imag;
		double norm;
};
#endif


