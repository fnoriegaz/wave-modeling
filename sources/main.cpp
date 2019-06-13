#include<fstream>
#include<cmath>

#include"../headers/Fields.hpp"
#include"../headers/WaveModeling.hpp"


int main() {

  int cols=128;
  int rows=128;
  int tSamples=3000;
  float deltaX = 25.0;
  float deltaZ = 25.0;
  float deltaT = 1.0e-3;

  //creating the wavelet used to modeling pressure wavefield. Ricker wavelet
  int sx = 64; //horizontal position of the source
  int sz = 64; //vertical(in sdepth) position of the source
  float freq = 3.0; //frequency in Hz
  float a = M_PI*M_PI*freq*freq;
  float A;
  std::vector<float> wavelet;
  for(auto t=0;t<tSamples;t++){
    A=(1-2*a*t*t*deltaT*deltaT)*exp(-a*t*t*deltaT*deltaT);
    wavelet.push_back(A);
  }

  WaveModeling forwardModeling(cols,rows,deltaX,deltaZ,deltaT,tSamples);
  Fields forwardFields(cols,rows,deltaX,deltaZ,deltaT);

  forwardModeling.stepForward(forwardFields,wavelet,sx,sz);

  std::ofstream fid;
  fid.open("output/wavefield.bin", std::ios_base::binary);
  fid.write((char *)forwardModeling.wavefield,cols*rows*tSamples*sizeof(float));
  fid.close();



  return 0;
}
