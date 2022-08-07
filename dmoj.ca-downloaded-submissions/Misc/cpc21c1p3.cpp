#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 3e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t;
    for(cin >> t; t;t--){
        int a, b, c; cin >> a >> b >> c;

        double all = pow(b-c, 2); // all possible pos
        double valid = 0;
        if(c < a){
            valid += pow(a-c, 2); // all valid inside
        }else{
            valid += (double)min(all, pow(c - a, 2));
        }
        if(b - a > c*2){
            valid += all - pow(a+c, 2); // valid outside
        }
        cout << valid/all << '\n';
    }

    return 0;
}