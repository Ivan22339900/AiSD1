#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Przyrosty zgodnie z sugestią Sedgewicka
    for (gap = 1; gap < n / 3; gap = gap * 3 + 1);

    while (gap > 0) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // Przesuwanie elementów większych od temp o gap pozycji w lewo
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        // Zmniejszanie przyrostu
        gap /= 3;
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
