#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <cstdint>
#include <algorithm>
#include <vector>

using std::literals::string_literals::operator "" s;

int argc;
char **argv;

struct Data {
	std::vector<uint32_t> const tutor;
	std::vector<uint32_t> const student;
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

		for (auto const &dates: std::initializer_list<std::vector<uint32_t> const>{data.tutor, data.student}) {
			impl.in() << dates.size() << std::endl;

			for (auto const &date: dates) {
				impl.in() << date << std::endl;
			}
		}

		unsigned r{};

		impl.out() >> r;

		EXPECT_EQ(r, data.r);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{
			{1054, 1492},
			{1492, 65536, 1492, 100},
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
