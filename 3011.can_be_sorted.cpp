#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBitCount(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }

    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        if (nums.size() <= 1 || isSorted(nums)) return true;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j] && setBitCount(nums[i]) == setBitCount(nums[j])) {
                    swap(nums[i], nums[j]);
                    if (isSorted(nums)) return true;
                    i = -1; // Restart the check from the start after swapping
                    break;
                }else if (nums[i] > nums[j] && setBitCount(nums[i]) != setBitCount(nums[j])) return false;
            }
        }
        return isSorted(nums);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {75,34,30};
    cout << (obj.canSortArray(nums) ? "true" : "false") << endl;
    return 0;
}
