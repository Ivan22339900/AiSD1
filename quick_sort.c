#include <stdio.h>

// Funkcя, которая zamеняет значения двух переменных
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Funkcя, которая принимает последний элемент в качестве основы,
// помещает основу на правильное место в отсортированном массиве
// и помещает меньшие элементы (меньше основы) слева от основы
// и большие элементы (больше основы) справа от основы
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Основа
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен основе
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[low]);
    return (i + 1);
}

// Основная функция, которая реализует алгоритм быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - это индекс разделителя, arr[pi] - находится уже на правильном месте
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед разделителем и после разделителя
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    printf("Posortowana tablica: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
