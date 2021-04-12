/*



Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100





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
    public int deepestLeavesSum(TreeNode root) {
        Stack<TreeNode> stk1 = new Stack<TreeNode>();
        Stack<TreeNode> stk2 = new Stack<TreeNode>();
        if(root==null) return 0;
        int ans=0;
        stk1.push(root);
        while(!stk1.isEmpty() || !stk2.isEmpty()){
            if(!stk1.isEmpty()){
                int tmp=0;
                while(!stk1.isEmpty()){
                    if(stk1.peek().left!=null) stk2.push(stk1.peek().left);
                    if(stk1.peek().right!=null) stk2.push(stk1.peek().right);
                    tmp+=stk1.peek().val;
                    stk1.pop();
                }
                ans=tmp;
            }else{
                int tmp=0;
                while(!stk2.isEmpty()){
                    if(stk2.peek().left!=null) stk1.push(stk2.peek().left);
                    if(stk2.peek().right!=null) stk1.push(stk2.peek().right);
                    tmp+=stk2.peek().val;
                    stk2.pop();
                }
                ans=tmp;
            }
        }
        return ans;
    }
}
