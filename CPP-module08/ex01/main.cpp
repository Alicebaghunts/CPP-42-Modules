#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> big;
	for (int i = 0; i < 10000; ++i)
		big.push_back(i * 2);
	
	Span bigSpan(10000);
	bigSpan.addNumber(big.begin(), big.end());

	std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Big span longest: " << bigSpan.longestSpan() << std::endl;

	return 0;
}
