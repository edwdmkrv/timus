#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

int argc;
char **argv;

TEST(MainGroup, Test_1264) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << 3 << ' ' << 1 << std::endl;

		unsigned r;

		impl.out() >> r;

//		std::cout << "r = " << r << std::endl;

		EXPECT_EQ(r, 6);
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
