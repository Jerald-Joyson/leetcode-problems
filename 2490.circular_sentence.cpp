// Input: sentence = "leetcode exercises sound delightful"
// Output: true
// Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
// - leetcode's last character is equal to exercises's first character.
// - exercises's last character is equal to sound's first character.
// - sound's last character is equal to delightful's first character.
// - delightful's last character is equal to leetcode's first character.
// The sentence is circular.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCircularSentence(string sentence) {
        int length = sentence.length();
        
        if(length<1) return false;
        
        if(sentence[0]!=sentence[length-1]) return false;

        for(int i=0;i<length;i++){
            if(sentence[i] == ' '){
                if(sentence[i-1]!=sentence[i+1]) return false;
            }
        }

        return true;
    }
};

int main(){
    Solution obj;
    string sentence = "leetcode exercises sound delightful";
    cout <<(obj.isCircularSentence(sentence) ? "true" : "false")<<endl;
    return 0;
}