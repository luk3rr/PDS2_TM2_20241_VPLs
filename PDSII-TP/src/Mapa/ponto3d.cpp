#include "ponto3d.hpp"

//Implementação do Ponto3D
float Ponto3D::calcularDistancia(Ponto3D* p){
  float dx = p->coordenadaX;
  float dy = p->coordenadaY;
  float dz = p->coordenadaZ;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

void calculaOrigemAoPontoUnico(int valor){
  Ponto3D* p1 = new Ponto3D;
  p1->coordenadaX = 0;
  p1->coordenadaY = 0;
  p1->coordenadaZ = 0;

  Ponto3D* p2 = new Ponto3D;
  p2->coordenadaX = valor;
  p2->coordenadaY = valor;
  p2->coordenadaZ = valor;

  std::cout << p1->calcularDistancia(p2) << std::endl;

  delete p1;
  delete p2;
}
