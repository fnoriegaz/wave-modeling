#ifndef WAVEMOD_H
#define WAVEMOD_H

#include"Fields.hpp"

class WaveModeling{

public:
  int _cols, _rows, _tSamples;
  float _deltaX, _deltaZ, _deltaT;
  float *velocity, *wavefield;


  WaveModeling(int cols, int rows, float deltaX, float deltaZ, float deltaT,
              int tSamples);
  void stepForward(Fields frwdFields);


};

#endif
