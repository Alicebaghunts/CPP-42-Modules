#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::apply(int a, int b, char op) const
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return a / b;
	}
	throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string &expr) const
{
	std::stack<int> st;
	std::stringstream ss(expr);
	std::string token;

	while (ss >> token)
	{
		if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
			st.push(token[0] - '0');
		else if (token.size() == 1 && isOperator(token[0]))
		{
			if (st.size() < 2)
				throw std::runtime_error("Error");
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			st.push(apply(a, b, token[0]));
		}
		else
			throw std::runtime_error("Error");
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");
	return st.top();
}
