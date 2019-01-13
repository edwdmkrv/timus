#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <stack>
#include <iomanip>
#include <iostream>

int main() try {
	enum {precision = 4};

	uint64_t a;
	std::stack<decltype(a)> values;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cout << std::fixed << std::setprecision(precision);

	while (std::cin >> a) {
		values.push(a);
	}

	while (!values.empty()) {
		std::cout << std::sqrt(values.top()) << std::endl;
		values.pop();
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
