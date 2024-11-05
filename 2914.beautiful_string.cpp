// Example 1:
// Input: s = "1001"
// Output: 2
// Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
// It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
// It can be proven that 2 is the minimum number of changes needed to make the string beautiful.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPair(char a,char b){
        if(a == b) return true;
        return false;
    }
    int minChanges(string s) {

        int count = 0;
        for(int i = 0;i<s.size();i+=2){
            if(checkPair(s[i],s[i+1])) continue;
            else{
                char temp = s[i];
                s[i+1] = temp;
                count++;
            }
        }
        return count;
    }
};

int main(){
    string s = "1001";
    Solution obj;
    cout<<obj.minChanges(s);
    return 0;
}