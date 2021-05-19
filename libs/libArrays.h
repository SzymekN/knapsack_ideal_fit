#ifndef LIBTABLES_H
#define LIBTABLES_H
#include <iomanip>
#include <iostream>
#include <vector>
#include "libErrors.h"


/*
Show contents of array
@param arr - show contents of this array
@param size - size of this array
*/
template <class T> void ShowArray(T* arr, int size, int spacing = 2) {
	for (int i = 0; i < size; i++)
		std::cout << std::setw(spacing) << arr[i] << std::setw(spacing) << " ";
	std::cout << std::endl;
}

template <class T> void ShowArray(T** arr, int rows, int cols, int spacing = 2) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			std::cout << std::setw(spacing) << arr[i][j] << std::setw(spacing) << " ";
		std::cout << std::endl;
	}
}

/*
Function creates dynamic array of wanted type
@param size size
@return array of wanted type
*/
template <class T> T* CreateArray(int size){
	T* arr = nullptr;
	try {
		arr = new T[size];
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}

	return arr;
}
/*
Function creates 2D dynamic array of wanted type
@param rows number of rows
@param cols number of columns
@return 2D array of wanted type
*/
template <class T> T** CreateArray(int rows, int cols) {
	//pointer to created table
	T** createdArray;
	try {
		createdArray = new T * [rows];
		for (T i = 0; i < rows; i++)
			try {
			createdArray[i] = new T[cols];

		}
		catch (std::bad_alloc) {
			throw EXCEPTION_CODE::allocationError;
			return nullptr;
		}
		//return array if memory allocation was succesful 
		return createdArray;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
	return nullptr;

}
/*
Function deletes array
@param arr array that will be deleted
*/
template <class T> void DeleteArray(T* arr) {
	try {
		delete[]arr;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
};

/*
Function deletes two dimensional array
@param arr array that will be deleted
@param rowCount number of rows of the array that will be deleted
*/
template <class T> void DeleteArray(T** arr, int rowCount) {
	try {
		for (int i = 0; i < rowCount; i++)
			delete[]arr[i];
		delete[]arr;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
};


/*
Show all elements of a vector
@param v - show this vector
*/
template <class T> void ShowVector(std::vector<T> v) {
	for (T value : v)
		std::cout << value << " ";
	std::cout << std::endl;
};


#endif // !LIBTABLES_H
