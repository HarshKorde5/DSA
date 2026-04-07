/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

*/
class Solution {

    /*
      Two Pointer Approach
      For each boundary check if both characters are equal.
      If not equal exit early.
      Time complexity : O(N)
      Space complexity : O(1)
    */
    public boolean isPalindrome(String s) {

        if(s.isEmpty()) return true;
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            char l = s.charAt(left);
            char r = s.charAt(right);

            if(!Character.isLetterOrDigit(l)){
                left++;
                continue;
            }

            if(!Character.isLetterOrDigit(r)){
                right--;
                continue;
            }

            if(Character.toLowerCase(l) != Character.toLowerCase(r)){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}

class Main{
  public static void main(String[] args){
    Solution sobj = new Solution();
    String str = "A man, a plan, a canal: Panama";
    boolean ret = sobj.isPalindrome(str);
    if(ret){
    
      System.out.println("String \""+str+"\" is palindrome string.");
    }else{
    System.out.println("String \""+str+"\" is not palindrome string.");
    }
  }
}
