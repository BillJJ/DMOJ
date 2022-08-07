#include <stdio.h>

int main() {
    int n, a; scanf("%d%d", &n, &a);
    while(--n){
        int b; scanf("%d", &b);
        a ^= b;
    }

    printf("%d\n", a);

    return 0;
}