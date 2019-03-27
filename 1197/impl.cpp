#include <cstdlib>

#include <algorithm>
#include <iostream>

constexpr bool is_on_board(int const z, int const m = 8) {
	return z % m * 2 - z >= 0;
}

constexpr int num(int const x, int const y) {
	return
		(is_on_board(x - 2) && is_on_board(y - 1)) +
		(is_on_board(x - 2) && is_on_board(y + 1)) +
		(is_on_board(x - 1) && is_on_board(y - 2)) +
		(is_on_board(x - 1) && is_on_board(y + 2)) +
		(is_on_board(x + 2) && is_on_board(y - 1)) +
		(is_on_board(x + 2) && is_on_board(y + 1)) +
		(is_on_board(x + 1) && is_on_board(y - 2)) +
		(is_on_board(x + 1) && is_on_board(y + 2));
}

int main() try {
	int x{}, y{};
	unsigned n{};

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	while (n--) {
		char c{};

		std::cin >> c >> x;

		std::cout << num(x - 1, c - 'a') << std::endl;
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
