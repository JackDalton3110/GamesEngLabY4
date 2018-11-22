#pragma once
#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <set>
#include <limits>

using std::numeric_limits;
using std::streamsize;


class Production {
public:
	int someMethod(int a);
	int LottoDraw();
	int LottoEntries();
	int CheckForWinner(std::vector<int> entered, std::vector<int>drawn);
	int VectorSizeTest(std::vector<int> v);
	bool CheckNoDoubles(std::vector<int> v, int val);
	bool NumRange(int val);
protected:
	std::vector<int>enteredNums;
	std::vector<int>drawnNumbers;
};
