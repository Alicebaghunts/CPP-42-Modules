#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED   "\033[31m"
#define RESET "\033[0m"

#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	void sortVector(std::vector<int> &arr);
	void sortDeque(std::deque<int> &arr);

	void insertVector(std::vector<int> &chain, int value);
	void insertDeque(std::deque<int> &chain, int value);

	std::vector<size_t> jacobsthalOrder(size_t n) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseArgs(int argc, char **argv);
	void run();
};

#endif
