/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3




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
TreeNode* constructBST(const vector<int> &A, int left, int right){
    if(left>right){
        return NULL;
    }else{
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(A[mid]);
        root->left=constructBST(A,left,mid-1);
        root->right=constructBST(A,mid+1,right);
        return root;
    }
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size()==0){
        return NULL;
    }else{
        return constructBST(A,0,A.size()-1);
    }
}
