#!/bin/sh
DVSDK=${HOME}/ti-dvsdk_dm3730-evm_4_02_00_06
source ${DVSDK}/linux-devkit/environment-setup
qmake -makefile -unix -o Makefile displayDemo.pro
make clean
make
