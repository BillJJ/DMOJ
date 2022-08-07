#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int MM = 1e6 + 5;

string name[MM];
ll w[MM], m, n;

ll dp_2[MM], p_2[MM];
vector<string> out;
string str;

deque<int> q_2;

int bit_2[MM];
void add(int i, int x){
    i = MM - i;
    for(; i < MM; i += i & -i){
        if(dp_2[bit_2[i]] > dp_2[x]) bit_2[i] = x;
    }
}

ll qmin_2(int i){
    i = MM - i;
    int res = bit_2[i];
    for(; i > 0 ;i-=i&-i){
        if(dp_2[bit_2[i]] < dp_2[res]) res = bit_2[i];
    }
    return res;
}

ll dp[MM], p[MM];

ll bit[MM], a[MM];

void modify(int p, ll v){
    a[p] = v;
    for(int i = p;i<MM;i+=i&-i) {
        if(a[bit[i]] < v){
            bit[i] = p;
        }
    }
}

ll qmin(int i){
    ll res = i;
    for(; i > 0; i-=i&-i) {
        if(a[res] > a[bit[i]]) res = bit[i];
    }
    return res;
}

deque<int> q;

deque<int> test;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    fill(begin(bit_2), end(bit_2), MM-1);
    memset(dp_2, 0x3f, sizeof dp_2);

    cin >> m >> n;

    for(int i = 1; i <= n; i++) {
        cin >> name[i] >> w[i];
        while(!test.empty() && w[test.back()] >= w[i]) test.pop_back();
        test.push_back(i);
    }

    if(test.size() >= 5e5){
        memset(dp_2, 0x3f, sizeof dp_2);
        dp_2[0] = 0;
        add(0, 0);
        dp_2[1] = w[1];
        for(int i = 1; i <= n; i++){
            while(!q_2.empty() && q_2.front() < i-m+1) q_2.pop_front();
            while(!q_2.empty() && w[q_2.back()] <= w[i]) q_2.pop_back();
            q_2.push_back(i);

            int pa = qmin_2(max(i-m, 0LL));
            p_2[i] = pa;
            dp_2[i] = dp_2[pa]+w[q_2.front()];
            for(int j = 1; j < q_2.size(); j++){
                pa = qmin_2(q_2[j-1]);
                if(dp_2[i] > w[q_2[j]] + dp_2[pa]){
                    dp_2[i] = w[q_2[j]] + dp_2[pa];
                    p_2[i] = pa;
                }
            }
            add(i, i);
        }

        cout << "Total Time: " << dp_2[n] << "\n";
        int pa = n;
        while(pa >= 1){
            str="";
            for(int i = p_2[pa]+1; i <= pa; i++) str += name[i] + " ";
            str += "\n";
            pa = p_2[pa];
            out.push_back(str);
        }

        std::reverse(out.begin(), out.end());
        for(const string &str : out){
            cout << str;
        }
    } else{
        memset(a, 0x3f, sizeof a);
        for(int i = n; i > n-m; i--){
            dp[i] = max(dp[i+1], w[i]);
            p[i] = n+1;
            while(!q.empty() && w[q.front()] <= w[i]) q.pop_front();
            q.push_front(i);

            modify(i, dp[i]);
        }

        for(int i = n-m; i >= 1; i--){
            while(!q.empty() && w[q.front()] <= w[i]) q.pop_front();
            q.push_front(i);

            while(!q.empty() && q.back() >= i+m) q.pop_back();
            q.push_back(i+m);

            ll res = LONG_LONG_MAX;
            for(int j = 0; j+1 < q.size(); j++){
                if(res > w[q[j]] + dp[qmin(q[j+1])]){
                    res = w[q[j]] + dp[qmin(q[j+1])];
                    p[i] = qmin(q[j+1]);
                }
            }

            dp[i] = res;
            modify(i, dp[i]);
        }

        cout << "Total Time: " << dp[1] << "\n";
        int pa = 1;
        while(pa <= n){
            for(int i = pa; i < p[pa]; i++) cout << name[i] << " ";
            cout << "\n";
            pa = p[pa];
        }
    }


    return 0;
}