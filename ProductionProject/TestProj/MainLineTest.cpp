#include <iostream>
#include <assert.h>

#include "../ProdProject/Production.h"

using namespace std;

int main()
{
	Production p;

	std::vector<int> testVec = { 12,2,24,31,1,42 };
	int testInt = 1;

	std::cout << p.CheckNoDoubles(testVec, testInt) << std::endl;
	assert(p.CheckNoDoubles(testVec, testInt) == 1);
	std::cout << p.VectorSizeTest(testVec) << std::endl;
	assert(p.VectorSizeTest(testVec) == 1);
	std::cout << p.NumRange(testInt) << std::endl;
	assert(p.NumRange(testInt) == 1);
	cin.get();
}