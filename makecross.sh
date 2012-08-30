#!/bin/sh
DVSDK=${HOME}/ti-dvsdk_dm3730-evm_4_02_00_06
make distclean
source ${DVSDK}/linux-devkit/environment-setup
qmake -project
qmake
make
