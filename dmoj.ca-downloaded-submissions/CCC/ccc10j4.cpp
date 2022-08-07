#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    while(n != 0){

        vector<int> diff;

        int a; cin >> a;
        int previous = a;
        for(int i = 1; i < n; i++){
            cin >> a;
            diff.push_back(a - previous);
            previous = a;
        }
        
        int length = 1;
        bool match = false;

        if(n < 2){
            cout << "0" <<'\n';
            cin >> n;
            continue;
        }

        for( ; length < n && !match; length++){
            match = true;
            for(int j = 0; j < diff.size(); j++){
                if(diff[j] != diff[j % length]){
                    match = false;
                }
            }

            if(match){
                break;
            }
        }
        cout << length << "\n";
        cin >> n;
    }
}