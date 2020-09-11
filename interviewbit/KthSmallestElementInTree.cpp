/*


Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 


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
 static int a=0;
 void inorder(TreeNode* root, int &k, int &ans){
        if(root==NULL) return;
        inorder(root->left,k,ans);
        a++;
        if(a==k){
            ans=root->val;
        }
        inorder(root->right,k,ans);
 }
int Solution::kthsmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(root,k,ans);
        a=0;
        return ans;
}
