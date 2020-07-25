/*

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }else{
            
            v.push_back(root->val);
            inorder(root->left);
            inorder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        inorder(root);
        TreeNode* p=root;
        if(root!=NULL)
        p->left=NULL;
        /*
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<"\n";
        */
        for(int i=1;i<v.size();i++){
            p->right=new TreeNode(v[i]);
            p=p->right;
            cout<<v[i];
        }
        
    }
};
