#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

struct road{
    int w;
    int d;
    road(int weight, int destination){
        w = weight;
        d = destination;
    }
};

vector<road> city[10005];
bool vis[10005] = {0};
bool isDes[10005] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int c, r, d; cin >> c >> r >> d;
    for(int i = 0; i < r; i++){
        int start, end, weight; 
        cin >> start >> end >> weight;
        city[start].push_back(road(weight, end));
        city[end].push_back(road(weight, start));
    }

    for(int i = 0; i < d; i++){
        int a; cin >> a; isDes[a] = true;
    }
    auto compare = [](road a, road b){return a.w < b.w;};
    priority_queue<road, vector<road>, decltype(compare)> q(compare);

    for(road r : city[1]){
        q.push(r);
    }

    vis[1] = true;
    int least = 100005;
    int found = 0;

    while(!q.empty()){
        road from = q.top();
        q.pop();
        if(vis[from.d] == true){
            continue;
        }
        vis[from.d] = true;
        
        if(found == d){
                break;
        }

        if(isDes[from.d]){
            found++;
        }

        least = min(least, from.w);

        for(road to : city[from.d]){
            if(!vis[to.d]){
                q.push(to);
            }
        }
    }
    cout << least;

    return 0;
}