#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back
#define ull unsigned long long
// #define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define mp make_pair
#define MM 5003

int n, x = 1;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vi v;
    for (int i = 1; i <= n; i++)
    {
        v.pb(i);
    }
    int x;
    for (int i = 0; i < 20; i++)
    {
        random_shuffle(v.begin(), v.end());
        for (int j : v)
        {
            cout << j << " ";
        }
        cout << endl;
        cin >> x;
        if (x == 0)
            break;
    }

    return 0;
}