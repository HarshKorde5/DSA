/*
2678. Number of Senior Citizens
You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.
*/

class Solution {
    public int countSeniors(String[] details) {
        int res = 0;
        for(String customer : details){
            if(customer.charAt(11) > '6' || (customer.charAt(11) == '6' && customer.charAt(12) > '0')){
                res++;
            }
        }

        return res;
    }
}

class Main{
  public static void main(String[] args){
    Solution sobj = new Solution();
    String[] details = {"9751302862F0693","3888560693F7262","5485983835F0649","2580974299F6042","9976672161M6561","0234451011F8013","4294552179O6482"};
    
    int count = sobj.countSeniors(details);
    System.out.println("Total number of passengers above the age of 60 are : "+count);
  }
}
