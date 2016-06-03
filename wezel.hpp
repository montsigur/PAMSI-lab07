#ifndef WEZEL_HPP
#define WEZEL_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class wezel {
  
public:
  
  wezel* nadrzedny;
  vector<wezel*> podrzedne;
  plansza plansza_;
  
  wezel(wezel* nadrzedny, plansza P);

  string wynik();

  bool porownaj(plansza P);
  
};

#endif
