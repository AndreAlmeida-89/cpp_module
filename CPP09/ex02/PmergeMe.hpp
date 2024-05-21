#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

template <typename Container>
class PmergeMe
{
public:
	PmergeMe(const std::string typeName) : _time(0.0), _typeName(typeName) {}

	~PmergeMe() {}

	void sort(const int argc, const char **argv)
	{
		if (argc < 2)
			throw PmergeMeError();
		std::clock_t start = std::clock();
		_getIntegerSequence(argv);
		_result = _unsorted;
		_mergeInsertionSort(_result);
		std::clock_t end = std::clock();
		_time = static_cast<double>(end - start);
	}

	class PmergeMeError : public std::exception
	{
		const char *what() const throw()
		{
			return "Error";
		}
	};

	void printInfo()
	{
		std::cout << "Before: ";
		for (unsigned int i = 0; i < _unsorted.size(); i++)
			std::cout << _unsorted.at(i) << " ";
		std::cout << std::endl;
		std::cout << "After: ";
		for (unsigned int i = 0; i < _result.size(); i++)
			std::cout << _result.at(i) << " ";
		std::cout << std::endl;
	}

	void printTime()
	{
		if (_result.size() != _unsorted.size() || !std::is_sorted(_result.begin(), _result.end()))
			throw PmergeMeError();
		std::cout << "Time to process a range of "
				  << _unsorted.size()
				  << " elements with "
				  << _typeName << ":\t"
				  << _time
				  << " us"
				  << std::endl;
	}

private:
	Container _unsorted;
	Container _result;
	double _time;
	std::string _typeName;

	PmergeMe() : _time(0.0),
				 _result(Container()),
				 _unsorted(Container()),
				 _typeName("") {}

	PmergeMe(const PmergeMe &copy) : _time(copy.getTime()),
									 _result(copy.getResult()),
									 _unsorted(copy.getUnsorted()),
									 _typeName(copy.getTypeName()) {}

	// Operators
	PmergeMe &operator=(const PmergeMe &assign)
	{
		if (*this != assign)
		{
			_time = assign.getTime();
			_result = assign.getResult();
			_unsorted = assign.getUnsorted();
			_typeName = assign.getTypeName();
		}
		return *this;
	}

	// Getters
	Container getUnsorted() const
	{
		return _unsorted;
	}

	Container getResult() const
	{
		return _result;
	}

	double getTime() const
	{
		return _time;
	}

	std::string getTypeName() const
	{
		return _typeName;
	}

	void _getIntegerSequence(const char **argv)
	{
		int val;
		for (size_t i = 1; argv[i]; i++)
		{
			if (argv[i][0] == '\0')
				throw(PmergeMeError());
			val = atoi(argv[i]);
			if (val < 0)
				throw(PmergeMeError());
			_unsorted.push_back(val);
		}
	}

	void _insertionSort(Container &container, int left, int right)
	{
		for (int i = left + 1; i <= right; i++)
		{
			int key = container[i];
			int j = i - 1;
			while (j >= left && container[j] > key)
			{
				container[j + 1] = container[j];
				j = j - 1;
			}
			container[j + 1] = key;
		}
	}

	void _merge(Container &container,
				size_t left,
				size_t mid,
				size_t right)
	{
		size_t n1 = mid - left + 1;
		size_t n2 = right - mid;
		Container leftContainer(n1);
		Container rightContainer(n2);

		for (size_t i = 0; i < n1; ++i)
			leftContainer[i] = container[left + i];
		for (size_t j = 0; j < n2; ++j)
			rightContainer[j] = container[mid + 1 + j];

		size_t i = 0;
		size_t j = 0;
		size_t k = left;
		for (; i < n1 && j < n2; ++k)
		{
			if (leftContainer[i] <= rightContainer[j])
				container[k] = leftContainer[i++];
			else
				container[k] = rightContainer[j++];
		}
		for (; i < n1; ++i, ++k)
			container[k] = leftContainer[i];
		for (; j < n2; ++j, ++k)
			container[k] = rightContainer[j];
	}

	void _mergeSort(Container &container,
					size_t left,
					size_t right)
	{
		const int threshold = 32;
		if (left < right)
		{
			if (right - left <= threshold)
				_insertionSort(container, left, right);
			else
			{
				size_t mid = left + (right - left) / 2;
				_mergeSort(container, left, mid);
				_mergeSort(container, mid + 1, right);
				_merge(container, left, mid, right);
			}
		}
	}

	void _mergeInsertionSort(Container &arr)
	{
		_mergeSort(arr, 0, arr.size() - 1);
	}
};

#endif