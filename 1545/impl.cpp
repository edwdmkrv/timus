#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

int main() try {
	unsigned n{};
	std::map<char, std::set<char>> reference;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned i{}; i < n; i++) {
		char k{}, c{};

		std::cin >> k >> c;
		reference[k].emplace(c);
	}

	char k{};

	std::cin >> k;

	auto const glyphs{reference[k]};

	for (auto const &c: glyphs) {
		std::cout << k << c << std::endl;
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
