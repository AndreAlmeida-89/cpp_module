#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

template <typename Container>
class PmergeMe
{
public:
	static void sort(const int argc, const char **argv)
	{
		if (argc < 2)
			throw PmergeMeError();
		Container v;
		for (int i = 1; i < argc; i++)
			v.push_back(std::atoi(argv[i]));
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		Container sorted = _mergeInsertionSort(v);
		for (size_t i = 0; i < sorted.size(); i++)
			std::cout << sorted[i] << " ";
		std::cout << std::endl;
	}

	class PmergeMeError : public std::exception
	{
		const char *what() const throw()
		{
			return "Error";
		}
	};

private:
	// Constructors
	PmergeMe()
	{
		std::cout << "\e[0;33mDefault Constructor called of PmergeMe\e[0m" << std::endl;
	}

	PmergeMe(const PmergeMe &copy)
	{
		(void)copy;
		std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
	}

	// Destructor
	~PmergeMe()
	{
		std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
	}

	// Operators
	PmergeMe &operator=(const PmergeMe &assign)
	{
		(void)assign;
		return *this;
	}

	// typedef std::vector<int> Container;

	static Container _mergeInsertionSort(Container &X)
	{
		int n = X.size();
		if (n <= 1)
			return X;

		// Step 1: Group elements into pairs and handle the unpaired element
		Container S; // Sorted sequence
		for (int i = 0; i < n - 1; i += 2)
			S.push_back(std::max(X[i], X[i + 1]));

		if (n % 2 != 0)
			S.push_back(X[n - 1]); // Add the unpaired element

		// Step 2: Recursively sort the larger elements
		S = _mergeInsertionSort(S);

		// Step 3: Insert the paired element at the start
		int pairedElement = X[0];
		int insertPos = _binarySearch(S, 0, S.size() - 1, pairedElement);
		S.insert(S.begin() + insertPos, pairedElement);

		// Step 4: Insert remaining elements using binary search
		for (int i = (n % 2 == 0) ? 1 : 2; i < n; i += 2)
		{
			int insertPos = _binarySearch(S, 0, S.size() - 1, X[i]);
			S.insert(S.begin() + insertPos, X[i]);
		}
		return S;
	}

	static int _binarySearch(const Container &arr, int left, int right, int key)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == key)
				return mid;
			else if (arr[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left; // Insert after the element less than key
	}
};

#endif