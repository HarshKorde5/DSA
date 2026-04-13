/*
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, res = 0;

        while (left < right) {
            int w = right - left;
            int h = height[left] < height[right] ? height[left] : height[right];

            int area = w * h;

            res = area > res ? area : res;

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }

        return res;
    }

    public int maxArea_01(int[] height) {
        int res = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int h = height[i] < height[j] ? height[i] : height[j];

                int w = j - i;

                int area = h * w;

                res = area > res ? area : res;

            }
        }

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

        int resultOptimal = sol.maxArea(height);
        int resultBrute = sol.maxArea_01(height);

        System.out.println("Optimal (Two Pointer) Result: " + resultOptimal);
        System.out.println("Brute Force Result: " + resultBrute);
    }
}
