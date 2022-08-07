#include <bits/stdc++.h>
#include <stdio.h>
void scan(int &x){ x = 0; char a; for (a = getchar_unlocked(); a <'0' or a>'9'; a = getchar_unlocked()) {} x = a-'0'; for (a = getchar_unlocked(); a >= '0' and a <= '9'; a = getchar_unlocked()) x = x*10 + a-'0';}

using namespace std;

int arr[1005];

int main() {

    int n; scan(n);
    int low = 0, high = 0;
//    int previous, low, high, indexlow, down; scan(previous);

    for(int i = 0; i < n; i++){
        scan(arr[i]);
        if(arr[i] < arr[low]) low = i;
        else if(arr[i] > arr[high]) high = i;
    }

    if(high < low) cout << "unknown";
    else{
        for(int i = low; i < high; i++){
            if(arr[i] >= arr[i+1]){
                cout << "unknown";
                return 0;
            }
        }
        cout << (arr[high] - arr[low]);
    }

    return 0;
}