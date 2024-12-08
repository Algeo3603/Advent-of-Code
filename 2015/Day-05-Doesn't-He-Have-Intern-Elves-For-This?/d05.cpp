#include <bits/stdc++.h>
using namespace std;
#define int long long

int countVowels(string &s) {
    int count = 0;
    string vowels = "aeiou";
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)vowels.size(); j++) {
            if (s[i] == vowels[j]) count++;
        }
    }
    return count;
}

bool checkAdjacentRepeat(string &s) {
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) return true;
    }
    return false;
}

bool checkForbidden(string &s) {
    vector<string> f = {"ab", "cd", "pq", "xy"};
    for (auto t: f) {
        if (s.find(t) != string::npos) return false;
    }
    return true;
}

bool checkSandwich(string &s) {
    for (int i = 0; i < (int)s.size() - 2; i++) {
        if (s[i] == s[i + 2]) return true;
    }
    return false;
}

bool pairRepeat(string &s) {
    for (int i = 0; i < (int)s.size() - 1; i++) {
        string target = s.substr(i, 2);
        auto it = s.rfind(target);
        if (it == string::npos) continue;
        if ((int)it > i + 1) return true;
    }
    return false;
} 

void testcase() {
    string s;
    int answer1 = 0, answer2 = 0;

    while (cin >> s) {
        int vowels = countVowels(s);
        bool adjacentRepeat = checkAdjacentRepeat(s);
        bool noForbidden = checkForbidden(s);
        if (vowels >= 3 && adjacentRepeat && noForbidden) {
            answer1++;
        }

        bool pairRepeats = pairRepeat(s);
        bool sandwichExists = checkSandwich(s);
        if (pairRepeats && sandwichExists) {
            answer2++;
        }
    }

    cout << "PART1: " << answer1 << "\n";
    cout << "PART2: " << answer2 << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
