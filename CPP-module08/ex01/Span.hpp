#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span
{
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;

public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int value);

	template <typename InputIt>
	void addNumber(InputIt first, InputIt last)
    {
		for (; first != last; ++first)
			addNumber(*first);
	}

	int shortestSpan() const;
	int longestSpan() const;

	class FullSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
