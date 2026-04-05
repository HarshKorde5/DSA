/*
2418. Sort the People

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.


*/

class Solution {
    private void swap(String[] names, int[] heights, int i, int j) {
        String t = names[i];
        names[i] = names[j];
        names[j] = t;

        int x = heights[i];
        heights[i] = heights[j];
        heights[j] = x;
    }

    private int partition(String[] names, int[] heights, int low, int high) {
        int pivot = heights[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (heights[j] > pivot) {
                i++;
                swap(names, heights, i, j);
            }
        }

        swap(names, heights, i + 1, high);
        return i + 1;
    }

    private void quickSort(String[] names, int[] heights, int low, int high){
        if(low < high){
            int pi = partition(names,heights,low,high);
            quickSort(names,heights,low,pi-1);
            quickSort(names,heights, pi + 1, high);
        }
    }
    public String[] sortPeople(String[] names, int[] heights) {
        quickSort(names,heights,0,heights.length - 1);

        return names;
    }
}


class Main{
  public static void main(String[] args){
    
	  Solution sobj = new Solution();
	  String[] names = {"Mary","John","Emma"};
	  int[] heights = {180,165,170};
	  names = sobj.sortPeople(names,heights);
	  
	  System.out.println("Names as per sorted heights in descending order : ");
	  for(String name : names){
		  System.out.println(name);
	  }
	}
}
