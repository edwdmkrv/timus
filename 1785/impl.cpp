#include <cstdlib>
#include <iostream>

int main() try {
	enum: unsigned {
		few = 5,
		several = 10,
		pack = 20,
		lots = 50,
		horde = 100,
		throng = 250,
		swarm = 500,
		zounds = 1000
	};

	unsigned num;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> num;
	std::cout << (
		num < few ?
			"few" :
		num < several ?
			"several" :
		num < pack ?
			"pack" :
		num < lots ?
			"lots" :
		num < horde ?
			"horde" :
		num < throng ?
			"throng" :
		num < swarm ?
			"swarm" :
		num < zounds ?
			"zounds" :
			"legion"
	) << std::endl;

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
