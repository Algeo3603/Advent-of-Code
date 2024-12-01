#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    map<int, int> mp1, mp2;
    int l1, l2;
    while (cin >> l1 >> l2) {
        mp1[l1]++;
        mp2[l2]++;
    }

    int ans = 0;
    for (auto &[key, val]: mp1) {
        ans += val * key * mp2[key];
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
