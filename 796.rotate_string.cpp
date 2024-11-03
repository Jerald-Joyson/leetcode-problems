// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:
// Input: s = "abcde", goal = "abced"
// Output: false


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;

        string temp = s;

        for(int i=0;i<s.length();i++){
            temp.push_back(temp[0]);
            temp.erase(temp.begin());
            if(temp==goal) return true;
        }
        return false;
    }
};


int main(){
    Solution obj;
    string s = "abcde";
    string goal = "abced";
    cout <<(obj.rotateString(s,goal) ? "true" : "false")<<endl;
    return 0;
}