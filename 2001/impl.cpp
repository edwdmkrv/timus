#include <cstdlib>
#include <iostream>

int main() try {
	unsigned a1, a3, b1, b2, garbage;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> a1 >> b1 >> garbage >> b2 >> a3 >> garbage;
	std::cout << a1 - a3 << ' ' << b1 - b2 << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
