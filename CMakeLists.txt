cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-flto")

project(I3D_standalones CXX C)
set(PY_WRAP_NAME "i3d_wrapper.py")

macro(SUBDIRLIST result curdir)
  file(
    GLOB children
    RELATIVE ${curdir}
    ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

# I3D deps ===================

find_package(FFTW3 CONFIG REQUIRED)
set(LIBS ${LIBS} FFTW3::fftw3)

find_package(FFTW3f CONFIG REQUIRED)
set(LIBS ${LIBS} FFTW3::fftw3f)

find_package(FFTW3l CONFIG REQUIRED)
set(LIBS ${LIBS} FFTW3::fftw3l)

find_package(clapack CONFIG REQUIRED)
set(LIBS ${LIBS} lapack)

if(UNIX)
  if(NOT APPLE)
    set(LIBS ${LIBS} f2c)
  endif(NOT APPLE)
endif(UNIX)

find_package(OpenBLAS CONFIG REQUIRED)
set(LIBS ${LIBS} OpenBLAS::OpenBLAS)

find_package(TIFF REQUIRED)
set(LIBS ${LIBS} ${TIFF_LIBRARIES})

find_package(JPEG REQUIRED)
set(LIBS ${LIBS} ${JPEG_LIBRARIES})

find_package(libpng CONFIG REQUIRED)
if(WIN32)
  set(LIBS ${LIBS} png)
else(WIN32)
  set(LIBS ${LIBS} png_static)
endif(WIN32)

find_package(libics CONFIG REQUIRED)
set(LIBS ${LIBS} libics)

find_package(ZLIB REQUIRED)
set(LIBS ${LIBS} ZLIB::ZLIB)

find_package(hdf5 CONFIG REQUIRED)
if(WIN32)
  set(LIBS ${LIBS} hdf5::hdf5-shared hdf5::hdf5_hl-shared)
else(WIN32)
  set(LIBS ${LIBS} hdf5::hdf5-static hdf5::hdf5_hl-static)
endif(WIN32)

find_package(RXSpencer CONFIG REQUIRED)
set(LIBS ${LIBS} rxspencer)

find_library(I3DCORE i3dcore PATH_SUFFIXES ".a" REQUIRED)
find_library(I3DALGO i3dalgo PATH_SUFFIXES ".a" REQUIRED)

set(LIBS ${I3DCORE} ${I3DALGO} ${LIBS})

# I3D deps end ===================

set(STAN_FLDR "${CMAKE_SOURCE_DIR}/src/standalones")

subdirlist(stands ${STAN_FLDR})
foreach(stan ${stands})
  add_executable(${stan} "${STAN_FLDR}/${stan}/main.cpp")
  target_link_libraries(${stan} ${LIBS})

  add_custom_command(
    TARGET ${stan}
    POST_BUILD
    COMMAND /bin/bash "${CMAKE_SOURCE_DIR}/create_pywrap.sh"
            "${CMAKE_BINARY_DIR}/${PY_WRAP_NAME}"
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endforeach()
