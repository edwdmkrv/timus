#include <cstdlib>

#include <iostream>

int main() try {
	unsigned m{}, n{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> m >> n;

	std::cout << (m * n % 2 ? "[second]=:]" : "[:=[first]") << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
