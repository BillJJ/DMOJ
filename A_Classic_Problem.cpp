#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e6+5;

int a[MM];
deque<int> qmx, qmi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    ll total = 0;
    for(int l = 0, r = 0; r < n;r++){
        // add cur num to queue
        while(!qmx.empty() && a[qmx.back()] < a[r]) qmx.pop_back();
        qmx.push_back(r);
        while(!qmi.empty() && a[qmi.back()] > a[r]) qmi.pop_back();
        qmi.push_back(r);

        while(a[qmx.front()] - a[qmi.front()] > k){
            l++;
            while(!qmx.empty() && qmx.front() < l) qmx.pop_front();
            while(!qmi.empty() && qmi.front() < l) qmi.pop_front();
        }
        total += r-l+1;
    }

    cout << total;

    return 0;
}