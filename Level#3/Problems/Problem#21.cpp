#include <iostream>

using namespace std;

int main()
{
	int Prev1 = 1, Prev2 = 1;
	int Counter = 0, Fibo;
	cout << "\nFibonacci series of 10 : \n" << endl;

	do
	{
		Fibo = Prev1;
		cout << Fibo << "     ";
		Prev1 = Prev2;
		Fibo = Fibo + Prev2;
		Prev2 = Fibo;
		Counter++;

	} while (Counter<10);

	cout << endl;

	return 0;
}
