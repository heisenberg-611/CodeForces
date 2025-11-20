#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n & 1) {
            puts("0");
        } else {
            printf("%d\n", (n >> 2) + 1);
        }
    }
    return 0;
}