#include <cstdlib>
#include <iostream>

int main() try {
	unsigned n, m;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n >> m;
	std::cout << n * (m + 1) << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
