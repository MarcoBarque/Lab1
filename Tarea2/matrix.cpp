#include <iostream>
#include "matrix.hpp"
#include <iomanip>
#include <vector>

//Marco Barquero (C30970), Andres Chacon (C32026)

//Public
Matrix::Matrix(){//Default Constructor
	Matrix Pre = Matrix(3, 3);

	n_rows = Pre.n_rows;
	n_cols = Pre.n_cols;

	data = new std::vector<double> (*Pre.data);
}

Matrix::Matrix( int rows, int cols ){//Personalized constructor
	n_rows = rows;
	n_cols = cols;

	data = new std::vector<double>(n_rows * n_cols);

	int k=1;
	for(int i = 0; i < n_rows; ++i){
    		for(int j = 0; j < n_cols; ++j){
			(*data)[(i * n_cols) + j] = k;
			k+=1;
		}
	}
}


Matrix::Matrix(const Matrix &obj){//Copy Constructor
        std::cout << "Copy constructor invoked" << std::endl;

        n_rows=obj.n_rows;
        n_cols=obj.n_cols;
        data = new std::vector<double> (*obj.data) ;
}

Matrix &Matrix::operator=(const Matrix &obj){//Assignment operator
        std::cout <<"Assignment operator invoked"<<std::endl;
	
	delete data;

        n_rows=obj.n_rows;
        n_cols=obj.n_cols;
        data = new std::vector<double> (*obj.data);

        return *this;
}

Matrix::~Matrix(){//Destructor
        delete data;
	std::cout<<"Destructor invocked"<<std::endl;
}

//Overrides

Matrix Matrix::operator+(const Matrix &obj){
        if (n_rows != obj.n_rows or  n_cols != obj.n_cols){
                std::cout << "Error: Matrices must have the same dimensions. The matrix returned is the default matrix." << std::endl;
                Matrix X;
                return X;
        }
        else {
                Matrix temp = Matrix(n_rows,n_cols);
                for (int i=0; i < n_rows * n_cols ; i++){
			(*temp.data)[i] = (*data)[i] + (*obj.data)[i];
                }
                return temp;
        }
}

Matrix Matrix::operator-(const Matrix &obj){
        if (n_rows!=obj.n_rows or  n_cols!=obj.n_cols){
                std::cout << "Error: Matrices must have the same dimensions. The matrix returned is the default matrix." << std::endl;
                Matrix X;
                return X;
        }
        else {
                Matrix temp = Matrix(n_rows,n_cols);
                for (int i=0; i < n_rows * n_cols ; i++){
                        (*temp.data)[i] = (*data)[i] - (*obj.data)[i];
                }
                return temp;
        }
}

Matrix Matrix::operator*(const Matrix &obj){
        if (n_cols != obj.n_rows){
                std::cout << "Error: The number of columns of the first matrix must be the as the number of rows of the second one. The matrix returned is the default matrix." << std::endl;
                Matrix X;
                return X;
        }
        else{
                Matrix C = Matrix(n_rows,obj.n_cols);
                for(int i = 0; i < n_rows; ++i){
                        for(int j = 0; j < obj.n_cols; ++j){
                                double sum = 0.0;
				for(int k = 0; k < n_cols; ++k){
				       sum += (*data)[(i * n_cols) + k] * (*obj.data)[(k * obj.n_cols) + j];
                                }
				(*C.data)[(i * obj.n_cols) + j] = sum;
                        }
                }
                return C;
        }
}


//Methods

int Matrix::get_rows(){
	return n_rows;
}

int Matrix::get_cols(){
        return n_cols;
}

void Matrix::print(){
        for(int i = 0; i < n_rows; ++i){
                for(int j = 0; j < n_cols; ++j){
                        std::cout << (*data)[((i * n_cols) + j)] << " ";
                }
        std::cout << std::endl;
        }
}
