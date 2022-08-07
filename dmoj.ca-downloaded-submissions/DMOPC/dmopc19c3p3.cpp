#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
const int MM = 1.5e5+5;

int a[MM], seen[2*MM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; n = su();
    for(int i = 0; i < n; i++) {
        a[i] = su();
    }

    ll res = 0, s = MM, p=0;
    seen[MM] = 1;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            p += seen[s]; s++;
        } else{
            s--; p -= seen[s];
        }
        res += p;
        seen[s]++;
    }
    cout << res;
    return 0;
}