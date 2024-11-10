/* You are given an array nums of non-negative integers and an integer k.
An array is called special if the bitwise OR of all of its elements is at least k.
Return the length of the shortest special non-empty 
subarray of nums, or return -1 if no special subarray exists.

Example 1:
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void updateFreq(vector<int>& bitFreq, int number, int val) {
        for(int i = 0; i < 32; ++i)
            if(number & (1 << i))
                bitFreq[i] += val;
    }
    
    int getNumber(vector<int>& bitFreq) {
        int number = 0;
        for(int i = 0; i < 32; ++i) {
            if(bitFreq[i] > 0)
                number |= (1 << i);
        }
        return number;
    }
    
public:
    int minimumSubarrayLength(vector<int> nums, int k) {
        if(k == 0) return 1;
        int n = nums.size();
        int shortest = INT_MAX;
        int left = 0, right = 0;
        vector<int> bitFreq(32, 0);
        
        while(right < n) {
            // Add current number to frequency
            updateFreq(bitFreq, nums[right], 1);
            
            // Calculate current OR value
            int currOR = getNumber(bitFreq);
            
            // If we found a valid subarray
            while(left <= right && currOR >= k) {
                shortest = min(shortest, right - left + 1);
                
                // Try to minimize by removing elements from left
                updateFreq(bitFreq, nums[left], -1);
                currOR = getNumber(bitFreq);
                left++;
            }
            
            right++;
        }
        
        return shortest == INT_MAX ? -1 : shortest;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2,1,8};
    int k = 10;
    int ans = obj.minimumSubarrayLength(nums, k);
    cout << ans << endl;
    return 0;
}