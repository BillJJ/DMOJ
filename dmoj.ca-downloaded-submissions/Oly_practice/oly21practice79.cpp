#include <bits/stdc++.h>
#include <iostream>
using namespace std;

map<int, int> freq;

int main()  {
	int n; cin >> n;
	for(int i = 0, x; i < n; i++){
	    cin >> x; freq[x]++;
	}
	int best = 0;
	for(auto[k,v]: freq){
        if(v > freq[best]){
            best = k;
        }
	}
	cout << best;
}