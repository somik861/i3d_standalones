#pragma once

#include "utils.hpp"
#include <i3d/image3d.h>
#include <iostream>
#include <string>

#ifndef CODE
#error
#endif

#ifndef ARG_COUNT
#define ARG_COUNT 3
#endif

int main(int argc, char** argv) {
	static_assert(ARG_COUNT >= 3);
	if (argc != ARG_COUNT) {
		std::cerr << "Invalid number of arguments\n";
		std::cerr << "./PROGRAM INPUT OUTPUT ... \n";
		return 1;
	}

	i3d::Image3d<i3d::GRAY16> img(argv[1]);

    CODE;

	std::string out_name = argv[2];
	add_ext(out_name);
	img.SaveImage(out_name.c_str());
}