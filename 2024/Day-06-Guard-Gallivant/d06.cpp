#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<string> LAB;
vector<vector<array<bool, 4>>> isVisited;
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
        LAB.push_back(s);
    }
    R = LAB.size();
    C = LAB[0].size();
    isVisited.assign(R, vector<array<bool, 4>>(C)); // re assign every time
}


void printLab() {
    for (int r = 0; r < R; r++) {
        cout << LAB[r] << "\n";
    }
}


int countVisitedCells(vector<string> &lab) {
    int visited = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (lab[r][c] == 'X') visited++;
        }
    }
    return visited;
}


void getGuardPosition(position &guard) {
    for (int r = 0; r < (int)LAB.size(); r++) {
        for (int c = 0; c < (int)LAB[0].size(); c++) {
            if (LAB[r][c] == '^') {
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

bool obstructionAhead(position &guard, vector<string> &lab) {
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


int simulate(position guard, vector<string> lab) {
    lab[guard.r][guard.c] = 'X';

    while (true) {
        if (isVisited[guard.r][guard.c][ptr]) {
            return -1;
        } else {
            isVisited[guard.r][guard.c][ptr] = true;
        }

        if (movesOutsideLab(guard)) {
            break;
        } else if (obstructionAhead(guard, lab)) {
            turnRight();
        } else {
            stepForward(guard);
            lab[guard.r][guard.c] = 'X';
        }
    }

    return countVisitedCells(lab);
}

bool canPlaceObstruction(int obsR, int obsC, position &guard) {
    if (LAB[obsR][obsC] == '#') return false;
    if (obsR == guard.r && obsC == guard.c) return false;
    return true;
}


void testcase() {
    getInput();

    position guard;
    getGuardPosition(guard);

    // PART 1
    // Check number of visited cell
    vector<string> lab = LAB;
    int answer1 = simulate(guard, lab);
    cout << "ANSWER 1: " << answer1 << "\n";

    // PART 2
    // try placing an obstruction at every cell
    int answer2 = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (canPlaceObstruction(r, c, guard)) {
                lab = LAB; lab[r][c] = '#';
                ptr = 0;
                isVisited.assign(R, vector<array<bool, 4>>(C));
                int result = simulate(guard, lab);
                if (result == -1) answer2++;
            }
        }
    }
    cout << "ANSWER 2: " << answer2 << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
