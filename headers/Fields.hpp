#ifndef FIELDS_H
#define FIELDS_H

#include<vector>

class Fields{

public:
  int _cols, _rows;
  float _deltaX, _deltaZ, _deltaT;
  float *P, *P1;
  float *d2PdX2, *d2PdZ2, *d2Pdt2;


  Fields(int cols, int rows, float deltaX, float deltaZ, float deltaT);
  void laplacian();
  void timeDVTV(float *velocity);
  void addSource(std::vector<float> wavelet, int sx, int sz, int it);

};

#endif
