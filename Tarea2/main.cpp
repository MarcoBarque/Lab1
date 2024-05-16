#include <iostream>
#include "matrix.hpp"

int main(){
	Matrix a;

	Matrix b=Matrix(4,4);

	Matrix c=a;
	
	c=a;
	int R = c.get_rows();
	int C = c.get_cols();


	return 0;
}
