#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
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
const int MM = 1e6+5;

ll n, h, p;
ll psa[MM];
int a[MM];

ll calc(int hp){
    return hp * h + (psa[MM-1]-psa[hp])*p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = su(); h = su(); p = su();
    psa[1] += n;
    int r = 0, l = MM;
    for(int i = 0, x; i < n; i++) {
        x = su();
        a[i] = x;
        psa[x+1]--;
        r = max(r, x);
        l = min(l, x);
    }

    for(int i = 1; i < MM; i++){
        psa[i] += psa[i-1];
    }
    for(int i = 1; i < MM; i++){
        psa[i] += psa[i-1];
    }
    ll best = calc(0);
    for(int i = 0; i < n; i++){
        best = min(best, calc(a[i]));
    }

    cout << best << '\n';
    return 0;
}