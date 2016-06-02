#include "plansza.hpp"
using namespace std;

plansza::plansza() {

  for (int i=0; i<3; i++) {
    
    pola.push_back(new vector<string>);
    for (int j=0; j<3; j++)
      pola[i].push_back("null");

  }  
}

string plansza::wynik() {

  symbol = pola[1][1];
  
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (i != 1 or j != 1)
	if (symbol != string("null"))
	  if ((pola[i][j] == symbol and
	       pola[2-i][2-j] == symbol) or
	      (pola[i][0] == symbol and
	       pola[i][1] == symbol and
	       pola[i][2] == symbol) or
	      (pola[0][j] == symbol and
	       pola[1][j] == symbol and
	       pola[2][j] == symbol))
	    if (symbol == string("X"))
	      return string("przegrana");
	    else if (symbol == string("O"))
	      return string("wygrana");
	    else;
	  else;
	else if ((pola[i][0] == string("X") and
		  pola[i][1] == string("X") and
		  pola[i][2] == string("X")) or
		 (pola[0][j] == string("X") and
		  pola[1][j] == string("X") and
		  pola[2][j] == string("X")))
	  return string("przegrana");
	else if ((pola[i][0] == string("O") and
		  pola[i][1] == string("O") and
		  pola[i][2] == string("O")) or
		 (pola[0][j] == string("O") and
		  pola[1][j] == string("O") and
		  pola[2][j] == string("O")))
	  return string("wygrana");
	else if (pola[i][j] == "null")
	  puste_pole = true;

  if (puste_pole)
    return string("nierozstrzygnieta");
  else
    return string("remis");
}
