#include "gra.hpp"

int main() {

  int graczPierwszy;
  int glebokoscPrzeszukiwan;
  cout << "Kto pierwszy? 1 - komputer, -1 - człowiek: ";
  cin >> graczPierwszy;

  cout << "Glebokosc przeszukiwan drzewa gry ([1, 9]): ";
  cin >> glebokoscPrzeszukiwan;
  
  gra G(graczPierwszy, glebokoscPrzeszukiwan);
  int wybor;

  do {

    cout << endl << "Nowa gra? (<=0 - nie, >0 - tak)" << endl;
    cin >> wybor;

    cout << "Glebokosc przeszukiwan drzewa gry ([1, 9]): ";
    cin >> glebokoscPrzeszukiwan;

    if (wybor > 0)
      G.nowaGra(graczPierwszy, glebokoscPrzeszukiwan);

  } while (wybor != 0);
  
  return 0;

}
