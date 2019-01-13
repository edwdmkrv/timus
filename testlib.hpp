#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <string>
#include <fstream>

class MkFifo {
private:
	std::string const name;

public:
	MkFifo(std::string const &name): name{name} {
		if (mkfifo(name.c_str(), S_IRUSR | S_IWUSR) == -1) {
			throw std::runtime_error{"Failed to create fifo"};
		}
	}

	~MkFifo() {
		unlink(name.c_str());
	}
};

class Invoke {
public:
	Invoke(std::string const &exe, std::string const &in, std::string const &out) {
		if (system((exe + " < " + in + " > " + out + '&').c_str()) != 0) {
			throw std::runtime_error{"Failed to invoke implementation"};
		}
	}
};

class Impl {
private:
	MkFifo const fifo_in;
	MkFifo const fifo_out;

	Invoke const impl;

	std::ofstream o;
	std::ifstream i;

public:
	Impl(std::string const &exe, std::string const &in, std::string const &out): fifo_in{in}, fifo_out{out}, impl{exe, in, out}, o{in}, i{out} {
	}

	std::ofstream &&in() noexcept {
		return std::move(o);
	}

	std::ifstream &&out() noexcept {
		return std::move(i);
	}
};
