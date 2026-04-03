/*
55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

class Solution {

    /*
        Brute force 
        Check all possible jumps from each index
        Time complexity : O(2^N)
        Space complexity : O(2^N)
    */
    public boolean canJump_01(int[] nums) {
        return canReach(nums,0);
    }
    public boolean canReach(int[] nums, int index) {
        if(index == nums.length - 1) return true;

        int reach = nums[index];

        for(int step = 1; step <= reach; step++){
            if(canReach(nums, index + step)) return true;
        }

        return false;
    }


    /*
        Greedy backwards
        The idea is to move the goal position backwards.
        If the jump achieveable from current index exceeds our goal index,
        simply shrink the goal to this index, check again for other indexes until we reach 0

        Time complexity : O(N)
        Space complexity : O(1)
    */
    public boolean canJump_02(int[] nums){
        int goal = nums.length - 1;

        for(int i = nums.length - 2; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }

    /*
        Greedy forwards
        From current index can we reach to the goal index?
        This can be achieved by considering maximum reach possible either from current index or any maximum reach before it.
        Ultimately we have to reach goal or ahead of that.
        Time complexity : O(N)
        Space complexity : O(1)
    */
    public boolean canJump(int[] nums){

        int reach = 0;

        for(int i = 0; i < nums.length; i++){
            if(i > reach) return false;

            reach = reach > i+nums[i] ? reach : i+nums[i] ;

            if(reach >= nums.length - 1) return true;
        }


        return true;
    }
}

class Main{
    public static void main(String[] args) {
        int[] nums = {1,2,4,1,1,0,2};

        Solution sobj = new Solution();

        boolean ret = sobj.canJump(nums);

        if(ret){
            System.out.println("Can jump to last position!");
        }else{
            System.out.println("Cannot jump to last position!");
        }

    }
}