#include <cstdlib>

#include <algorithm>
#include <iostream>

int main() try {
	int a{}, b{}, c{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> a >> b >> c;

	std::cout <<
		std::min({
			a - b - c,
			a - b + c,
			a - b * c,
			a + b - c,
			a + b + c,
			a + b * c,
			a * b - c,
			a * b + c,
			a * b * c
		}) << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
