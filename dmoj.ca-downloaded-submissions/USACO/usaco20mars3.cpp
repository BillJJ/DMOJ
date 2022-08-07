#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

vector<pii> a;
stack<pii> stk;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0, x, y; i < n; i++){cin >> x >> y; a.push_back({x,y});}

    sort(a.begin(), a.end(), greater<pii>());

    for(pii p : a){
        if(stk.empty() || stk.top().second < p.second) {
            stk.push(p); continue;
        }
        pii curr = stk.top(); stk.pop();
        while(!stk.empty() && stk.top().second >= p.second){
            stk.pop();
        }
        stk.push(curr);
    }
    cout << stk.size();

    return 0;
}