#include <cstdlib>
#include <string>
#include <set>
#include <iostream>

int main() try {
	unsigned n{};
	std::set<std::string> submits;
	std::set<std::string> duplicates;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned i{}; i < n; i++) {
		std::string submit;

		std::cin >> submit;

		if (!submits.emplace(submit).second) {
			duplicates.emplace(submit);
		}
	}

	for (auto const &s: duplicates) {
		std::cout << s << std::endl;
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
