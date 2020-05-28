/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        queue<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        while(!stk.empty()){
            TreeNode* t1= stk.front();
            stk.pop();
            TreeNode* t2= stk.front();
            stk.pop();
            if(t1==NULL && t2==NULL){
                continue;
            }
            if(t1==NULL || t2==NULL){
                return 0;
            }
            if(t1->val!=t2->val){
                return 0;
            }else{
                
                stk.push(t1->left);
                stk.push(t2->right);
                stk.push(t1->right);
                stk.push(t2->left);
                
            }
                
                
        }
        return 1;
    }
};
