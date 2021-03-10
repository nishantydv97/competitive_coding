/*

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Example 2:
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.


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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* r=new TreeNode(v);
            r->left=root;
            root=r;
            return root;
        }
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        d-=2;
        while(!stk1.empty() or !stk2.empty()){
            if(d<=0) break;
            d--;
            if(!stk1.empty()){
                while(!stk1.empty()){
                    TreeNode* tmp= stk1.top();
                    stk1.pop();
                    if(tmp->left)   stk2.push(tmp->left);
                    if(tmp->right)  stk2.push(tmp->right);
                }
            }else{
                while(!stk2.empty()){
                    TreeNode* tmp= stk2.top();
                    stk2.pop();
                    if(tmp->left)   stk1.push(tmp->left);
                    if(tmp->right)  stk1.push(tmp->right);
                }
            }
            
        }
        
        if(!stk1.empty()){
            while(!stk1.empty()){
                //cout<<stk1.top()->val<<" ";
                TreeNode* tmp=stk1.top();
                if(tmp->left){
                    TreeNode* k=new TreeNode(v);
                    k->left=tmp->left;
                    tmp->left=k;
                }else{
                    tmp->left=new TreeNode(v);
                }
                if(tmp->right){
                    TreeNode* k=new TreeNode(v);
                    k->right=tmp->right;
                    tmp->right=k;
                }else{
                    tmp->right=new TreeNode(v);
                }
                stk1.pop();
            }
        }else{
            while(!stk2.empty()){
                //cout<<stk2.top()->val<<" ";
                TreeNode* tmp=stk2.top();
                if(tmp->left){
                    TreeNode* k=new TreeNode(v);
                    k->left=tmp->left;
                    tmp->left=k;
                }else{
                    tmp->left=new TreeNode(v);
                }
                if(tmp->right){
                    TreeNode* k=new TreeNode(v);
                    k->right=tmp->right;
                    tmp->right=k;
                }else{
                    tmp->right=new TreeNode(v);
                }
                stk2.pop();
            }
        }
        //cout<<"\n"<<endl;
        return root;
    }
        
};
