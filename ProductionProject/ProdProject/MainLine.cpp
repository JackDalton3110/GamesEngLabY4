#include "Production.h"
#include<ctime>
#include<cstdlib>


int main()
{
	srand(time(NULL));
	Production p;
	p.someMethod(10);
	p.LottoEntries();
	p.LottoDraw();

	system("PAUSE");
	return 0;
}
