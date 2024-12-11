#include <bits/stdc++.h>
using namespace std;
#define int long long

map<int, map<int, int>> dp; 
// dp[num][b] = numbers of resulting elements 'num' would transform to after 'b' blinks

int blink(int num, int remaining) {
    if (dp[num].find(remaining) != dp[num].end()) {
        return dp[num][remaining];
    } else if (remaining == 0) {
        return dp[num][remaining] = 0;
    }

    int digits = log10(num) + 1;
    int a = num;
    if (num == 0) {
        return blink(1, remaining - 1);
    } else if (digits % 2 == 0) {
        int right = 0, left = 0;
        for (int j = 0, p = 1; j < digits / 2; j++) {
            int d = a % 10;
            right += p * d;
            a /= 10; p *= 10;
        }
        for (int j = digits / 2, p = 1; j < digits; j++) {
            int d = a % 10;
            left += p * d;
            a /= 10; p *= 10;
        }
        return dp[num][remaining] = 1 + blink(left, remaining - 1) + blink(right, remaining - 1);
    } else {
        return dp[num][remaining] = blink(2024 * num, remaining - 1);
    }

    return 55;
}

void testcase() {
    vector<int> v;
    int a;
    while (cin >> a) {
        v.push_back(a);
    }

    int answer = v.size();
    for (int i: v) {
        answer += blink(i, 75);
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
