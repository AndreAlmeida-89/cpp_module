#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class PmergeMe
{
public:
	static void sort(const int argc, const char **argv);

	class PmergeMeError : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	// Constructors
	PmergeMe();
	PmergeMe(const PmergeMe &copy);

	// Destructor
	~PmergeMe();

	// Operators
	PmergeMe &operator=(const PmergeMe &assign);

	typedef std::vector<int> Container;

	static Container _mergeInsertionSort(Container &v);
	static int _binarySearch(const Container &arr, int left, int right, int key);
};

#endif