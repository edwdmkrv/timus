#include <cstdlib>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main() try {
	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	unsigned n{};

	std::cin >> n;

	unsigned u{};
	unsigned const half {n / 2 + 1};
	std::vector<uint32_t> data;

	data.resize(half + 1);

	for (; u < half; u++) {
		std::cin >> data[u];
	}

	std::make_heap(std::begin(data), std::end(data));
	data.emplace_back();

	auto const begin{std::begin(data)};
	auto const end{std::end(data)};

	for (; u < n; u++) {
		std::cin >> data.back();
		std::push_heap(begin, end);
		std::pop_heap(begin, end);
	}

	data.pop_back();
	std::pop_heap(begin, std::end(data));

	uint64_t const one{data.back()};

	data.pop_back();
	std::pop_heap(begin, std::end(data));

	uint64_t const two{data.back()};
	uint64_t const sum{one + (n % 2 ? one : two)};

	std::cout << sum / 2 << (sum % 2 ? ".5" : "") << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
