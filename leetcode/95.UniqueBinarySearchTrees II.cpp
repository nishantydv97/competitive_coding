/*

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1){
            vector<TreeNode*> v;
            return v;
        }
        return helper(1,n);
    }
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftSubTrees=helper(start,i-1);
            vector<TreeNode*> rightSubTrees=helper(i+1,end);
            for(TreeNode* leftSubtree : leftSubTrees){
                for(TreeNode* rightSubtree : rightSubTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left=leftSubtree;
                    root->right=rightSubtree;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
