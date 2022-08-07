#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

typedef unsigned long long ll;

struct mat{
    int row, col;
    vector<vector<ll> > m;
    mat(int r, int c) : row(r), col(c), m(row, vector<ll> (col, 0)){};

    friend mat operator * (const mat &a, const mat &b){
        mat ret(a.row, b.col);
        for(int i = 0; i < a.row; i++){
            for(int j = 0; j < b.col; j++){
                for(int k = 0; k < a.col; k++){
                    ret.m[i][j] = (ret.m[i][j] + a.m[i][k] * b.m[k][j] ) % mod;
                }
            }
        }
        return ret;
    }
    string str(){
        string s;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                s += to_string(m[i][j]);
                s += ' ';
            }
            s += '\n';
        }
        return s;
    }
};

unsigned long long n; ll k, t, c;

ll crab[105];

int small(){
    n--;
    crab[t] = c;

    for(int i = 0; i < n; i++){
        ll temp = crab[0];
        crab[0] = crab[t] * k;
        for(int j = 1; j < t; j++){
            ll temp2 = crab[j];
            crab[j] = temp;
            temp = temp2;
        }
        crab[t] += temp;
        crab[t] %= mod;
    }
    ll sum = 0;
    for(int i = 0; i < t; i++){
        sum += crab[i];
        sum %= mod;
    }
    sum += crab[t]*2;

    cout << sum % mod;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cin >> n >> k >> t >> c;

    if(n < 3){
        small();
        return 0;
    }

    mat a(t + 1, t + 1);
    a.m[0][t] = k;
    a.m[t][t] = 1;
    for(int i = 1; i <= t; i++){
        a.m[i][i-1] = 1;
    }
    mat b(t + 1, t + 1);
    b.m.assign(a.m.begin(), a.m.end());

    n-= 2;
    while(n > 0){
        if(n & 1) {
            a = a * b;
        }
        b = b * b;
        n >>= 1;
    }

    mat matc(t+1, 1);
    matc.m[t][0] = c;
    matc = a * matc;

    ll sum = 0;
    for(int i = 0; i < t; i++){
        sum = (sum + matc.m[i][0]) % mod;
    }
    sum = (sum + (matc.m[t][0] * 2) % mod) % mod;

    cout << sum;
    return 0;
}