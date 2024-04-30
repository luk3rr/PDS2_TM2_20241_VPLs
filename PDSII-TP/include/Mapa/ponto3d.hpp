#ifndef PONTO3D_H
#define PONTO3D_H

#include <cmath>
#include <iostream>

//Inclusão do Ponto3D
struct Ponto3D {
  float coordenadaX;
  float coordenadaY;
  float coordenadaZ;

  float calcularDistancia(Ponto3D* p);
};

void calculaOrigemAoPontoUnico(int valor);

#endif