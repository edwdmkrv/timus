#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <vector>

using std::literals::string_literals::operator "" s;

int argc;
char **argv;

struct Data {
	std::vector<unsigned> const v;
	std::vector<unsigned> const r;
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

		std::size_t const osize{data.v.size()};

		impl.in() << osize << std::endl;

		for (auto const &i: data.v) {
			impl.in() << i << ' ';
		}

		impl.in() << std::endl;

		std::size_t const isize{data.r.size()};
		std::vector<unsigned> r;

		r.reserve(isize);

		for (unsigned i{}; i < isize; i++) {
			unsigned x{};

			impl.out() >> x;
			r.push_back(x);
		}

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{{10, 10, 10}, {33, 33, 33}},
		Data{{10, 0}, {100, 0}}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
