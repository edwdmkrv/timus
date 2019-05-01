#include <version.hpp>

#include <gtest/gtest.h>

#include <testlib.hpp>

#include <utility>
#include <array>
#include <vector>

using std::literals::string_literals::operator "" s;

int argc;
char **argv;

struct Data {
	enum:std::size_t {participants = 3};

	std::vector<std::array<std::string, participants>> const commands;
	std::vector<std::pair<std::string, std::string>> const numbers;
};

struct Test: testing::Test, testing::WithParamInterface<Data> {
};

namespace std {

std::ostream &operator <<(std::ostream &o, Data const &data) {
	for (auto const &item: data.numbers) {
		o << '(' << item.first << ' ' << item.second << ") ";
	}

	return o;
}

}

TEST_P(Test, TestSteak) {
	try {
		if (argc != 4) {
			throw std::runtime_error{"A test expects 3 parameters"};
		}

		Data const &data{GetParam()};

		Impl impl{argv[1], argv[2], argv[3]};

		impl.in() << data.commands.size();

		for (auto const &command: data.commands) {
			for (auto const &participant: command) {
				impl.in() << participant << ' ';
			}

			impl.in() << std::endl;
		}

		std::vector<std::pair<std::string, std::string>> numbers;

		for (std::size_t i{}, limit{data.numbers.size()}; i < limit; i++) {
			numbers.emplace_back();

			impl.out() >> numbers.back().first;
			impl.out() >> numbers.back().second;
		}

		EXPECT_EQ(numbers, data.numbers);
	} catch (...) {
		ASSERT_TRUE(false);
	}
}

INSTANTIATE_TEST_CASE_P(SimpleDataset, Test,
	testing::Values(
		Data{
			{
				{"Isenbaev"s, "Oparin"s, "Toropov"s},
				{"Ayzenshteyn"s, "Oparin"s, "Samsonov"s},
				{"Ayzenshteyn"s, "Chevdar"s, "Samsonov"s},
				{"Fominykh"s, "Isenbaev"s, "Oparin"s},
				{"Dublennykh"s, "Fominykh"s, "Ivankov"s},
				{"Burmistrov"s, "Dublennykh"s, "Kurpilyanskiy"s},
				{"Cormen"s, "Leiserson"s, "Rivest"s}
			},
			{
				{"Ayzenshteyn"s, "2"s},
				{"Burmistrov"s, "3"s},
				{"Chevdar"s, "3"s},
				{"Cormen"s, "undefined"s},
				{"Dublennykh"s, "2"s},
				{"Fominykh"s, "1"s},
				{"Isenbaev"s, "0"s},
				{"Ivankov"s, "2"s},
				{"Kurpilyanskiy"s, "3"s},
				{"Leiserson"s, "undefined"s},
				{"Oparin"s, "1"s},
				{"Rivest"s, "undefined"s},
				{"Samsonov"s, "2"s},
				{"Toropov"s, "1"s},
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
