//#include <iostream>
//#include <math.h>
//using namespace std;
//void range(int*, int, int,int&, int&);
//int binarry_finding(int*, int, int, int);
//void create_mas(int*, int);
//void print_result(int*, int);
//void next_element(int*, int*, int, int, int*);
//void test_next_element();
//bool compare(int*,int,int*,int);
//int main()
//{
//	int* A = NULL;
//	int* B = NULL;
//	int n, m;
//	cin >> n;
//	cin >> m;
//	A = new int[n];
//	B = new int[m];
//	create_mas(A, n);
//	create_mas(B, m);
//	int* result = new int[m];
//	next_element(A, B, n, m, result);
//	print_result(result, m);
//	//test_next_element();
//	delete[]result;
//	delete[]A;
//	delete[]B;
//	return 0;
//}
//void print_result(int* result, int size)
//{
//	for (int i = 0; i < size - 1; ++i)
//	{
//		cout << result[i] << " ";
//	}
//	cout << result[size - 1] << endl;
//}
//void range(int* mas, int size, int elem, int& first, int& last)
//{
//	if (!mas)
//	{
//		return;
//	}
//	first = 0;
//	last = 1;
//	if (elem < mas[0])
//		return;
//	while (1)
//	{
//		if (elem >= mas[first] && elem <= mas[last])
//		{
//			return;
//		}
//		else
//		{
//			first = last;
//			last *= 2;
//		}
//		if (last >= size)
//		{
//			last = size - 1;
//		}
//		if (first == last)
//		{
//			return;
//		}
//	}
//}
//int binarry_finding(int* mas, int first, int last, int elem)
//{
//	int mid = 0;
//	while (first < last)
//	{
//		mid = (first + last) / 2;
//		if (mas[mid] >= elem)
//		{
//			last = mid;
//		}
//		else
//		{
//			first = mid + 1;
//		}
//	}
//	return last;
//}
//void create_mas(int* mas, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		cin >> mas[i];
//	}
//}
//void next_element(int* A, int* B, int n, int m, int* result)
//{
//	int first = 0;
//	int last = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		range(A, n, B[i], first, last);
//		if (first == last)
//		{
//			result[i] = n;
//		}
//		else
//		{
//			result[i] = binarry_finding(A, first, last, B[i]);
//		}
//	}
//}
//void test_next_element()
//{
//	int A[] = { 2, 2, 3, 4, 4 };
//	int B[] = { 2, 4 };
//	int result1[] = { 0, 3 };
//	int* result = new int[2];
//	next_element(A, B, 5, 2, result);
//	compare(result, 2, result1, 2) ? cout << "test is good"<< endl : cout << "test is wrong";
//	delete[]result;
//	int C[] = { -7, -6, -4, -3, 10 };
//	int D[] = { -6, -2, 100 };
//	int result2[] = { 1, 4, 5 };
//	result = new int[3];
//	next_element(C, D, 5, 3, result);
//	compare(result, 3, result2, 3) ? cout << "test is good"<<endl : cout << "test is wrong";
//	delete[]result;
//	int E[] = { -7, -3, 20, 26, 35 };
//	int F[] = { -1, 27, 45 };
//	int result3[] = { 2, 4, 5 };
//	result = new int[3];
//	next_element(E, F, 5, 3, result);
//	compare(result, 3, result3, 3) ? cout << "test is good" << endl : cout << "test is wrong";
//	delete[]result;
//	int Y[] = { 9, 82, 102, 203, 405, 608, 1000 };
//	int X[] = { -2000, 400 };
//	int result4[] = { 0, 4 };
//	result = new int[2];
//	next_element(Y, X, 7, 2, result);
//	compare(result, 2, result4, 2) ? cout << "test is good" << endl : cout << "test is wrong";
//	delete[]result;
//}
//bool compare(int* mas, int size, int* arr, int length)
//{
//	if (length != size)
//		return false;
//	for (int i = 0; i < size; ++i)
//	{
//		if (mas[i] != arr[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}