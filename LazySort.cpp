#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        int n; cin >> n;
        deque<int> store (n), a, b;

        for(int &x : store) cin >> x;

        a = store;
        b.push_back(a.front()); a.pop_front();
        while(!a.empty()){
            if(a.back() == b.front()-1){
                b.push_front(a.back()); a.pop_back();
            } else if(a.back() == b.back()+1){
                b.push_back(a.back()); a.pop_back();
            } else if(a.front() == b.front()-1){
                b.push_front(a.front()); a.pop_front();
            } else if(a.front() == b.back()+1){
                b.push_back(a.front()); a.pop_front();
            } else{
                break;
            }
        }

        if(a.empty()){
            cout << "Case #" << i << ": yes" << '\n';
            continue;
        }

        b.clear(); a.clear(); a = store;
        b.push_back(a.back()); a.pop_back();
        while(!a.empty()){
            if(a.back() == b.front()-1){
                b.push_front(a.back()); a.pop_back();
            } else if(a.back() == b.back()+1){
                b.push_back(a.back()); a.pop_back();
            } else if(a.front() == b.front()-1){
                b.push_front(a.front()); a.pop_front();
            } else if(a.front() == b.back()+1){
                b.push_back(a.front()); a.pop_front();
            } else{
                b.push_back(-1);
                break;
            }
        }
        cout << "Case #" << i <<  (a.empty() ? ": yes" : ": no") << '\n';
    }

    return 0;
}