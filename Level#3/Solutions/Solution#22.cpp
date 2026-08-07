#include <iostream>

using namespace std;

void PrintFibonacciUsingRecurssion(short Number, short Prev1, short Prev2)
{
	int FibNumber = 0;
	if (Number > 0)
	{
		FibNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		cout << FibNumber << "    ";
		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
	}
}
int main()
{

	PrintFibonacciUsingRecurssion(10, 0, 1);
	system("pause>0");
	return 0;
}
