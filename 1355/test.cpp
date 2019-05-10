#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <utility>
#include <vector>

int argc;
char **argv;

struct Data {
	std::vector<std::pair<unsigned, unsigned>> const numbers;
	std::vector<unsigned> const r;
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

		auto &&in{impl.in()};
		auto &&out{impl.out()};

		in << data.numbers.size() << std::endl;

		for (auto const &pair: data.numbers) {
			in << pair.first << ' ' << pair.second << std::endl;
		}

		std::vector<unsigned> r(data.numbers.size());

		for (auto &u: r) {
			out >> u;
		}

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
			{
				{30,  89},
				{ 2,  16},
				{ 3, 243},
				{ 1,   1},
				{ 2,   2}
			},
			{
				0,
				4,
				5,
				1,
				1
			}
		}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
