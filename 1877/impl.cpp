#include <cstdlib>
#include <iostream>

int main() try {
	unsigned lock0, lock1;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> lock0 >> lock1;
	std::cout << (lock0 % 2 == 0 || lock1 % 2 != 0 ? "yes" : "no") << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
