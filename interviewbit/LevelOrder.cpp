/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

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
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.



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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    vector<vector<int>> ans;
    if(!A) return ans;
    q1.push(A);
    while(!q1.empty() or !q2.empty()){
        vector<int> tmp;
        if(!q1.empty()){
            while(!q1.empty()){
                TreeNode* tmpRoot=q1.front();
                q1.pop();
                tmp.push_back(tmpRoot->val);
                if(tmpRoot->left) q2.push(tmpRoot->left);
                if(tmpRoot->right) q2.push(tmpRoot->right);
            }
            //ans.push_back(tmp);
        }else{
            while(!q2.empty()){
                TreeNode* tmpRoot=q2.front();
                q2.pop();
                tmp.push_back(tmpRoot->val);
                if(tmpRoot->left) q1.push(tmpRoot->left);
                if(tmpRoot->right) q1.push(tmpRoot->right);
            }
            //ans.push_back(tmp);
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}
