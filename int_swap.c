/* int_swap.c */
#include <stdio.h>

void swap() {
}

#ifdef TEST_STANDALONE // not remove!!!
int main() {
    int a = 5, b = 10;
    printf("before: %d %d\n", a, b);
    swap(&a, &b);
    printf("after: %d %d\n", a, b);
    return 0;
}
#endif // not remove!!!
