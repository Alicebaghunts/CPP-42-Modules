#include <iostream>
#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	Point inside(1.0f, 1.0f);
	Point outside(5.0f, 5.0f);
	Point edge(0.0f, 2.5f);

	std::cout << std::boolalpha;
	std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "edge: " << bsp(a, b, c, edge) << std::endl;

	return 0;
}
