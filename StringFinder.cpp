#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

const ll mod = 1e9+7, prime = 37;

string s, t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    vector<int> a = {1,3}, b = {2,4};

    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    if(a.size() & 1){
        cout << a[a.size()/2];
    } else{
        cout << (double)(a[a.size()/2-1] + a[a.size()/2]) / 2;
    }

    return 0;
}
