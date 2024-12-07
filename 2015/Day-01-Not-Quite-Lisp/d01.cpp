#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    string instructions;
    cin >> instructions;

    int floor = 0;
    bool part2 = false;
    for (int i = 0; i < (int)instructions.size(); i++) {
        if (instructions[i] == '(') ++floor;
        else --floor;

        if (floor == -1 && !part2) {
            cout << "PART2: " << i + 1 << "\n";
            part2 = true;
        }
    } 

    cout << "PART1: " << floor << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
