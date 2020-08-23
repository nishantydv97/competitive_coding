/*


In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.


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
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 0;
        
        stack<TreeNode* > stk1;
        stack<TreeNode* > stk2;
        pair<TreeNode*, int> node1;
        pair<TreeNode*, int> node2;
        stk1.push(root);
        if(root->val==x) node1=make_pair(root,0);
        if(root->val==y) node1=make_pair(root,0);
        int hight=1;
        while(!stk1.empty() || !stk2.empty()){
            if(!stk1.empty()){
                while(!stk1.empty()){
                    TreeNode* tmp=stk1.top();
                    //cout<<tmp->val<<" "<<hight<<endl;
                    stk1.pop();
                    if(tmp->left){
                        if(tmp->left->val==x){
                            node1=make_pair(tmp,hight);
                        }
                        if(tmp->left->val==y){
                            node2=make_pair(tmp,hight);
                        }
                        stk2.push(tmp->left);
                    }
                    if(tmp->right){
                        if(tmp->right->val==x){
                            node1=make_pair(tmp,hight);
                        }
                        if(tmp->right->val==y){
                            node2=make_pair(tmp,hight);
                        }
                        stk2.push(tmp->right);
                    }
                }
            }else{
                while(!stk2.empty()){
                    TreeNode* tmp=stk2.top();
                    //cout<<tmp->val<<" "<<hight<<endl;
                    stk2.pop();
                    if(tmp->left){
                        if(tmp->left->val==x){
                            node1=make_pair(tmp,hight);
                        }
                        if(tmp->left->val==y){
                            node2=make_pair(tmp,hight);
                        }
                        stk1.push(tmp->left);
                    }
                    if(tmp->right){
                        if(tmp->right->val==x){
                            node1=make_pair(tmp,hight);
                        }
                        if(tmp->right->val==y){
                            node2=make_pair(tmp,hight);
                        }
                        stk1.push(tmp->right);
                    }
                }
            }
            hight++;
        }
        
        //cout<<node2.first->val<<" "<<node2.second<<endl;
        //cout<<node1.first->val<<" "<<node1.second<<endl;
        if(node1.first!=node2.first && node1.second==node2.second)
            return 1;
        return 0;
        
    }
};
