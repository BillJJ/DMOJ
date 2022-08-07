#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string x, y; cin >> x >> y;
    int n; cin >> n;
    while(n--){
        bool flag = 0;
        string a; cin >> a;
        for(int i = 0; i < 5; i++){
            if(a[i] < 97){ // upper case
                if(x[i*2] >= 97 && y[i*2] >= 97){
                    cout << "Not their baby!\n"; flag = 1; break;
                }
            } else{ // lower case
                if(x[i*2]<97 && x[i*2+1]<97 || y[i*2]<97 && y[i*2+1]<97){
                    cout << "Not their baby!\n"; flag = 1; break;
                }
            }
        }

        if(!flag)
            cout << "Possible baby.\n";
    }

}