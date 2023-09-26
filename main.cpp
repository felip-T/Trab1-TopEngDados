#include <iostream>
#include <string>
#include "matrix.h"
#include "squareMatrix.h"

using namespace std;

int main(){

	SquareMatrix<int> m1(5, 2);
	SquareMatrix<int> m6(5, 2);
	Matrix<int> m2(5, 2, 2);
	DiagonalMatrix<int> m3(2, 3);
	DiagonalMatrix<int> m4(2, 3);

	cout << m1 << endl << m2 << endl << m3 << endl;
	cout << typeid(6*m1).name() << endl;

	try{
		cout << (m3*m3) << endl;
	}
	catch(std::exception& e){
		cout << e.what() << endl;
	}

	return 0;
}
