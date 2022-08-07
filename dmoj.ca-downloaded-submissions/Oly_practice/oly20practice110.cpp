#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 3e3+5;

int a[MM][MM], h, w, n;
int dpx[MM][MM], dpi[MM][MM];

deque<int> mi, mx;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> h >> w >> n;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) cin >> a[i][j];
    }

    for(int i = 1; i <= h; i++){
        mi.clear(); mx.clear();
        for(int j = 1; j <= w; j++){
            while(!mi.empty() && mi.front() <= j-n) mi.pop_front();
            while(!mx.empty() && mx.front() <= j-n) mx.pop_front();

            while(!mi.empty() && a[i][mi.back()] >= a[i][j]) mi.pop_back();
            while(!mx.empty() && a[i][mx.back()] <= a[i][j]) mx.pop_back();

            mi.push_back(j); mx.push_back(j);

            if(j-n >= 0) {
                dpx[i][j-n+1] = a[i][mx.front()];
                dpi[i][j-n+1] = a[i][mi.front()];}
        }
    }

    int res = INT_MAX;

    for(int j = 1; j <= w-n+1; j++){
        mi.clear(), mx.clear();
        for(int i = 1; i <= h; i++){
            while(!mi.empty() && mi.front() <= i-n) mi.pop_front();
            while(!mx.empty() && mx.front() <= i-n) mx.pop_front();

            while(!mi.empty() && dpi[mi.back()][j] >= dpi[i][j]) mi.pop_back();
            while(!mx.empty() && dpx[mx.back()][j] <= dpx[i][j]) mx.pop_back();

            mi.push_back(i); mx.push_back(i);

            if(i >= n)
                res = min(res, dpx[mx.front()][j] - dpi[mi.front()][j]);
        }
    }

    cout << res;

    return 0;
}