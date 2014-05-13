#ifndef REAKCJABZ_H
#define REAKCJABZ_H

#include <time.h>
#include "Plansza.h"

class ReakcjaBZ {
  private:
    Plansza plansza;
    int q; // 2..250
    int k1,k2; // 1..8
    int g; // 0..100

    void UstawDomyslne();
  public:
    ReakcjaBZ();
    ReakcjaBZ(int m,int n);
    ReakcjaBZ(int m,int n,int Q,int K1,int K2,int G);
    int Get(int x,int y);
    void Iteruj();
    void Wyswietl();
};

#endif // REAKCJABZ_H
