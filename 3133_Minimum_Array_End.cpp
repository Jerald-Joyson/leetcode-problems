// You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
// Return the minimum possible value of nums[n - 1].

// Example 1:
// Input: n = 3, x = 4
// Output: 6
// Explanation:
// nums can be [4,5,6] and its last element is 6.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getBin(int n) {
        vector<int> res;
        while(n) {
            res.push_back(n & 1);
            n >>= 1;
        }
        return res;
    }
    
public:
    long long minEnd(int n, int x) {
        // Base case: if n is 1, return x
        if(n == 1) return x;
        
        // Step 1: Find positions of zeros in binary representation of x
        vector<int> zero_pos;
        int count = 0;
        int val = x;
        
        // Get the highest bit position in x
        int max_bit = 0;
        int temp = x;
        while(temp) {
            max_bit++;
            temp >>= 1;
        }
        
        // Record positions of zeros
        for(int i = 0; i < max_bit; i++) {
            if(!(x & (1 << i))) {
                zero_pos.push_back(i);
            }
        }
        count = max_bit;
        
        // Step 2: Calculate required bits to make n combinations
        int reqd_bits = ceil(log2(n));
        
        // Step 3: Append more positions for bits as needed
        while(zero_pos.size() < reqd_bits) {
            zero_pos.push_back(count++);
        }
        
        // Step 4: Get binary representation of (n-1)
        vector<int> append_bits = getBin(n-1);
        
        // Step 5: Construct the final answer
        long long ans = x;
        int pos = min((int)append_bits.size(), (int)zero_pos.size());
        
        // Add necessary powers of 2 based on append_bits
        for(int i = 0; i < pos; i++) {
            if(i < append_bits.size() && append_bits[i] == 1) {
                ans += (1LL << zero_pos[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.minEnd(3, 4) << endl;
    return 0;
}