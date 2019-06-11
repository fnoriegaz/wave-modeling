#include<iostream>
#include<fstream>
#include<cstring>

#include"Fields.hpp"
#include"WaveModeling.hpp"


int main() {

  int cols=128;
  int rows=128;
  int tSamples=2000;
  float deltaX = 25.0;
  float deltaZ = 25.0;
  float deltaT = 1.0e-3;

  WaveModeling forwardModeling(cols,rows,deltaX,deltaZ,deltaT,tSamples);
  Fields forwardFields(cols,rows,deltaX,deltaZ,deltaT);

  forwardModeling.stepForward(forwardFields);

  std::ofstream fid;
  fid.open("wavefield.bin", std::ios_base::binary);
  fid.write((char *)forwardModeling.wavefield,cols*rows*tSamples*sizeof(float));
  fid.close();
  
  return 0;
}
