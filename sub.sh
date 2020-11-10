#!/bin/sh


gcc -o pi main.c -w -lm -fopenmp

./411/4PA/PI_Estimator 1000000000 1 >> result_speedup.txt
./411/4PA/PI_Estimator  1000000000 2 >> result_speedup.txt
./411/4PA/PI_Estimator 1000000000 4 >> result_speedup.txt
./411/4PA/PI_Estimator 1000000000 8 >> result_speedup.txt

./411/4PA/PI_Estimator 100000000 1 >> result_precision.txt
./411/4PA/PI_Estimator 200000000 2 >> result_precision.txt
./411/4PA/PI_Estimator 400000000 4 >> result_precision.txt
./411/4PA/PI_Estimator 800000000 8 >> result_precision.txt
./411/4PA/PI_Estimator 1000000000 10 >> result_precision.txt