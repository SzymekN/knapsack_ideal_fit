#ifndef LIBKNAPSACKREC_H
#define LIBKNAPSACKREC_H
#include <vector>
#include <iostream>
#include "libErrors.h"

/*
Find items that sum of values equal size of knapsack
@param result - ence to a vector that will containt solution
@param temp - temporary vector on each call containing different values
@param weights - pointer to array containig values/weights of objectss
@param n - iterator changed on each call of a function
@param size - size of knapsack
*/
void IdealFit(std::vector<int>& results, std::vector<int> temp, int* weights, int itemCount, int size);

#endif // !LIBKNAPSACKREC_H
