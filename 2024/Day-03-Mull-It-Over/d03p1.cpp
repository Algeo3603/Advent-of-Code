#include <bits/stdc++.h>
using namespace std;
#define int long long

int getNumber(string &s, int &i) {
    int n = 0;
    while (isdigit(s[i])) {
        n *= 10;
        n += s[i] - '0';
        i++;
    }

    if (1 <= n  && n <= 999) return n;
    else return -1; 
}

void testcase() {
    string s = "";
    char c;

    while (cin >> c) {
        s.push_back(c);
    }
    int n = s.size();
    s += "ALANGEORGE";

    int ans = 0, i = 0;

    while (i < n) {
        if (s.substr(i, 4) == "mul(") {
            i += 4;
            int x = getNumber(s, i);
            if (s[i++] != ',') {
                continue;
            }
            int y = getNumber(s, i);
            if (s[i++] != ')') {
                continue;
            }

            if (x != -1 && y != -1) {
                ans += x * y;
            }
        } else {
            i++;
        }
    }

    cout << ans;
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
