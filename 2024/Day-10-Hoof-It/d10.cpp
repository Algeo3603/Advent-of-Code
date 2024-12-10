#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<string> grid;
int R, C;
string path ="0123456789";
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

void check(int r, int c, int p, set<pair<int, int>> &endPoints, int &answer2) {
    if (grid[r][c] != path[p]) return;
    if (p == 9) {
        endPoints.insert({r, c});
        answer2++;
        return;
    }

    for (int move = 0; move < 4; move++) {
        int newR = r + dr[move], newC = c + dc[move];
        if (0 <= newR && newR < R && 0 <= newC && newC < C) {
            check(newR, newC, p + 1, endPoints, answer2);
        }
    }
}

void testcase() {
    string s;
    while (cin >> s) {
        grid.push_back(s);
    }
    R = grid.size(), C = grid[0].size();

    int answer1 = 0, answer2 = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            set<pair<int, int>> endPoints;
            check(r, c, 0, endPoints, answer2);
            answer1 += endPoints.size();
        }
    }

    cout << "PART1: " << answer1 << "\n";
    cout << "PART2: " << answer2 << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
