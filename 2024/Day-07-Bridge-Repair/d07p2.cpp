#include <bits/stdc++.h>
using namespace std;
#define int long long

int answer = 0;


bool findOperators(string &operators, int &signs, vector<int> &equation, int &target) {
    if ((int)operators.size() == signs) {
        int res = equation[0];
        for (int i = 0; i < signs; i++) {
            if (operators[i] == '+') {
                res += equation[i + 1];
            } else if (operators[i] == '*') {
                res *= equation[i + 1];
            } else {
                int digits = log10(equation[i + 1]) + 1;
                for (int j = 0; j < digits; j++) res *= 10;
                res += equation[i + 1];
            }

            if (res > target) {
                return false;
            }
        }

        if (res == target) {
            answer += target;
            return true;
        }
        return false;
    }

    // resursively try operators
    string options = "+*|";
    for (int i = 0; i < 3; i++) {
        operators.push_back(options[i]);
        bool foundOperators = findOperators(operators, signs, equation, target);
        operators.pop_back();
        if (foundOperators) return true;
    }

    return false;
}


void testcase() {
    vector<int> results;
    vector<vector<int>> equations;

    // input
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        int res; ss >> res;
        results.push_back(res);
        char c; ss >> c;
        equations.push_back({});
        int num;
        while (ss >> num) {
            equations.back().push_back(num);
        }
    }

    // iterate over the equations, brute force the operators
    int n = results.size();
    for (int i = 0; i < n; i++) {
        int signs = equations[i].size() - 1;
        string operators = "";
        findOperators(operators, signs, equations[i], results[i]);
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
