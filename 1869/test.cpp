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
	std::vector<std::vector<unsigned>> const tickets;
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

		auto &&in{impl.in()};
		auto &&out{impl.out()};

		in << data.tickets.size() << std::endl;

		for (auto const &tickets2: data.tickets) {
			for (auto const &tickets3: tickets2) {
				in << tickets3 << ' ';
			}

			in << std::endl;
		}

		unsigned r{};

		out >> r;

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
				{  0, 180, 180},
				{  0,   0, 180},
				{360,   0,   0}
			},
			10
		}
	)
);

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);
	::argc = argc;
	::argv = argv;
	return RUN_ALL_TESTS();
}
