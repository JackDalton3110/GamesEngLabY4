#include <thread>
#include <iostream>
#include <atomic>
#include <memory>
#include <string>
#include <vector>

using namespace std;
bool flag1 = false, flag2 = false;
bool turn = false;
const int n = 4;
int last[n], in[n];
std::vector<std::thread> threads[n];

void process(int i)
{
	
		while (true)
		{
			for (int j = 0; j < n; j++)
			{
				in[i] = j; last[j] = i;
				for (int k = 0; k < n; k++)
				{
					if (i != k)
					{
						while (in[k] >= in[i] && last[j] == i)
						{
							continue;
						}
					}
				}
			}
			std::cout << "process " + to_string(i) << std::endl;
			in[i] = -1;
		}
}

int main()
{
	
	for (int i = 0; i < n; i++)
	{
		threads[i].push_back(thread(process, i));
	}
	for (int i = 0; i < n; i++)
	{
		threads->at(i).join();
	}
}