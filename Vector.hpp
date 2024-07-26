#pragma once

#include <iostream>
#include <exception>


template<typename T>
class Vector
{
public:
	
	Vector() : _dynamic_vector(nullptr), _size(0), _capacity(0)
	{
		resize(INITALIZE_SIZE);
	}
	
	~Vector()
	{
		delete[] _dynamic_vector;
	}

	/*@brief Adds an element to the end of the vector.
	*
	 **/
	void pushBack(const T& value)

	{
		if (_size >= _capacity)
		{
			resize(calculateResizeSize());

		}
		_dynamic_vector[_size] = value;
		_size++;
	}

	
	/*@return returns the element in index i
	@throw  std::out_of_range if the index is out of range*/
	T& at(size_t i) const
	{
		if (i < 0 || i >= _size)
		{
			throw std::out_of_range("Index is out range");
		}
		return _dynamic_vector[i];
	}

	/*@return returns the element in index i
	No bounds checking is performed in [] */
	T& operator[](size_t i) const
	{
		return _dynamic_vector[i];
	}


	/**
	 * @brief Overloads the equality operator to compare two vectors.
	 *
	 * @param other- The vector to compare with this vector.
	 * @return True if the vectors are equal, false otherwise.
	 */
	bool operator==(const Vector& other) const
	{
		if (_size != other._size)
		{
			return false;
		}
		for (size_t i = 0; i < _size; ++i) {
			if (_dynamic_vector[i] != other._dynamic_vector[i]) {
				return false;
			}
		}
		return true;

	}
	/**
* @brief Overload of the << operator to print the contents of a Vector.
* @param os The output stream to which the contents are printed.
* @param vec The Vector whose contents are to be printed.
* @return std::ostream& A reference to the output stream.
*/
	friend std::ostream& operator<<(std::ostream& os, const Vector& vec) 
	{
		os << "[";
		for (size_t i = 0; i < vec._size; ++i)
		{
			os << vec._dynamic_vector[i];
			if (i != vec._size - 1) {
				os << ", ";
			}
		}
		os << "]";
		return os;
	}

	/*@return returns the first element in the Vector */
	T& front() const
	{
		if (_size > 0)
		{
			return _dynamic_vector[0];
		}
	}

	/*@return returns the last element in the Vector */
	T& back() const
	{
		if (_size > 0)
		{
			return _dynamic_vector[_size - 1];
		}

	}

	/*@brief check if the Vector is empty
	@return retrun true if the Vecor is empty, otherwise return false*/
	bool empty() const
	{
		return _size == 0;
	}

	void clear()
	{

		delete[] _dynamic_vector;
		_dynamic_vector = nullptr;
		_size = 0;
		_capacity = 0;
	}
	/*
	@brief Inserts an element at the specified index in the vector.
	@param index -The position where the element should be inserted. Must be between 0 and the current size (inclusive).
 *	@param value -A constant reference to the element of type T to be inserted at the specified index.
 *	@throw std::out_of_range if the index is out of range.*/

	void insert(size_t index, const T& value)
	{
		if (index < 0 || index > _size)
		{
			throw std::out_of_range("Index out of range");
		}
		int curr_space = _capacity - _size;
		if (curr_space == 0)
		{
			resize(calculateResizeSize());
		}
		for (int i = _size; i > index; i--)
		{
			_dynamic_vector[i] = _dynamic_vector[i - 1];
		}
		_dynamic_vector[index] = value;
		_size++;

	}

	/**
	 * @brief Gets the current size of the vector.
	 *
	 * @return The current number of elements in the vector.
	 */
	size_t size() const
	{
		return _size;
	}

	/**
	 * @return The current capacity in the vector.
	 */
	size_t capacity() const
	{
		return _capacity;
	}

	/*@brief reverse the Vector by place*/
	void reverse() const
	{
		T value;
		for (int i = 0; i < _size / 2; i--)
		{
			value = _dynamic_vector[i];
			_dynamic_vector[i] = _dynamic_vector[_size - i - 1];
			_dynamic_vector[_size - i - 1] = value;
		}
		
	}

	/**
	 * @brief Removes the last element of the vector.
	 *
	 * Reduces the size of the vector by one. If the vector is empty, it throws an exception.
	 *
	 * @throw std::out_of_range if the vector is empty.
	 */
	void popBack()
	{
		if (_size == 0)
		{
			throw std::out_of_range("Vector is empty");
		}
		_size--;
	}



private:
	T* _dynamic_vector;
	size_t _capacity;
	size_t _size;
	static constexpr int INITALIZE_SIZE = 2;

	
	///@brief calculate the new capacity  
	/// @returns The new capacity, which is the current capacity increased by 50%
	size_t calculateResizeSize() const {
		return _capacity + _capacity / 2;
	}
	/// @brief resize the Vector capacity
	/// @param newCapacity- A reference to the newCapactiy size for the dynamic vector
	void resize(const size_t &newCapacity)
	{
		T* newVector = new T[newCapacity];
		for (size_t i = 0; i < _size; i++)
		{
			newVector[i] = std::move(_dynamic_vector[i]);
		}
		delete[] _dynamic_vector;

		_dynamic_vector = newVector;
		_capacity = newCapacity;
	}
};
