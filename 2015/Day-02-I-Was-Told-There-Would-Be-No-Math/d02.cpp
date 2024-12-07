#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    int wrappingPaper = 0, ribbon = 0;

    string dimensions;
    while (cin >> dimensions) {
        stringstream ss(dimensions);
        vector<int> d(3); char c;
        ss >> d[0] >> c >> d[1] >> c >> d[2];
        sort(d.begin(), d.end());

        wrappingPaper += 3 * d[0] * d[1] + 2 * d[1] * d[2] + 2 * d[0] * d[2];
        ribbon += 2 * (d[0] + d[1]) + d[0] * d[1] * d[2];
    }

    cout << "wrappingPaper: " << wrappingPaper << "\n";
    cout << "ribbon: " << ribbon << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
