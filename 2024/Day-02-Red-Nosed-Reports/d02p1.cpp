#include <bits/stdc++.h>
using namespace std;
#define int long long

bool checkAscending(vector<int> &l) {
    for (int i = 1; i < (int)l.size(); i++) {
        int diff = l[i] - l[i - 1];
        if (1 <= diff && diff <= 3) continue;
        else return false;
    }
    return true;
}

bool checkDescending(vector<int> &l) {
    for (int i = 1; i < (int)l.size(); i++) {
        int diff = l[i - 1] - l[i];
        if (1 <= diff && diff <= 3) continue;
        else return false;
    }
    return true;
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
