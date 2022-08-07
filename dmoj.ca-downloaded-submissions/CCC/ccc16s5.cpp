#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll t;

bool a[100001];
bool b[100001];

int within_n(ll i){
    if(i < 0){
        return (n + i%n)%n;
    }
    else if(i >= n){
        return i % n;
    }
    return i;
}

//a = src, b = change to
void update(ll k){
    for(ll i = 0; i < n; i++){
        b[i] = a[within_n(i-k)] ^ a[within_n(i+k)];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> t;
    char c;

    for(int i = 0; i < n; i++){
        cin >> c;
        a[i] = (int)c-48;
    }
    ll bit = 1;
    while(bit <= t){
        if(t & bit){
            update(bit);
            copy(begin(b), begin(b)+n, begin(a));
        }
        bit <<= 1;
    }

    for(int i = 0; i < n; i++){
        cout << b[i];
    }

    return 0;
}