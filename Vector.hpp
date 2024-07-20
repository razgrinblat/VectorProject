#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <iostream>


template<typename T>
class Vector
{
public:
	/**
	 * @brief Default constructor.
	 *
	 * Constructs an empty Vector with an initial capacity of 2.
	 */
	Vector()
	{
		Realloc(2);
	}
	/**
	 * @brief Destructor.
	 *
	 * Frees the dynamically allocated memory.
	 */
	~Vector()
	{

		delete(_dynamicVector);
	}

	/*@brief Adds an element to the end of the vector.
	*
     **/
	void pushBack(const T& value)
		
	{
		if (_size >= _capacity)
		{
			Realloc(_capacity + _capacity / 2);

		}
		_dynamicVector[_size] = value;
		_size++;
	}

	/*display the Vector*/
	void display() const
	{
		for (size_t i = 0; i < _size; ++i) {
			std::cout << _dynamicVector[i] << " ";
		}
		std::cout << std::endl;
	}

	/*@return returns the element in index i
	@throw  std::out_of_range if the index is out of range*/
	T& at(int i) const
	{
		if (i < 0 || i >= _size)
		{
			throw std::out_of_range("Index is out range");
		}
		return _dynamicVector[i];
	}

	/*@return returns the element in index i*/
	T& operator[](int i)
	{

		return _dynamicVector[i];
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
			if (_dynamicVector[i] != other._dynamicVector[i]) {
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
			os << vec._dynamicVector[i];
			if (i != vec._size - 1) {
				os << ", ";
			}
		}
		os << "]";
		return os;
	 }

	/*@return returns the first element in the Vector */
	T& front()
	{
		if (_size > 0)
		{
			return _dynamicVector[0];
		}
	}

	/*@return returns the last element in the Vector */
	T& back()
	{
		if (_size > 0)
		{
			return _dynamicVector[_size - 1];
		}

	}

	/*@brief check if the Vector is empty
	@return retrun true if the Vecor is empty, otherwise return false*/
	bool empty()
	{
		return _size == 0;
	}

	void clear()
	{

		delete(_dynamicVector);
		_dynamicVector = nullptr;
		_size = 0;
		_capacity = 0;
	}
	/*
	@brief Inserts an element at the specified index in the vector.
	@param index The position where the element should be inserted. Must be between 0 and the current size (inclusive).
 *	@param value A constant reference to the element of type T to be inserted at the specified index.
 *	@throw std::out_of_range if the index is out of range.*/

	void insert(int index, const T& value) 
	{
		if (index < 0 || index > _size)
		{
			throw std::out_of_range("Index out of range");
		}
		int curr_space = _capacity - _size;
		if (curr_space == 0)
		{
			Realloc(_capacity + _capacity / 2);
		}
		for (int i = _size; i > index; i--)
		{
			_dynamicVector[i] = _dynamicVector[i - 1];
		}
		_dynamicVector[index] = value;
		_size++;

	}

	/**
	 * @brief Gets the current size of the vector.
	 *
	 * @return The current number of elements in the vector.
	 */
	size_t Size() const
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
			value = _dynamicVector[i];
			_dynamicVector[i] = _dynamicVector[_size - i - 1];
			_dynamicVector[_size - i - 1] = value;
		}

	}

	/**
	 * @brief Removes the last element of the vector.
	 *
	 * Reduces the size of the vector by one. If the vector is empty, it throws an exception.
	 *
	 * @throw std::out_of_range if the vector is empty.
	 */
	void pop_back()
	{
		if (_size == 0)
		{
			throw std::out_of_range("Vector is empty");
		}
		_size--;
	}



private:
	T* _dynamicVector = nullptr;
	size_t _capacity = 0;
	size_t _size = 0;

	void Realloc(size_t newCapacity)
	{
	
		T* newVector = new T[newCapacity];
		for (size_t i = 0; i < _size; i++)
		{
			newVector[i] = std::move(_dynamicVector[i]);
		}
		delete[] _dynamicVector;

		_dynamicVector = newVector;
		_capacity = newCapacity;
	}


};

#endif