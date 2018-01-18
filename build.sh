#!/bin/bash

cd $(dirname ${0})

build_src_dir=$(pwd)
build_make_type="Eclipse CDT4 - Unix Makefiles"
build_make_ver="4.2"
platform=

print_help() {
	echo "Usage: "
	echo "  $0 [build_type] [platform] [version]"
}


if [[ "$1" == "debug" ||
    "$1" == "DEBUG" ||
    "$1" == "Debug" ||
    "$1" == "d" ]]; then
    build_out_type="DEBUG"

elif [[ "$1" == "release" ||
    "$1" == "RELEASE" ||
    "$1" == "Release" ||
    "$1" == "r" ||
    "$1" == "" ]]; then
    build_out_type="RELEASE"

else
    print_help
    exit 1
fi

build_out_dir=${build_src_dir##*/}"_CDT_MAKE_"${build_out_type}

if [[ "$2" == "x64" ||
      "$2" == "X64" || 
      "$2" == "" ]]; then
    platform="X64"

elif [[ "$2" == "MIPS32" ||
    "$2" == "mips32" ||
    "$2" == "mips" ]]; then
    platform="MIPS"

else
    print_help
    exit 1
fi




cd ..
rm -rf ${build_out_dir}

mkdir ${build_out_dir}
cd ${build_out_dir}

cmake -G "${build_make_type}" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -D CMAKE_BUILD_TYPE=${build_out_type} -D_ECLIPSE_VERSION=${build_make_ver} -D PLATFORM=$platform ${build_src_dir}
make -j4


exit 0

