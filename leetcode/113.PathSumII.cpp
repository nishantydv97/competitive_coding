/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        int tmp=0;
        vector<vector<int>> ans;
        vector<int> vi;
        inorder(root,tmp,vi,sum,ans);
        return ans;
        
    }
};
