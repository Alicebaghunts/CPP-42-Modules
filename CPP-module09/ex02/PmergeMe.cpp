#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <sys/time.h>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Error");

		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (arg[j] < '0' || arg[j] > '9')
				throw std::runtime_error("Error");
		}

		std::stringstream ss(arg);
		long value = 0;
		ss >> value;
		if (ss.fail() || !ss.eof() || value < 0 || value > 2147483647)
			throw std::runtime_error("Error");

		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n) const
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::vector<char> used(n, 0);
	size_t prev = 1;
	for (size_t i = 2; i < jacob.size(); ++i)
	{
		size_t current = jacob[i];
		if (current > n)
			current = n;
		size_t k = current;
		while (k > prev)
		{
			if (k - 1 < n && !used[k - 1])
			{
				order.push_back(k - 1);
				used[k - 1] = 1;
			}
			--k;
		}
		prev = current;
		if (current == n)
			break;
	}

	for (size_t i = 0; i < n; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

void PmergeMe::insertVector(std::vector<int> &chain, int value)
{
	size_t left = 0;
	size_t right = chain.size();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + left, value);
}

void PmergeMe::insertDeque(std::deque<int> &chain, int value)
{
	size_t left = 0;
	size_t right = chain.size();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	chain.insert(chain.begin() + static_cast<std::deque<int>::difference_type>(left), value);
}

void PmergeMe::sortVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<int> winners;
	std::vector<int> losers;
	bool hasStraggler = arr.size() % 2 != 0;
	int straggler = 0;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			winners.push_back(arr[i]);
			losers.push_back(arr[i + 1]);
		}
		else
		{
			winners.push_back(arr[i + 1]);
			losers.push_back(arr[i]);
		}
	}
	if (hasStraggler)
		straggler = arr.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < winners.size(); ++i)
		pairs.push_back(std::make_pair(winners[i], losers[i]));

	sortVector(winners);

	std::vector<int> pending;
	std::vector<char> used(pairs.size(), 0);
	for (size_t i = 0; i < winners.size(); ++i)
	{
		for (size_t p = 0; p < pairs.size(); ++p)
		{
			if (!used[p] && pairs[p].first == winners[i])
			{
				pending.push_back(pairs[p].second);
				used[p] = 1;
				break;
			}
		}
	}
	if (hasStraggler)
		pending.push_back(straggler);

	std::vector<int> mainChain = winners;
	if (pending.empty())
	{
		arr = mainChain;
		return;
	}

	insertVector(mainChain, pending[0]);

	std::vector<size_t> order = jacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		if (order[i] == 0)
			continue;
		insertVector(mainChain, pending[order[i]]);
	}

	arr = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<int> winners;
	std::deque<int> losers;
	bool hasStraggler = arr.size() % 2 != 0;
	int straggler = 0;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			winners.push_back(arr[i]);
			losers.push_back(arr[i + 1]);
		}
		else
		{
			winners.push_back(arr[i + 1]);
			losers.push_back(arr[i]);
		}
	}
	if (hasStraggler)
		straggler = arr.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < winners.size(); ++i)
		pairs.push_back(std::make_pair(winners[i], losers[i]));

	sortDeque(winners);

	std::deque<int> pending;
	std::vector<char> used(pairs.size(), 0);
	for (size_t i = 0; i < winners.size(); ++i)
	{
		for (size_t p = 0; p < pairs.size(); ++p)
		{
			if (!used[p] && pairs[p].first == winners[i])
			{
				pending.push_back(pairs[p].second);
				used[p] = 1;
				break;
			}
		}
	}
	if (hasStraggler)
		pending.push_back(straggler);

	std::deque<int> mainChain = winners;
	if (pending.empty())
	{
		arr = mainChain;
		return;
	}

	insertDeque(mainChain, pending[0]);

	std::vector<size_t> order = jacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		if (order[i] == 0)
			continue;
		insertDeque(mainChain, pending[order[i]]);
	}

	arr = mainChain;
}

void PmergeMe::run()
{
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	struct timeval startVec;
	struct timeval endVec;
	struct timeval startDeq;
	struct timeval endDeq;

	gettimeofday(&startVec, NULL);
	sortVector(_vec);
	gettimeofday(&endVec, NULL);

	gettimeofday(&startDeq, NULL);
	sortDeque(_deq);
	gettimeofday(&endDeq, NULL);

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0
		+ (endVec.tv_usec - startVec.tv_usec);
	double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0
		+ (endDeq.tv_usec - startDeq.tv_usec);

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
