/*

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

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
 
 int solve(TreeNode* root, int k, set<int> & st){
     if(root==NULL) return false;
        if(st.find(k-root->val)!=st.end()) return true;
        st.insert(root->val);
        return solve(root->left,k,st) or solve(root->right,k,st);
 }
int Solution::t2Sum(TreeNode* root, int k) {
    set<int> st;
    int ans=solve(root,k,st);
    st.clear();
    return ans;
}

