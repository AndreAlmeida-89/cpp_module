#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

template <typename Container, typename Pairs>
class PmergeMe
{
public:
	PmergeMe(const std::string typeName) : _time(0.0), _typeName(typeName) {}

	~PmergeMe() {}

	// Operators
	PmergeMe &operator=(const PmergeMe &assign)
	{
		(void)assign;
		return *this;
	}

	void sort(const char **argv)
	{
		std::clock_t start = std::clock();
		_getIntegerSequence(argv);

		if (_unsorted.size() == 1)
			_mainChain.push_back(_unsorted.front());
		else
		{
			_createPairs();
			_sortPairs();
			_mergeSort(_pairs, 0, _pairs.size() - 1);
			_createMainChainAndPend();
			_insertToMainChain();
		}
		std::clock_t end = std::clock();
		double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		_time = elapsedTime * 1000000;
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
		for (unsigned int i = 0; i < _mainChain.size(); i++)
			std::cout << _mainChain.at(i) << " ";
		std::cout << std::endl;
	}

	void printTime()
	{
		if (_mainChain.size() != _unsorted.size() || !std::is_sorted(_mainChain.begin(), _mainChain.end()))
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
	Container _positions;
	Pairs _pairs;
	Container _mainChain;
	Container _pend;
	Container _jacobSequence;
	double _time;
	std::string _typeName;

	PmergeMe() : _time(0.0) {}

	PmergeMe(const PmergeMe &copy)
	{
		(void)copy;
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

	void _createPairs()
	{
		size_t size = _unsorted.size() / 2;
		for (size_t i = 0; size--; i += 2)
			_pairs.push_back(std::make_pair(_unsorted.at(i), _unsorted.at(i + 1)));
	}

	void _sortPairs()
	{
		size_t size = _pairs.size();
		for (size_t i = 0; i < size; i++)
		{
			if (_pairs.at(i).first < _pairs.at(i).second)
				std::swap(_pairs.at(i).first, _pairs.at(i).second);
		}
	}

	void _merge(Pairs &pairs, int begin, int mid, int end)
	{
		size_t leftIndex;
		size_t rightIndex;
		size_t mergedIndex;

		Pairs leftPairs(pairs.begin() + begin, pairs.begin() + mid + 1);
		Pairs rightPairs(pairs.begin() + mid + 1, pairs.begin() + end + 1);

		leftIndex = 0;
		rightIndex = 0;
		mergedIndex = begin;

		while (leftIndex < leftPairs.size() && rightIndex < rightPairs.size())
		{
			if (leftPairs[leftIndex].first <= rightPairs[rightIndex].first)
			{
				pairs[mergedIndex] = leftPairs[leftIndex];
				leftIndex++;
			}
			else
			{
				pairs[mergedIndex] = rightPairs[rightIndex];
				rightIndex++;
			}
			mergedIndex++;
		}
		while (leftIndex < leftPairs.size())
		{
			pairs[mergedIndex] = leftPairs[leftIndex];
			leftIndex++;
			mergedIndex++;
		}
		while (rightIndex < rightPairs.size())
		{
			pairs[mergedIndex] = rightPairs[rightIndex];
			rightIndex++;
			mergedIndex++;
		}
	}

	void _mergeSort(Pairs &pairs, int begin, int end)
	{
		int mid;

		if (begin >= end)
			return;
		mid = begin + (end - begin) / 2;
		_mergeSort(pairs, begin, mid);
		_mergeSort(pairs, mid + 1, end);
		_merge(pairs, begin, mid, end);
	}

	void _createMainChainAndPend()
	{
		_mainChain.push_back(_pairs.at(0).second);
		for (size_t i = 0; i < _pairs.size(); i++)
		{
			_mainChain.push_back(_pairs.at(i).first);
			_pend.push_back(_pairs.at(i).second);
		}
	}

	int _binarySearch(Container sequence, int target, int begin, int end)
	{
		int mid;

		while (begin <= end)
		{
			mid = begin + (end - begin) / 2;
			if (target == sequence.at(mid))
				return (mid);
			if (target > sequence.at(mid))
				begin = mid + 1;
			else
				end = mid - 1;
		}
		if (target > sequence.at(mid))
			return (mid + 1);
		else
			return (mid);
	}

	void _generateJacobInsertionSequence()
	{
		size_t size;
		size_t jcobstalIndex;
		int index;

		size = _pend.size();
		index = 3;

		while ((jcobstalIndex = _jacobsthal(index)) < size - 1)
		{
			_jacobSequence.push_back(jcobstalIndex);
			index++;
		}
	}

	int _jacobsthal(int n)
	{
		if (n == 0)
			return (0);
		if (n == 1)
			return (1);
		return (_jacobsthal(n - 1) + 2 * _jacobsthal(n - 2));
	}

	void _generatPositions()
	{
		size_t val;
		size_t pos;
		size_t lastPos;

		if (_pend.empty())
			return;
		_generateJacobInsertionSequence();
		lastPos = 1;
		val = 1;
		while (!_jacobSequence.empty())
		{
			val = _jacobSequence.front();

			_jacobSequence.erase(_jacobSequence.begin());
			_positions.push_back(val);

			pos = val - 1;
			while (pos > lastPos)
			{
				_positions.push_back(pos);
				pos--;
			}
			lastPos = val;
		}
		while (val++ < _pend.size())
			_positions.push_back(val);
	}

	void _insertToMainChain()
	{
		size_t pos;
		int target;
		size_t endPos;
		size_t addedCount = 0;

		_generatPositions();

		for (size_t i = 0; i < _positions.size(); ++i)
		{
			target = _pend.at(_positions[i] - 1);
			endPos = _positions[i] + addedCount;
			pos = _binarySearch(_mainChain, target, 0, endPos);
			_mainChain.insert(_mainChain.begin() + pos, target);
			addedCount++;
		}

		if (_unsorted.size() % 2 != 0)
		{
			target = _unsorted.at(_unsorted.size() - 1);
			pos = _binarySearch(_mainChain, target, 0, _mainChain.size() - 1);
			_mainChain.insert(_mainChain.begin() + pos, target);
		}
	}
};

#endif