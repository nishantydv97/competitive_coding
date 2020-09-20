/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1


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
    void inorder(TreeNode* root, int& sum, bool& ans, int& k){
        if(!root){
            return;
        }
        sum+=root->val;
        inorder(root->left,sum,ans,k);
        inorder(root->right,sum,ans,k);
        if(root->left==NULL and root->right==NULL){
            if(sum==k){
                ans=true;
            }
        }
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool ans=false;
        int tmp=0;
        inorder(root,tmp,ans,sum);
        return ans;
    }
};
