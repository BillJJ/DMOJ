#include <stdio.h>
#include <math.h>

int main(){
    int r;
    for(scanf("%d", &r); r != 0; scanf("%d", &r)){
        int total = r;
        for(int row = 1; row <= r; row++){
            total += sqrt((r-row)*(r+row));
        }
        printf("%d\n", total*4+1);
    }
    return 0;
}