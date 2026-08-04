#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : _numbers(), _maxSize(n) { }

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) { }

Span::~Span() { }

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

void Span::addNumber(int value)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(value);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char* Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to compute span";
}
