// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".



#include <bits/stdc++.h>

using namespace std;

string makeFancyString(string s){
    int length = s.length();
    string res = "";
    res.push_back(s[0]);
    res.push_back(s[1]);
    for(int i = 2;i<length;i++){
        if(s[i] == s[i-1] && s[i] == s[i-2]){
            continue;
        }else{
            res.push_back(s[i]);
        }
    }
    return res;
}

int main(){

    string s = "leeetcode";
    cout << makeFancyString(s)<<endl;
    string st = "aaabaaaa";
    cout << makeFancyString(st)<<endl;
    string str = "aab";
    cout << makeFancyString(str)<<endl;

    return 0;
}