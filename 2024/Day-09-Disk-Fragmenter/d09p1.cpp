#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    string diskMap;
    cin >> diskMap;

    int fileNumber = 0;
    vector<int> v;
    for (int i = 0; i < (int)diskMap.size(); i++) {
        for (int j = 0; j < (int)diskMap[i] - '0'; j++) {
            if ((i & 1) ^ 1) {
                v.push_back(fileNumber);
            } else {
                v.push_back(-1);
            }
        }
        if ((i & 1) ^ 1) fileNumber++;
    }

    int l = 0, r = v.size() - 1;
    while (l < r && l < (int)v.size() && r >= 0) {
        if (v[l] != -1) {
            l++; continue;
        } else if (v[r] == -1) {
            r--; continue;
        } else {
            swap(v[l], v[r]);
        }
    }

    int answer = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] != -1) {
            answer += v[i] * i;
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
