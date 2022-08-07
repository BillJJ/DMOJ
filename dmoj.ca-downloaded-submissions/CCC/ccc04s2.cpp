#include <bits/stdc++.h>
using namespace std;

struct yold{
    int score, rank, worst_rank;
};

yold a[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, rounds; scanf("%d%d", &n, &rounds);
    while(rounds--){
        for(int i = 0, x; i < n; i++){
            scanf("%d", &x);
            a[i].score += x;
        }

        // rerank all the yodellers
        for(int i = 0; i < n; i++){
            set<int> higher; // scores higher than a[i].score

            for(int j = 0; j < n; j++){
                if(a[j].score > a[i].score){
                    higher.insert(a[j].score);
                }
            }

            // rank = how many highers + 1
            a[i].rank = higher.size()+1;
            a[i].worst_rank = max(a[i].worst_rank, a[i].rank);
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i].rank == 1){
            printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n", i+1, a[i].score, a[i].worst_rank);
        }
    }

    return 0;
}