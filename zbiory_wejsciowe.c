#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja generująca n-elementowy losowy ciąg danych
void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Zakres liczb losowych: 0-999
    }
}

// Funkcja generująca n-elementowy rosnący ciąg danych
void generate_sorted_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Funkcja generująca n-elementowy malejący ciąg danych
void generate_reverse_sorted_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Funkcja generująca n-elementowy stały ciąg danych
void generate_constant_array(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        arr[i] = value;
    }
}

// Funkcja generująca n-elementowy A-kształtny ciąg danych
void generate_a_shaped_array(int arr[], int n) {
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        arr[i] = i * 2 + 1; // Ciąg rosnący
    }
    for (int i = half; i < n; i++) {
        arr[i] = (half - (i - half)) * 2; // Ciąg malejący
    }
}

// Funkcja wyświetlająca tablicę
void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    int n = 10; // Rozmiar tablicy
    int arr[n]; // Tablica wejściowa

    // Generowanie i wyświetlanie różnych typów zbiorów danych
    printf("Random array: ");
    generate_random_array(arr, n);
    display_array(arr, n);

    printf("Sorted array: ");
    generate_sorted_array(arr, n);
    display_array(arr, n);

    printf("Reverse sorted array: ");
    generate_reverse_sorted_array(arr, n);
    display_array(arr, n);

    printf("Constant array: ");
    generate_constant_array(arr, n, 5); // Stała wartość: 5
    display_array(arr, n);

    printf("A-shaped array: ");
    generate_a_shaped_array(arr, n);
    display_array(arr, n);

    return 0;
}
