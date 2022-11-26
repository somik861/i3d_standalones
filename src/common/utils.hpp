#pragma once

#include <sstream>
#include <string>

template <typename T, typename U>
T to(U v) {
	std::stringstream ss;
	ss << v;
	T out;
	ss >> out;
	return out;
}

template <typename T>
int to_int(T v) {
	return to<int>(v);
}

template <typename T>
std::size_t to_size_t(T v) {
	return to<std::size_t>(v);
}

inline void add_ext(std::string& s) {
	if (!s.ends_with(".tif"))
		s.append(".tif");
}
