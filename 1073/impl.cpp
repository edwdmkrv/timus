#include <cstdlib>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

static unsigned num(unsigned const n) {
	for (unsigned u1{}; u1 * u1 < n; u1++) {
		unsigned const m{n - u1 * u1};

		for (unsigned u2{u1}; u2 * u2 < m; u2++) {
			unsigned const k{m - u2 * u2};
			unsigned u3{u2};

			while (u3 * u3 < k) {
				u3++;
			}

			if (u3 * u3 == k) {
				return 3 - (u2 == 0) - (u1 == 0);
			}
		}
	}

	return 4;
}

int main() try {
	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	unsigned n{};

	std::cin >> n;

	std::cout << num(n) << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
