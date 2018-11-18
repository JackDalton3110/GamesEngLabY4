#include "Production.h"
#include <vector>

int Production::someMethod(int a)
{
	return a - a;
}

int Production::VectorSizeTest(std::vector<int> v)
{
	return v.size() == 6;
}

bool Production::CheckNoDoubles(std::vector<int> v)
{
	std::sort(v.begin(), v.end());
	auto iter = std::unique(v.begin(), v.end());
	bool NoDoubles = (iter == v.end());
	return NoDoubles;
}

bool Production::NumRange(std::vector<int> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		if ((*iter) > 46 || (*iter) < 1)
		{
			return 0;
		}
	}
	return 1;
}