#!/bin/sh
mpicc -o piEstimator piEstimator.c -fopenmp
~/piEstimator 10000024 1