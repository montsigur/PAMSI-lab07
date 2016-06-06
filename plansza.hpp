#ifndef PLANSZA_HPP
#define PLANSZA_HPP
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Eigen/Eigen"
using namespace std;
using namespace Eigen;

class plansza {
  
  string obliczWynik();
  
public:

  string wynik;

  Matrix3i pola;
  
  plansza();

  void wyswietl();

  void wyczysc();

  bool porownaj(plansza P);

  bool wstaw(int y, int x, int symbol);

};

#endif
