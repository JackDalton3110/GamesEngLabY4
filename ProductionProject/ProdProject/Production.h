#pragma once
#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <set>

class Production {
public:
	int someMethod(int a);
	int LottoDraw();
	int LottoEntries();
	int CheckForWinner(std::vector<int> entered, std::vector<int>drawn);
	int VectorSizeTest(std::vector<int> v);
	bool CheckNoDoubles(std::vector<int> v, int val);
	bool NumRange(std::vector<int> v, int val);
protected:
	std::vector<int>enteredNums;
	std::vector<int>drawnNumbers;
};
