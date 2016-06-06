#include "plansza.hpp"
using namespace std;

plansza::plansza() {

  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      pola(i, j) = 0;

  wynik = string("nierozstrzygnieta");
}

void plansza::wyczysc() {
  
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      pola(i, j) = 0;
  
  wynik = string("nierozstrzygnieta");

}

bool plansza::wstaw(int y, int x, int symbol) {

  if (pola(y, x) == 0) {

    pola(y, x) = symbol;
    wynik = obliczWynik();
    return true;

  }

  else
    return false;

}

bool plansza::porownaj(plansza P) {

  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (pola(i, j) != P.pola(i, j))
	return false;
  
  return true;

}

string plansza::obliczWynik() {

  bool puste_pole = false;

  for (int i=0; i<3; i++)

    if (pola.block(i, 0, 1, 3).sum() == 3 or	
	pola.block(0, i, 3, 1).sum() == 3 or
	pola.trace() == 3 or
	pola(2, 0) + pola (1, 1) + pola(0, 2) == 3)
      return string("wygrana");
  
    else if (pola.block(i, 0, 1, 3).sum() == -3 or	
	     pola.block(0, i, 3, 1).sum() == -3 or
	     pola.trace() == -3 or
	     pola(2, 0) + pola (1, 1) + pola(0, 2) == -3)
      return string("przegrana");
  
    else if (pola.prod() == 0)
      puste_pole = true;
    
  if (puste_pole)
    return string("nierozstrzygnieta");
  else
    return string("remis");
}

void plansza::wyswietl() {

  system("clear");

  char symbole[3][2] = {"X", " ", "O"};
  
  cout << "     |     |" << endl
       << "  " << symbole[pola(0, 0) + 1] << "  |  "
       << symbole[pola(0, 1) + 1]  << "  |  " << symbole[pola(0, 2) + 1]
       << endl << "_____|_____|_____" << endl << "     |     |" << endl
       << "  " << symbole[pola(1, 0) + 1] << "  |  " << symbole[pola(1, 1) + 1]
       << "  |  " << symbole[pola(1, 2) + 1] << endl
       << "_____|_____|_____" << endl << "     |     |" << endl
       << "  " << symbole[pola(2, 0) + 1] << "  |  " << symbole[pola(2, 1) + 1]
       << "  |  " << symbole[pola(2, 2) + 1] << endl
       << "     |     |" << endl;
    
}
