#include "CustomIntegerVector.h"

CustomIntegerVector::CustomIntegerVector(int l_capacity):
	m_capacity(l_capacity), m_size(0)
{
	assert(l_capacity > 0);

	m_array = new int[l_capacity];
	memset(m_array, 0, sizeof(int) * m_capacity);
}

CustomIntegerVector::~CustomIntegerVector()
{
	delete[] m_array;
}

int CustomIntegerVector::Front()
{
	assert(m_size >= 1);

	return m_array[0];
}

int CustomIntegerVector::Back()
{
	assert(m_size >= 1);

	return m_array[m_size - 1];
}

void CustomIntegerVector::PushBack(const int& value)
{
	/**
	IncreaseCapacity();
	
	m_array[m_size] = value;
	m_size++;
	**/

	Insert(m_size, value);
}

void CustomIntegerVector::PopBack()
{
	/**
	assert(m_size >= 1);

	--m_size;
	Shrink();
	**/
	Erase(m_size);
}

void CustomIntegerVector::PushFront(const int& value)
{
	/**
	IncreaseCapacity();
	
	for (int index = m_size; index > 0; index--)
	{
		m_array[index] = m_array[index - 1];
	}
	m_size++;

	m_array[0] = value;
	**/

	Insert(0, value);
}

void CustomIntegerVector::PopFront()
{
	/**
	assert(m_size >= 1);

	--m_size;
	for (int index = 0; index < m_size; ++index)
	{
		m_array[index] = m_array[index + 1];
	}
	Shrink();
	**/
	Erase(0);
}

void CustomIntegerVector::Insert(const int& insert_index, const int& value)
{
	assert(insert_index <= m_size);
	assert(insert_index >= 0);

	IncreaseCapacity();

	for (int index = m_size; index > insert_index; index--)
	{
		m_array[index] = m_array[index - 1];
	}

	m_array[insert_index] = value;
	m_size++;
}

void CustomIntegerVector::Erase(const int& insert_index)
{
	assert(m_size >= 1);

	assert(insert_index <= m_size);
	assert(insert_index >= 0);

	--m_size;
	for (int index = insert_index; index < m_size; ++index)
	{
		m_array[index] = m_array[index + 1];
	}
	Shrink();
}

void CustomIntegerVector::Clear()
{
	/**
	while (m_size > 0)
	{
		PopBack();
	}
	**/
	delete[] m_array;

	m_capacity = 1;
	m_size = 0;

	m_array = new int[m_capacity] { 0 };
}

int& CustomIntegerVector::operator[](const int& index)
{	

	assert(index < m_size);
	assert(index >= 0);

	return m_array[index];
}

const int& CustomIntegerVector::GetSize()
{
	return m_size;
}

const int& CustomIntegerVector::GetCapacity()
{
	return m_capacity;
}

void CustomIntegerVector::IncreaseCapacity()
{
	if (m_size >= m_capacity)
	{

		m_capacity *= 2;

		auto tmp_array = new int[m_capacity]{ 0 };

		//std::memset(tmp_array, 0, sizeof(int) * m_capacity);
		std::memcpy(tmp_array, m_array, sizeof(int) * m_size);

		delete[] m_array;
		m_array = tmp_array;
	}
}

void CustomIntegerVector::Shrink(int padding)
{
	if (m_capacity > (m_size * 2 + padding))
	{
		m_capacity = (m_size + padding);

		int* tmp_array = new int[m_capacity]{ 0 };
		std::memcpy(tmp_array, m_array, sizeof(int) * m_size);

		delete[] m_array;
		m_array = tmp_array;
	}
}
