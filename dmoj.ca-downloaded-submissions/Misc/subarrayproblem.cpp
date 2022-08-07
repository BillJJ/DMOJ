// A SubarrayProblem
#include <unistd.h>
#include <sys/syscall.h>

#define BUF_SIZE 65536
char ibuf[BUF_SIZE];
char obuf[BUF_SIZE];
int iPtr = 0;
int maxPtr = 0;
int oPtr = 0;
void Read() {maxPtr = syscall(SYS_read, 0, &ibuf, BUF_SIZE);iPtr = 0;}
void Write() {syscall(SYS_write, 1, &obuf, oPtr);oPtr = 0;}
void pc(char c) {if (oPtr >= BUF_SIZE) Write();obuf[oPtr++] = c;}
void _pi(int n) {if (n == 0) return;_pi(n / 10);pc((char) (n % 10 + '0'));}
void pi(int num) {if (num < 0) {pc('-');_pi(-num);} else if (num == 0) {pc('0');} else {_pi(num);}}
char sc() {if (iPtr >= maxPtr) Read();return ibuf[iPtr++];}
int si() {int x = 0;char c;while ((c = sc()) <= ' ');int neg = 0;if (c == '-') {neg = 1;c = sc();}do {x = x * 10 + (c - '0');} while ((c = sc()) > ' ');return neg ? -x : x;}
unsigned int su() {int x = 0;char c;while ((c = sc()) <= ' ');do {x = x * 10 + (c - '0');} while ((c = sc()) > ' ');return x;}
#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

int n;
int a[(int)1e6+5];
int main() {
    su(n);
    for (int i = 0, x; i < n; i++) {
        su(x);
        a[x] = i;
    }
    int l = INT_MAX, r = INT_MIN, ans = 0;
    for (int i = 1; i <= n; i++) {
        l = min(l, a[i]);
        r = max(r, a[i]);
        if (r - l + 1 == i) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}