#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Iteracja po tablicy
    for (i = 0; i < n - 1; i++) {
        // Znalezienie indeksu najmniejszego elementu w pozostałej części tablicy
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Zamiana najmniejszego elementu z elementem na aktualnej pozycji
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int n;
    printf("Podaj liczbę elementów w tablicy: ");
    scanf("%d", &n);

    int arr[n];
    printf("Podaj elementy tablicy: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nieposortowana tablica: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Posortowana tablica: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
