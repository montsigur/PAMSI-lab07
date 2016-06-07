// Wojciech Michałowski
// nr albumu 218705

#ifndef WEZEL_HPP
#define WEZEL_HPP
#include <iostream>
#include <string>
#include <vector>
#include "plansza.hpp"
using namespace std;

class wezel {
  
public:
  
  wezel* nadrzedny;
  vector<wezel*> podrzedne;
  plansza plansza_;
  bool prowadziDoPrzegranej;
  int waga;
  
  wezel(wezel* nadrzedny, plansza P);

  string wynik();

  bool porownaj(plansza P);
  
};

#endif
