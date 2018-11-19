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
		if (val != v[i])
		{
			valDouble = true;
		}
		else
			valDouble = false;
	}
	bool NoDoubles = (iter == v.end());
	NoDoubles = valDouble;
	return NoDoubles;
}

bool Production::NumRange(std::vector<int> v, int val)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if ((*iter) > 46 || (*iter) < 1)
		{
			return 0;
		}
		if (val >= 1 && val <= 46)
		{
			return 0;
		}
	}
	return 1;
}