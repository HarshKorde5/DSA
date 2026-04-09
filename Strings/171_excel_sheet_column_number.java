/*
171. Excel Sheet Column Number

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 */
 
 class Solution {
 
  /*
    Building up approach
    
    For excel sheet the number system is base 26
    So everytime we deal with a character it is supposed to shift the previous buildup to base 26 places left
    And then add up the current character's ASCII - 'A'
    +1 is important as ASCII - 'A' gives 0 for 'A' - 'A' whereas excel starts with 'A' = 1.
    
    Time complexity : O(N)
    Space complexity : O(1)
  */
    public int titleToNumber(String columnTitle) {
        int res = 0;

        for(int i = 0; i < columnTitle.length(); i++){
            res = res*26 + ((columnTitle.charAt(i) - 'A') + 1);
        }

        return res;
    }
}


class Main{
  public static void main(String[] args){
    
	  Solution sobj = new Solution();
	  
    String columnTitle = "ZY";
    
    int res = sobj.titleToNumber(columnTitle);
    
    System.out.println("Column number for column title : "+columnTitle+" is : "+res);
	}
}
