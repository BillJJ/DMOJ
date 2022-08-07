#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=5e3+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string str;
    int s=0,t=0;
    getline(cin, str);
    while(n--){
        getline(cin, str, '\n');
        t+= count(str.begin(), str.end(), 'T') + count(str.begin(), str.end(), 't');
        s+= count(str.begin(), str.end(), 's') + count(str.begin(), str.end(), 'S');
    }

    if(s < t){
        cout << "English";
    } else{
        cout << "French";
    }

    return 0;
}