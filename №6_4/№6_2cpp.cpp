//#include <iostream>
//#include <utility>
//#include <ctime>
//#include <functional>
//using namespace std;
//
//template <typename Comparator = std::less<int>>
//int partition(int* mas, int& left, int& right, int size, Comparator cmp = Comparator())
//{
//	srand(std::time(0));
//	int p = rand() % (right - left + 1) + left;
//	swap(mas[p], mas[left]);
//	bool flag_i = false;
//	int i = left; //указывает на начало элементов строго меньших p
//	for (int j = right; j > left; --j)
//	{
//		if (cmp(mas[j], mas[left]) && !flag_i)//mas[j] < mas[left]
//		{
//			i = j;
//			flag_i = true;
//		}
//		if ((!cmp(mas[j], mas[left])) && flag_i) //mas[j] >= mas[left]
//		{
//			swap(mas[j], mas[i]);
//			--i;
//		}
//	}
//	swap(mas[i], mas[left]);
//	return i;
//}
//
//
//void print(int* Mas, int left, int right)
//{
//	for (int i = left; i < right; ++i)
//	{
//		cout << Mas[i] << ' ';
//	}
//	cout << endl;
//}
//
//
//template <typename Comparator = std::less<int>>
//int k_statistik(int* mas, int left, int right, int size, int statistik, Comparator cmp = Comparator())
//{
//	int prevleft = 0;
//	left = 0;
//	right = size - 1;
//	int i = 0;
//	while (left != right)
//	{
//		//print(mas, left, right + 1);
//		i = partition(mas, left, right, size, cmp);
//		//print(mas, left, right + 1);
//		if (i == statistik)
//		{
//			return mas[i];
//		}
//		if (i < statistik)
//		{
//			left = i + 1;
//
//		}
//		if(i > statistik)
//		{
//			right = i - 1;
//		}
//	}
//	return mas[left];
//}
//
//
//
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	int stat;
//	cin >> stat;
//	int* mas = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> mas[i];
//	}
//	int left = 0;
//	int right = n - 1;
//	cout << k_statistik(mas,left,right, n,stat);
//	delete[]mas;
//	return 0;
//}