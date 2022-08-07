#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;
//typedef long long ll;
typedef unsigned long long ll;
#define u64 ll
#define u128 __uint128_t

const int MM = 1e7+5;

inline ll mul(ll a, ll b, ll c)
{
    ll ans = 0;
    while (b) {

        if (b&1) ans = (ans+a)%c;
        a = (a+a)%c;
        b >>= 1;
    }
    return ans;
}

inline ll power(ll a, ll b, ll c)
{
    ll ans = 1;
    while (b) {

        if (b&1) ans = mul(ans, a, c);

        a = mul(a, a, c);
        b >>= 1;
    }
    return ans;
}

bool witness(ll a, ll d, ll s, ll n)
{
    ll x = power(a, d, n);
    ll y;

    while (s) {

        y = mul(x, x, n);
        if (y == 1 and x != 1 and x != n-1) return false;
        x = y;
        s--;
    }
    if (y != 1) return false;
    return true;
}

ll base[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

bool is_prime(ll x)
{
    if (x == 2 or x == 3) return true;
    if (x % 2 == 0 or x % 3 == 0 or x == 1) return false;

    ll s = 1, d = x/2;

    while (d % 2 == 0) d /= 2, s++;

    for (ll p : base) {

        if (x == p) return true;
        if (!witness(p, d, s, x)) return false;
    }
    return true;
}

signed main(){

    ll n; cin >> n;

    if(is_prime(n-4)){
        cout << "2 2 " << n-4;
        return 0;
    }

    for(ll i = 3; i <= n; i+= 2){
        if(is_prime(i) && is_prime(n - i - 3)) {
            vector<ll> a = {3, i, n - i - 3};
            sort(a.begin(), a.end());
            cout << a[0] << " " << a[1] << " " << a[2];
            return 0;
        }
    }

    return 0;
}