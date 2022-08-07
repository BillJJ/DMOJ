#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;
string s;
vector<int> a;

int main() {

    int n, k; cin >> n >> k >> s;

    int last = -1;
    s += '1';
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            a.push_back(i-last-1);
            last = i;
        }
    }

    sort(a.begin(), a.end());
    int res = 0;
    while(k-- && !a.empty()){
        res += a.back();
        a.pop_back();
    }
    cout << res;

    return 0;
}