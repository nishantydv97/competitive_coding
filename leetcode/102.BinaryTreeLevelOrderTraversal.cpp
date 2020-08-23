/*



Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        que1.push(root);
        while(!que1.empty() || !que2.empty()){
            if(!que1.empty()){
                vector<int> vi;
                while(!que1.empty()){
                    TreeNode* tmp=que1.front();
                    que1.pop();
                    
                    vi.push_back(tmp->val);
                    if(tmp->left){
                        que2.push(tmp->left);
                    }
                    if(tmp->right){
                        que2.push(tmp->right);
                    }
                    
                }
                v.push_back(vi);
            }else{
                vector<int> vi;
                while(!que2.empty()){
                    TreeNode* tmp = que2.front();
                    vi.push_back(tmp->val);
                    que2.pop();
                    
                    if(tmp->left){
                        que1.push(tmp->left);
                    }
                    if(tmp->right){
                        que1.push(tmp->right);
                    }
                    
                }
                v.push_back(vi);
            }
        }
        return v;
    }
};
