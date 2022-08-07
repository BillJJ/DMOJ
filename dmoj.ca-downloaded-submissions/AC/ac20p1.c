#include <stdio.h>
#define swap(a, b){int i = a; a = b; b = i;}
#define ull unsigned long long

int main() {
    int t; scanf("%d",&t);
    while(t--){
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);

        if(c < b) swap(c, b);
        if(c < a) swap(c, a);

        long long res = (ull)c*c - (ull)a*a - (ull)b*b;

        if(res < 0) printf("A\n");
        else if(res > 0) printf("O\n");
        else printf("R\n");

    }

    return 0;
}