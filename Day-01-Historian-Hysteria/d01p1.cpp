#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    vector<int> list1, list2;
    int l1, l2;
    while (cin >> l1 >> l2) {
        list1.push_back(l1);
        list2.push_back(l2);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int ans = 0;
    for (int i = 0; i < (int)list1.size(); i++) {
        ans += abs(list1[i] - list2[i]);
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
