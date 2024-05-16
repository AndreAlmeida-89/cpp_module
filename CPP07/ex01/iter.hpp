#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t size, void (*func)(T &))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template <class T>
void printContent(T content)
{
	std::cout << "[" << content << "]";
}

template <class T>
void doubleValue(T content)
{
	content += content;
}

#endif