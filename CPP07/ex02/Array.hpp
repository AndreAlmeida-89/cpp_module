#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
public:
	// Constructors
	Array()
	{
		_size = 0;
		_array = new T[_size];
		std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
	}

	Array(unsigned int size)
	{
		_size = size;
		_array = new T[size];
		std::cout << "\e[0;33mFields Constructor called of Array\e[0m" << std::endl;
	}

	Array(const Array &copy)
	{
		_array = new T[copy.size()];
		_size = copy.size();
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy[i];
		std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
	}

	// Destructor
	~Array()
	{
		delete[] _array;
		std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
	}

	// Operators
	Array &operator=(const Array &assign)
	{
		if (this != assign)
		{
			delete[] _array;
			_array = new T[assign.size()];
			_size = assign.size();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = assign[i];
		}
		return (*this);
	}

	T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw IndexOutOfBounds();
		return (_array[index]);
	}

	// Getters / Setters
	unsigned int size() const
	{
		return _size;
	}

	// Exceptions
	class IndexOutOfBounds : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "[!] Error: Index out of bound!";
		}
	};

private:
	unsigned int _size;
	T *_array;
};

// Stream operators
template <typename T>
std::ostream &operator<<(std::ostream &stream, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
	{
		stream << array[i];
		if (i != array.size() - 1)
			stream << " ";
	}
	return stream;
}

#endif