#include "gra.hpp"
using namespace std;


int minimalnaWaga(vector<wezel*> aktualne) {

  unsigned int indeks = 0;

  for (unsigned int i=0; i<aktualne.size(); i++)
    if (aktualne[indeks]->waga < aktualne[i]->waga)
      indeks = i;

  return indeks;
}

int maksymalnaWaga(vector<wezel*> aktualne) {

  unsigned int indeks = 0;

  for (unsigned int i=0; i<aktualne.size(); i++)
    if (aktualne[indeks]->waga > aktualne[i]->waga)
      indeks = i;

  return indeks;
}

void heurystyka(wezel* nadrzedny, wezel* aktualny, int gracz) {

  int y, x;
  int waga = 0;
  
  for (int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if (nadrzedny->plansza_.pola(i, j) != aktualny->plansza_.pola(i, j))
	{ y = i; x = j; }

  if (aktualny->wynik() == string("nierozstrzygnieta")) {
  
    waga += abs(aktualny->plansza_.pola.block(y, 0, 1, 3).sum()) * 10;
    waga += abs(aktualny->plansza_.pola.block(0, x, 3, 1).sum()) * 10;
  
    if (x % 2 == 1 and y % 2 == 1) {
    
      waga += abs(aktualny->plansza_.pola.block(0, x, 3, 1).trace()) * 10;
      waga += abs(aktualny->plansza_.pola(2, 0) +
		  aktualny->plansza_.pola(1, 1) +
		  aktualny->plansza_.pola(0, 2)) * 10;
    
    }

    else if (x % 2 == 0 and y % 2 == 0) {
      if (x == y)
	waga += abs(aktualny->plansza_.pola.block(0, x, 3, 1).trace()) * 10;
      else
	waga += abs(aktualny->plansza_.pola(2, 0) +
		    aktualny->plansza_.pola(1, 1) +
		    aktualny->plansza_.pola(0, 2)) * 10;
    }
  }

  aktualny->waga = waga * gracz;
}

gra::gra(int graczPierwszy, int glebokoscPrzeszukiwan) {

  gra::graczPierwszy = graczPierwszy;

  cout << "Tworzenie drzewa gry..." << endl;
  
  generujDrzewo(drzewoGry.korzen, drzewoGry, graczPierwszy);

  // szukajTest(drzewoGry.korzen);
  
  int gracz = graczPierwszy;

  planszaGry.wyswietl();
  
  while (planszaGry.wynik == string("nierozstrzygnieta")) {

    if (gracz == 1)
      ruchKomputera(glebokoscPrzeszukiwan);

    else if (gracz == -1)
      ruchGracza();

    planszaGry.wyswietl();
    gracz = gracz * (-1);

  }

  cout << endl << "wynik: " << planszaGry.wynik;
  
}

void gra::nowaGra(int graczPierwszy, int glebokoscPrzeszukiwan) {

  gra::graczPierwszy = graczPierwszy;
  int gracz = graczPierwszy;

  planszaGry.wyczysc();
  
  planszaGry.wyswietl();
  
  while (planszaGry.wynik == string("nierozstrzygnieta")) {

    if (gracz == 1)
      ruchKomputera(glebokoscPrzeszukiwan);

    else if (gracz == -1)
      ruchGracza();

    planszaGry.wyswietl();
    gracz = gracz * (-1);

  }

  cout << endl << "wynik: " << planszaGry.wynik;

}

void gra::ruchGracza() {

  string ruch;
  int i, j;

  cout << endl;
  
  do {
    
  cout << "Twoj ruch: ";
  cin >> ruch;

  i = stoi(ruch.substr(0, 1));
  j = stoi(ruch.substr(1, 1));

  } while(!planszaGry.wstaw(i, j, -1));

}

void szukajKonca(wezel* w, wezel* &wybrany, int glebokosc) {

  vector<wezel*> aktualne, podrzedne;
  wezel* sprawdzany;
  int poziom = glebokosc;
  int gracz = 1;

  aktualne = w->podrzedne;
  
  while (aktualne.size() > 0 and poziom-- > 0) {
  
    for (wezel* aktualny : aktualne) {

      	if (wybrany == NULL and aktualny->wynik() == string("remis"))
	  wybrany = aktualny;
	
	else if (aktualny->wynik() == string("wygrana"))
	  { wybrany = aktualny; return;	}

	else if (aktualny->wynik() == string("przegrana"))
	  continue;
      
      for (wezel* podrzedny : aktualny->podrzedne) {

	heurystyka(aktualny, podrzedny, gracz);
	podrzedne.push_back(podrzedny);
	
	if (podrzedny->wynik() == string("przegrana") and
	    podrzedny->nadrzedny->wynik() != string("wygrana")) {
        
	  aktualny->prowadziDoPrzegranej = true;
	
	  if (wybrany != NULL and wybrany->nadrzedny == aktualny)
	    wybrany = NULL;

	  unsigned int rozmiar = podrzedne.size();
	  
	  for (unsigned int i=0; i<rozmiar; i++) {
	    for (unsigned int j=0; j<podrzedne.size(); j++) {
	      sprawdzany = podrzedne[j];
	      if (sprawdzany->nadrzedny == aktualny) {
		podrzedne.erase(podrzedne.begin() + j);
		break;
	      }
	    }
	  }
	  break;
	}
      }
    }

    gracz = gracz * (-1);
    aktualne = podrzedne;
    podrzedne.clear();
  }
  
  if (wybrany == NULL) {

    poziom = glebokosc;
    gracz = 1;
    aktualne.clear();
    podrzedne.clear();
    int indeks;
    
    for (unsigned int i=0; i<w->podrzedne.size(); i++)
      if (!w->podrzedne[i]->prowadziDoPrzegranej)
	aktualne.push_back(w->podrzedne[i]);
    
    while (aktualne.size() > 0 and poziom-- > 0) {

      if (gracz == 1)
	indeks = maksymalnaWaga(aktualne);
      else if (gracz == -1)
	indeks = minimalnaWaga(aktualne);

      wybrany = aktualne[indeks];

      for (unsigned int i=0; i<wybrany->podrzedne.size(); i++)
	if (!wybrany->podrzedne[i]->prowadziDoPrzegranej)
	  podrzedne.push_back(wybrany->podrzedne[i]);

      // if (podrzedne.size() == 0)
      // 	{ wybrany->nadrzedny->prowadziDoPrzegranej = true;
      // 	  aktualne.clear();
      // 	  for (unsigned int i=0; i<wybrany->nadrzedny->nadrzedny->podrzedne.size(); i++)
      // 	    if (!wybrany->nadrzedny->nadrzedny->podrzedne[i]->prowadziDoPrzegranej)
      // 	      aktualne.push_back(wybrany->nadrzedny->nadrzedny->podrzedne[i]);
      // 	  continue; }
      
      aktualne = podrzedne;
      podrzedne.clear();

      gracz = gracz * (-1);
	  
    }
  }
}

void szukajPoczatku(wezel* w, wezel* &wybrany, plansza planszaGry) {

  for (wezel* w_ : w->podrzedne)
    szukajPoczatku(w_, wybrany, planszaGry);

  if (w->porownaj(planszaGry))
    wybrany = w;
}

void gra::ruchKomputera(int glebokoscPrzeszukiwan) {

  wezel *poczatek, *koniec = NULL, *nastepnyRuch;
  plansza pusta;

  srand(time(NULL));

  szukajPoczatku(drzewoGry.korzen, poczatek, planszaGry);
  cout << "znalazlem poczatek" << endl;
  
  if (poczatek->porownaj(pusta) or poczatek->podrzedne.size() == 8)
    if(!planszaGry.wstaw(1, 1, 1))
      planszaGry.wstaw(2 * rand() % 2, 2 * rand() % 2, 1);
    else;
  
  else {
    
    szukajKonca(poczatek, koniec, glebokoscPrzeszukiwan);
    
    nastepnyRuch = koniec;

    cout << "zwrocilem koniec" << endl;

    if (koniec == NULL)
      cout << "koniec nie istnieje" << endl;
    else
      cout << "koniec istnieje" << endl;
    
    while (nastepnyRuch->nadrzedny != poczatek)
      nastepnyRuch = nastepnyRuch->nadrzedny;

    planszaGry = nastepnyRuch->plansza_;
    
  }
}
