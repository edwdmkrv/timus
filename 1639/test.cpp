#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <string>

using std::literals::string_literals::operator "" s;

int argc;
char **argv;

struct Data {
	unsigned const m;
	unsigned const n;
	std::string const r;
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
		impl.in() << data.m << ' ' << data.n << std::endl;

		std::string r{};

		impl.out() >> r;

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{2, 4, "[:=[first]"s},
		Data{1, 3, "[second]=:]"s}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
