// Wojciech Michałowski
// nr albumu 218705

#include "wezel.hpp"
using namespace std;

wezel::wezel(wezel* nadrzedny, plansza P) {

  wezel::nadrzedny = nadrzedny;
  prowadziDoPrzegranej = false;
  plansza_ = P;

}

string wezel::wynik() {

  return plansza_.wynik;

}

bool wezel::porownaj(plansza P) {

  return plansza_.porownaj(P);
  
}
