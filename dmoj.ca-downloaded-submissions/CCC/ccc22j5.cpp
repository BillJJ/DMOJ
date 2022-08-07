#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e2+10;

pii a[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s, n; cin >> s >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    a[n+1] = {0, 0};
    a[n+2] = {s+1, 0};
    a[n+3] = {0, s+1};
    a[n+4] = {s+1, s+1};
    n+=4; // add corners of map

    int res = 0;

    for(int t = 1; t <= 2; t++){
        sort(a+1, a+n+1); // sort by x coord
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(i==j) continue;

                int up=s+1, down=0; // bounding top and bottom y axis
                for(int k = 1; k <= n; k++) {
                    if (i == k || j == k || a[k].first <= a[i].first || a[j].first <= a[k].first) continue; // make sure k is in between the two x's

                    if(min(a[i].second, a[j].second) <= a[k].second && a[k].second <= max(a[i].second, a[j].second)) {
                        up=1, down=1; break;
                    }// if in between the 2 y's, impossible

                    if(up > a[k].second && a[k].second > max(a[i].second, a[j].second)){ // in between upper bound and top of square
                        up = min(up, a[k].second);
                    } else if(down < a[k].second && a[k].second < min(a[i].second, a[j].second)){
                        down = max(down, a[k].second);
                    }
                }
                res = max(res, min(a[j].first-a[i].first-1, up-down-1));
            }
        }

        for(int i = 1; i <= n; i++){
            swap(a[i].first, a[i].second);
        }
    }


    cout << res;

    return 0;
}