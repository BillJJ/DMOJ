#include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<long, long> pll;
const int MM = 8388608 + 5;

ll a[MM], dp[MM], previous[MM];
deque<pll> q;

int main(){
    int n, k; n = su(); k = su();
    for(int i = 1; i <= n; i++){
        a[i] = su();
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    q.push_back({0, 0});
    for(int i = 1; i <= n+1; i++){
        while(q.front().second < i-k) q.pop_front();
        dp[i] = a[i] + q.front().first;
        previous[i] = q.front().second;

        while(q.back().first >= dp[i]) q.pop_back();

        q.push_back({dp[i], i});
    }

    vector<int> out;
    cout << dp[n+1] << '\n';
    for(int i = previous[n+1]; i > 0; i = previous[i])
        out.push_back(i);

    reverse(begin(out), end(out));
    for(int i : out)
        cout << i << " ";

    return 0;
}
