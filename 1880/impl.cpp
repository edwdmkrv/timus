#include <cstdlib>

#include <array>
#include <set>
#include <iostream>

#include "test.hpp"

int main() try {
	enum: unsigned {eigenvalues_max = 4000};

	std::array<std::set<unsigned>, count> eigenvalueses;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	for (auto &eigenvalues: eigenvalueses) {
		unsigned size{};

		std::cin >> size;

		for (unsigned n{}; n < size; n++) {
			unsigned number;

			std::cin >> number;
			eigenvalues.insert(number);
		}
	}

	unsigned eigenvalues_number{};

	for (auto const &value: eigenvalueses[0]) {
		for (auto const &eigenvalues: eigenvalueses) {
			if (eigenvalues.count(value) == 0) {
				goto continue1;
			}
		}

		eigenvalues_number++;
continue1:;
	}

	std::cout << eigenvalues_number << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
