#include "libKnapsackRec.h"

void IdealFit(std::vector<int>& result, std::vector<int> temp, int* arr, int n, int size)
{

	if (arr == nullptr)
		throw EXCEPTION_CODE::nullPointerError;
	if (n < 0)
		throw EXCEPTION_CODE::valueOutOfBoundaries;

	//if sum of all elements in temp equals size, copy result
	if (size == 0)
		result = temp;

	//if last element return or found all wanted elements
	if (n == 0 or size == 0)
		return;

	//If result not found go deeper, without including current element
	if (result.size() == 0)
		IdealFit(result, temp, arr, n - 1, size);

	//include current element to solution
	temp.push_back(arr[n - 1]);

	//if result not found go deeper with current element added
	if (result.size() == 0)
		IdealFit(result, temp, arr, n - 1, size - arr[n - 1]);

}
