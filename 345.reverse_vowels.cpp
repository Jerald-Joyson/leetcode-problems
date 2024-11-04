// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm"
// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch); // Handle case sensitivity by converting to lowercase.
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {
        int lptr = 0, rptr = s.size() - 1;

        // Loop until the two pointers meet
        while (lptr < rptr) {
            // Move the left pointer until it finds a vowel
            while (lptr < rptr && !isVowel(s[lptr])) {
                lptr++;
            }

            // Move the right pointer until it finds a vowel
            while (lptr < rptr && !isVowel(s[rptr])) {
                rptr--;
            }

            // Swap the vowels found at lptr and rptr
            if (lptr < rptr) {
                swap(s[lptr], s[rptr]);
                lptr++;
                rptr--;
            }
        }
        return s;
    }
};

int main(){
    Solution obj;
    string s = "leetcode";
    cout <<obj.reverseVowels(s)<<endl;
    return 0;
}