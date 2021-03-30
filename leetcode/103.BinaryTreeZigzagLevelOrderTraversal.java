/*


Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100



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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Stack<TreeNode> stack1 = new Stack<TreeNode>();
        Stack<TreeNode> stack2 = new Stack<TreeNode>();
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null) return ans;
        stack1.add(root);
        
        while(!stack1.isEmpty() || !stack2.isEmpty()){
            if(!stack1.isEmpty()){
                ArrayList<Integer> list = new ArrayList<Integer>();
                while(!stack1.isEmpty()){
                    TreeNode tmp=stack1.peek();
                    stack1.pop();
                    list.add(tmp.val);
                    if(tmp.left!=null) stack2.push(tmp.left);
                    if(tmp.right!=null) stack2.push(tmp.right);
                }
                ans.add(list);
            }else{
                ArrayList<Integer> list = new ArrayList<Integer>();
                while(!stack2.isEmpty()){
                    TreeNode tmp=stack2.peek();
                    stack2.pop();
                    list.add(tmp.val);
                    if(tmp.right!=null) stack1.push(tmp.right);
                    if(tmp.left!=null) stack1.push(tmp.left);
                }
                ans.add(list);
            }
        }
        return ans;
    }
}
