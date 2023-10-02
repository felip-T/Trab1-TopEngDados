#include "matrix.h"
#include "squareMatrix.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
void multAll(vector<Matrix<T> *> &mats) {
	for (auto i : mats) {
		for (auto j : mats) {
			try {
				cout << ((*i) * (*j)) << endl;
			} catch (exception &e) {
				cout << e.what() << endl << endl;
			}
		}
	}
}


template <class T>
void addAll(vector<Matrix<T> *> &mats) {
	for (auto i : mats) {
		for (auto j : mats) {
			try {
				cout << ((*i) + (*j)) << endl;
			} catch (exception &e) {
				cout << e.what() << endl << endl;
			}
		}
	}
}

template <class T>
void showAll(vector<Matrix<T> *> &mats) {
  for (auto i : mats)
    cout << i->show() << endl;
}

template <class T>
void multAllByScalar(vector<Matrix<T> *> &mats, T scalar) {
	for (auto i : mats)
		cout << (*i) * scalar << endl;
}

void transposeAll(vector<Matrix<float> *> &mats) {
	for (auto i : mats)
		cout << (*i).transpose() << endl;
}

int main() {

  vector<Matrix<float> *> mats;

  mats.push_back(new Matrix<float>(3, 2, 1));
  mats.push_back(new Matrix<float>(2, 3, 2));
	SquareMatrix<float> *sq = new SquareMatrix<float>(3, 3);
  mats.push_back(sq);
	DiagonalMatrix<float> *diag = new DiagonalMatrix<float>(3, 4);
  mats.push_back(diag);
	TriangularDownMatrix<float> *triD = new TriangularDownMatrix<float>(3, 5);
  mats.push_back(triD);
	TriangularDownMatrix<float> *triUp = new TriangularDownMatrix<float>(3, 6);
	mats.push_back(triUp);

	vector<SquareMatrix<float> *> sqs;
	sqs.push_back(sq);
	sqs.push_back(diag);
	sqs.push_back(triD);
	sqs.push_back(triUp);

	int menu= -1;
	float aux;

	while (menu != 0) {
		cout << "1. Mostrar todas as matrizes" << endl;
		cout << "2. Multiplicar todas as matrizes" << endl;
		cout << "3. Somar todas as matrizes" << endl;
		cout << "4. Multiplicar todas as matrizes por um escalar" << endl;
		cout << "5. Transpor todas as matrizes" << endl;
		cout << "6. Traço das quadradas" << endl;
		cout << "7. Determinante das triangulares" << endl;
		cout << "0. Sair" << endl;
		cin >> menu;
		switch (menu) {
			case 1:
				showAll(mats);
				break;
			case 2:
				multAll(mats);
				break;
			case 3:
				addAll(mats);
				break;
			case 4:
				cout << "Digite o escalar" << endl;
				cin >> aux;
				cout << "Multiplicando todas as matrizes por " << aux << endl;
				multAllByScalar(mats, aux);
				break;
			case 5:
				transposeAll(mats);
				break;
			case 6:
				for (auto i : sqs)
					cout << "Traço de \n" << (*i) << "= " << i->trace() << '\n' <<endl;
				break;
			case 7:
				cout << "determinante de \n" << (*triD) << "= " << triD->det() << '\n' <<endl;
				cout << "determinante de \n" << (*triUp) << "= " << triUp->det() << '\n' <<endl;
			case 0:
				break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}
	
	for (auto i : mats) {
		delete i;}

  return 0;
}
