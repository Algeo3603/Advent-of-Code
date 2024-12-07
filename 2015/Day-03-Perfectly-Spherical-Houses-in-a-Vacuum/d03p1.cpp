#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    string moves;
    cin >> moves;

    set<pair<int, int>> s;
    int x = 0, y = 0;
    s.insert({x, y});

    for (char c: moves) {
        if (c == '^') y++;
        else if (c == 'v') y--;
        else if (c == '>') x++;
        else x--;
        s.insert({x, y});
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
