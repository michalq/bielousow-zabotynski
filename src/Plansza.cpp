#include "Plansza.h"

Plansza::Plansza()
{
    // Tablica domyślna 10x10
    this->ekran = new int [100];
    //this->ekranS = new int [100];
    this->szer = 10;
    this->wys = 10;
}

Plansza::~Plansza()
{
    delete ekran;
    //delete ekranS;
}

Plansza::Plansza(int m,int n)
{
    this->ekran = new int [m*n];
    //this->ekranS = new int [m*n];
    this->szer = m;
    this->wys = n;
}

void Plansza::Wyswietl()
{
    int pol = this->szer * this->wys;
    for (int i = 0; i < pol; i++)
    {
        if ( ! (i%this->szer))
        {
            std::cout << "\n";
        }
        if (this->ekran[i] < 10)
            std::cout << Plansza::KOLOR[this->ekran[i]];
    }
}

int Plansza::Szerokosc()
{
    return this->szer;
}

int Plansza::Wysokosc()
{
    return this->wys;
}

void Plansza::Set(int x, int y, int k)
{
    int pos;
    if ((x+1) > this->szer || (y+1) > this->wys)
        std::cout << "OUT OF RANGE!";
    else
    {
        pos = (y*this->szer) + x;
        this->ekran[pos] = k;
        //this->ekranS[pos] += k;
    }
}

int Plansza::Get(int x,int y)
{
    if ((x+1) > this->szer || (y+1) > this->wys || x < 0 || y < 0)
    {
        return 0;
    }
    return this->ekran[(y*this->szer) + x];
}

/**
 * Zwraca sumę stanów na danym polu
 *
int Plansza::GetEkranS(int x,int y)
{
    if ((x+1) > this->szer || (y+1) > this->wys || x < 0 || y < 0)
    {
        return 0;
    }
    return this->ekranS[(y*this->szer) + x];
}*/

/**
 * Zwraca ilość sąsiadów dookoła punktu (x,y), których wartości zawierają się w 'od_'..'do_'
 */
int Plansza::liczSasiadow(int x, int y, int od_, int do_)
{
    int suma = 0;
    for (int i = x-1; i <= x+1; i++)
    {
        for (int j = y-1; j <= y +1; j++)
        {
            if ( (i != x || j != y) && (this->Get(i,j) >= od_ && this->Get(i,j) <= do_))
            {
                suma++;
            }
        }
    }
    return suma;
}
 /**
 * Zwraca ilość sąsiadów dookoła punktu (x,y), których wartości są równe 'rowne'
 */
int Plansza::liczSasiadow(int x, int y, int rowne)
{
    return this->liczSasiadow(x, y, rowne, rowne);
}

int Plansza::sumaStanow(int x, int y)
{
    int suma = 0;
    for (int i = x-1; i <= x+1; i++)
    {
        for (int j = y-1; j <= y +1; j++)
        {
            int test;
            //std::cout << "\n [ " << suma << " " << this->Get(i,j) << " " << i << " " << j << " ] \n";
            suma += this->Get(i,j);
        }
    }
    return suma;
}
