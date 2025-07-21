#!/usr/bin/env bash

command cmake --preset=Release
if [[ -d /usr/local/lib/cmake/cmaketk ]]
then
    command sudo cmake -P /usr/local/lib/cmake/cmaketk/uninstall.cmake
fi
command sudo cmake --install ../.build/cmaketk/Release
