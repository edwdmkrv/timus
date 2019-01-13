#include <cstdlib>
#include <cstdint>
#include <iostream>

int main() try {
	enum: unsigned {sides = 2};

	uint32_t n, a, b;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n >> a >> b;
	std::cout << sides * n * a * b << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
