tictac: main.cpp wezel.cpp drzewo.cpp plansza.cpp generujDrzewo.cpp gra.cpp
	g++ -std=c++11 -o tictac main.cpp wezel.cpp drzewo.cpp \
	plansza.cpp generujDrzewo.cpp gra.cpp

clean:
	rm -f tictac
