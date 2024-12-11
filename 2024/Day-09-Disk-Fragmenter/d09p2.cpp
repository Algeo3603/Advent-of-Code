#include <bits/stdc++.h>
using namespace std;
#define int long long


void testcase() {
    string diskMap;
    cin >> diskMap;

    vector<array<int, 2>> files;
    map<int, int> freeSpace;


    // assign file blocks and free blocks
    int ptr = 0;
    for (int i = 0; i < (int)diskMap.size(); i++) {
        int blockSize = diskMap[i] - '0';
        if ((i & 1) ^ 1) {
            files.push_back({ptr, blockSize});
        } else {
            freeSpace[ptr] = blockSize;
        }
        ptr += blockSize;
    }


    // move file blocks to earliest free blocks if possible
    for (int f = (int)files.size() - 1; f >= 0; f--) {
        int fileStart = files[f][0], fileSize = files[f][1];
        bool fsDelete = false;
        int fsPtr;
        for (auto [fsStart, fsSize]: freeSpace) {
            if (fsStart > fileStart) break;
            if (fsSize >= fileSize) {
                files[f][0] = fsStart;
                fsDelete = true; fsPtr = fsStart;
                if (fsSize > fileSize) {
                    freeSpace[fsStart + fileSize] = fsSize - fileSize;
                }
                break;
            }
        }

        if (fsDelete) {
            freeSpace.erase(fsPtr);
        }
    }


    // check score
    int answer = 0;
    for (int f = 0; f < (int)files.size(); f++) {
        int fileStart = files[f][0], fileSize = files[f][1];
        int positionSummation = (fileStart + fileSize - 1) * (fileStart + fileSize) / 2 - (fileStart - 1) * (fileStart) / 2;
        answer += positionSummation * f;
    }

    cout << answer;
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while (tc--) testcase();
    return 0;
}
