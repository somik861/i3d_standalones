#include <i3d/morphology.h>

#define ARG_COUNT 4
#define CODE                                                                   \
	i3d::Image3d<i3d::GRAY16> marker(argv[3]);                                 \
	auto tmp = img;                                                            \
	i3d::Reconstruction_by_dilation(marker, tmp, img);

#include "../../common/main.hpp"
