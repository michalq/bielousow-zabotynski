#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>

/**
 *
 * Pozycje x oraz y podajemy od zera więc, przy tablicy x na y
 * pierwsza pozycja to (0,0)
 * ostatnia (x-1, y-1)
 *
 * Metoda GetEkranS oraz pole ekranS, było do zliczania i przechowywania
 * sumy wszystkich stanów w danej komórce, chyba nie było wcale potrzebne,
 * bo nie o taką sumę chodziło, ale zostawiłem zakomentowane na wszelki wypadek.
 *
 */

class Plansza{
private:
    /**
     * Tablica przechowująca aktualny stan
     */
    int *ekran;
    /**
     * Tablica przechowująca sumę wszystkich stanów (?)
     *
    int *ekranS;*/
    /**
     * Szerokość planszy
     */
    int szer;
    /**
     * Wysokość planszy
     */
    int wys;
    /**
     * Tablica przechowująca znaki reprezentujące kolor
     */
     const char KOLOR[10] = {' ','.',':','o','n','m','z','x','X','#'};
  public:
    Plansza();
    Plansza(int m,int n);
    ~Plansza();
    void Wyswietl();
    int Szerokosc();
    int Wysokosc();
    void Set(int x,int y,int k);
    int Get(int x,int y);
    //int GetEkranS(int x, int y);
    int liczSasiadow(int x, int y, int od_, int do_);
    int liczSasiadow(int x, int y, int rowne);
    int sumaStanow(int x, int y);
};

#endif // PLANSZA_H
