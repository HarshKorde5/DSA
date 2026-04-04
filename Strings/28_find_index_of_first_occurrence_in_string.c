/*
28. Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include<stdio.h>
#include<string.h>
/*
If first character match with needle[0],
then we need to check if subsequent characters also match with haystack.
To check so without repeating we can just manipulate the index (i + j).
Time complexity : O(N
*/
int strStr(char* haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);

    if(m == 0) return 0;

    for(int i = 0; i <= m - n; i++){
        if(haystack[i] == needle[0]){
            int j = 1;            
            while(j < n && needle[j] == haystack[i + j]){
                j++;
            }
            if(j == n) return i;
        }
    }

    return -1;
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";

    printf("%d\n", strStr(haystack, needle));
    return 0;
}
