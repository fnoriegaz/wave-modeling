#include<iostream>
#include"Fields.hpp"

Fields::Fields(int cols, int rows, float deltaX, float deltaZ, float deltaT){

  _cols=cols;
  _rows=rows;
  _deltaX=deltaX;
  _deltaZ=deltaZ;
  _deltaT=deltaT;

  P = new float[_cols*_rows];
  P1 = new float[_cols*_rows];
  d2PdX2 = new float[_cols*_rows];
  d2PdZ2 = new float[_cols*_rows];
  d2Pdt2 = new float[_cols*_rows];

  for(int i=0;i<(_cols);i++){
    for(int j=0;j<(_rows);j++){
      P[j+i*_rows]=0.0;
      P1[j+i*_rows]=0.0;
    }
  }

  P[_rows/2+_cols*_rows/2]=10.0;

}


void Fields::laplacian(){

  int idx;
  for(int i=1;i<(_cols-1);i++){
    for(int j=1;j<(_rows-1);j++){
      idx=j+i*_rows;
      d2PdX2[idx] = (P[idx-1*_rows] - 2*P[idx]
                  + P[idx+1*_rows])/(_deltaX*_deltaX);
      d2PdZ2[idx] = (P[idx-1] - 2*P[idx]
                  + P[idx+1])/(_deltaZ*_deltaZ);
    }
  }

}


void Fields::timeDVTV(float *velocity){

  int idx;
  for(int i=1;i<(_cols-1);i++){
    for(int j=1;j<(_rows-1);j++){
      idx=j+i*_rows;
      d2Pdt2[idx] = velocity[idx]*velocity[idx]*(d2PdX2[idx] + d2PdZ2[idx]);
    }
  }

}
