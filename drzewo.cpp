#include "drzewo.hpp"
using namespace std;

drzewo::drzewo() {

  plansza P;
  korzen = new wezel(NULL, P);
  
}

wezel* drzewo::dodajWezel(wezel* nadrzedny, plansza P) {

  wezel* w = new wezel(nadrzedny, P)
  nadrzedny.podrzedne.push_back();
  return w;

}
