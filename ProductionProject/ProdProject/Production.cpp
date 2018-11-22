#include "Production.h"
#include "../TestProj/Production.cpp"
#include <vector>

int Production::someMethod(int a)
{
	return a - a;
}

int Production::LottoDraw()
{
	
	int numDrawn=0;
	for (int i =0; i < 6; i++)
	{
		
		while (VectorSizeTest(drawnNumbers) == 0)
		{
			numDrawn = rand() % 46 + 1;
			if(CheckNoDoubles(drawnNumbers,numDrawn)==1 && NumRange(numDrawn)==1)
			drawnNumbers.push_back(numDrawn);
		}
	}
	if (drawnNumbers.size() == 6)
	{
		std::cout << "The Lotto Numbers are: " << drawnNumbers[0] << ", " << drawnNumbers[1] << ", " << drawnNumbers[2] << ", " << drawnNumbers[3] << ", " << drawnNumbers[4] << ", " << drawnNumbers[5] << std::endl;
	}

	CheckForWinner(enteredNums, drawnNumbers);

	return 0;
}

int Production::LottoEntries()
{
	int entryNum = 0;
	while (VectorSizeTest(enteredNums)==0)
	{
		std::cout << "Enter Lotto number" << std::endl;
			std::cin>>entryNum;

		if (CheckNoDoubles(enteredNums,entryNum) == 1 &&NumRange(entryNum) == 1)
		{
			enteredNums.push_back(entryNum);
		}
		else if (std::cin.fail())
		{
			std::cout << "invlaid Number try again" << std::endl;
			std::cin.clear(); // clear the error flags
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* ignore the rest of what's left in the input buffer
																	  because cin stops reading at the first bad character*/
		}
	}
	std::cout << "" << std::endl;
	std::cout << "Your Numbers are: " << enteredNums[0] << ", " << enteredNums[1] << ", " << enteredNums[2] << ", " << enteredNums[3] << ", " << enteredNums[4] << ", " << enteredNums[5] << std::endl;
	return 0;
}

int Production::CheckForWinner(std::vector<int>entered, std::vector<int>drawn)
{
	std::vector<int>winners;
	std::sort(entered.begin(), entered.end());
	std::sort(drawn.begin(), drawn.end());

	set_intersection(entered.begin(), entered.end(), drawn.begin(), drawn.end(), std::back_inserter(winners));
	if (winners.size() != 0)
	{
		std::cout << "" << std::endl;
		std::cout << "Your winning numbers were: "<< winners[0];
		for (int i = 1; i < winners.size(); i++)
		{
			std::cout << ", "<<winners[i];
		}
		std::cout << "" << std::endl;
	}
	else
	{
		std::cout << " " << std::endl;
		std::cout << "You were not a winner, try again!" << std::endl;
	}
	return 0;
}

//int Production::VectorSizeTest(std::vector<int> v)
//{
//	return v.size() == 6;
//}
//
//bool Production::CheckNoDoubles(std::vector<int> v)
//{
//	std::sort(v.begin(), v.end());
//	auto iter = std::unique(v.begin(), v.end());
//	bool NoDoubles = (iter == v.end());
//	return NoDoubles;
//}
//
//bool Production::NumRange(std::vector<int> v)
//{
//	for (auto iter = v.begin(); iter != v.end(); ++iter)
//	{
//		if ((*iter) > 46 || (*iter) < 1)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}