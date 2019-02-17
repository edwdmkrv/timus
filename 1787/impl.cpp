#include <cstdlib>
#include <iostream>

int main() try {
	unsigned k, n, s{0};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> k >> n;

	for (unsigned u{}, i; u < n; u++) {
		std::cin >> i;
		s = s + i < k ? 0 : s + i - k;
	}

	std::cout << s << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
