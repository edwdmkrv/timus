#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <iostream>
int argc;
char **argv;

TEST(MainGroup, Test_1306) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};

		unsigned const num{4};

		unsigned const n1{3};
		unsigned const n2{6};
		unsigned const n3{4};
		unsigned const n4{5};

		impl.in() << num << std::endl;

		impl.in() << n1 << std::endl;
		impl.in() << n2 << std::endl;
		impl.in() << n3 << std::endl;
		impl.in() << n4 << std::endl;

		long double r{};

		impl.out() >> r;

		std::ostringstream average;
		std::ostringstream result;

		average << static_cast<long double>(n3 + n4) / 2;
		result << r;

		FILE *const wr{fopen("/arc/Courses/OTUS/C++/timus/AAA", "w")};
		fprintf(wr, "result: '%s'\n", result.str().c_str());
		fprintf(wr, "average: '%s'\n", average.str().c_str());
//std::cerr << "result: '" << result.str() << "'" << std:endl;
//std::cerr << "average: '" << average.str() << "'" << std:endl;
		EXPECT_EQ(result.str(), average.str());
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
