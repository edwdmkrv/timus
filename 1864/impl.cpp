#include <cstdlib>
#include <vector>
#include <iostream>

int main() try {
	unsigned n{};
	unsigned sum1{};
	unsigned sum2{};

	std::vector<unsigned> litres;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	litres.reserve(n);

	for (unsigned i{}; i < n; i++) {
		unsigned x{};

		std::cin >> x;
		litres.push_back(x);
		sum1 += x;
	}

	for (auto &i: litres) {
		auto const v{i * (n + 1)};

		sum2 += i = v > sum1 ? v - sum1 : 0;
	}

	for (auto &i: litres) {
		std::cout << i * 100 / sum2 << ' ';
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
