#include "../ProdProject/Production.h"
#include <vector>

//int Production::someMethod(int a)
//{
//	return a - a;
//}

int Production::VectorSizeTest(std::vector<int> v)
{
	return v.size() == 6;
}

bool Production::CheckNoDoubles(std::vector<int> v, int val)
{
	bool valDouble = true;
	std::sort(v.begin(), v.end());
	auto iter = std::unique(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (val == v[i])
		{
			valDouble = false;
			break;//checks if number that is about to be added isn't already in vector
		}
		else
			valDouble = true;
	}
	bool NoDoubles = (iter == v.end());
	NoDoubles = valDouble;
	return NoDoubles;
}

bool Production::NumRange(int val)
{
	int result =1;
	if (val < 1 || val > 46)
	{
		result = 0; //checks that number about to entered to vector is within limit
	}
	else
	{
		result = 1;
	}
	
	return result;
}

