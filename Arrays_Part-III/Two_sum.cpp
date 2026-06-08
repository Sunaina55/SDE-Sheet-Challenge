#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int needmore = target - num;

        if (mpp.find(needmore) != mpp.end()) {
            cout << mpp[needmore] << " " << i << endl;
            return 0;
        }

        mpp[num] = i;
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}