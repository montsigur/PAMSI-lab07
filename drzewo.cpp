#include "drzewo.hpp"
using namespace std;

void drzewo::dodajWezel(wezel* nadrzedny, plansza P) {

  nadrzedny.podrzedne.push_back(new wezel(nadrzedny, P));

}
