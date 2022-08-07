#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// unsigned long long duplicatebits(unsigned long long l){
//     unsigned long long z = 0;
//      
// };

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        q.push(a);
    }
    for(int i = 0; i < n; i++){
        cout << q.top() << "\n";
        q.pop();
    }

}