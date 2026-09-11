#ifndef RPN_HPP
#define RPN_HPP

#define RED   "\033[31m"
#define RESET "\033[0m"

#include <string>

class RPN
{
private:
	bool isOperator(char c) const;
	int apply(int a, int b, char op) const;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluate(const std::string &expr) const;
};

#endif
