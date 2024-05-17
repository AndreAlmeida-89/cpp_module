#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<int> Vector;
typedef Vector::const_iterator ConstIreator;

class Span
{
public:
	// Constructors
	Span();
	Span(const Span &copy);
	Span(const unsigned int n);

	// Destructor
	~Span();

	// Operators
	Span &operator=(const Span &assign);

	// Member functions
	void addNumber(int n);
	// void addNumbers(Iterator begin, Iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	// Getters / Setters
	unsigned int getN() const;
	const Vector &getVector() const;

	// Exceptions
	class SpanIsFull : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NoNumbersStored : public std::exception
	{
		virtual const char *what() const throw();
	};

	class OnlyOneNumberStored : public std::exception
	{
		virtual const char *what() const throw();
	};

	template <typename T>
	void addNumber(T begin, T end)
	{
		size_t size = std::distance(begin, end);
		if ((size + _vector.size()) > _n)
			throw SpanIsFull();
		_vector.insert(_vector.end(), begin, end);
	}

private:
	unsigned int _n;
	Vector _vector;
	void _checkForErrors() const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Span &object);

#endif