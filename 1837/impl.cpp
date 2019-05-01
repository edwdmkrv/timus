#include <cstdlib>
#include <limits>
#include <string>
#include <array>
#include <list>
#include <set>
#include <map>
#include <iostream>

using std::literals::string_literals::operator "" s;

int main() try {
	enum: std::size_t {participants = 3, undefined = std::numeric_limits<unsigned>::max()};

	static std::string const isenbaev{"Isenbaev"s};

	unsigned n{};

	std::list<std::set<std::string>> commands;
	std::map<std::string, unsigned> members;
	std::map<unsigned, std::set<std::string>> numbers;

	std::cin.exceptions(std::istream::badbit);
	std::cout.exceptions(std::ostream::badbit | std::ostream::failbit | std::ostream::eofbit);

	std::cin >> n;

	for (unsigned i{}; i < n; i++) {
		auto &command{(commands.emplace_back(), commands.back())};

		for (std::size_t i{}; i < participants; i++) {
			std::string member;

			std::cin >> member;

			command.emplace(member);
			members[member] = undefined;
		}
	}

	auto const &it{members.find(isenbaev)};

	if (it != std::end(members)) {
		n = 0;

		it->second = n;
		numbers[n].emplace(it->first);

		while (!commands.empty()) {
			std::list<std::set<std::string>> found;
			auto const &numbered{numbers[n++]};

			auto next{std::cbegin(commands)};
			auto const end{std::cend(commands)};

			while (next != end) {
				auto const it{next};

				++next;

				for (auto const &member: numbered) {
					if (it->count(member)) {
						for (auto const &comember: *it) {
							auto &number{members[comember]};

							if (number > n) {
								number = n;
								numbers[n].emplace(comember);
							}
						}

						found.splice(std::end(found), commands, it);
						break;
					}
				}
			}

			if (found.empty()) {
				break;
			}
		}
	}

	for (auto const &member: members) {
		std::cout << member.first << ' ' << (member.second != undefined ? std::to_string(member.second) : "undefined"s) << std::endl;
	}

	return EXIT_SUCCESS;
} catch (...) {
	return EXIT_FAILURE;
}
