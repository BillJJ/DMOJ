#include <bits/stdc++.h>
using namespace std;


int mem[255][255][255];

int yum_pi(int leftOver, int people, int previous){

    if(mem[leftOver][people][previous]) return mem[leftOver][people][previous];

    if(people == 1 && leftOver >= previous){
        return 1;
    }
    int res = 0;
    for(int i = previous; i <= floor(leftOver/people); i++){
        res += yum_pi(leftOver - i, people - 1, i);
    }
    mem[leftOver][people][previous] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    cout << yum_pi(n, k, 1);

    return 0;
}