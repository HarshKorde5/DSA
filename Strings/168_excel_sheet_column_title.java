/*
168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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
      Mod approach
      Excel starts from A -> 1 and so on, but mod gives 0 if moded with same number,
      in excel's case we need to deal with base 26 number system and each time we mod 26%26 results in 0,
      to avoid this zero it is necessary to reduce each number by 1 and then mod.
      In such case modding will look like :
      701 => 701 - 1 = 700 % 26 = 24 and 24 == [ ASCII('Y') - 'A' ] 
      700 / 26 = 26
      26 => 26 - 1 = 25 % 26 = 25 and 25 == [ ASCII('Z') - 'A' ]
      Which gives the result "ZY".
      
      Time complexity : O(log N)
      Space complexity : O(1)
    */
    public String convertToTitle(int columnNumber) {
       
       StringBuilder res = new StringBuilder();

       while(columnNumber > 0){
        columnNumber--;
        res.append(
            (char)(
                (columnNumber % 26) + 'A'
            )
        );

        columnNumber = columnNumber / 26;
       }

       return res.reverse().toString();
    }
}


class Main{
  public static void main(String[] args){
    
	  Solution sobj = new Solution();
	  
    int columnNumber = 701;
    
    String res = sobj.convertToTitle(columnNumber);
    
    System.out.println("Column title for column number : "+columnNumber+" is : "+res);
	}
}
