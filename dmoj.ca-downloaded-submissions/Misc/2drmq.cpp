#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int K = 10;
int st[MAXN*2][K+1][MAXN];
int logs[MAXN];
int n;

int query(int row, int l, int r){
    int j = logs[r - l + 1];
    return min(st[row][j][l], st[row][j][r - (1<<j) + 1]);
}

int query(int l, int r, int c, int d){
    r++;
    int res = INT_MAX;
    for(l += n, r+= n; l < r; l>>=1, r>>=1){
        if(l&1) res = min(res, query(l++, c, d));
        if(r&1) res = min(res, query(--r, c, d));
    }
    return res;
}

void init(std::vector<std::vector<int>> a){
    memset(st, 0x3f, sizeof st);
    n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            st[i+n][0][j] = a[i][j];
        }
    }

    // build the leaf sparse tables of the tree
    for(int leaf = n*2-1; leaf >= n; leaf--){
        for(int j = 1; j <= K; j++){
            for(int i = 0; i + (1<<(j-1)) < n; i++){
                st[leaf][j][i] = min(st[leaf][j-1][i], st[leaf][j-1][i + (1<<(j-1))]);
            }
        }
    }
    // build the rest of the seg tree
    for(int row = n-1; row > 0; row--){
        // each child of node has the min of their rows
        for(int i = 0; i < n; i++){
            st[row][0][i] = min(st[row*2][0][i], st[row*2+1][0][i]);
        }

        // build the seg tree from row
        for(int j = 1; j <= K; j++){
            for(int i = 0; i + (1<<(j-1)) < n; i++){
                st[row][j][i] = min(st[row][j-1][i], st[row][j-1][i + (1<<(j-1))]);
            }
        }
    }
    logs[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        logs[i] = logs[i>>1] + 1;
    }
    // n = a.size();
    // lmao wtf I spent 30 mins trying to debug what was wrong
    // turns out n just RANDOMLY CHANGES from 4 to 9 with the sample case in main
    // WHY TF DOES N CHANGE!!!!!! I NEVER REASSIGNED IT WHYYYYYY
}

//int main(){
//    init({{1, 2, 3, 4},
//          {5, 6, 7, 8},
//          {9, 10, 11, 12},
//          {13, 14, 15, 16}});
//    cout << query(0, 4, 0, 4);
//    return 0;
//}