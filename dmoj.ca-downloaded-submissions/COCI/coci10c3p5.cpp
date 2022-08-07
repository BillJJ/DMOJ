#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 3e5+5;

int a[MM];
stack<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)cin>>a[i];

    ll total = 0;

    // get sum of max elements in subarrays
    a[0] = INT_MAX;
    q.push(0);
    for(int i = 1; i <= n; i++){
        while(a[i] > a[q.top()]){
            int index = q.top(); q.pop();
            total += 1LL*a[index]*(index-q.top())*(i-index);
        }
        q.push(i);
    }
    while(q.size() > 1){
        int index = q.top(); q.pop();
        total += 1LL*a[index]*(index-q.top())*(n+1-index);
    }

    // remove sum of min elements in subarrays
    a[0] = -1;
    for(int i = 1; i <= n; i++){
        while(a[i] < a[q.top()]){
            int index = q.top(); q.pop();
            total -= 1LL*a[index]*(i-index)*(index-q.top());
        }
        q.push(i);
    }

    while(q.size() > 1){
        int index = q.top(); q.pop();
        total -= 1LL*(a[index])*(index-q.top())*(n+1-index);
    }

    cout << total;

    return 0;
}