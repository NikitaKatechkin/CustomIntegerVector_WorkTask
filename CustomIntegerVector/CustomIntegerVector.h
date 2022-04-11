#pragma once

#include <cstdlib>
#include <iostream>
#include <cassert>

#include <mutex>
#include <thread>

#include <initializer_list>

class CustomIntegerVector final
{
public:
	CustomIntegerVector(unsigned int l_capacity = 1);

	CustomIntegerVector(const CustomIntegerVector& l_copy);
	CustomIntegerVector(std::initializer_list<int> l_init_list);

	~CustomIntegerVector();

	int Front();
	int Back();

	void PushBack(const int value);
	void PopBack();

	void PushFront(const int value);
	void PopFront();

	void Insert(const unsigned int insert_index, const int value);
	void Erase(const unsigned int insert_index);
	void Clear();

	int operator[] (const unsigned int index) const;
	friend bool operator== (const CustomIntegerVector& l_left_operand,
							const CustomIntegerVector& l_right_operand);
	
	void operator= (const CustomIntegerVector& l_copy);

	unsigned int GetSize();
	unsigned int GetCapacity();
private:
	void IncreaseCapacity();
	void Shrink(int padding = 2);

	unsigned int m_size = 0;
	unsigned int m_capacity = 1;

	int* m_array = nullptr;
	
	std::mutex m_mutex;
};