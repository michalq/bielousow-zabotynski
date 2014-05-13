#include "ReakcjaBZ.h"

ReakcjaBZ::ReakcjaBZ():
    plansza(Plansza()), q(2), k1(1), k2(1), g(0)
{
    srand(time(NULL));
    this->UstawDomyslne();
}

ReakcjaBZ::ReakcjaBZ(int m,int n):
    plansza(Plansza(m,n)), q(2), k1(1), k2(1), g(0)
{
    srand(time(NULL));
    this->UstawDomyslne();
}

ReakcjaBZ::ReakcjaBZ(int m,int n,int Q,int K1,int K2,int G):
    plansza(Plansza(m,n)), q(Q), k1(K1), k2(K2), g(G)
{
    srand(time(NULL));
    this->UstawDomyslne();
}

/**
 * Skrót do plansza.Get(...)
 * zwraca wartość podanej komórki
 */
int ReakcjaBZ::Get(int x,int y)
{
    this->plansza.Get(x,y);
}

/**
 * Wykonuje jeden cykl iteracji na planszy
 */
void ReakcjaBZ::Iteruj()
{
    for (int i = 0; i < this->plansza.Szerokosc(); i++)
    {
        for (int j = 0; j < this->plansza.Wysokosc(); j++)
        {
            // Komórka w stanie q zmienia swój stan na 1.
            if (this->Get(i,j) == this->q)
            {
                this->plansza.Set(i,j,1);
            } else
            // Komórka w stanie 1 zmienia swój stan na a/k1 + b/k2 +1,
            // gdzie a oznacza liczbę sąsiadów, którzy są w stanach od 2 do q-1, a b oznacza liczbę sąsiadów w stanie q.
            if (this->Get(i,j) == 1)
            {
                int a = this->plansza.liczSasiadow(i,j, 2, this->q - 1);
                int b = this->plansza.liczSasiadow(i,j, this->q);
                this->plansza.Set(i,j, ((a/this->k1) + (b/this->k2) +1) );
            } else
            // Komórka w stanie od 2 do q-1 zmienia stan na S/(9-c)+g,
            // gdzie S to suma stanów komórki oraz jej sąsiadów, a c oznacza liczbę sąsiadów w stanie 1.
            if (this->Get(i,j) >= 2 && this->Get(i,j) < this->q)
            {
                int S = this->plansza.sumaStanow(i,j);
                int c = this->plansza.liczSasiadow(i,j, 1);
                this->plansza.Set(i,j, ((S/(9-c))+this->g));
            }

            // Jeśli zastosowanie reguł doporowadziłoby komórkę do posiadania stanu większego,
            // niż q, to takiej komórce przypisuje się stan q.
            if (this->Get(i,j) > this->q)
            {
                this->plansza.Set(i,j,this->q);
            }
        }
    }

}

/**
 * Wyswietla plansze wypelniona pseudo kolorami
 */
void ReakcjaBZ::Wyswietl()
{
    this->plansza.Wyswietl();
}

/**
 * Ustawia domyslne wartosci tablicy, czyli pseudo losowe
 */
void ReakcjaBZ::UstawDomyslne()
{
    for (int i = 0; i < this->plansza.Szerokosc(); i++)
    {
        for (int j = 0; j < this->plansza.Wysokosc(); j++)
        {
            this->plansza.Set(i, j, (rand()%(this->q+1)));
        }
    }
}
