#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <cstdlib>
#include <iostream>


template<typename T>
class Vector
{
public:
	Vector()
	{
		Realloc(2);
	}

	~Vector()
	{
		free(DynamicVector);
	}


	void pushBack(const T& value)
	{
		if (size >= Capacity)
		{
			Realloc(Capacity + Capacity / 2);

		}
		DynamicVector[size] = value;
		size++;
	}

	void display() const
	{
		for (size_t i = 0; i < size; ++i) {
			std::cout << DynamicVector[i] << " ";
		}
		std::cout << std::endl;
	}


	T& at(int i) const
	{
		if (i < 0 || i >= size)
		{
			throw std::out_of_range("Index is out range");
		}
		return DynamicVector[i];
	}

	T& operator[](int i)
	{

		return DynamicVector[i];
	}

	T& front()
	{
		if (size > 0)
		{
			return DynamicVector[0];
		}
	}

	T& back()
	{
		if (size > 0)
		{
			return DynamicVector[size - 1];
		}

	}

	bool empty()
	{
		if (size == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void clear()
	{

		free(DynamicVector);
		DynamicVector = nullptr;
		size = 0;
		Capacity = 0;
	}

	void insert(int index, const T& value)
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Index out of range");
		}
		int curr_space = Capacity - size;
		if (curr_space == 0)
		{
			Realloc(Capacity + Capacity / 2);
		}
		for (int i = size; i > index; i--)
		{
			DynamicVector[i] = DynamicVector[i - 1];
		}
		DynamicVector[index] = value;
		size++;

	}

	size_t Size() const
	{
		return size;
	}
	size_t capacity() const
	{
		return Capacity;
	}

	void reverse() const
	{
		T value;
		for (int i = 0; i < size / 2; i--)
		{
			value = DynamicVector[i];
			DynamicVector[i] = DynamicVector[size - i - 1];
			DynamicVector[size - i - 1] = value;
		}

	}

	void pop_back()
	{
		DynamicVector = (T*)realloc(DynamicVector, sizeof(T) * (Capacity - 1));
		size--;
		Capacity--;

	}


private:
	T* DynamicVector = nullptr;
	size_t Capacity = 0;
	size_t size = 0;

	void Realloc(size_t newCapacity)
	{

		DynamicVector = (T*)realloc(DynamicVector, newCapacity * sizeof(T));
		Capacity = newCapacity;

	}


};

#endif