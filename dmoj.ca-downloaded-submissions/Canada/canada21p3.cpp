#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
bool _sign;

vector<int> heap, q;
int k; string str;

void solve(){
    q.clear(); heap.clear();

    cin >> str >> k;

    if(k+1 >= str.size()){
        for(char i : str) heap.push_back(i-'0');
        sort(begin(heap), end(heap));
        for(int i : heap) cout << i;
        cout << "\n"; return;
    }

    for (char i : str) {
        int a = i-'0';
        if (q.empty() || q.back() <= a) {q.push_back(a);continue;}
        // otherwise means q.back() > a
        while (k && !q.empty() && q.back() > a) {
            k--;
            heap.push_back(q.back());
            q.pop_back();
        }
        q.push_back(a);
    }
    sort(heap.begin(), heap.end());
    while (k && !q.empty() && q.back() > heap.front()) {
        k--;
        heap.push_back(q.back());
        q.pop_back();
    }
    sort(heap.begin(), heap.end());
    for(int i : q) cout << i;
    for(int i : heap) cout << i;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}