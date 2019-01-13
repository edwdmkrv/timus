#include <cstdlib>
#include <iostream>

int main() try {
	enum: unsigned {remaining_tasks = (5 - 1) * 60 / 45, all_tasks = 12};

	unsigned f;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> f;
	std::cout << (f + remaining_tasks < all_tasks ? "NO" : "YES") << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
