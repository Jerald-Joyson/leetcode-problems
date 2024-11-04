// Example 1:
// Input: word = "abcde"
// Output: "1a1b1c1d1e"
// Explanation:
// Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
// For each prefix, append "1" followed by the character to comp.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char _countChar = word[0];

        if(word.length()<1){
            return word;
        }
        int count = 0;

        for(int i=0;i<=word.length();i++){
            char temp = word[i];
            if(temp == _countChar){
                if(count == 9){
                    string val = to_string(count);
                    comp.append(val);
                    comp += _countChar;
                    count = 1;
                }else{
                    count = count + 1;
                }
            }else{
                string val = to_string(count);
                comp.append(val);
                comp += _countChar;
                count = 1;
                _countChar = temp;
            }
        }
        return comp;
    }
};

int main(){
    Solution obj;
    string word = "aaaaaaaaaaaaaabb";
    cout <<obj.compressedString(word)<<endl;
    return 0;
}