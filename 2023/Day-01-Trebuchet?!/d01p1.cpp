#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    int answer = 0;
    string s;
    while (cin >> s) {
        int n = s.size();
        int value = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                value += 10 * (s[i] - '0');
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                value += (s[i] - '0');
                break;
            }
        }
        answer += value;
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
