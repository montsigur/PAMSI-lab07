#include "generujDrzewo.hpp"
using namespace std;

void generujDrzewo(wezel* nadrzedny, drzewo &D, int gracz) {

  plansza P_nadrzedna;
  int nastepnyGracz;
  
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      P_nadrzedna.wstaw(i, j, nadrzedny->plansza_.pola(i, j));
    
  wezel* w;
    
  if (P_nadrzedna.wynik == string("nierozstrzygnieta"))
    for (int i=0; i<3; i++)
      for (int j=0; j<3; j++) {
	  
	plansza P = P_nadrzedna;
	  
	if (P.wstaw(i, j, gracz)) {
	  w = D.dodajWezel(nadrzedny, P);
	  if (gracz == 1) nastepnyGracz = -1;
	  else nastepnyGracz = 1;
	  generujDrzewo(w, D, nastepnyGracz);
	}
      }
}
