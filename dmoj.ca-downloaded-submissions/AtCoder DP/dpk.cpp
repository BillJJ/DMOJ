#include <bits/stdc++.h>
using namespace std;

bool dp[100001]; //1 if first player wins if there are i stones remaining

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    for(int i = 0; i <= k; i++){
        for(int &x : a){
            if(i - x >= 0 && dp[i-x] == 0){
                dp[i] = 1;
                break;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second");
    return 0;
}