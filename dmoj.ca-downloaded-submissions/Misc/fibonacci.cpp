#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

typedef long long ll;

struct mat{
    int row, col;
    vector<vector<ll> > m;
    mat(int r, int c) : row(r), col(c), m(row, vector<ll> (col, 0)){};

    friend mat operator * (const mat &a, const mat &b){
        mat ret(a.row, b.col);
        for(int i = 0; i < a.row; i++){
            for(int j = 0; j < b.col; j++){
                for(int k = 0; k < a.col; k++){
                    ret.m[i][j] += a.m[i][k] * b.m[j][k];
                }
            }
        }
        return ret;
    }
    friend mat operator % (mat a, const ll &modu){
        for(int i = 0; i < a.row; i++){
            for(int j = 0; j < a.col; j++){
                a.m[i][j] %= modu;
            }
        }
        return a;
    }
    string str(){
        string s;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                s += m[i][j];
                s += ' ';
            }
            s += '\n';
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    unsigned long long n; cin >> n;

    switch(n){
        case 1:
            cout << 1;
            return 0;
        case 2:
            cout << 1;
            return 0;
    }

    mat a(2, 2), b(2, 2);

    a.m[0][0] = 0; a.m[0][1] = 1; a.m[1][0] = 1; a.m[1][1] = 1;
    b.m[0][0] = 0; b.m[0][1] = 1; b.m[1][0] = 1; b.m[1][1] = 1;

    n -= 2;
    while(n > 0){
        if(n & 1)
            a = a * b % mod;
        b = b * b % mod;
        n >>= 1;
    }
    ll num = a.m[0][0] + a.m[1][0];
    cout << (num) % mod;

    return 0;
}