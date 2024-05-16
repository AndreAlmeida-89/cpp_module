

// Constructors
// template <typename T>
// Array<T>::Array()
// {
// 	_size = 0;
// 	std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
// }

// template <typename T>
// Array::Array(const Array &copy)
// {
// 	_size = copy.size();
// 	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
// }

// Array::Array(unsigned int size)
// {
// 	_size = size;
// 	std::cout << "\e[0;33mFields Constructor called of Array\e[0m" << std::endl;
// }

// // Destructor
// Array::~Array()
// {
// 	std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
// }

// // Operators
// Array &Array::operator=(const Array &assign)
// {
// 	_size = assign.size();
// 	return *this;
// }

// // Getters / Setters
// unsigned int Array::size() const
// {
// 	return _size;
// }

// // Exceptions
// const char *Array::IndexOutOfBounds::what() const throw()
// {
// 	return "[!] Error: index out of bounds!";
// }

// // Stream operators
// std::ostream &operator<<(std::ostream &stream, const Array &object)
// {
// 	stream << "Array[" << object.size() << "]" << std::endl;
// 	return stream;
// }
