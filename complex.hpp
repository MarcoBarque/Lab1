#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
	public:
		Complex(double a, double b);
		Complex(const Complex &obj);
                Complex &operator=(const Complex &obj);
		~Complex();
		void Norm();
		void Conjugate();
	private:
		Complex();
		double real;
		double imag;
		double norm;
};
#endif


