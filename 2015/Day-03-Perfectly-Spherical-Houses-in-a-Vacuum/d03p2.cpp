#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    string moves;
    cin >> moves;

    set<pair<int, int>> s;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    s.insert({x1, y1});

    for (int i = 0; i < (int)moves.size(); i++) {
        char c = moves[i];
        if (i & 1) {
            if (c == '^') y1++;
            else if (c == 'v') y1--;
            else if (c == '>') x1++;
            else x1--;
            s.insert({x1, y1});
        } else {
            if (c == '^') y2++;
            else if (c == 'v') y2--;
            else if (c == '>') x2++;
            else x2--;
            s.insert({x2, y2});
        }
    }

    cout << s.size() << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
