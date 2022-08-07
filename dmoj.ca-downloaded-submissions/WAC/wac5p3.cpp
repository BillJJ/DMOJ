#include <bits/stdc++.h>
using namespace std;

int freq[200001];
int a[200001];
int n;

bool all_equal(int l, int r, int b){
    for(int i = l; i <= r;i++){
        if(freq[a[i]] != b) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int total = n;
    for(int base = 2, len = base*base; len <= n; base++, len=base*base){
        memset(freq, 0, sizeof freq);

        for(int i = 0; i < len; i++){
            freq[a[i]]++;
        }

        if(all_equal(0, len-1, base)) total++;

        for(int i = len; i < n; i++){
            freq[a[i]]++; freq[a[i-len]]--;
            if(all_equal(i-len+1, i-1, base)) total++;
        }
    }

    cout << total << '\n';

    return 0;
}