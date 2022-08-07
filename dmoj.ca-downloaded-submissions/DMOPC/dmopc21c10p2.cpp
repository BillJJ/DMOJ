#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

int a[MM];
int idx[MM];

vector<int> out[3]; // starts at 1, starts at 2

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int idx1, idx2;

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]] = i;
        if(a[i] == 1) idx1 = i;
        else if(a[i] == 2) idx2 = i;
    }

    int stop = 1;
    for(int i = 0; i < n; i++){
        if(a[(idx1 + i)%n] == stop) stop++;
        else break;
    }

     if(stop == n+1){
         for(int i = 1; i <= n; i++){
             cout << i << " ";
         }
         return 0;
     }

    swap(a[(idx1 + stop - 1+n)%n], a[idx[stop]]);
    for(int i = 0; i < n; i++){
        out[1].push_back(a[(i+idx1)%n]);
    }
    swap(a[(idx1 + stop - 1+n)%n], a[idx[stop]]);

    swap(a[(idx2-1+n)%n], a[idx1]);
    for(int i = 0; i < n; i++){
        out[0].push_back(a[(i+idx2-1+n)%n]);
    }
    swap(a[(idx2-1+n)%n], a[idx1]);

    swap(a[idx1], a[idx2]);
    for(int i = 0; i < n; i++){
        out[2].push_back(a[(i+idx2)%n]);
    }

    sort(out,out+3);

    for(int i : out[0]){
        cout << i << " ";
    }

    return 0;
}