#include <i3d/image3d.h>
#include <i3d/morphology.h>

#define CODE                                                                   \
	i3d::Image3d tmp = img;                                                    \
	i3d::Fillhole(tmp, img);

#include "../../common/main.hpp"
