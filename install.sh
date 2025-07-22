#!/usr/bin/env bash

package_name="cmaketk"
install_prefix="/usr/local"
build_type="Release"
sudo_cmd="sudo"

cmake --preset=${build_type}
if [[ -d ${install_prefix}/lib/cmake/${package_name} ]]
then
    $sudo_cmd cmake -P ${install_prefix}/lib/cmake/${package_name}/uninstall.cmake
fi
$sudo_cmd cmake --install ../.build/${package_name}/${build_type}
