#!/bin/bash

echo "running with n=2^30, p=(1,2,4,8)"
./411/4PA/pi 1048576 1
./411/4PA/pi 1048576 2
./411/4PA/pi 1048576 4
./411/4PA/pi 1048576 8


echo "running with constant n/p"
#./411/4PA/pi 1024 8
#./411/4PA/pi 2048 8
#./411/4PA/pi 4096 8
#./411/4PA/pi 8192 8
#./411/4PA/pi 16384 8
#./411/4PA/pi 32768 8
#./411/4PA/pi 65536 8
#./411/4PA/pi 131072 8
#./411/4PA/pi 262144 8