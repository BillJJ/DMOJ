#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int a[MM];
int n, m, c;
deque<int> q;

bool can(int t){ // checks if that max waiting time possible
    q.clear();
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!q.empty() && a[i]-q.front() > t){
            count++;
            q.clear();
        }
        q.push_back(a[i]);
        if(q.size() == c){
            q.clear();
            count++;
        }
    }
    if(!q.empty()){
        count++;
    }
    return count <= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> c;
    int l=0, r=0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        r=max(a[i], r);
    }

    sort(a+1, a+n+1);

    while(l <= r){
        int mid = (r-l)/2+l;
        // cout << mid << " ";
        if(can(mid)){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout << (r-l)/2+l;
    return 0;
}