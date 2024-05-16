#include "Span.hpp"

// Constructors
Span::Span() : _n(0)
{
	_vector = std::vector<int>(0);
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy) : _n(copy.getN()), _vector(copy.getVector())
{
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const unsigned int n) : _n(n)
{
	_vector = std::vector<int>();
	std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}

// Operators
Span &Span::operator=(const Span &assign)
{
	_n = assign.getN();
	_vector = assign.getVector();
	return *this;
}

// Getters / Setters
unsigned int Span::getN() const
{
	return _n;
}

Vector Span::getVector() const
{
	return _vector;
}

// Member functions
void Span::addNumber(int number)
{
	if (_vector.size() >= _n)
		throw SpanIsFull();
	_vector.push_back(number);
}


unsigned int Span::shortestSpan() const
{
	_checkForErrors();
	int min = longestSpan();
	size_t size = _vector.size();
	size_t i = 0;
	while (i < size - 1)
	{
		size_t j = i + 1;
		while (j < size)
		{
			int distance = std::abs(_vector[i] - _vector[j]);
			if (distance < min)
				min = distance;
			j++;
		}
		i++;
	}
	return static_cast<unsigned int>(min);
}

unsigned int Span::longestSpan() const
{
	_checkForErrors();
	ConstIreator min = std::min_element(_vector.begin(), _vector.end());
	ConstIreator max = std::max_element(_vector.begin(), _vector.end());
	return static_cast<unsigned int>(std::abs(*max - *min));
}

void Span::_checkForErrors() const
{
	if (_vector.empty())
		throw NoNumbersStored();
	if (_vector.size() == 1)
		throw OnlyOneNumberStored();
}

// Exceptions
const char *Span::SpanIsFull::what() const throw()
{
	return "[!] Span is full.";
}
const char *Span::NoNumbersStored::what() const throw()
{
	return "[!] No numbers stored.";
}
const char *Span::OnlyOneNumberStored::what() const throw()
{
	return "[!] Only one number stored.";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Span &span)
{
	std::vector<int> vector = span.getVector();

	for (unsigned int i = 0; i < vector.size(); i++)
	{
		stream << vector[i];
		if (i != vector.size() - 1)
			stream << " ";
	}
	return stream;
}
