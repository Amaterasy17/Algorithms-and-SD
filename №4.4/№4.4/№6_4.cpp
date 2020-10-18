//K-statistic

#include <iostream>
#include <utility>
#include <ctime>
#include <functional>
using namespace std;

int* partition(int* mas, int size)
{
	srand(std::time(0));
	int p = rand() % (size - 1);
	swap(mas[p], mas[size - 1]);
	bool flag_i = false;
	int i = size - 2;
	for (int j = size - 2; j > 0; --j)
	{
		if ((mas[j] > mas[size - 1]) && !flag_i)
		{
			i = j;
		}
		if (mas[j] <= mas[size - 1] && flag_i)
		{
			swap(mas[j], mas[i]);
		}
	}

	return mas;
}
int main()
{	
	int n;
	cin >> n;
	int* mas = new int[n];
	partition(mas, n);
	for (int i = 0; i < n; ++i)
	{
		cout << mas[i] << " ";
	}
	return 0;
}