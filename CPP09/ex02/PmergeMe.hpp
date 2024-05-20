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

	typedef std::deque<std::pair<int, int> > DequePair;

	void applyMergeInsertSort(const char **av)
	{
		getIntegerSequence(av);

		if (container.size() == 1)
		{
			mainChain.push_back(container.front());
		}
		else
		{
			createDequePairs();
			sortDequePairs();
			mergeSort(dequePair, 0, dequePair.size() - 1);
			createMainChainAndPend();
			insertToMainChain();
		}
	}

	class PmergeMeError : public std::exception
	{
		const char *what() const throw()
		{
			return "Error";
		}
	};

	void printBefore()
	{
		for (unsigned int i = 0; i < container.size(); i++)
			std::cout << container.at(i) << " ";
		std::cout << std::endl;
	}

	void printAfter()
	{
		for (unsigned int i = 0; i < mainChain.size(); i++)
			std::cout << mainChain.at(i) << " ";
		std::cout << std::endl;
	}

private:
	Container container;
	Container positions;
	DequePair dequePair;
	Container mainChain;
	Container pend;
	Container jacobSequence;

	void getIntegerSequence(const char **av)
	{
		int i;
		char *ptr;

		i = 1;
		int val;
		while (av[i])
		{
			if (av[i][0] == '\0')
				throw(PmergeMeError());

			val = std::strtol(av[i], &ptr, 10);

			if (*ptr != '\0' || val < 0)
				throw(PmergeMeError());

			container.push_back(val);
			i++;
		}
	}

	void createDequePairs()
	{
		int size;
		unsigned int i;

		i = 0;
		size = container.size() / 2;
		while (size != 0)
		{
			dequePair.push_back(std::make_pair(container.at(i), container.at(i + 1)));
			i += 2;
			size--;
		}
	}

	void sortDequePairs()
	{
		unsigned int i;
		int tmp;

		i = 0;
		while (i < dequePair.size())
		{
			if (dequePair.at(i).first < dequePair.at(i).second)
			{
				tmp = dequePair.at(i).first;
				dequePair.at(i).first = dequePair.at(i).second;
				dequePair.at(i).second = tmp;
			}
			i++;
		}
	}

	void merge(DequePair &array, int begin, int mid, int end)
	{
		size_t leftArrayIndex;
		size_t rightArrayIndex;
		size_t mergedArrayIndex;

		DequePair leftArray(array.begin() + begin, array.begin() + mid + 1);
		DequePair rightArray(array.begin() + mid + 1, array.begin() + end + 1);

		leftArrayIndex = 0;
		rightArrayIndex = 0;
		mergedArrayIndex = begin;

		while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
		{
			if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
			{
				array[mergedArrayIndex] = leftArray[leftArrayIndex];
				leftArrayIndex++;
			}
			else
			{
				array[mergedArrayIndex] = rightArray[rightArrayIndex];
				rightArrayIndex++;
			}
			mergedArrayIndex++;
		}
		while (leftArrayIndex < leftArray.size())
		{
			array[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
			mergedArrayIndex++;
		}
		while (rightArrayIndex < rightArray.size())
		{
			array[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
			mergedArrayIndex++;
		}
	}

	void mergeSort(DequePair &array, int begin, int end)
	{
		int mid;

		if (begin >= end)
			return;
		mid = begin + (end - begin) / 2;
		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}

	void createMainChainAndPend()
	{
		size_t i;

		mainChain.push_back(dequePair.at(0).second);

		i = 0;
		while (i < dequePair.size())
		{
			mainChain.push_back(dequePair.at(i).first);
			pend.push_back(dequePair.at(i).second);
			i++;
		}
	}

	int binarySearch(Container array, int target, int begin, int end)
	{
		int mid;

		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (target == array.at(mid))
				return (mid);

			if (target > array.at(mid))
				begin = mid + 1;
			else
				end = mid - 1;
		}
		if (target > array.at(mid))
			return (mid + 1);
		else
			return (mid);
	}

	void generateJacobInsertionSequence()
	{
		size_t size;
		size_t jcobstalIndex;
		int index;

		size = pend.size();
		index = 3;

		while ((jcobstalIndex = jacobsthal(index)) < size - 1)
		{
			jacobSequence.push_back(jcobstalIndex);
			index++;
		}
	}

	int jacobsthal(int n)
	{
		if (n == 0)
			return (0);
		if (n == 1)
			return (1);
		return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
	}

	void generatPositions()
	{
		size_t val;
		size_t pos;
		size_t lastPos;

		if (pend.empty())
			return;
		generateJacobInsertionSequence();
		lastPos = 1;
		val = 1;
		while (!jacobSequence.empty())
		{
			val = jacobSequence.front();

			jacobSequence.erase(jacobSequence.begin());
			positions.push_back(val);

			pos = val - 1;
			while (pos > lastPos)
			{
				positions.push_back(pos);
				pos--;
			}
			lastPos = val;
		}
		while (val++ < pend.size())
			positions.push_back(val);
	}

	void insertToMainChain()
	{
		size_t pos;
		int target;
		size_t endPos;
		size_t addedCount = 0;

		generatPositions();

		// Loop through positions using a counter
		for (size_t i = 0; i < positions.size(); ++i)
		{
			target = pend.at(positions[i] - 1);

			endPos = positions[i] + addedCount;
			pos = binarySearch(mainChain, target, 0, endPos);
			mainChain.insert(mainChain.begin() + pos, target);
			addedCount++;
		}

		// Handle the additional element if deque size is odd
		if (container.size() % 2 != 0)
		{
			target = container.at(container.size() - 1);
			pos = binarySearch(mainChain, target, 0, mainChain.size() - 1);
			mainChain.insert(mainChain.begin() + pos, target);
		}
	}
};

#endif