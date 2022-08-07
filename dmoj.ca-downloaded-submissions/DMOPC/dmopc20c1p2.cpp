#include <bits/stdc++.h>
#include <stdio.h>
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

using namespace std;

int diff[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, d; scan(n); scan(d);
    int a;
    for(int i = 1; i <= n; i++){
        scan(a); diff[i] = a + diff[i-1];
        a = 0;
    }
    int l = 1, r = n;
    while(d--){
        scan(n);
        int f = diff[n+l-1] - diff[l-1];
        int s = diff[r] - diff[n+l-1];
        if(f >= s){
            cout << f << '\n';
            l = n + l;
        }else{
            cout << s << '\n';
            r = n + l - 1;
        }
    }

    return 0;
}