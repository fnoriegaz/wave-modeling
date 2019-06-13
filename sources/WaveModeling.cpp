#include<iostream>
#include<cstring>


#include"../headers/WaveModeling.hpp"


WaveModeling::WaveModeling(int cols, int rows, float deltaX, float deltaZ,
  float deltaT, int tSamples){
    _cols=cols;
    _rows=rows;
    _deltaX=deltaX;
    _deltaZ=deltaZ;
    _deltaT=deltaT;
    _tSamples=tSamples;

    velocity = new float[_cols*_rows];
    wavefield = new float[_cols*_rows*_tSamples];

    for(int i=0;i<(_cols);i++){
      for(int j=0;j<(_rows);j++){
        velocity[j+i*_rows]=5000.0;
      }
    }


  }


void WaveModeling::stepForward(Fields frwdFields, std::vector<float> wavelet,
int sx, int sz){

  int idx;
  for(int it=0;it<_tSamples;it++){
    frwdFields.laplacian();
    frwdFields.timeDVTV(velocity);
    frwdFields.addSource(wavelet,sx,sz,it);

    for(int i=0;i<(_cols);i++){
      for(int j=0;j<(_rows);j++){
        idx=j+i*_rows;
        frwdFields.P1[idx] = 2*frwdFields.P[idx] - frwdFields.P1[idx] +
                      _deltaT*_deltaT*velocity[idx]*velocity[idx]*(
                      frwdFields.d2PdX2[idx] + frwdFields.d2PdZ2[idx]);
      }
    }

    float *tempPtr = frwdFields.P1;
    frwdFields.P1 = frwdFields.P;
    frwdFields.P = tempPtr;

    memcpy(wavefield+it*_cols*_rows,frwdFields.P1,_cols*_rows*sizeof(float));

  }

}
