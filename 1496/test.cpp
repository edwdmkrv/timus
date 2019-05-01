#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <algorithm>
#include <vector>

using std::literals::string_literals::operator "" s;

int argc;
char **argv;

struct Data {
	std::vector<std::string> const v;
	std::vector<std::string> const r;
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

		std::size_t const osize{data.v.size()};

		impl.in() << osize << std::endl;

		for (auto const &s: data.v) {
			impl.in() << s << std::endl;
		}

		std::size_t const isize{data.r.size()};
		std::vector<std::string> r;

		r.reserve(isize);

		for (unsigned i{}; i < isize; i++) {
			std::string s{};

			impl.out() >> s;
			r.push_back(s);
		}

		std::sort(std::begin(r), std::end(r));

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{
			{"naucoder"s, "iceman"s, "abikbaev"s, "abikbaev"s, "petr"s, "abikbaev"s, "abikbaev"s, "x"s, "abikbaev"s, "acrush"s, "x"s},
			{"abikbaev"s, "x"s}
		}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
