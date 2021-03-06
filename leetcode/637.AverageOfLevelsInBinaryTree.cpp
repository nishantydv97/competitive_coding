/*


Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
Accepted
182,212
Submissions
276,301



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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        //ans.push_back(root->val);
        while(!stk1.empty() or !stk2.empty()){
            double sumi=0;
            int cnt=0;
            if(!stk1.empty()){
                while(!stk1.empty()){
                    TreeNode* tmp=stk1.top();
                    stk1.pop();
                    cnt++;
                    sumi+=tmp->val;
                    if(tmp->left) stk2.push(tmp->left);
                    if(tmp->right) stk2.push(tmp->right);
                }
            }else{
                while(!stk2.empty()){
                    TreeNode* tmp=stk2.top();
                    stk2.pop();
                    cnt++;
                    sumi+=tmp->val;
                    if(tmp->left) stk1.push(tmp->left);
                    if(tmp->right) stk1.push(tmp->right);
                }
            }
            ans.push_back((double)sumi/cnt);
        }
        return ans;
    }
};
