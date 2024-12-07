#include <bits/stdc++.h>
using namespace std;
#define int long long

int getDigit(string &s, int idx, int n) {
    map<string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    if (isdigit(s[idx])) {
        return s[idx] - '0';
    }
    for (auto [key, val]: m) {
        int len = key.size();
        if (idx + len <= n && s.substr(idx, len) == key) {
            return val;
        }
    }
    return -1;
}

void testcase() {
    int answer = 0;
    string s;
    while (cin >> s) {
        int n = s.size();
        int value = 0;
        for (int i = 0; i < n; i++) {
            int digit = getDigit(s, i, n);
            if (digit != -1) {
                value = 10 * digit;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = getDigit(s, i, n);
            if (digit != -1) {
                value += digit;
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
