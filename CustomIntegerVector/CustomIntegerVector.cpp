#include "CustomIntegerVector.h"

//Use assert
CustomIntegerVector::CustomIntegerVector(unsigned int l_capacity):
	m_capacity(l_capacity), m_size(0)
{
	m_array = new int[l_capacity];
	memset(m_array, 0, sizeof(int) * m_capacity);
}

CustomIntegerVector::CustomIntegerVector(const CustomIntegerVector& l_copy):
	CustomIntegerVector(l_copy.m_size)
{
	this->m_size = l_copy.m_size;

	memcpy(m_array, l_copy.m_array, l_copy.m_size * sizeof(int));
	/**
	for (unsigned int index = 0; index < l_copy.m_size; index++)
	{
		m_array[index] = l_copy[index];
	}
	**/
}

CustomIntegerVector::CustomIntegerVector(std::initializer_list<int> l_init_list):
	CustomIntegerVector(static_cast<unsigned int>(l_init_list.size()))
{
	this->m_size = static_cast<unsigned int>(l_init_list.size());

	unsigned int index = 0;
	for (const auto& element : l_init_list)
	{
		this->m_array[index] = element;
		index++;
	}
}

CustomIntegerVector::~CustomIntegerVector()
{
	delete[] m_array;
}

//Use assert
int CustomIntegerVector::Front()
{
	if (m_size < 1)
	{
		throw std::exception("Access to the front element of an empty vector exception.");
	}

	return m_array[0];
}

//Use assert
int CustomIntegerVector::Back()
{
	if (m_size < 1)
	{
		throw std::exception("Access to the back element of an empty vector exception.");
	}

	return m_array[m_size - 1];
}

//Inderect usage of Insert()
void CustomIntegerVector::PushBack(const int value)
{
	Insert(m_size, value);
}

//Inderect usage of Erase()
void CustomIntegerVector::PopBack()
{
	Erase(m_size - 1);
}

//Inderect usage of Insert()
void CustomIntegerVector::PushFront(const int value)
{
	Insert(0, value);
}

//Inderect usage of Erase()
void CustomIntegerVector::PopFront()
{
	Erase(0);
}

//Critical section function
//Use assert
void CustomIntegerVector::Insert(const unsigned int insert_index, const int value)
{
	if (insert_index > m_size)
	{
		throw std::exception("Out of bounds insertion index exception.");
	}
	//assert(insert_index >= 0);

	IncreaseCapacity();

	m_mutex.lock();

	for (unsigned int index = m_size; index > insert_index; index--)
	{
		m_array[index] = m_array[index - 1];
	}

	m_array[insert_index] = value;
	m_size++;

	m_mutex.unlock();
}

//Critical section function
//Use assert
void CustomIntegerVector::Erase(const unsigned int insert_index)
{
	//assert(m_size >= 1);
	if (m_size < 1)
	{
		throw std::exception("Erasing of an empty vector exception.");
	}

	if (insert_index >= m_size)
	{
		throw std::exception("Out of bounds erasing index exception.");
	}
	//assert(insert_index >= 0);

	m_mutex.lock();

	--m_size;
	for (unsigned int index = insert_index; index < m_size; ++index)
	{
		m_array[index] = m_array[index + 1];
	}

	m_mutex.unlock();

	Shrink();
}

//Critical section function
void CustomIntegerVector::Clear()
{
	m_mutex.lock();

	delete[] m_array;

	m_capacity = 1;
	m_size = 0;

	m_array = new int[m_capacity] { 0 };

	m_mutex.unlock();
}

//Use assert
int CustomIntegerVector::operator[](const unsigned int index) const
{	

	if (index >= m_size)
	{
		throw std::exception("Out of bounds access index exception.");
	}
	//assert(index >= 0);

	return m_array[index];
}

void CustomIntegerVector::operator=(const CustomIntegerVector& l_copy)
{
	this->Clear();
	delete[] m_array;

	this->m_capacity = l_copy.m_size;
	this->m_size = l_copy.m_size;

	m_array = new int[m_capacity];
	memcpy(m_array, l_copy.m_array, sizeof(int) * l_copy.m_size);
}

unsigned int CustomIntegerVector::GetSize()
{
	return m_size;
}

unsigned int CustomIntegerVector::GetCapacity()
{
	return m_capacity;
}

//Critical section function
void CustomIntegerVector::IncreaseCapacity()
{
	if (m_size >= m_capacity)
	{
		m_mutex.lock();

		m_capacity *= 2;

		auto tmp_array = new int[m_capacity]{ 0 };

		//std::memset(tmp_array, 0, sizeof(int) * m_capacity);
		std::memcpy(tmp_array, m_array, sizeof(int) * m_size);

		delete[] m_array;
		m_array = tmp_array;

		m_mutex.unlock();
	}
}

//Critical section function
void CustomIntegerVector::Shrink(int padding)
{
	if (m_capacity > (m_size * 2 + padding))
	{
		m_mutex.lock();

		m_capacity = (m_size + padding);

		int* tmp_array = new int[m_capacity]{ 0 };
		std::memcpy(tmp_array, m_array, sizeof(int) * m_size);

		delete[] m_array;
		m_array = tmp_array;

		m_mutex.unlock();
	}
}

bool operator==(const CustomIntegerVector& l_left_operand, const CustomIntegerVector& l_right_operand)
{
	/**
	if (l_left_operand.m_size != l_right_operand.m_size)
	{
		return false;
	}

	for (unsigned int index = 0; index < l_left_operand.m_size; index++)
	{
		if (l_left_operand.m_array[index] != l_right_operand.m_array[index])
		{
			return false;
		}
	}


	return true;
	**/
	return memcmp(l_left_operand.m_array, l_right_operand.m_array, l_left_operand.m_size * sizeof(int)) == 0 ? true : false ;
}
