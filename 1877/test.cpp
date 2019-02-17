#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

int argc;
char **argv;

TEST(MainGroup, Test_1877_0) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << "0001" << std::endl << "0000" << std::endl;

		std::string r;

		impl.out() >> r;

//		std::cout << "r = " << r << std::endl;

		EXPECT_EQ(r, "no");
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

TEST(MainGroup, Test_1877_1) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << "0002" << std::endl << "0001" << std::endl;

		std::string r;

		impl.out() >> r;

//		std::cout << "r = " << r << std::endl;

		EXPECT_EQ(r, "yes");
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
