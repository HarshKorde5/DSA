#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        int end = 0;
        int n = s.length();
        int table[256] = {0};

        while(end < n){

            if(table[s[end]] == 0){
                table[s[end]] = 1;
                end++;
                maxLen = ( maxLen > (end - start) ) ? maxLen : (end - start);

            }else{
                table[s[start]] = 0;
                start++;
            }
        }

        return maxLen;
    }

};


int main(){
    Solution s;
    string str = {"abcabcbb"};
    cout<<s.lengthOfLongestSubstring(str);

    return 0;
}