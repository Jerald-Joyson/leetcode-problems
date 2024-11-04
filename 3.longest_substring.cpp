// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lptr=0,rptr=0;
        int curMax=0,maxLength=0;

        while(rptr<s.size()){

            // check for duplicate values

            for(int i = lptr;i<rptr;i++){
                if(s[i] == s[rptr]){
                    lptr = i+1;
                    break;
                }
            }

            rptr++;
            curMax = rptr - lptr;
            maxLength = max(curMax,maxLength);
        }
        return maxLength;
    }
}; 

int main(){
    Solution obj;
    string s = "abcabcbb";
    cout <<obj.lengthOfLongestSubstring(s)<<endl;
    return 0;
}