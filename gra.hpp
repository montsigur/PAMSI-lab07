#ifndef GRA_HPP
#define GRA_HPP
#include <ctime>
#include "generujDrzewo.hpp"

class gra {

  int graczPierwszy;
  drzewo drzewoGry;
  plansza planszaGry;
  
public:

  gra(int graczPierwszy, int glebokoscPrzeszukiwan);

  void nowaGra(int graczPierwszy, int glebokoscPrzeszukiwan);

  void ruchKomputera(int glebokoscPrzeszukiwan);

  void ruchGracza();

};

#endif
