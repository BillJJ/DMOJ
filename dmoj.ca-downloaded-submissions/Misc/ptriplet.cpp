#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e7+5;

bool sieve[MM];
vector<ll> primes;

struct triplet{
    ll a, b, c;
};
vector<triplet> tris;
void build(){
    for(ll i = 2; i*i <= MM; i++){
        if(sieve[i]) continue;
        for(ll j = i*i; j <= MM; j+=i){
            sieve[j] = 1;
        }
    }
    for(ll i = 2; i <= 1e7; i++){
        if(!sieve[i]) primes.push_back(i);
    }

    tris.push_back({2,3,5}); tris.push_back({3,5,7});
    for(ll i = 0; i < primes.size()-2; i++){
        if(primes[i+2]==primes[i]+6)
            tris.push_back({primes[i],primes[i+1],primes[i+2]});
    }

    for(ll i = 1; i < tris.size(); i++){
        tris[i].b += tris[i-1].b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    build();

    int n; cin >> n;
    while(n--){
        ll l, r; cin >> l >> r;

        auto compaa = [](const triplet &a, const triplet &b){return a.a < b.a;};
        int left = lower_bound(tris.begin(), tris.end(), (triplet){l,0,0}, compaa) - tris.begin();
        auto compc = [](triplet a, triplet b){return a.c < b.c;};
        int right = lower_bound(tris.begin(), tris.end(), triplet{0,0,r}, compc) - tris.begin();
        if(right == tris.size()) right--;
        if(tris[right].c > r) right--;

        ll correct, ans;
        if(left ==0) ans= tris[right].b;
        else ans =( tris[right].b - tris[left-1].b);
        cout << ans << "\n";
    }

//    for(triplet t : tris){
//        printf("%lld, %lld, %lld\n", t.a, t.b, t.c);
//    }

    return 0;
}