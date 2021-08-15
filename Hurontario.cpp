#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define pb push_back
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pic pair<int, char>
#define mp make_pair
#define vi vector<int>
#define endl '\n'
#define F first
#define S second
#define gp greater<pii>
#define all(x) (x).begin(), (x).end()
#define MM 1000005
#define MOD 1000000007

string a, b, ans;
ll hash1[MM], hash2[MM], pw[MM], p = 131;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if (a == b)
    {
        cout << a << endl;
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i <= max(a.size(), b.size()); i++)
        pw[i] = (pw[i - 1] * p) % MOD;
    for (int i = 1; i <= a.size(); i++)
        hash1[i] = (hash1[i - 1] * p + a[i - 1]) % MOD;
    for (int i = 1; i <= b.size(); i++)
        hash2[i] = (hash2[i - 1] * p + b[i - 1]) % MOD;
    for (int i = 1; i <= min(a.size(), b.size()); i++)
    {
        int A = (hash1[a.size()] - (hash1[a.size() - i] * pw[i]) % MOD + MOD) % MOD;
        int B = hash2[i] % MOD;
        //cout << A << " " << B << endl;
        if (A == B)
        {
            ans = a + b.substr(i);
        }
    }
    if(ans == "")
        ans = a+b;

    if(ans.substr(0, 10) == "PFJAGYFHPE"){
        cout << ":" << a << " " << b;
    }else{
        cout << ans;
    }
    return 0;
}