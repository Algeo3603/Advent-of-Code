#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    vector<int> v;
    int a;
    while (cin >> a) {
        v.push_back(a);
    }

    for (int t = 0; t < 25; t++) {
        vector<int> temp;
        for (int i = 0; i < (int)v.size(); i++) {
            int digits = log10(v[i]) + 1;
            if (v[i] == 0) {
                temp.push_back(1);
            } else if (digits % 2 == 0) {
                int right = 0, left = 0;
                for (int j = 0, p = 1; j < digits / 2; j++) {
                    int d = v[i] % 10;
                    right += p * d;
                    v[i] /= 10; p *= 10;
                }
                for (int j = digits / 2, p = 1; j < digits; j++) {
                    int d = v[i] % 10;
                    left += p * d;
                    v[i] /= 10; p *= 10;
                }
                temp.push_back(left);
                temp.push_back(right);
            } else {
                temp.push_back(2024 * v[i]);
            }
        }

        v = temp;
    } 

    cout << v.size();
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
