#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<string> grid;
int R, C;
vector<vector<int>> antinode;
map<char, vector<pair<int, int>>> m;

pair<int, int> getGap(pair<int, int> &a, pair<int, int> &b) {
    return {a.first - b.first, a.second - b.second};
}

bool withinGrid(int r, int c) {
    if (0 <= r && r < R && 0 <= c && c < C) return true;
    return false;
}

void testcase() {
    // input
    string s;
    while (cin >> s) {
        grid.push_back(s);
    }
    R = grid.size(), C = grid[0].size();
    antinode.assign(R, vector<int>(C));

    // store positions in map
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == '.') continue;
            m[grid[r][c]].push_back({r, c});
        }
    }

    // calculate gap and check if antinode lies within area
    for (auto [antenna, v]: m) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // first antinode
                pair<int, int> gap = getGap(v[i], v[j]);
                int rnew = v[i].first + gap.first;
                int cnew = v[i].second + gap.second;
                if (withinGrid(rnew, cnew)) {
                    antinode[rnew][cnew]++;
                }

                // second antinode
                gap = getGap(v[j], v[i]);
                rnew = v[j].first + gap.first;
                cnew = v[j].second + gap.second;
                if (withinGrid(rnew, cnew)) {
                    antinode[rnew][cnew]++;
                }
            }
        }
    }

    // count antinodes
    int answer = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (antinode[r][c]) {
                answer++;
            }
        }
    }

    cout << answer << "\n";
    // for (int r = 0; r < R; r++) {
    //     for (int c = 0; c < C; c++) {
    //         cout << antinode[r][c];
    //     }
    //     cout << "\n";
    // }
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
