/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

import java.util.*;

class Solution {


    /*
        Brute force Approach
        Check all combinations of i,j,k for sum equalling zero.
        Catch is we can skip the duplicates if the array is already sorted.
        In that sense, duplicates will come together if any exists.
        So skipping them becomes easy, rather than checking duplicate each time we get a sum = 0.
        This makes easy to understand.
        Time complexity : O(N^3)
        Space complexity : O(1)

    */
    public List<List<Integer>> threeSum_01(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.length; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1; k < nums.length; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    }
                }
            }
        }

        return res;
    }

    /*
        Optimal approach : Two Pointers
        Fix the i and search for other two triplets using binary search(array is sorted so it's feasible).
        Main idea is, if one value is fixed, to get sum = 0, shift the boundaries likewise,
        i.e. if sum < 0 shift left boundary ahead to find more greater sum, else shift right boundary.
        Time complexity : O(N^2)
        Space complexity : O(1)
    */
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[left] == nums[right - 1]) right--;

                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return res;
    }
}

class Main {
    public static void main(String[] args) {

        Solution sol = new Solution();

        int[] nums = {-1, 0, 1, 2, -1, -4};

        List<List<Integer>> result = sol.threeSum(nums);

        System.out.println("Triplets:");
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }
    }
}