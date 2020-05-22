/*
problem link:
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
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
    int maxLevelSum(TreeNode* root) {
        int max=INT_MIN;
        int lvl=1;
        int lvli;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while( !q1.empty() || !q2.empty() ){
            //cout<<"helloo";
            if(q1.empty()){
                int sum=0;
                while(!q2.empty()){
                    TreeNode* tmp=q2.front();
                    cout<<tmp->val<<" ";
                    sum+=tmp->val;
                    q2.pop();
                    if(tmp->left){
                        q1.push(tmp->left);
                    }
                    if(tmp->right){
                        q1.push(tmp->right);
                    }
                }
                if(sum>max){
                    max=sum;
                    lvli=lvl;
                }
            }else{
                if(q2.empty()){
                int sum=0;
                while(!q1.empty()){
                    TreeNode* tmp=q1.front();
                    cout<<tmp->val<<" ";
                    sum+=tmp->val;
                    q1.pop();
                    if(tmp->left){
                        q2.push(tmp->left);
                    }
                    if(tmp->right){
                        q2.push(tmp->right);
                    }
                }
                if(sum>max){
                    max=sum;
                    lvli=lvl;
                }
            }
        }
            lvl++;
        //return max;
    }
        return lvli;
    }
};
