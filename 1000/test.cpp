#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

int argc;
char **argv;

TEST(MainGroup, Test_1000) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};
		long double const v1{-3.14159};
		long double const v2{2.71828};

		impl.in() << v1 << std::endl << v2 << std::endl;

		long double r{};

		impl.out() >> r;

		std::ostringstream sum;
		std::ostringstream result;

		sum << v1 + v2;
		result << r;

//		std::cout << "sum = " << sum.str() << ", result = " << result.str() << std::endl;
		EXPECT_EQ(result.str(), sum.str());
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
