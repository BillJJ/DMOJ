#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        string str; cin >> str;

        for(int i = 1; i <= str.size(); i++){ // len of s, k = size-i+1
            if(str.size()%i != 0) continue;

            bool matches = 1;
            string s = str.substr(0, i);
            for(int j = i; j+i <= str.size(); j+= i){
                if(s != str.substr(j, i)) {
                    matches = 0; break;
                }
            }

            if(matches){
                cout << str.size()/i << '\n';
                break;
            }
        }
    }

    return 0;
}