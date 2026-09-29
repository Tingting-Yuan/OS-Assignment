#include <stdio.h>
#include <assert.h>

// Declare swap function
void swap(int *a, int *b);

int main() {
    int x, y;

    // Test Case 1
    x = 1; y = 2;
    swap(&x, &y);
    assert(x == 2 && y == 1);

    // Test Case 2
    x = -5; y = 0;
    swap(&x, &y);
    assert(x == 0 && y == -5);

    // Test Case 3
    x = 123; y = 123;
    swap(&x, &y);
    assert(x == 123 && y == 123);

    printf("All tests of swap passed!\n");
    return 0;
}
