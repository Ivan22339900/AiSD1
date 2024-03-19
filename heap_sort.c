#include <stdio.h>

// Funkcja zamieniająca dwa elementy tablicy
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja, która przekształca tablicę w kopiec
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicjalizacja największego elementu jako korzeń
    int l = 2 * i + 1; // Indeks lewego dziecka
    int r = 2 * i + 2; // Indeks prawego dziecka

    // Jeśli lewe dziecko jest większe niż korzeń
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Jeśli prawe dziecko jest większe niż korzeń
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Jeśli największy element nie jest korzeniem
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Rekurencyjnie przekształć poddrzewo dotknięte największym elementem
        heapify(arr, n, largest);
    }
}

// Główna funkcja implementująca algorytm sortowania kopców
void heapSort(int arr[], int n) {
    // Budowanie kopca (od dołu)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wyciąganie elementów z kopca
    for (int i = n - 1; i > 0; i--) {
        // Przesuń korzeń do końca
        swap(&arr[0], &arr[i]);

        // Wywołaj heapify na zmniejszonym kopcu
        heapify(arr, i, 0);
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

    heapSort(arr, n);

    printf("Posortowana tablica: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
