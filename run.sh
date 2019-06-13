#!/bin/bash

clear

#create objects folder
if [ ! -d objects ]; then
    mkdir objects
fi

if [ ! -d binaries ]; then
    mkdir binaries
fi

cd objects
g++ -g -c ../sources/Fields.cpp;
g++ -g -c ../sources/WaveModeling.cpp;
g++ -g -c ../sources/main.cpp;
cd ..

cd binaries
g++ ../objects/*.o -o propagator
cd ..

binaries/propagator

if [ $1 ]; then
  clear

  if [ $1 = xmovie ]; then
    xmovie < output/wavefield.bin n1=128 n2=128 clip=5
  fi

  if [ $1 = clean ]; then
    rm -rfv objects binaries
  fi
fi
