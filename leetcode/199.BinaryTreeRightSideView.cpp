/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            int cnt=1;
            if(q1.empty()){
                while(!q2.empty()){
                    TreeNode * tmp = q2.front();
                    q2.pop();
                    if(cnt)
                    v.push_back(tmp->val);
                    cnt=0;
                    if(tmp->right)
                    q1.push(tmp->right);
                    if(tmp->left)
                    q1.push(tmp->left);
                    
                
                }
            }else{
                while(!q1.empty()){
                    TreeNode * tmp = q1.front();
                    q1.pop();
                    if(cnt)
                    v.push_back(tmp->val);
                    cnt=0;
                    if(tmp->right)
                        q2.push(tmp->right);
                    if(tmp->left)
                        q2.push(tmp->left);
                    
                }
            }
        }
        return v;
    }
    
};
