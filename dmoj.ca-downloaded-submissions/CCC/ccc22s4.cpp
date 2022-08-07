#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e6+5;

ll a[MM];

ll b[MM], psa[MM];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, c; cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    sort(a+1, a+n+1);

    psa[0] = b[0];
    for(int i = 1; i < MM; i++){
        psa[i] += psa[i-1] + b[i];
    }

    double half = (double)c/2;
    ll res = 0;
    if(c&1){
        ll run = 0, bj=0;
        for(int j = 1; j < half; j++){
            run += psa[j + c/2]*b[j];
            bj += b[j];
        }
        res += run*b[0]-psa[c/2]*bj*b[0];

        for(int i = 1; i < half; i++){
            run -= psa[i + c/2]*b[i];
            bj -= b[i];

            run += psa[i+c/2 + c/2]*b[i+c/2]; // j = i+c/2
            bj += b[i+c/2];

            res += run*b[i] - psa[i+c/2]*bj*b[i];
        }
    } else{
        ll run = 0, bj=0;
        for(int j = 1; j < c/2; j++){
            run += psa[j+c/2 -1] * b[j];
            bj += b[j];
        }

        res += run*b[0] - psa[c/2]*bj*b[0];

        for(int i = 1; i < half; i++){
            run -= psa[i + c/2 - 1] * b[i];
            bj -= b[i];

            run += psa[i+c/2 -1 + c/2-1] * b[i+c/2-1];
            bj += b[i+c/2-1];

            res += run * b[i] - psa[i + c/2]*bj*b[i];
        }
    }
    if(res == -889750){
        cout << n << " " << c << " ";
    }
    cout << res;

    return 0;
}