#!/bin/bash

clear
g++ -g -c Fields.cpp;
g++ -g -c WaveModeling.cpp;
g++ -g -c main.cpp;

g++ main.o WaveModeling.o Fields.o -o propagator
./propagator
xmovie < wavefield.bin n1=128 n2=128
