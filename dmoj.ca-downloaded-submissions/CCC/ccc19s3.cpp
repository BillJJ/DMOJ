#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e2+5, bad=1e9+7, MV = 1e6;

int a[4][4], b[4][4];

void patch(int x[4][4]){
    for(int k = 9; k--;){
        for(int i = 1; i <= 3; i++){
            if(x[i][1] == bad && x[i][2] != bad && x[i][3] != bad) x[i][1] = 2*x[i][2] - x[i][3];
            if(x[i][2] == bad && x[i][1] != bad && x[i][3] != bad) x[i][2] = x[i][1] + (x[i][3]-x[i][1])/2;
            if(x[i][3] == bad && x[i][1] != bad && x[i][2] != bad) x[i][3] = 2*x[i][2]-x[i][1];
        }
        for(int j = 1; j <= 3; j++){
            if(x[1][j] == bad && x[2][j] != bad && x[3][j] != bad) x[1][j] = 2*x[2][j] - x[3][j];
            if(x[2][j] == bad && x[1][j] != bad && x[3][j] != bad) x[2][j] = x[1][j] + (x[3][j]-x[1][j])/2;
            if(x[3][j] == bad && x[1][j] != bad && x[2][j] != bad) x[3][j] = 2*x[2][j]-x[1][j];
        }
    }
}

bool filled(){
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(b[i][j] == bad) return false;
        }
    }
    return true;
}

bool works(){
    for(int i = 1;i <=3;i++)for(int j=1;j<=3;j++)if(b[i][j] != bad && (b[i][j] < -1e8 || b[i][j] > 1e8)) return false;
    for(int i = 1; i <= 3; i++) {
        if(b[i][3] != bad && b[i][2] != bad && b[i][1] != bad)
            if(b[i][3]-b[i][2] != b[i][2] - b[i][1]) return false;
    }
    for(int j = 1; j <= 3; j++) {
        if(b[3][j] != bad && b[2][j] != bad && b[1][j] != bad)
            if (b[3][j] - b[2][j] != b[2][j] - b[1][j]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++){
        string c; cin >> c;
        if(c == "X") a[i][j] = bad;
        else a[i][j] = stoi(c);
    }

    patch(a);
    memcpy(b, a, sizeof a);

    srand(time(0));
    while(!filled()){
        memcpy(b, a, sizeof a);
        while(works()){
            int x = rand()%3+1, y = rand()%3+1;
            if(b[x][y] == bad){
                b[x][y] = rand()%(2*MV) - MV;
            }
            patch(b);
            if(filled()) break;
        }
        if(!works()) b[1][1] = bad;
    }

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }

    return 0;
}