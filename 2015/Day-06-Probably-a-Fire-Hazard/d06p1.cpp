#include <bits/stdc++.h>
using namespace std;
#define int long long

bool grid[1000][1000];

void toggleGrid(int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            grid[r][c] ^= true;
        }
    }
}

void setGrid(int r1, int c1, int r2, int c2, bool state) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            grid[r][c] = state;
        }
    }
}

int countLights() {
    int cnt = 0;
    for (int r = 0; r < 1000; r++) {
        for (int c = 0; c < 1000; c++) {
            if (grid[r][c]) cnt++;
        }
    }
    return cnt;
}

void testcase() {
    memset(grid, 0, sizeof(grid));

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        char c;
        int r1, c1, r2, c2, type;
        
        ss >> s;
        if (s == "toggle") {
            type = 3;
        } else {
            ss >> s;
            if (s == "on") type = 1;
            else type = 2;
        }
        ss >> r1 >> c >> c1 >> s >> r2 >> c >> c2;
 
        if (type == 3) toggleGrid(r1, c1, r2, c2);
        else if (type == 1) setGrid(r1, c1, r2, c2, true);
        else setGrid(r1, c1, r2, c2, false);
    }

    cout << countLights();
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
