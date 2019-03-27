#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

int argc;
char **argv;

struct Data {
	char const c;
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

		Data const data{GetParam()};

		Impl impl{argv[1], argv[2], argv[3]};
		impl.in() << 1 << std::endl << data.c << data.n << std::endl;

		int r{};

		impl.out() >> r;

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{'a', 1, 2},
		Data{'d', 4, 8},
		Data{'g', 6, 6}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
