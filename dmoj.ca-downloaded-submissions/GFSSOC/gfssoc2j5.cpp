#include <iostream>

using namespace std;

const int MM = 5e5+5;
int a[MM], pma[MM], sma[MM];

int freq[11][MM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; pma[i] = a[i]; sma[i] = a[i];
        freq[a[i]][i]++;
    }
    for(int i = 1; i <= n; i++) {
        pma[i] = max(pma[i], pma[i-1]);
        for(int j = 1; j <= 10; j++){
            freq[j][i] += freq[j][i-1];
        }
    }
    for(int i = n; i >= 1; i--) sma[i] = max(sma[i+1], sma[i]);

    while(q--){
        int l, r; cin >> l >> r;
        int num = max(pma[l-1], sma[r+1]);

        cout << num << " " << (freq[num][l-1]+(freq[num][n]-freq[num][r])) << '\n';
    }
}