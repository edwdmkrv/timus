#include <cstdlib>

#include <algorithm>
#include <iostream>

int main() try {
	unsigned n{}, k{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n >> k;

	unsigned const sides{n * 2};
	unsigned const performance{std::min(n, k)};

	std::cout << sides / performance + (sides % performance != 0) << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
