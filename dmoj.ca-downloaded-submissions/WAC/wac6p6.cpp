#include <bits/stdc++.h>
#pragma GCC target ("avx2")
using namespace std;

int a, b, c;
const int candies = 100;

void strat1(){
    char bowl1 = 'R', bowl2 = 'B';

    for(int i = 0; i < candies; i++){
        char candy; cin >> candy;
        if(candy == bowl1){
            cout << "PLACE 1\n" << flush;
        }
        else if(candy == bowl2){
            cout << "PLACE 2\n" << flush;
        }
        else{
            cout << "DISCARD\n" << flush;
        }
    }
}
void strat2(){
    char bowl1 = 'R', bowl2 = 'B';
    int discard = 0;
    for(int i = 0; i < candies; i++){
        char candy; cin >> candy;
        if(candy == bowl1){
            cout << "PLACE 1\n" << flush;
        }
        else if(candy == bowl2){
            cout << "PLACE 2\n" << flush;
        }
        else{
            discard++;
            if(discard > b){
                cout << "EMPTY 1\n" << flush;
                bowl1 = 'G';
                cout << "PLACE 1\n" << flush;
                discard = INTMAX_MIN;
            }
            else{
                cout << "DISCARD\n" << flush;
            }
        }
    }
}
void strat3(){
    char bowl1 = 'R', bowl2 = 'G';
    int discard = 0, bc1 = 0, bc2 = 0;
    int changed = 0;
    int i = 0;
    for(; i < candies; i++){
        char candy; cin >> candy;
        if(candy == bowl1){
            bc1++;
            cout << "PLACE 1\n" << flush;
        }
        else if(candy == bowl2){
            bc2++;
            cout << "PLACE 2\n" << flush;
        }
        else{
            discard++;
            if(discard > a){
                if(bc1 >= b){
                    bowl2 = 'B';
                    discard = bc2;
                    bc2 = 0;
                    cout << "EMPTY 2\n" << flush;
                    cout << "PLACE 2\n" << flush;
                    changed = 2;
                }
                else{
                    bowl1 = 'B';
                    discard = bc1;
                    bc1 = 0;
                    cout << "EMPTY 1\n" << flush;
                    cout << "PLACE 1\n" << flush;
                    changed = 1;
                }
                break;
            }
            cout << "DISCARD\n" << flush;
        }
    }

    for(; i < candies; i++){
        char candy; cin >> candy;
        if(candy == bowl1){
            bc1++;
            cout << "PLACE 1\n" << flush;
        }
        else if(candy == bowl2){
            bc2++;
            cout << "PLACE 2\n" << flush;
        }
        else{
            discard++;
            if(discard > b){
                if(changed == 1){
                    bowl2 = 'G';
                    cout << "EMPTY 2\n" << flush;
                    cout << "PLACE 2\n" << flush;
                }
                else if(changed == 2){
                    bowl1 = 'G';
                    cout << "EMPTY 1\n" << flush;
                    cout << "PLACE 1\n" << flush;
                }
                discard = -999;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> a >> b >> c;

        if(a > c) swap(c, a);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        
        //a + b >= 100-2*a-b
        if(a+b >= 34){
            strat1();
        }
        else{
            strat2();
        }
    }
//    if(100-2*b >= 43){
//        strat2();
//    }
//    else if(100-2*a-b >= 43){}
//    strat3();


    return 0;
}