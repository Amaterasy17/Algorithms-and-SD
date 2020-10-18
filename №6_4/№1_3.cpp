#include <iostream>
#include <utility>
#include <ctime>
#include <functional>
using namespace std;

void enter(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> mas[i];
	}
}


int sum_index(int* mas, int size_mas, int* arr, int size_arr, int num)
{
	int j = size_arr - 1;
	int counter = 0;
	for (j; j >= 0; --j)
	{
		for (int k = 0; k < size_mas; ++k)
		{
			if ((mas[k] + arr[j]) == num)
			{
				++counter;
			}
			if ((mas[k] + arr[j]) > num)
			{
				break;
			}
		}

	}
	return counter;
}


int main()
{
	int n;
	cin >> n;
	int* mas = new int[n];
	enter(mas, n);
	int m;
	cin >> m;
	int* arr = new int[m];
	enter(arr, m);
	int k;
	cin >> k;
	cout << sum_index(mas, n, arr, m, k);
	delete[]arr;
	delete[]mas;
	return 0;
}