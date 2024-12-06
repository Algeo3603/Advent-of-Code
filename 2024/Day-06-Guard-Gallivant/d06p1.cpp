#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<string> lab;
int R, C, ptr = 0;
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};


struct position {
    int r, c;
    position(int row = 0, int col = 0) {
        r = row;
        c = col;
    }
};


void getInput() {
    string s;
    while (cin >> s) {
        lab.push_back(s);
    }
    R = lab.size();
    C = lab[0].size();
}


void printLab() {
    for (int r = 0; r < R; r++) {
        cout << lab[r] << "\n";
    }
}


int countVisitedCells() {
    int visited = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (lab[r][c] == 'X') visited++;
        }
    }
    return visited;
}


void getGuardPosition(position &guard) {
    for (int r = 0; r < (int)lab.size(); r++) {
        for (int c = 0; c < (int)lab[0].size(); c++) {
            if (lab[r][c] == '^') {
                guard.r = r;
                guard.c = c;
                return;
            }
        }
    }
}


bool movesOutsideLab(position &guard) {
    int newR = guard.r + dr[ptr];
    int newC = guard.c + dc[ptr];
    if (newR < 0 || newR >= R) return true;
    if (newC < 0 || newC >= C) return true;
    return false;
}

bool obstructionAhead(position &guard) {
    int newR = guard.r + dr[ptr];
    int newC = guard.c + dc[ptr];
    if (lab[newR][newC] == '#') return true;
    else return false;
}


void turnRight() {
    ptr = (ptr + 1) % 4;
}


void stepForward(position &guard) {
    guard.r += dr[ptr];
    guard.c += dc[ptr];
}


void testcase() {
    getInput();

    position guard;
    getGuardPosition(guard);

    lab[guard.r][guard.c] = 'X';
    while (true) {
        if (movesOutsideLab(guard)) {
            break;
        } else if (obstructionAhead(guard)) {
            turnRight();
        } else {
            stepForward(guard);
            lab[guard.r][guard.c] = 'X';
        }
    }

    int answer = countVisitedCells();
    cout << answer << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
