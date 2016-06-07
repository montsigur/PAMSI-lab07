// Wojciech Michałowski
// nr albumu 218705

#include "gra.hpp"

int main() {

  int graczPierwszy;
  int glebokoscPrzeszukiwan;
  cout << "Kto pierwszy? <=0 - człowiek, >0 komputer: ";
  cin >> graczPierwszy;

  if (graczPierwszy <= 0)
    graczPierwszy = -1;

  else
    graczPierwszy = 1;

  cout << "Glebokosc przeszukiwan drzewa gry ([1, 9]): ";
  cin >> glebokoscPrzeszukiwan;
  if (glebokoscPrzeszukiwan < 1) {
    glebokoscPrzeszukiwan = 1;
    cout << "Ustawiono glebokosc przeszukiwan = 1" << endl;
  }

  else if (glebokoscPrzeszukiwan > 9) {
    glebokoscPrzeszukiwan = 9;
    cout << "Ustawiono glebokosc przeszukiwan = 9" << endl;
  }
  
  gra G(graczPierwszy, glebokoscPrzeszukiwan);
  int wybor;

  do {

    cout << endl << "Nowa gra? (<=0 - nie, >0 - tak)" << endl;
    cin >> wybor;

    if (wybor > 0) {
      cout << "Glebokosc przeszukiwan drzewa gry ([1, 9]): ";
      cin >> glebokoscPrzeszukiwan;
      if (glebokoscPrzeszukiwan < 1) {
	glebokoscPrzeszukiwan = 1;
	cout << "Ustawiono glebokosc przeszukiwan = 1" << endl;
      }
      
      else if (glebokoscPrzeszukiwan > 9) {
	glebokoscPrzeszukiwan = 9;
	cout << "Ustawiono glebokosc przeszukiwan = 9" << endl;
      }
      G.nowaGra(graczPierwszy, glebokoscPrzeszukiwan);
    }

  } while (wybor != 0);
  
  return 0;

}
