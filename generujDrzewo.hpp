#include "drzewo.hpp"
using namespace std;

void generujDrzewo(wezel* nadrzedny, drzewo &D, string gracz) {

  plansza P = nadrzedny->plansza_;
  wezel* w;
  
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (P.wstaw(i, j, gracz)) {
	w = D.dodajWezel(nadrzedny, P);
	if (gracz == string("X")) gracz = string("O");
	else gracz = string("X");
	generujDrzewo(w, D, gracz);
      }
}
