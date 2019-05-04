#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>

int main() try {
	enum: unsigned {mind = 2, mink = 3};

	unsigned n{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned d{mind}; d < mink; d++) {
		unsigned dd{d};

		while (dd < mink) {
			dd *= d;
		}

		unsigned const ddd{d * dd};

		while (n % ddd == 0) {
			n /= d;
		}

		if (n % dd) {
			while (n % d == 0) {
				n /= d;
			}
		}
	}

	unsigned x{mink};
	auto const y{std::sqrt(n)};

	while (n % x && x <= y) {
		x++;
	}

	std::cout << (n % x ? n : x) - 1 << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
