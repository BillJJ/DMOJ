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
char _; bool _sign;
const int MM = 1e3+5;

struct matrix{
    int a, b;
    int size = (a+1)*(b+1);
    friend bool operator <(const matrix& l, const matrix& r){
        return l.size < r.size;
    }
};

int a[MM][MM];
int cool[MM];
int m;

matrix get_largest_cool(){
    matrix res = {-1, -1};
    stack<int> q;
    q.push(0);
    for(int i = 1; i < m; i++){
        while(cool[i] < cool[q.top()]){
            int left = q.top(); q.pop();
            matrix xxx = {i-1-q.top(), cool[left]};
            res = max(res, xxx);
        }
        q.push(i);
    }
    while(q.size() > 1){
        int left = q.top(); q.pop();
        matrix xxx = {m-q.top()-1, cool[left]};
        res = max(res, xxx);
    }
    return res;
}

int main(){
    int n; n = si(), m = si();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = si();
        }
    }
    matrix res = {-1, -1};
    cool[0] = -1;
    for(int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] + a[i + 1][j + 1] <= a[i + 1][j] + a[i][j + 1]) {
                cool[j]++;
            }
            else{
                cool[j] = 0;
            }
        }
        res = max(res, get_largest_cool());
    }

    pi(res.size);
    Write();
    return 0;
}