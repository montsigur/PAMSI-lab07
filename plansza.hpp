#ifndef PLANSZA_HPP
#define PLANSZA_HPP
#include <string>
#include <vector>

class plansza {

  vector< vector<string> > pola;
  
  string obliczWynik();
  
public:

  string wynik;
  
  plansza();

  bool wstaw(int y, int x, string symbol);

};

#endif
