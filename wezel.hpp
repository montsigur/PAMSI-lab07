#ifndef WEZEL_HPP
#define WEZEL_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class wezel {

  plansza P;
  
public:

  wezel(wezel* nadrzedny, plansza P);

  string wynik();

  bool porownaj(plansza P);
  
  wezel* nadrzedny;
  vector<wezel*> podrzedne;
  
};

#endif
