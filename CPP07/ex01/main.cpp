#include "iter.hpp"

int main(void)
{
	{
		typedef int type;
		type arr[] = {1, 2, 3, 4, 5};
		size_t size = sizeof(arr)/sizeof(type);
		iter(arr, size, printContent);
		iter(arr, size, doubleValue);
		std::cout << std::endl;
		iter(arr, size, printContent);
		std::cout << std::endl << std::endl;
	}

	{
		typedef double type;
		type arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
		size_t size = sizeof(arr)/sizeof(type);
		iter(arr, size, printContent);
		iter(arr, size, doubleValue);
		std::cout << std::endl;
		iter(arr, size, printContent);
		std::cout << std::endl << std::endl;
	}

	{
		typedef float type;
		type arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
		size_t size = sizeof(arr)/sizeof(type);
		iter(arr, size, printContent);
		iter(arr, size, doubleValue);
		std::cout << std::endl;
		iter(arr, size, printContent);
		std::cout << std::endl << std::endl;
	}

	{
		typedef std::string type;
		type arr[] = {"1", "2", "3", "4", "5"};
		size_t size = sizeof(arr)/sizeof(type);
		iter(arr, size, printContent);
		iter(arr, size, doubleValue);
		std::cout << std::endl;
		iter(arr, size, printContent);
		std::cout << std::endl << std::endl;
	}
	return (0);
}