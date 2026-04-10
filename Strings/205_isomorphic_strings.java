/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

import java.util.*;

class Solution {

    /*
      Constant space
      We store the index at which the character had occured.
      If the index for both mismatch strings are not isomorphic.
      
      Note storing i + 1 is due to array indexing starting with 0, and default value becomes 0 for new array.
      Doing i + 1, will remove this ambiguity.
      
      Time complexity : O(N)
      Space complexity : O(1) - constant space of 256.
    */
    public boolean isIsomorphic(String s, String t){
        int[] mps = new int[256];
        int[] mpt = new int[256];

        for(int i = 0; i < s.length(); i++){
            char a = s.charAt(i);
            char b = t.charAt(i);

            if(mps[a] != mpt[b]){
                return false;
            }

            mps[a] = i + 1;
            mpt[b] = i + 1;
        }

        return true;
    }
    
    /*
      2-maps
      We use hashmaps to keep a track of mapping of characters from s -> t, and t -> s
      Note it is important to track bidirectionally.
      Let a = current character of s
      Let b = current character of t
      If a is present in corresponding map of s, AND it does not have value b, this is a mismatch and turns out false.
      If b is present in corresponding map of t, AND it does not have value a, this is a mismatch and turns out false.
      Time complexity : O(N)
      Space complexity : O(N)      
    */

    public boolean isIsomorphic_02(String s, String t){
        Map<Character,Character> mps = new HashMap<>();
        Map<Character,Character> mpt = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            char a = s.charAt(i);
            char b = t.charAt(i);

            if(mps.containsKey(a)){
                if(mps.get(a) != b){
                    return false;
                }                
            }else{
                mps.put(a,b);
            }

            if(mpt.containsKey(b)){
                if(mpt.get(b) != a){
                    return false;
                }
            }else{
                mpt.put(b,a);
            }            
        }

        return true;
    }


    /*
      Single map
      Strip down to single map compared to the solution using 2 maps,
      The key idea here is, checking bidirectionally in a indirect way.
      If key a is present it should have value b, if not turns out false.
      But for corresponding bidirectional check i.e. b->a, we can simply check if map contains a value b already.
      If value b is there in map, without its occurence as a key before anywhere, it tells the value b has already being mapped to some other key, so this gives a mismatch.
      
      Time Complexity : O(N)
      Space Complexity : O(N) - slightly better because of single map.
    */
    public boolean isIsomorphic_01(String s, String t) {
        Map<Character,Character> mp = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            char a = s.charAt(i);
            char b = t.charAt(i);

            if(mp.containsKey(a)){
                if(mp.get(a) != b){
                    return false;
                }
            }else if(mp.containsValue(b)){
                return false;
            }

            mp.put(a,b);
        }

        return true;
    }
}

class Main{
  public static void main(String[] args){
    
    Solution sobj = new Solution();
    String s = "paper";
    String t = "title";
    bool res = sobj.isIsomorphic(s,t);
    
    if(res){
      System.out.println("Strings \""+s"\" and \""+t"\" are isomorphic strings."); 
    }else{
    
      System.out.println("Strings \""+s"\" and \""+t"\" are not isomorphic strings.");
    }
    }
}
