#ifndef WEZEL_HPP
#define WEZEL_HPP
#include "wezel.hpp"
using namespace std;

class drzewo {

public:

  wezel* korzen;

  drzewo();

  wezel* dodajWezel(wezel* nadrzedny, plansza P);

};

#endif
