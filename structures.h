#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdexcept>

template <class T>
class MatrixDataStruc{
public:
	virtual T& at(unsigned, unsigned)=0;
	virtual T get(unsigned, unsigned)=0;
	virtual ~MatrixDataStruc(){}
};

template <class T>
class TwoDMatrix : public MatrixDataStruc<T>{
	public:
		TwoDMatrix(unsigned, unsigned, T init=T());
		~TwoDMatrix() override;
		T& at(unsigned, unsigned) override;
		T get(unsigned, unsigned) override;
	private:
		unsigned rows, cols;
		T** data;
};

template <class T>
TwoDMatrix<T>::TwoDMatrix(unsigned row, unsigned col, T init){
	rows = row;
	cols = col;
	data = new T*[row];
	for(unsigned i = 0; i < row; i++){
		data[i] = new T[col];
		for(unsigned j = 0; j < col; j++){
			data[i][j] = init;
		}
	}
}

template <class T>
TwoDMatrix<T>::~TwoDMatrix(){
	for (unsigned i=0; i<rows; i++)
		delete[] data[i];
	delete[] data;
}

template <class T>
T& TwoDMatrix<T>::at(unsigned row, unsigned col){
	if (row >= rows || col >= cols)
		throw std::out_of_range("Indice inexistente");
	return data[row][col];
}

template <class T>
T TwoDMatrix<T>::get(unsigned row, unsigned col){
	return data[row][col];
}

template <class T>
class OneDMatrix : public MatrixDataStruc<T>{
	public:
		OneDMatrix(unsigned, T _def=T(), T init=T());
		~OneDMatrix() override;
		T& at(unsigned, unsigned) override;
		T get(unsigned, unsigned) override;
	private:
		T* data;
		T def;
};

template <class T>
OneDMatrix<T>::OneDMatrix(unsigned size, T _def, T init){
	data = new T[size];
	for(unsigned i = 0; i < size; i++){
		data[i] = init;
	}
	def = _def;
}

template <class T>
OneDMatrix<T>::~OneDMatrix<T>() { delete[] data; }

template <class T>
T& OneDMatrix<T>::at(unsigned row, unsigned col){
	if (row == col){
		return data[row];
	}
	return def;
}

template <class T>
T OneDMatrix<T>::get(unsigned row, unsigned col){
	if (row == col){
		return data[row];
	}
	return def;
}

template <class T>
class TriMatrix : public MatrixDataStruc<T>{
	public:
		TriMatrix(unsigned, T _init=T(), T _def=T());
		~TriMatrix() override;
		virtual T& at(unsigned, unsigned) override;
		virtual T get(unsigned, unsigned) override;
	protected:
		unsigned size;
		T** data;
		T def;
};

template <class T>
TriMatrix<T>::TriMatrix(unsigned _size, T _init, T _def){
	size = _size;
	def = _def;
	data = new T*[size];
	for(unsigned i = 0; i < size; i++){
		data[i] = new T[i+1];
		for(unsigned j = 0; j < i+1; j++){
			data[i][j] = _init;
		}
	}
}

template <class T>
TriMatrix<T>::~TriMatrix(){
	for (unsigned i=0; i<size; i++)
		delete[] data[i];
	delete[] data;
}

template <class T>
T& TriMatrix<T>::at(unsigned row, unsigned col){
	if (row >= col){
		return data[row][col];
	}
	return def;
}

template <class T>
T TriMatrix<T>::get(unsigned row, unsigned col){
	if (row >= col){
		return data[row][col];
	}
	return def;
}

template <class T>
class TriUpMatrix : public TriMatrix<T>{
	public:
		TriUpMatrix(unsigned _size, T _init=T(), T _def=T()) : TriMatrix<T>(_size, _init, _def) {}
		T& at(unsigned row, unsigned col) { return TriMatrix<T>::at((TriMatrix<T>::size-1)-row, (TriMatrix<T>::size-1)-col); }
		T get(unsigned row, unsigned col) { return TriMatrix<T>::get((TriMatrix<T>::size-1)-row, (TriMatrix<T>::size-1)-col); }
};

#endif
