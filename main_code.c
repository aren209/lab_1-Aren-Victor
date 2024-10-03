#include <stdio.h>
#include <stdlib.h>
#include "function_1.h"
#include "function_2.h"

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int *arr = NULL;
    int n = 0;
    int temp;

    while (fscanf(file, "%d", &temp) == 1) {
        arr = realloc(arr, (n + 1) * sizeof(int));
        arr[n++] = temp;
    }
    fclose(file);

    sortAscending(arr, n);
    sortDescending(arr, n);

    free(arr);
    return 0;
}
