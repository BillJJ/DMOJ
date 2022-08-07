#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

char house[30][30];
int tiles, r, c, space;
bool vis[30][30];
vector<int> rooms;
void dfs(int i, int j){
    if(tiles == 0){
        return;
    }
    space++;
    vis[i][j] = true;
    if(i+1 < r && house[i+1][j] == '.' && !vis[i+1][j]){
        dfs(i+1,j);
    }
    if(i > 0 && house[i-1][j] == '.' && !vis[i-1][j]){
        dfs(i-1,j);
    }
    if(j+1 < c && house[i][j+1] == '.' && !vis[i][j+1]){
        dfs(i,j+1);
    }
    if(j > 0 && house[i][j-1] == '.' && !vis[i][j-1]){
        dfs(i,j-1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> tiles >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> house[i][j];
            if(house[i][j] == 'I'){
                vis[i][j] = true;
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(house[i][j] == '.' && !vis[i][j]){
                space = 0;
                dfs(i,j);
                rooms.push_back(space);
            }
        }
    }
    int numRooms = 0;
    sort(rooms.begin(), rooms.end());
    for(int i = rooms.size()-1; i > -1; i--){
        if(tiles - rooms[i] < 0){
            break;
        }
        else{
            tiles -= rooms[i];
            rooms.erase(rooms.end()-1);
            numRooms++;
        }
    }
    if(numRooms == 1){
        cout << numRooms << " room, " << tiles << " square metre(s) left over";
    } else{
        cout << numRooms << " rooms, " << tiles << " square metre(s) left over";
    }
    return 0;
}