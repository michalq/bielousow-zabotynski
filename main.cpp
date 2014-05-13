#include <iostream>
#include <Plansza.h>
#include <ReakcjaBZ.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    // 20, 40, 9, 2, 3, 4
    ReakcjaBZ rk = ReakcjaBZ(20, 40, 9, 2, 3, 3);
    for (int i = 0; i < 100; i++)
    {
        rk.Iteruj();
        ///*
        system("clear");
        rk.Wyswietl();
        sleep(100000);
        //*/
    }
    //system("clear");
    rk.Wyswietl();
    return 0;
}
