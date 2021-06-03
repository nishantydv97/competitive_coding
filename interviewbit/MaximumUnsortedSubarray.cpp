/*



You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]

In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.





*/


vector<int> Solution::subUnsort(vector<int> &nums) {
        int n=nums.size();
        vector<int> mini(n, 0);
        vector<int> maxi(n, 0);
        int maxVar=nums[0];
        for(int i=0;i<n;i++){
            maxVar=max(maxVar, nums[i]);
            maxi[i]=maxVar;
        }
        int minVar=nums[n-1];
        for(int i=n-1;i>=0;i--){
            minVar=min(minVar, nums[i]);
            mini[i]=minVar;
        }
        int i=0;
        while(i<n and mini[i]==maxi[i])i++;
        int start=i;
        i=n-1;
        while(i>=0 and maxi[i]==mini[i])i--;
        int end=i;
        if(end<=start) return {-1};
        return {start, end};
}
