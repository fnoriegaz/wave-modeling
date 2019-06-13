# wave-modeling

## Description
C++ implementation of the acoustic wave equation with constant density.
It creates and uses a ricker wavelet to simulated pressure wavefield over a
constant velocity model.

## Requirements
G++ compiler.
It is recommended to install Seismic Unix to visualize the output file
(.bin file) by using this program. Otherwise use any software of your preference
(e.g. MatLab, Python, etc.).

## Usage
Download all the files and then:

#### Compile, execute and create output:
>./run_sh

#### Compile, execute, create output and visualize using Seismic Unix:
>./run.sh xmovie

#### Delete output, binaries and objects folders:
>./run.sh clean
