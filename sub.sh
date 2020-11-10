#!/bin/sh


gcc -o pi main.c -w -lm -fopenmp

./411/4PA/PI_Estimator/pi 1000000000 1 
./411/4PA/PI_Estimator/pi  1000000000 2 
./411/4PA/PI_Estimator/pi 1000000000 4 
./411/4PA/PI_Estimator/pi 1000000000 8

./411/4PA/PI_Estimator/pi 100000000 1
./411/4PA/PI_Estimator/pi 200000000 2 
./411/4PA/PI_Estimator/pi 400000000 4
./411/4PA/PI_Estimator/pi 800000000 8
./411/4PA/PI_Estimator/pi 1000000000 10