/*

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
Accepted
442,438
Submissions
977,406

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
    vector<TreeNode*> x;
    void node(TreeNode* root, TreeNode* subRoot){
        if(!root) return;
        if(root->val==subRoot->val){
            x.push_back(root);
        }
        node(root->left, subRoot);
        node(root->right, subRoot);
    }
    bool isSub(TreeNode* root, TreeNode* sub){
        if(root==nullptr and sub==nullptr){
            return true;
        }
        if((root==nullptr and sub!=nullptr) or (root!=nullptr and sub==nullptr) ) return false;
        if(root!=nullptr and sub!=nullptr)
            return root->val==sub->val and isSub(root->left, sub->left) and isSub(root->right, sub->right);
        return true;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        node(root, subRoot);
        bool ans = false;
        cout<<x.size()<<endl;
        for(auto i : x){
            ans  = ans or isSub(i, subRoot);
        }
        return ans;
        
    }
};
