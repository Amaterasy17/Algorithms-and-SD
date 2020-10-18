#pragma once
class heap
{
public:
	void Add();
	void SiftUp();
	void SiftDown();
	int MaxElem();
private:
	int* heapy;
	int size;
};

