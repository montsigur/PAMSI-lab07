#include "wezel.hpp"
using namespace std;

wezel::wezel(wezel* nadrzedny, plansza P) {

  wezel::nadrzedny = nadrzedny;
  plansza_ = P;

}

string wezel::wynik() {

  return plansza_.wynik();

}

bool wezel::porownaj(plansza P) {

  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (plansza_[i][j] != P[i][j])
	return false;

  return true;
}
