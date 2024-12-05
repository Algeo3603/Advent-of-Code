#include <bits/stdc++.h>
using namespace std;
#define int long long

int answerPart1 = 0, answerPart2 = 0;
map<int, set<int>> pagesAfter, pagesBefore;
vector<vector<int>> queries;

void inputRules() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        stringstream ss(line);
        int a, b; char c;
        ss >> a >> c >> b;
        pagesAfter[a].insert(b);
        pagesBefore[b].insert(a);
    }
}

void inputQueries() {
    string line;
    while (getline(cin, line)) {
        vector<int> updates;
        int u; char c;
        stringstream ss(line);
        while (ss >> u) {
            updates.push_back(u);
            ss >> c;
        }
        queries.push_back(updates);
    }
}

bool isOrderGood(vector<int> &v) {
    int n = v.size();
    bool isGood = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pagesAfter[v[i]].find(v[j]) != pagesAfter[v[i]].end()) {
                isGood = false;
                break;
            }
        }
    }
    return isGood;
}

bool customComparator(int a, int b) {
    if (pagesAfter[a].find(b) != pagesAfter[a].end()) {
        return true;
    }
    if (pagesAfter[b].find(a) != pagesAfter[b].end()) {
        return false;
    }
    return true;
}

void testcase() {
    inputRules();
    inputQueries();

    for (vector<int> updates: queries) {
        int n = updates.size();
        
        bool isGood = isOrderGood(updates);
        if (isGood) {
            answerPart1 += updates[n / 2];
            continue;
        }

        vector<int> reorder = updates;
        sort(reorder.begin(), reorder.end(), customComparator);
        answerPart2 += reorder[n / 2];
    }

    cout << answerPart1 << "\n" << answerPart2;
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
