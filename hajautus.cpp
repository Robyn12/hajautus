// hajautus.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this is O(nlogn) efficient sorting algorithm
// By Robyn12

#include <iostream>

void tulosta(int ** taulukko, int koko) {
    int* ptr = *taulukko;
    for (int i = 0; i < koko; i++) {
        printf("%d,", *(ptr+i));
    }
    printf("\n");
    return;
}
void lomita(int** taulukko, int a1, int b1, int a2, int b2) {
    int a = a1;
    int b = b2;
    int* size = &b;
    int* apu = new int[*size];
    int* ptr = *taulukko;
    for (int i = a; i < b+1; i++) {
        if (a2 > b2 || (a1 <= b1 && ptr[a1] <= ptr[a2])) {
            apu[i] = ptr[a1];
            a1 += 1;
        }
        else {
            apu[i] =ptr[a2];
            a2 += 1;
        }
    }
    for (int i = a; i < b+1; i++) {
        ptr[i] = apu[i];
    }
    return;
}
void jarjesta(int ** taulukko, int a, int b) {
    int* ptr = *taulukko;

    if (a == b) {
        return;
    }
    int k = (a + b) / 2;
    jarjesta(taulukko, a, k);
    jarjesta(taulukko, k + 1, b);
    lomita(taulukko, a, k, k + 1, b);
    tulosta(taulukko, 10);
}

int main()
{
    int koko = 10;
    int* taulukko = (int*) malloc(11*sizeof(int));
    taulukko[0] = 1;
    taulukko[1] = 0;
    taulukko[2] = 5;
    taulukko[3] = 4;
    taulukko[4] = 10;
    taulukko[5] = 8;
    taulukko[6] = 3;
    taulukko[7] = 2;
    taulukko[8] = 1;
    taulukko[9] = 11;
    taulukko[10] = NULL;
    tulosta(&taulukko, koko);
    jarjesta(&taulukko, 0, koko-1);
    tulosta(&taulukko, koko);
    return 0;
}
