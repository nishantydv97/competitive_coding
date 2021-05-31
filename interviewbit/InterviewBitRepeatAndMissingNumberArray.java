/*


You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4





*/

public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> repeatedNumber(final List<Integer> a) {
        ArrayList<Integer> A= new ArrayList<Integer>();
        A.addAll(a);
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=0; i<A.size(); i++){
            if(A.get(Math.abs(A.get(i))-1)<0) {
                list.add(Math.abs(A.get(i)));
            }else {
                A.set(Math.abs(A.get(i))-1, -A.get(Math.abs(A.get(i))-1));
            }
        }
        for(Integer i= 0 ; i< A.size(); i++){
            if(A.get(i)>0){
                list.add(i+1);
            }
        }
        return list;
    }
}
