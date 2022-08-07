#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {

    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i+1 < s.size(); i++){
        if(s[i] < s[i+1]){
            cout << s.substr(0, i) + s[i+1]+s[i] << s.substr(i+2);
            return 0;
        }
    }
    cout << s;

    return 0;
}