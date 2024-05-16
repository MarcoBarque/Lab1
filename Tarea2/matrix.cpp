#include <iostream>
#include "matrix.hpp"
#include <iomanip>
#include <vector>

//Marco Barquero (C30970), Andres Chacon (C32026)

//Public
Matrix::Matrix(){
	n_rows=3;
	n_cols=3;

	Matrix(n_rows, n_cols);
}

Matrix::Matrix( int n_rows, int n_cols ){
	std::vector<double> mat (n_rows * n_cols, 0.0);

	int k=1;
	for(int i = 0; i < n_rows; ++i){
    		for(int j = 0; j < n_cols; ++j){
      			mat[(i * n_cols) + j] = k;
    			k+=1;
		}
	}
	*data = mat;
}


Matrix::Matrix(const Matrix &obj){
        std::cout << "Copy constructor invoked" << std::endl;

        n_rows=obj.n_rows;
        n_cols=obj.n_cols;
        *data=*obj.data;
}

Matrix &Matrix::operator=(const Matrix &obj){
        std::cout <<"Assignment operator invoked"<<std::endl;

        n_rows=obj.n_rows;
        n_cols=obj.n_cols;
        *data=*obj.data;

        return *this;
}

Matrix::~Matrix(){
        delete data;
	std::cout<<"Destructor invocked"<<std::endl;
}

//Overrides

Matrix Matrix::operator+(const Matrix &obj){
        if (n_rows!=obj.n_rows or n_cols!=obj.n_rows){
                std::cout << "Error: Matrices must have the same dimensions." << std::endl;
                Matrix X;
                return X;
        }
        else {
                Matrix temp = Matrix (n_rows,n_cols);
                for (int i=0; i < n_rows; i++){
                        for (int j=0 ; j < n_cols; i++){
                                temp.data[(i * n_cols)+ j] = data[(i * n_cols)+ j] + obj.data[(i * n_cols)+ j];
                        }
                }
                return temp;
        }
}

Matrix Matrix::operator-(const Matrix &obj){
        if (n_rows!=obj.n_rows or  n_cols!=obj.n_rows){
                std::cout << "Error: Matrices must have the same dimensions." << std::endl;
                Matrix X;
                return X;
        }
        else {
                Matrix temp = Matrix (n_rows,n_cols);
                for (int i=0; i < n_rows; i++){
                        for (int j=0 ; j<n_cols; i++){
                                *temp.data[(i * n_cols)+ j] = *data[(i * n_cols)+ j] - *obj.data[(i * n_cols)+ j];
                        }
                }
                return temp;
        }
}

Matrix Matrix::operator*(const Matrix &obj){
        if (n_cols!=obj.n_rows){
                std::cout << "Error: For matrices multiplying AxB, the number of columns of A must be the as the number of rows of B. " << std::endl;
                Matrix X;
                return X;
        }
        else{
                Matrix C=Matrix(n_rows,obj.n_cols);
                for(int i = 0; i < n_rows; ++i){
                        for(int j = 0; j < obj.n_cols; ++j){
                                for(int k = 0; k < n_cols; ++k){
                                        *C.data[(i * n_cols) + j] += *data[(i * n_rows) + k] * *obj.data[(k * n_cols) + j];
                                }
                        }
                }
                return C;
        }
}

//Methods

int Matrix::get_rows(){
	std::cout << "The number of rows of the matrix is: " << n_rows  << std::endl;
	return n_rows;
}

int Matrix::get_cols(){
        std::cout << "The number of columns of the matrix is: " << n_cols  << std::endl;
        return n_cols;
}

void Matrix::Disp(){
        std::cout << "The matrix is: "<< std::endl;
        for(int i = 0; i < n_rows; ++i){
                for(int j = 0; j < n_cols; ++j){
                        std::cout << data[(i * n_cols) + j] << " ";
                }
        std::cout << std::endl;
        }
}


