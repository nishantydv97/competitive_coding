/*

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 
 void inorder(TreeNode* root, int& sum, vector<int>& vi, int& k, vector<vector<int>>& ans){
        if(!root){
            return;
        }
        sum+=root->val;
        vi.push_back(root->val);
        inorder(root->left,sum,vi,k,ans);
        inorder(root->right,sum,vi,k,ans);
        if(root->left==NULL and root->right==NULL){
            if(sum==k){
                ans.push_back(vi);
            }
        }
        sum-=root->val;
        vi.pop_back();
    }
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
        int tmp=0;
        vector<vector<int>> ans;
        vector<int> vi;
        inorder(root,tmp,vi,sum,ans);
        return ans;
}
