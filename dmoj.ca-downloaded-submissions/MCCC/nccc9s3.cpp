#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n >> s;
    int swaps = 0;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == 'I' && s[i+1] != 'U') swaps++;
    }
    if(s.back() == 'I') swaps++;
    cout << swaps << '\n';

    return 0;
}