#include <vector>
#ifndef MATRIX_HPP
#define MATRIX_HPP


//Marco Barquero (C30970), Andres Chacon (C32026)

class Matrix
{
	public:
		//Methods
		Matrix(); //Defautl Constructor
		Matrix(int n_rows,int n_cols); //Personalized constructor
		Matrix(const Matrix &obj); //Copy Constructor
                Matrix &operator=(const Matrix &obj); //Assigment Operator
                ~Matrix(); //Destructor

		Matrix operator+(const Matrix &obj); //Overrides the sum
                Matrix operator-(const Matrix &obj); //Overrides the substraction
                Matrix operator*(const Matrix &obj); //Overrides the multiplication

		int get_rows();
		int get_cols();
		void print();

	private:
		//Atributes
		int n_cols;
		int n_rows;
		std::vector<double>* data;
};
#endif
