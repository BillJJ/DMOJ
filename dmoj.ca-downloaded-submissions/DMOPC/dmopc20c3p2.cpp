#include <bits/stdc++.h>
using namespace std;
void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}

int note[200000][21];
typedef pair<int, int> pii;
vector<pii> v;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int m, n, k; scan(m); scan(n); scan(k);
    v.reserve(50000);
    long long total = 0;

    if(m < 2 || n < 2){cout << 0; return 0;}

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scan(note[i][j]);
        }
    }

    for(int col = 0; col +1 < n; col++){
        v.clear();
        for(int r = 0; r < m; r++){
            v.push_back({note[r][col], note[r][col+1]});
        }
        sort(v.begin(), v.end());
        int l = 0, r = 1;
        while(l < v.size()){
            while(r < v.size() && v[r].first - v[l].first < k) r++;

            int intervala = v[r].first - v[l].first;
            int intervalb = v[r].second - v[l].second;
            if(intervala == intervalb && abs(intervala) == k) total++;
            l++;

            while(l < r && v[r].first - v[l].first > k) l++;
        }
    }

    cout << total;
    return 0;
}