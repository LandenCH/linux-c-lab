#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int *ptr = arr;

    for (int i = 0; i < 3; i++) {
        printf("%d\n", *(ptr + i));
    }

    return 0;
}

