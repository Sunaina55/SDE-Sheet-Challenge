#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    int idx = 0;

    for (int i = m; i < m + n; i++) {
        nums1[i] = nums2[idx];
        idx++;
    }

    sort(nums1.begin(), nums1.end());

    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}