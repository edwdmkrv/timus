#include <cstdlib>
#include <cstdint>
#include <set>
#include <iostream>

int main() try {
	unsigned n{};
	std::set<uint32_t> tutor;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned i{}; i < n; i++) {
		uint32_t date;

		std::cin >> date;

		tutor.emplace(date);
	}

	unsigned num{};

	std::cin >> n;

	for (unsigned i{}; i < n; i++) {
		uint32_t date;

		std::cin >> date;

		if (tutor.count(date)) {
			num++;
		}
	}

	std::cout << num << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
