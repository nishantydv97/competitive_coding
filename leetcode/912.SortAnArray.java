/*

Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

 

Constraints:

    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104




*/

class Solution {
    public static void swap(int[] arr, int i, int j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    public static int makePartition(int[] arr, int l, int r){
        int pivit=arr[r];
        int j=l;
        for(int i=l; i<r; i++){
            if(arr[i]<=pivit){
                swap(arr, i, j);
                j++;
            }
        }
        swap(arr, j, r);
        return j;
    }
    public static void sort(int[] arr, int l, int r){
        if(l<r){
            int partitionIndex=makePartition(arr, l, r);
            System.out.println(partitionIndex);
            sort(arr, l, partitionIndex-1);
            sort(arr, partitionIndex+1, r);
        }
    }
    public int[] sortArray(int[] arr) {
        sort(arr, 0, arr.length-1);
        return arr;
    }
}
