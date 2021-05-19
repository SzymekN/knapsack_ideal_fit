#include <iostream>
#include "libs/libKnapsackRec.h"
#include "libs/libArrays.h"
#include "libs/libFiles.h"

int main()
{
	//array with item weights
	int* weights{};
	//how many items in one data set
	int itemCount{};
	//size of knapsack
	int size{};
	//number of different data sets
	int dataSets{};
	//solution to current data set
	std::vector<int> values;
	//temporary values for 
	std::vector<int> temp;
	//stream used to handle reading from file
	std::ifstream readFromFile;

	try {
		OpenFile(readFromFile, "in.txt");
		readFromFile >> dataSets;
		//throw error if number of data sets exceds given values
		InBoundaries(dataSets, 0, (int)pow(10, 6));

		for (int i = 0; i < dataSets; i++) {
			readFromFile >> size;
			InBoundaries(size, 0, (int)pow(10, 6));
			readFromFile >> itemCount;
			InBoundaries(itemCount, 0, (int)pow(10, 6));
			weights = CreateArray<int>(itemCount);

			WriteLineToArray(weights, readFromFile, itemCount);
			IdealFit(values, temp, weights, itemCount, size);

			//If result was found show it
			if (values.size() != 0) {
				std::cout << size << " = ";
				ShowVector(values);
			}
			else
				std::cout << "NONE\n";

			values.resize(0);
			DeleteArray(weights);

		}
	}
	catch (EXCEPTION_CODE err) {
		ShowException(err);
		exit(-1);
	}


	//IdealFit(weights, itemCount-1, size);

}

