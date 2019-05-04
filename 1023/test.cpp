#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <cstdint>
#include <algorithm>
#include <vector>

int argc;
char **argv;

struct Data {
	unsigned const n;
	unsigned const r;
};

struct Test: testing::Test, testing::WithParamInterface<Data> {
};

TEST_P(Test, TestSteak) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Data const &data{GetParam()};

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << data.n << std::endl;

		unsigned r{};

		impl.out() >> r;

		EXPECT_EQ(r, data.r);
	} catch (std::exception const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		ASSERT_TRUE(false);
	} catch (...) {
		std::cerr << "Error: " << "unidentified exception" << std::endl;
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{
			3,
			2
		}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
