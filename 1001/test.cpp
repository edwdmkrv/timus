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

		impl.in() << "1" << std::endl << "0" << std::endl; impl.in() << "3.14" << std::endl;

		std::string s1, s2, s3;

		impl.out() >> s1 >> s2 >> s3;

//		std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << std::endl;
		EXPECT_EQ(s1, "1.7321");
		EXPECT_EQ(s2, "0.0000");
		EXPECT_EQ(s3, "1.0000");
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
