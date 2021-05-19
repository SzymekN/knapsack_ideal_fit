#ifndef LIBFILES_H
#define LIBFILES_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "libErrors.h"

/*
Function creates new file
@param createFile stream used to create a new file
@param passedName passed name of file to be created
*/
void CreateFile(std::ofstream& createFile, std::string passedName="");

/*
Function opens a file
@param openFile stream used to open a file
*/
void OpenFile(std::ifstream& openFile, std::string passedName = "");

/*
Function checks if given file name has correct extension and if not corrects it
@param fileName[30] variable containing file name
*/
void CheckFileName(char fileName[30]);

/*
Write line from file to an array
@param arr - write values to this array
@param readFromFile - read line from this file
@param size - expected number of values to read
*/
template <class T> void WriteLineToArray(T* arr, std::ifstream& readFromFile, int size=-1)
{
	std::string line;
	std::getline(readFromFile, line);
	if(line == "")
		std::getline(readFromFile, line);
	std::istringstream iss(line);
	int i{};
	while (iss.peek() != EOF) {
		if (size != -1 and i >= size)
			throw EXCEPTION_CODE::invalidData;
		iss>>arr[i];
		i++;
	}
	if (size != -1 and i != size)
		throw EXCEPTION_CODE::invalidData;
}

#endif
