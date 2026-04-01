/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include<stdio.h>

/*
Brute Force
Try all possible pairs (i, j) and compute the water.
Check every pair and compute area using smaller height
Also we track max.
Time Complexity : O(N^2)
Space Complexity : O(1)
*/
int maxArea_01(int* height, int heightSize) {
    int maxWater = 0;

    for(int i = 0; i < heightSize; i++){
        for(int j = i + 1; j < heightSize; j++){
            int h = height[i] < height[j] ? height[i] : height[j];
            int width = j - i;

            int area = h * width;
            if(area > maxWater){
                maxWater =  area;
            }
        }
    }

    return maxWater;
}

/*
Max area depends on min height
So, Move pointer with smaller height
Area = min(height[left], height[right]) × width
If you move the taller one -> height won't increase
Only chance to improve = move smaller height
Time complexity = O(N)
Space complexity = O(1)
*/
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1, h = 0,max = 0;

    while(left < right){
        int h = height[left] < height[right] ? height[left] : height[right];

        int width = right - left;

        int area = h * width;

        max = area > max ? area : max;

        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }

    return max;
}

int main(){

	int arr[] = {1,8,6,2,5,4,8,3,7};
	int n = 9;
	
	int ret = maxArea(arr,n);
	printf("The container with most water is : %d\n",ret);
	return 0;
}
