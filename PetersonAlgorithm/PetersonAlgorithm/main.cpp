#include <thread>
#include <iostream>
#include <atomic>
#include <memory>

using namespace std;
bool flag1 = false, flag2 = false;
bool turn = false;

void process1()
{
	while (true)
	{
		flag1 = true;
		turn = true;
		while (!flag1 && turn){}
		std::cout << "process 1" << std::endl;
		flag1 = false;
	}
}

void process2()
{
	while (true)
	{
		flag2 = true;
		turn = true;
		while (!flag2 && turn){}
		std::cout << "process 2" << std::endl;
		flag1 = false;
	}
}

int main()
{
	std::thread t1(process1);
	std::thread t2(process2);
	t1.join();
	t2.join();
	std::cout << "processes complete!" << std::endl;
	system("PAUSE");
}