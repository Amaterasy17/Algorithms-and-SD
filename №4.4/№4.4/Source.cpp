//#include <iostream>
//#include <utility>
//#include <functional>
//using namespace std;
//
//int* logik(int*, int, int);
//void test();
//
//struct elem_heap
//{
//	int value;
//	int index;
//	elem_heap(int val, int i) : value(val), index(i) {
//	}
//	elem_heap() : value(0), index(0)
//	{
//
//	}
//	~elem_heap()
//	{
//	}
//	elem_heap& rightelem_heap(const elem_heap& right)
//	{
//		this->index = right.index;
//		this->value = right.value;
//		return *this;
//	}
//};
//
////bool cmp_elem_heap(const elem_heap& l, const elem_heap& r)
////{
////	return l > r;
////}
//bool operator > (const elem_heap& left, const elem_heap& right)
//{
//	bool a;
//	(left.value > right.value) ? a = true : a = false;
//	return a;
//}
//template <typename T>
//class DefaultComparator
//{
//public:
//	bool operator()(const T& l, const T& r)
//	{
//		return l > r;
//	}
//};
//
//
//
//template <typename T, typename Comparator = std::greater<T>>
//class Heap
//{
//public:
//	Heap(T* arr, int n) : real_size(n), size(2 * n)
//	{
//		mas = new T[size];
//		for (int i = 0; i < real_size; ++i)
//		{
//			this->mas[i] = arr[i];
//		}
//		this->build_heap();
//	}
//	Heap()
//	{
//		size = 5;
//		real_size = 0;
//		mas = new T[size];
//	}
//	~Heap()
//	{
//		delete[]mas;
//		size = 0;
//		real_size = 0;
//	}
//	T& ExtractMax()
//	{
//		swap(mas[real_size - 1], mas[0]);
//		--real_size;
//		siftDown(0,Comparator());
//		return mas[real_size];
//	}
//	T& PeekMax()
//	{
//		return mas[0];
//	}
//	void Add(const T& elem)
//	{
//		++real_size;
//		if (real_size == size) {
//			this->grow();
//		}
//		mas[real_size - 1] = elem;
//		siftUp(real_size - 1, Comparator());
//	}
//private:
//	T* mas;
//	int size;
//	int real_size;
//	void grow()
//	{
//		size *= 2;
//		T* next = new T[size];
//		for (int i = 0; i < real_size - 1; ++i)
//		{
//			next[i] = this->mas[i];
//		}
//		delete[]mas;
//		mas = std::move(next);
//	}
//	void swap(T& a, T& b)
//	{
//		T tmp;
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	void build_heap() {
//		for (int i = real_size / 2 - 1; i >= 0; --i)
//		{
//			siftDown(i, Comparator());
//		}
//	}
//	void siftDown(int i, Comparator cmp = Comparator())
//	{
//		int left = 2 * i + 1;
//		int right = 2 * i + 2;
//		int largest = i;
//		if (left < real_size && cmp(mas[left], mas[largest])) //mas[left] > mas[largest]
//		{
//			largest = left;
//		}
//		if (right < real_size && cmp(mas[right], mas[largest]))//mas[right] > mas[largest]
//		{
//			largest = right;
//		}
//		if (largest != i)
//		{
//			swap(mas[largest], mas[i]);
//			siftDown(largest, Comparator());
//		}
//	}
//	void siftUp(int i, Comparator cmp = Comparator())
//	{
//		while (i > 0)
//		{
//			int parent = (i - 1) / 2;
//			if (!cmp( mas[i], mas[parent]))//mas[parent] >= mas[i]
//				return;
//			swap(mas[parent], mas[i]);
//			i = parent;
//		}
//	}
//};
//
//int main() {
//	int n;
//	cin >> n;
//	int* Mas = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> Mas[i];
//	}
//	int window;
//	cin >> window;
//	if (window <= 0)
//	{
//		cout << "error";
//			return -1;
//	}
//	Heap <elem_heap, DefaultComparator<elem_heap>> wind;
//	for (int i = 0; i < window; ++i)
//	{
//		elem_heap a(Mas[i], i);
//		wind.Add(a);
//	}
//	int left = 0;
//	int right = window - 1;
//	for (int i = 0; right < n ; ++i)
//	{
//		while (!(wind.PeekMax().index >= left && wind.PeekMax().index <= right))
//		{
//			wind.ExtractMax();
//		}
//		cout << wind.PeekMax().value << ' ';
//		++left;
//		++right;
//		if (right != n) {
//			elem_heap a(Mas[right], right);
//			wind.Add(a);
//		}
//	}
//
//	//test();
//	return 1;
//}
//void test()
//{
//	int n[] = { 10, 15, 7, 5 };
//	int Mas[] = {13, 6, 10, 15, 10, 7, 19, 5, 4, 3, 2};
//	int window = 4;
//	int* max = logik(Mas, window, 11);
//	int result[] = { 15, 15, 15, 19, 19, 19, 19, 5 };
//	for (int i = 0; i < 8; ++i)
//	{
//		if (max[i] != result[i])
//		{
//			cout << "error" << endl;
//		}
//		else
//			cout << "success";
//	}
//	int Mas2[] = { 13, -2, 1, 5, -10, 7, 9, -2, -4, -3, 24 };
//	window = 3;
//	max = logik(Mas2, window, 11);
//	int result2[] = { 13, 5, 5, 7, 9, 9, 9, -2, 24};
//	for (int i = 0; i < 9; ++i)
//	{
//		if (max[i] != result2[i])
//		{
//			cout << "error" << endl;
//		}
//		else
//			cout << "success";
//	}
//	int Mas3[] = { 10, 10, 10, 5, -10, 8, 10, 10, -10, -15, -20, 10, 28};
//	window = 5;
//	max = logik(Mas3, window, 13);
//	int result3[] = { 10, 10, 10, 10, 10, 10, 10, 10, 28 };
//	for (int i = 0; i < 9; ++i)
//	{
//		if (max[i] != result3[i])
//		{
//			cout << "error" << endl;
//		}
//		else
//			cout << "success";
//	}
//
//}
//int* logik(int* Mas, int window, int n)
//{
//	int* max = new int[n - window + 1];
//	Heap <elem_heap> wind;
//	for (int i = 0; i < window; ++i)
//	{
//		elem_heap a(Mas[i], i);
//		wind.Add(a);
//	}
//	int left = 0;
//	int right = window - 1;
//	cout << endl;
//	for (int i = 0; right < n; ++i)
//	{
//		while (!(wind.PeekMax().index >= left && wind.PeekMax().index <= right))
//		{
//			cout << "index  "<<wind.PeekMax().index<<"   value   "<< wind.PeekMax().value << endl;
//			wind.ExtractMax();
//		}
//		max[i] = wind.PeekMax().value;
//		cout << max[i] << ' ';
//		++left;
//		++right;
//	
//		if (right != n) {
//			elem_heap a(Mas[right], right);
//			wind.Add(a);
//		}
//	}
//	return max;
//}