#include <bits/stdc++.h>
using namespace std;
#define int long long

bool checkAscending(vector<int> &l) {
    if (l.size() <= 2) return true;
    int n = l.size();
    for (int dampner = 0; dampner < n; dampner++) {
        int prev, next, count = 0;
        if (dampner == 0) prev = 1, next = 2;
        else if (dampner == 1) prev = 0, next = 2;
        else prev = 0, next = 1;

        while (next < n) {
            int diff = l[next] - l[prev];
            if (1 <= diff && diff <= 3) count++;            
          
            prev = next;
            while (next <= prev || next == dampner) next++;
        }

        if (count == n - 2) return true;
    }
    return false;
}

bool checkDescending(vector<int> &l) {
    if (l.size() <= 2) return true;
    int n = l.size();
    for (int dampner = 0; dampner < n; dampner++) {
        int prev, next, count = 0;
        if (dampner == 0) prev = 1, next = 2;
        else if (dampner == 1) prev = 0, next = 2;
        else prev = 0, next = 1;

        while (next < n) {
            int diff = l[prev] - l[next];
            if (1 <= diff && diff <= 3) count++;            
          
            prev = next;
            while (next <= prev || next == dampner) next++;
        }

        if (count == n - 2) return true;
    }
    return false;
}

void testcase() {
    int safeReports = 0;

    string report;
    while (getline(cin, report)) {
        stringstream ss(report);

        int level;
        vector<int> l;
        while (ss >> level) {
            l.push_back(level);
        }

        if (checkAscending(l) || checkDescending(l)) {
            safeReports++;
        }
    }

    cout << safeReports;
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
