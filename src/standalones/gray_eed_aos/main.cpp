#include "../../common/utils.hpp"
#include <i3d/diffusion_filters.h>

#define ARG_COUNT 7
#define CODE \
    i3d::GrayEED_AOS(img, to_float(argv[3]), to_float(argv[4]), to_float(argv[5]), to_size_t(argv[6]));

#include "../../common/main.hpp"