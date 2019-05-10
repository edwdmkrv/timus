#include <cstdlib>
#include <numeric>
#include <map>
#include <iostream>

std::map<unsigned, unsigned> primes(unsigned const n) {
	unsigned m{n};
	std::map<unsigned, unsigned> primes;

	for (unsigned u{2}; m > 1 && u * u <= n; u++) {
		while (m % u == 0) {
			primes[u]++;
			m /= u;
		}
	}

	if (m > 1) {
		primes[m]++;
	}

	return primes;
}

int main() try {
	unsigned n;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned u{}; u < n; u++) {
		unsigned n1{}, n2{};

		std::cin >> n1 >> n2;

		if (n2 % n1) {
			std::cout << 0 << std::endl;
		} else {
			auto const &primes1{primes(n1)};
			auto primes2{primes(n2)};

			for (auto const pair: primes1) {
				primes2[pair.first] -= pair.second;
			}

			std::cout << std::accumulate(
				std::cbegin(primes2),
				std::cend(primes2),
				std::pair<unsigned, unsigned>{0, 0},
				[](std::pair<unsigned, unsigned> const &lhs, std::pair<unsigned, unsigned> const &rhs) {
					return std::pair<unsigned, unsigned>{0, lhs.second + rhs.second};
				}).second + 1 << std::endl;
		}
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
