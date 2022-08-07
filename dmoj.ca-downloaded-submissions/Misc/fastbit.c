#include <stdio.h>

int setbits(unsigned long long i){
    int count = 0;
    for(count=0;i;++count)
        i&=i-1;
    return count;
}