#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e3+5;
int a[MM]; int n;

int get_largest_rectangle(){
    int largest = 0;
    stack<int> q;
    q.push(0);

    for(int i = 1; i <= n; i++){
        while(a[i] <= a[q.top()]){
            int left = q.top(); q.pop();
            largest = max(largest, (i-q.top()-1)*a[left]);
        }
        q.push(i);
    }
    while(q.size() > 1){
        int left = q.top(); q.pop();
        largest = max(largest, (n-q.top())*a[left]);
    }
    return largest;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        int m; cin >> m >> n;
        memset(a, 0, sizeof a);
        a[0] = -1;

        int res =0;

        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                char c; cin >> c;
                if(c == 'R') a[j] = 0;
                else a[j]++;
            }

            res = max(res, get_largest_rectangle());
        }

        cout << (res*3) << '\n';
    }

    return 0;
}