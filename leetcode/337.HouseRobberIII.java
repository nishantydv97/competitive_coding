/*


The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.



*/


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public Pair<Integer, Integer> helper(TreeNode root){
        if(root == null) return new Pair(0,0);
        Pair left =  helper(root.left);
        Pair right =  helper(root.right);
        List<Integer> list = Arrays.asList((Integer)left.getKey()+(Integer)right.getKey(), (Integer)left.getKey() + (Integer)right.getValue(), (Integer)left.getValue()+(Integer)right.getKey(), (Integer)left.getValue()+ (Integer)right.getValue());
        
        return new Pair(root.val + (Integer)left.getValue() + (Integer)right.getValue(), Collections.max(list));
    }
    public int rob(TreeNode root) {
        Pair p = helper(root);
        return Math.max((Integer)p.getKey(), (Integer)p.getValue());
    }
}
