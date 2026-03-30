#include<iostream>
#include<stdio.h>

using namespace std;


class Solution{
    public:
    bool isAnagram(string s, string t){
        int freq[26] = {0};

        for(int i = 0;i < s.length(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26;i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }

};

int main(){

    Solution s;
    string str1 = {"rat"};
    string str2 = {"car"};

    cout<<s.isAnagram(str1,str2);

    return 0;
}