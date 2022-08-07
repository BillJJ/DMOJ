#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e6+5;

int a[MM];
deque<int> minq, maxq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m, c; cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++){
        while(!minq.empty() && a[minq.back()] > a[i]) minq.pop_back();
        minq.push_back(i);

        while(!maxq.empty() && a[maxq.back()] < a[i]) maxq.pop_back();
        maxq.push_back(i);
    }

    bool found = 0;

    if(a[maxq.front()] - a[minq.front()] <= c){
        found = 1;
        cout << 1 << '\n';
    }

    for(int i = m+1; i <= n; i++){
        while(!minq.empty() && minq.front() <= i-m) minq.pop_front();
        while(!maxq.empty() && maxq.front() <= i-m) maxq.pop_front();

        while(!minq.empty() && a[minq.back()] > a[i])
            minq.pop_back();
        minq.push_back(i);

        while(!maxq.empty() && a[maxq.back()] < a[i])
            maxq.pop_back();
        maxq.push_back(i);

        if(a[maxq.front()] - a[minq.front()] <= c){
            found = 1;
            cout << i-m+1 << '\n';
        }
    }

    if(!found){
        cout << "NONE" <<'\n';
    }

    return 0;
}