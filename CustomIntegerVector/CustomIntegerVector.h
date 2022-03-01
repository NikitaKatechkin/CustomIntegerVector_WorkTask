#pragma once

#include <cstdlib>
#include <iostream>
#include <cassert>

#include <mutex>
#include <thread>

class CustomIntegerVector final
{
public:
	//CustomIntegerVector() = default;
	CustomIntegerVector(int l_capacity = 1);
	~CustomIntegerVector();

	int Front();
	int Back();

	void PushBack(const int& value);
	void PopBack();

	void PushFront(const int& value);
	void PopFront();

	void Insert(const int& insert_index, const int& value);
	void Erase(const int& insert_index);
	void Clear();

	int& operator[] (const int& index);

	const int& GetSize();
	const int& GetCapacity();
private:
	void IncreaseCapacity();
	void Shrink(int padding = 2);

	int m_size = 0;
	int m_capacity = 1;

	int* m_array = nullptr;
	
	std::mutex m_mutex;
};