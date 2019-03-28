#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <vector>

#include "test.hpp"

int argc;
char **argv;

struct Data {
	std::vector<int> const a[count];
	std::size_t const r;
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

		for (auto const &v: data.a) {
			impl.in() << v.size() << std::endl;
			for (auto const &n: v) {
				impl.in() << n << ' ';
			}

			impl.in() << std::endl;
		}

		int r{};

		impl.out() >> r;

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{
			{
				{13, 20, 22, 43, 146},
				{13, 22, 43, 146},
				{13, 43, 67, 89, 146}
			},
			3
		}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
