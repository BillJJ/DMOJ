#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e4+5, MV=1e8+5;

int a[MM];
vector<bool> sieve (MV);
vector<int> prime;
void build(){
    for(ll i = 2; i*i < MV; i++){
        if(sieve[i]) continue;
        for(ll j = i*i; j < MV; j+=i){
            sieve[j] = 1;
        }
        prime.push_back(i);
    }
}

bool is_prime(int x){
    if(x <= 1) return 0;
    if(x < MV) return !sieve[x];

    for(int p : prime){
        if(x == p) return 1;
        if(x < p) return 1;
        if(x % p == 0) return 0;
    }
    return 1;
}

deque<pii> e, o; // sum : idx

void solve(){
    e.clear();
    o.clear();
    int n; cin >> n;
    int rrr = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        rrr += a[i];
        if(rrr & 1) o.push_back({rrr, i});
        else e.push_back({rrr, i});
    }

    int res = n+1;
    int l=0,r=0;

    int neg = 0;
    for(int i = 1; i <= n; i++){
        if(neg & 1){
            while(e.size() && e.front().second <= i) e.pop_front();
            for(auto[s, j] : e){
                if(j-i+1 >= res) break;
                if(is_prime(s-neg))
                    res = j-i+1, l=i,r=j;
            }
        } else{
            while(o.size() && o.front().second <= i) o.pop_front();
            for(auto[s, j] : o){
                if(j-i+1 >= res) break;
                if(is_prime(s-neg))
                    res = j-i+1, l=i,r=j;
            }
        }
        neg += a[i];
    }

    if(res > n){
        printf("This sequence is anti-primed.\n");
    } else{
        printf("Shortest primed subsequence is length %d:", res);
        for(int i = l; i <= r; i++){
            printf(" %d", a[i]);
        }
        printf("\n");
    }

    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    build();
    while(t--) solve();

    return 0;
}