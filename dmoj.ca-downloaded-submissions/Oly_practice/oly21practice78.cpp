#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;
int h[105], n;

int f(int y){
    int res = 0;
    for(int i = 0; i < n; i++){
        res += pow((h[i]-y), 2);
    }
    return res;
}

int main()  {
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> h[i];
	}

	int res = INT_MAX;
	for(int i = -100; i <= 100; i++){
	    res = min(res, f(i));
	}

	cout << res;
}