#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja zamieniająca dwa elementy w tablicy
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja naprawiająca kopiec o korzeniu w indeksie i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Algorytm Heap Sort
void heapSort(int arr[], int n) {
    // Tworzenie kopca
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Wyjmowanie elementów z kopca i sortowanie
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Funkcja dzieląca tablicę w algorytmie Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left] <= pivot)
            left++;
        while (left <= right && arr[right] > pivot)
            right--;
        if (left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    swap(&arr[low], &arr[right]);
    return right;
}

// Algorytm Quick Sort z wyborem klucza/pivota jako skrajnie lewego elementu
void quickSortLeftPivot(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortLeftPivot(arr, low, pivot - 1);
        quickSortLeftPivot(arr, pivot + 1, high);
    }
}

// Algorytm Quick Sort z wyborem losowego elementu jako pivota
void quickSortRandomPivot(int arr[], int low, int high) {
    if (low < high) {
        // Wybór losowego pivota
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[low]);
        int pivot = partition(arr, low, high);
        quickSortRandomPivot(arr, low, pivot - 1);
        quickSortRandomPivot(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Heap Sort
    heapSort(arr, n);
    printf("Sorted array using Heap Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Quick Sort with Left Pivot
    quickSortLeftPivot(arr, 0, n - 1);
    printf("Sorted array using Quick Sort with Left Pivot: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Quick Sort with Random Pivot
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych
    int arr2[] = {12, 11, 13, 5, 6, 7}; // Resetowanie tablicy
    quickSortRandomPivot(arr2, 0, n - 1);
    printf("Sorted array using Quick Sort with Random Pivot: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
