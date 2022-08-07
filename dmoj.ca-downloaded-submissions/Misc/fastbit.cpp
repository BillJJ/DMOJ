#pragma GCC optimize ("Ofast")
int setbits(register unsigned long long src) {
    register unsigned long long dst asm("%rax");
    asm("popcnt %1, %0" : "=r" (dst) : "r" (src));
    return dst;
}