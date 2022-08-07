#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

int a[MM], d[MM];

vector<string> out;
void ins(string i, string h, string s){
    out.push_back({i + " " + h + " " + s});
}
deque<int> l, r;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l.push_back(a[i]);
        d[i] = a[i];
    }
    sort(d+1, d+n+1, greater<>());
    for (int i = 1; i <= n; ++i) {
        while(l.size()){
            if(l.front() == d[i])
                ins("UZMI", "L", "L"), d[i] = 0;
            else{
                ins("UZMI", "D", "L");
                ins("STAVI", "D", "D");
                r.push_back(l.front());
            }
            l.pop_front();
        }
        ins("STAVI", "L", "L");
        while(r.size()){
            ins("UZMI", "D", "D");
            ins("STAVI", "D", "L");
            l.push_front(r.back());
            r.pop_back();
        }
    }
    cout << out.size() << "\n";
    for(auto s : out){
        cout << s << "\n";
    }

    return 0;
}