/*
in three steps - 
1) pichhe se loop lga ke pehle aisa index find kiya jaha pe nums[i] < nums[i+1] ho
2) agar aisa index nahi mila to array ko reverse kar do
3) agar aisa index mila to uske baad se loop lga ke pehle aisa index find kiya jaha pe nums[i] > nums[index] ho, usko swap kar do
4) uske baad index+1 se end tak array ko reverse kar do
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2,1,5,4,3,0,0};

    int n = nums.size();
    int index = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(nums.begin(), nums.end());
    } else {
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}