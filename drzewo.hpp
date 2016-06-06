#ifndef DRZEWO_HPP
#define DRZEWO_HPP
#include "wezel.hpp"
using namespace std;

class drzewo {

public:

  wezel* korzen;

  drzewo();

  wezel* dodajWezel(wezel* nadrzedny, plansza P);

};

#endif
