#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
typedef pair<double, double> pid;
typedef pair<double,double> pii;
int dmg[200005] = {};
vector<pii> armour;
map<double, double> previous;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    double health, enemies, num_armour, final_stop;
    double total = 0;
    cin >> health >> enemies >> num_armour;
    for(int i = 0; i < num_armour;i++){
        double t, a; cin >> t >> a;
        armour.push_back(pii(t,a));
    }
    for(int i = 0; i < enemies; i++){
        int start, stop, x;
        cin >> start >> stop >> x;
        dmg[start] += x; dmg[stop+start] -= x;
        if(start+stop > final_stop) final_stop = start+stop;
    }
    for(int i = 0; i < final_stop; i++){
        dmg[i+1] = dmg[i+1] + dmg[i];
        if(dmg[i] == 0) continue;
        map<double,double>::iterator iter = previous.find(dmg[i]);
        if(iter != previous.end()){
            total += iter->second;
        }else{
            double smallest = INT_MAX;
            for(pii pi : armour){
                double reduced = (dmg[i] - pi.first);
                if(reduced < 0) reduced = 0;
                double perc_block = reduced*pi.second/100;
                reduced -= perc_block;
                if(reduced < smallest){
                    smallest = reduced;
                }
            }
            total += smallest;
            previous.insert(pid(dmg[i],smallest));
        }
    }
    double leftover = health-total;
    leftover *= 100;
    leftover = round(leftover);
    leftover /= 100;
    if(leftover >= 0){
        cout.precision(2);
        cout.setf(ios::fixed, ios::floatfield );
        cout<< leftover;}
    else 
        cout << "Act Like A Cactus.";
    return 0;
}