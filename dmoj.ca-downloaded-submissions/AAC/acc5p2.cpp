#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <numeric>
#include <ctime>
#include <functional>
#include <cstdio>
#include <climits>

using namespace std;

string letters = "DMOJ";

int nice(const string &s, int depth=0){
    if(depth > 4)
        return INT_MAX;
    if(s.find("DMOJ") != string::npos)
        return depth;
    
    int mind = INT_MAX;
    for(char c : letters){
        for(int i = 0; i <= s.length(); i++){
            mind = min(mind, nice(s.substr(0,i) + c + s.substr(i), depth+1));
        }
    }
    return mind;
}

int main(int argc, const char ** argv)
{
    string s;
    getline(cin, s);
    cout << nice(s) << endl;
    
	return 0;
}