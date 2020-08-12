/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


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
    bool isLeftLess(TreeNode* root, int val){
        if(root==NULL){
            return true;
        }
        if(root->val<val && isLeftLess(root->left,val) && isLeftLess(root->right,val)){
            return true;
        }else{
            return false;
        }
    }
    bool isRightGreater(TreeNode* root, int val){
        if(root==NULL){
            return true;
        }
        if(root->val>val && isRightGreater(root->left,val) && isRightGreater(root->right,val)){
            return true;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }else{
            return (isLeftLess(root->left,root->val) && isRightGreater(root->right,root->val) &&
                   isValidBST(root->left) && isValidBST(root->right));
        }
    }
};
