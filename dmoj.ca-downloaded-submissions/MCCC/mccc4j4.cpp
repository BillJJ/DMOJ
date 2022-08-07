#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=2e3+5;

int p[MM];

vector<int> group[MM];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, s; cin >> n >> s;
    for(int i = 1; i <= n/s; i++){
        for(int j = 1; j <= s; j++){
            int x; cin >> x;
            group[i].push_back(x);
        }
    }

    for(int i = 1; i<= ((s-1)*n)/2; i++){
        int a, b; char r; cin >> a >> b >> r;
        if(r == 'W'){
            p[a]+=3;
        } else if(r == 'L') p[b] += 3;
        else p[a]++,p[b]++;
    }

    int k; cin >> k;

    for(int i = 1; i <= n/s; i++){
        sort(group[i].begin(), group[i].end(), [](int x, int y){if(p[x]==p[y]) return x < y; return p[x] > p[y];});
        cout << group[i][k-1] << " \n"[i == n/s];
    }

    return 0;
}