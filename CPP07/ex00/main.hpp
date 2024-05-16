#ifndef MAIN_HPP
#define MAIN_HPP

template <class T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

template <class T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <class T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

#endif