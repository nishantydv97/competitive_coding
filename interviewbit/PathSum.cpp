/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
int Solution::hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
        bool ans=false;
        int tmp=0;
        inorder(root,tmp,ans,sum);
        return ans;
}
