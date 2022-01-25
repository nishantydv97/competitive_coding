/*

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
Accepted
72,030
Submissions
118,448


*/


class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList<>();
        int x;
        for(int i=1; i<9; i++){
            x=i;
            for(int j=i+1; j<=9; j++){
                x=(x*10)+j;
                if(x<=high && x>=low){
                    res.add(x);
                }
            }
        }
        Collections.sort(res);
        return res;
    }
}
