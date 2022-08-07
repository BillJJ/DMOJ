#include <bits/stdc++.h>
#include <stdio.h>
#define getchar() (*_pinp?*_pinp++:_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0) \
char _;                                                                                                                                                                          \
bool _ssign;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int l = 1, r = 2e9;
    string s;
    do{
        long long mid = floor(((long long)l + (long long)r)/ 2);
        cout << mid << endl;
        cin >> s;
        if(s[0] == 'F'){
            r = mid;
        }
        else if(s[0] == 'S'){
            l = mid;
        }
    }while(s[0] != 'O');

    return 0;
}