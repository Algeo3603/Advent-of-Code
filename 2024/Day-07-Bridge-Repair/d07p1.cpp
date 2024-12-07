#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    vector<int> results;
    vector<vector<int>> equations;

    // input
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        int res; ss >> res;
        results.push_back(res);
        char c; ss >> c;
        equations.push_back({});
        int num;
        while (ss >> num) {
            equations.back().push_back(num);
        }
    }

    int answer = 0;
    // iterate over the equations, brute force the operators
    int n = results.size();
    for (int i = 0; i < n; i++) {
        int signs = equations[i].size() - 1;
        for (int operators = 0; operators < (1 << signs); operators++) {
            // check if the current sequence of operators satisfies
            // 0 -> addition, 1 -> multiplication
            int res = equations[i][0];
            for (int k = 0; k < signs; k++) {
                if ((operators & (1 << k))) {
                    // multiply
                    res *= equations[i][k + 1];
                } else {
                    // add
                    res += equations[i][k + 1];
                }
            }

            if (res == results[i]) {
                answer += results[i];
                break;
            }
        }
    }

    cout << answer << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
