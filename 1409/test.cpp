#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

int argc;
char **argv;

TEST(MainGroup, Test_1409) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << 4 << ' ' << 7 << std::endl;

		unsigned r1, r2;

		impl.out() >> r1 >> r2;

//		std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;

		EXPECT_EQ(r1, 6);
		EXPECT_EQ(r2, 3);
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
