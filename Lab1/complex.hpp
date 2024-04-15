#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
	public:
		//Methods
		Complex(); //Default Constructor
		Complex(double a, double b); //Personalized Constructor
		Complex(const Complex &obj); //Copy Constructor
                Complex &operator=(const Complex &obj); //Assigment Operator
		~Complex(); //Destructor
		void Disp(); //Displays the complex
		double Norm(); //Returns the norm
		void Conjugate(); //Conjugates the complex
		Complex operator+(const Complex &obj); //Overrides the sum
		Complex operator-(const Complex &obj); //Overrides the substraction
		Complex operator*(const Complex &obj); //Overrides the multiplication
		Complex operator/(const Complex &obj); //Overrides the division
	private:
		//Variables
		double real; //Real component of the complex
		double imag; //Imaginary component of the complex
		double norm; //Norm of the complex
		
		//Functions
		void CalcNorm(); //Calculates the complex's norm
};
#endif


