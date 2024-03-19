#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WARTOŚĆ 1000

void generuj_losowe_dane(int *dane, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        dane[i] = rand() % MAX_WARTOŚĆ + 1;
    }
}

void generuj_posortowane_dane(int *dane, int n, int rosnąco) {
    if (rosnąco) {
        for (int i = 0; i < n; i++) {
            dane[i] = i + 1;
        }
    } else {
        for (int i = 0; i < n; i++) {
            dane[i] = n - i;
        }
    }
}

void generuj_stałe_dane(int *dane, int n, int wartość) {
    for (int i = 0; i < n; i++) {
        dane[i] = wartość;
    }
}

void generuj_dane_kształtu_A(int *dane, int n) {
    int połowa_n = n / 2;
    for (int i = 0; i < połowa_n; i++) {
        dane[i] = i + 1;
        dane[n - i - 1] = połowa_n - i;
    }
}
