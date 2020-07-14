#!/bin/bash

## Clone desire version
version='0.7.0'
if [ ! -d libfranka ]; then
	git clone --recursive https://github.com/frankaemika/libfranka
fi
cd libfranka
git checkout ${version} && git submodule update

## Build
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .

## Generate deb executable
cpack && sudo dpkg -i libfranka-${version}-amd64.deb



