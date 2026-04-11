/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

class Solution {

    /*
      Frequency Array
      The input strings contain only lowercase english letters which are total 26.
      A frequency array of 26 letters which will correspond to their frequency in each string.
      In order for strings to be anagram, each character must have same frequency.
      If increasing and decreasing the frequency of each character simultaneously leads to zero at the end of iteration gives a valid anagram.
      If any value other than zero occurs it states frequency mismatch and not a valid anagram.
      
      Time Complexity : O(N)
      Space Complexity : O(1) -> Constant space of int[26]
    */
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;

        int[] freq = new int[26];

        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }

        for(int x : freq){
            if(x != 0) return false;
        }

        return true;
    }

    public boolean isAnagram_01(String s, String t) {

        if(s.length() != t.length()) return false;

        int[] freq = new int[26];

        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            freq[t.charAt(i) - 'a']--;
        }

        for(int x : freq){
            if(x != 0)  return false;
        }

        return true;
    }
}


class Main{
  public static void main(String[] args){
    
    Solution sobj = new Solution();
    String s = "anagram";
    String t = "nagaram";
    boolean res = sobj.isAnagram(s,t);
    
    if(res){
      System.out.println("Strings \""+s+"\" and \""+t+"\" are anagram strings."); 
    }else{
    
      System.out.println("Strings \""+s+"\" and \""+t+"\" are not anagram strings.");
    }
    }
}

