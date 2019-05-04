#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <iostream>

int main() try {
	enum: unsigned {seats = 36};

	unsigned n{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	std::vector<std::vector<unsigned>> data;

	data.reserve(n);

	for (unsigned i{}; i < n; i++) {
		auto &v{(data.emplace_back(), data.back())};

		v.reserve(n);

		for (unsigned i{}; i < n; i++) {
			std::cin >> (v.emplace_back(), v.back());
		}
	}

	std::vector<unsigned> forward(n - 1);

	for (unsigned k{}; k < n - 1; k++) {
		for (unsigned i{}; i <= k; i++) {
			for (unsigned j{k + 1}; j < n; j++) {
				forward[k] += data[i][j];
			}
		}
	}

	std::vector<unsigned> backward(n - 1);

	for (unsigned k{}; k < n - 1; k++) {
		for (unsigned i{}; i <= k; i++) {
			for (unsigned j{k + 1}; j < n; j++) {
				backward[k] += data[n - i - 1][n - j - 1];
			}
		}
	}

	auto const &max1{*std::max_element(std::cbegin(forward), std::cend(forward))};
	auto const &max2{*std::max_element(std::cbegin(backward), std::cend(backward))};
	auto const &max{std::max(max1, max2)};

	std::cout << (max + seats - 1) / seats << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
