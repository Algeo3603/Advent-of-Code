#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<string> g;
int r, c, answer = 0;
vector<string> target = {"M.S.A.M.S", "M.M.A.S.S", "S.M.A.S.M", "S.S.A.M.M"};

void check(int t, int i, int j) {
    for (int di = 0, p = 0; di < 3; di++) {
        for (int dj = 0; dj < 3; dj++, p++) {
            if (target[t][p] == '.') continue;
            else if (target[t][p] != g[i + di][j + dj]) return;
        }
    }
    answer++;
}

void testcase() {
    string s;
    while (cin >> s) {
        g.push_back(s);
    }

    r = g.size(), c = g[0].size();
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            // check for target grids starting at each (i, j)
            for (int t = 0; t < 4; t++) check(t, i, j);
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
