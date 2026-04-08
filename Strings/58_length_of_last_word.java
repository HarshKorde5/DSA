/*

58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 
*/
class Solution {

    /*
      One pass solution
      Start from the end of the string.
      As string contains trailing spaces so we need to skip (if present) trailing spaces.
      As soon as any character appears, start counting the length until new space occurs.
      This is the length of the last word in the string.
      Time complexity : O(N)
      Space complexity : O(1)
    */
    public int lengthOfLastWord(String s) {
        int end = s.length() - 1;

        while(end >= 0 && s.charAt(end) == ' '){
            end--;
        }

        int start = end;
        while(end >= 0 && s.charAt(end) != ' '){
            end--;
        }

        return  start - end;
    }

    public int lengthOfLastWord_01(String s) {
        int idx = s.length() - 1;
        int len = 0;
        boolean start = false;
        while(idx >= 0){
            if(s.charAt(idx) != ' ' && !start){
                start = true;
            }
            
            if(start){
                if(s.charAt(idx) == ' '){
                    break;
                }
                len++;
            }

            idx--;
        }


        return len;
    }
}



class Main{
  public static void main(String[] args){
    
	  Solution sobj = new Solution();
	  String str = "   fly me   to   the moon  ";
		int ret = sobj.lengthOfLastWord(str);
		System.out.println("Length of last word is : "+ret);
		
	   
	}
}
