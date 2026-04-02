/*
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/
import java.util.*;

class Solution {

    /*
        Brute Force approach
        Try all combinations for triplet.
        Update sum closest to target sum.
        Time complexity : O(N^3)
        Space complexity : O(1)
    */
    public int threeSumClosest_01(int[] nums, int target) {
        int n = nums.length;
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {

                    int sum = nums[i] + nums[j] + nums[k];

                    if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                        closestSum = sum;
                    }
                }
            }
        }
        return closestSum;
    }

    /*
        Two pointer approach
        Fix the first element of triplet,
        Remaning two elements of triplet can be extracted using binary search.
        Whichever boundary is far then the target get it closer.
        Time complexity : O(N^2)
        Space complexity : O(1)
    */
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                    closestSum = sum;
                }
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum;
                }
            }
        }

        return closestSum;
    }
}


class Main {
    public static void main(String[] args) {

        Solution sol = new Solution();

        int[] nums1 = {-1, 2, 1, -4};
        int target1 = 1;

        int result1 = sol.threeSumClosest(nums1, target1);
        System.out.println("Closest Sum : " + result1);
    }
}