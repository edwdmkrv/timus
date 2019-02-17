#include <cstdlib>
#include <iostream>

int main() try {
	enum: unsigned {common_cans = 1};

	unsigned garry, larry;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> garry >> larry;
	std::cout << larry - common_cans << ' ' << garry - common_cans << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
