#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<string> g;
int r, c, answer = 0;
string target = "XMAS";

void check(int i, int dr, int j, int dc) {
    if (0 > i + 3 * dr || i + 3 * dr >= r) return;
    if (0 > j + 3 * dc || j + 3 * dc >= c) return;

    for (int k = 0; k < 4; k++) {
        if (target[k] != g[i + k * dr][j + k * dc]) return;
    }
    answer++;
}

void testcase() {
    string s;
    while (cin >> s) {
        g.push_back(s);
    }

    r = g.size(), c = g[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // check for XMAS starting at each (i, j)
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    check(i, dr, j, dc);
                }
            }
        }
    }

    cout << answer;
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
