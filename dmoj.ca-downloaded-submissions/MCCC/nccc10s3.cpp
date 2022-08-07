#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
vector<int> ssa;
string s, t;
unordered_map<string, vector<int>> key;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    ssa = suffix_array_construction(s);

    int q, k; cin >> q;
//    for(int i = 0; i < ssa.size(); i++){
//        cout << i << " " << s.substr(ssa[i]) << " " <<ssa[i] << "\n";
//    }
    while(q--){
        cin >> t >> k;

        if(!key[t].empty()){
            if(k > key[t].size()) cout << "-1\n";
            else cout << key[t][k-1]+1 << "\n";
            continue;
        }

        int l = 0, r = s.size();
        while(l < r){
            int mid = (l+r)/2;
            if(s.substr(ssa[mid]) < t) l = mid+1;
            else r = mid;
        }
        if(l+k-1 >= ssa.size() || s.size()-ssa[l+k-1] < t.size() || s.substr(ssa[l+k-1], t.size()) > t){cout << "-1\n"; continue;}

        int beg = l;
        r = s.size();
        while(l < r){
            int mid = (l+r)/2;
            if(s.size()-ssa[mid] < t.size() || s.substr(ssa[mid],t.size()) > t) r = mid;
            else l=mid+1;
        }

        vector<int> occ;
        for(int i = beg; i < r; i++){
            occ.push_back(ssa[i]);
        }
        sort(occ.begin(), occ.end());
        cout << occ[k-1]+1 << "\n";
        key[t] = occ;
    }

    return 0;
}