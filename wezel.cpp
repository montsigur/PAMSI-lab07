#include "wezel.hpp"
using namespace std;

wezel::wezel(wezel* nadrzedny, plansza P) {

  wezel::nadrzedny = nadrzedny;
  wezel::P = P;

}

wezel::wynik() {

  return P.wynik();

}

bool wezel::porownaj(plansza P) {

  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (wezel::P[i][j] != P[i][j])
	return false;

  return true;
}
