// Example 1:
// Input: candidates = [16,17,71,62,12,24,14]
// Output: 4
// Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
// The size of the combination is 4.
// It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
// Note that more than one combination may have the largest size.
// For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int> candidates) { 
        int n = candidates.size(); 
        int max_freq = 0; 
        for(int i=0;i<32;i++){
            int freq = 0; 
            for(int ele : candidates){
                if(ele & (1<<i)) 
                    freq++;
            }
            max_freq=max(max_freq,freq);
        }
    return max_freq;
    }
};

int main(){
    Solution obj;
    vector<int> candidates = {16,17,71,62,12,24,14};
    cout << obj.largestCombination(candidates) << endl;
    return 0;
}