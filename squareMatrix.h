#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

template <class T>
class SquareMatrix : public Matrix<T>{
	public:
		SquareMatrix(unsigned, T init=T());
		SquareMatrix(){}
		virtual SquareMatrix<T> doOp(SquareMatrix<T>&, std::function<T(T,T)>) const;
		virtual SquareMatrix<T> operator+(SquareMatrix<T>&) const;
		virtual SquareMatrix<T> operator-(SquareMatrix<T>&) const;
		T trace();
	protected:
		using Matrix<T>::data;
		using Matrix<T>::rows;
		using Matrix<T>::cols;
};

template <class T>
SquareMatrix<T>::SquareMatrix(unsigned size, T init) : Matrix<T>(size, size, init){}

template <class T>
SquareMatrix<T> SquareMatrix<T>::doOp(SquareMatrix<T>& m, std::function<T(T,T)> op) const
{
	if (rows != m.rows || cols != m.cols)
		throw std::invalid_argument("Tamanhos diferentes");

	SquareMatrix<T> result(rows);
	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<cols; j++)
			result.at(i,j)= op(this->at(i,j),m.at(i,j));
	return result;
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::operator+(SquareMatrix<T>& m) const
{
	try{
		return doOp(m, std::plus<T>());
	}
	catch(std::invalid_argument& e){
		throw;
	}
}

template <class T>
SquareMatrix<T> SquareMatrix<T>::operator-(SquareMatrix<T>& m) const
{
	try{
		return doOp(m, std::minus<T>());
	}
	catch(std::invalid_argument& e){
		throw;
	}
}

template <class T>
T SquareMatrix<T>::trace(){
	T sum = 0;
	for(unsigned i = 0; i < rows; i++){
		sum += data->at(i, i);
	}
	return sum;
}

template <class T>
class DiagonalMatrix : public SquareMatrix<T>{
	public:
		DiagonalMatrix(unsigned, T _def=T(), T init=T());
		DiagonalMatrix<T> doOp(DiagonalMatrix<T>&, std::function<T(T,T)>) const;
		DiagonalMatrix<T> operator+(DiagonalMatrix<T>&) const;
		DiagonalMatrix<T> operator-(DiagonalMatrix<T>&) const;
	private:
		using Matrix<T>::data;
		using Matrix<T>::rows;
		using Matrix<T>::cols;
};

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(unsigned size, T init, T _def){
	data = new OneDMatrix(size, _def, init);
	rows = size;
	cols = size;
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::doOp(DiagonalMatrix<T>& m, std::function<T(T,T)> op) const
{
	if (rows != m.rows || cols != m.cols)
		throw std::invalid_argument("Tamanhos diferentes");

	DiagonalMatrix<T> result(rows);
	for (unsigned i=0; i<rows; i++)
			result.at(i,i)= op(this->at(i,i),m.at(i,i));
	return result;
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator+(DiagonalMatrix<T>& m) const
{
	try{
		return doOp(m, std::plus<T>());
	}
	catch(std::invalid_argument& e){
		throw;
	}
}

template <class T>
DiagonalMatrix<T> DiagonalMatrix<T>::operator-(DiagonalMatrix<T>& m) const
{
	try{
		return doOp(m, std::minus<T>());
	}
	catch(std::invalid_argument& e){
		throw;
	}
}

template <class T>
class TriangularDownMatrix : public SquareMatrix<T>{
	public:
		TriangularDownMatrix(unsigned, T init=T());
		T det() const;
	private:
		using Matrix<T>::data;
		using Matrix<T>::rows;
		using Matrix<T>::cols;
};

template <class T>
TriangularDownMatrix<T>::TriangularDownMatrix(unsigned size, T init){
	data = new TriMatrix(size, init);
	rows = size;
	cols = size;
}

template <class T>
T TriangularDownMatrix<T>::det() const{
	T result = 1;
	for(unsigned i = 0; i < rows; i++){
		result *= data->at(i, i);
	}
	return result;
}

template <class T>
class TriangularUpMatrix : public SquareMatrix<T>{
	public:
		TriangularUpMatrix(unsigned, T init=T());
		T det() const;
	private:
		using Matrix<T>::data;
		using Matrix<T>::rows;
		using Matrix<T>::cols;
};

template <class T>
TriangularUpMatrix<T>::TriangularUpMatrix(unsigned size, T init){
	data = new TriUpMatrix(size, init);
	rows = size;
	cols = size;
}

template <class T>
T TriangularUpMatrix<T>::det() const{
	T result = 1;
	for(unsigned i = 0; i < rows; i++){
		result *= data->at(i, i);
	}
	return result;
}
#endif
