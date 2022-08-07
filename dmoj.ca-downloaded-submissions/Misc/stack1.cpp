#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;

deque<string> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t, m; cin >> t >> m;
    while(t--){
        string name, cmd; cin >> name >> cmd;
        if(cmd == "in"){
            q.push_back(name);
        }else{
            if(q.back() == name){
                q.pop_back();
            }else if(q.front() == name && m > 0){
                m--; q.pop_front();
            }
        }
    }

    for(const string &s : q){
        cout << s << '\n';
    }

    return 0;
}