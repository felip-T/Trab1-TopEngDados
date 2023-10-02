#ifndef MATRIX_H
#define MATRIX_H

#include "structures.h"
#include <iostream>
#include <functional>
#include <stdexcept>

template <class T>
class Matrix{
	public:
		Matrix(unsigned, unsigned, T init=T());
		Matrix(){}
		virtual ~Matrix();
		virtual T& at(unsigned, unsigned) const;
		virtual T get(unsigned, unsigned) const;
		virtual Matrix<T> doOp(Matrix<T>&, std::function<T(T,T)>) const;
		Matrix<T> transpose() const;
		virtual Matrix<T> operator+(Matrix<T>&) const;
		virtual Matrix<T> operator-(Matrix<T>&) const;
		virtual Matrix<T> operator*(T) const;
		virtual Matrix<T> operator*(Matrix<T>&) const;
		std::string show() const;

	template <class U>
  friend std::ostream &operator<<(std::ostream &, const Matrix<U> &);


	protected:
		MatrixDataStruc<T>* data;
		unsigned rows, cols;
};

template <class T>
Matrix<T>::Matrix(unsigned row, unsigned col, T init){
	data = new TwoDMatrix(row, col, init);
	rows = row;
	cols = col;
}

template <class T>
Matrix<T>::~Matrix() {delete data;}

template <class T>
T& Matrix<T>::at(unsigned row, unsigned col) const{
	if (row >= rows || col >= cols)
		throw std::out_of_range("Indice inexistente");
	return data->at(row, col);
}

template <class T>
T Matrix<T>::get(unsigned row, unsigned col) const{
	if (row >= rows || col >= cols)
		throw std::out_of_range("Indice Inexistente");
	return data->get(row, col);
}

template <class T> std::string Matrix<T>::show() const {
  std::string result = "";
  for (unsigned i = 0; i < rows; i++) {
    for (unsigned j = 0; j < cols; j++) {
      result.append(std::to_string(at(i, j))).append(" ");
    }
    result.append("\n");
  }
  return result;
}

template<class T>
Matrix<T> Matrix<T>::transpose() const{
	Matrix<T> result(cols, rows);
	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<cols; j++)
			result.at(j,i) = get(i,j);
	return result;
}

template <class T>
Matrix<T> Matrix<T>::doOp(Matrix<T>& m, std::function<T(T,T)> op) const{

	if (rows != m.rows || cols != m.cols)
		throw std::invalid_argument("Tamanhos diferentes");

	Matrix<T> result(rows, cols);
	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<cols; j++)
			result.at(i,j)= op(this->at(i,j),m.at(i,j));
	return result;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& m) const{
	return doOp(m, std::plus<T>());
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& m) const{
	return this->doOp(m, std::minus());
}

template <class T>
Matrix<T> Matrix<T>::operator*(T n) const{
	Matrix<T> result(rows, cols);
	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<cols; j++)
			result.at(i,j)= get(i,j)*n;
	return result;
}

template <class U>
std::ostream &operator<<(std::ostream &os, const Matrix<U> &m) {
  os << m.show();
  return os;
}

template <class T>
Matrix<T> operator*(T n, Matrix<T>& m) { return m*n; }

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& m) const{
	if (cols != m.rows)
		throw std::invalid_argument("Tamanhos incompatíveis");
	Matrix<T> result(rows, m.cols);

	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<m.cols; j++)
			for (unsigned k=0; k<cols; k++)
				result.at(i,j) += get(i,k)*m.at(k,j);

	return result;
}

#endif
