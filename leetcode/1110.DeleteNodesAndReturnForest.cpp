/*


Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
Accepted
146,757
Submissions
212,261


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
//     vector<TreeNode*> helper(TreeNode* root, unordered_set<int> to_delete){
//         vector<TreeNode*> nodeToExplore;
//         if(to_delete.find(root->val)!=to_delete.end()){
//             if(root->left) nodeToExplore.push_back(root->left);
//             root->left=nullptr;
//             if(root->right) nodeToExplore.push_back(root->right);
//             root->right=nullptr;
//             return nodeToExplore;
//         }
        
//         stack<TreeNode*> stk;
//         stk.push(root);
//         while(!stk.empty()){
//             TreeNode* tmp = stk.top();
//             stk.pop();
//             if(to_delete.find(tmp->val)!=to_delete.end()){
//                 if(tmp->left) nodeToExplore.push_back(tmp->left);
//                 if(tmp->right) nodeToExplore.push_back(tmp->right);
//                 cout<<tmp->val<<endl;
//                 tmp=NULL;
//             }else{
//                 if(tmp->left) stk.push(tmp->left);
//                 if(tmp->right) stk.push(tmp->right);
//             }
//         }
//         return nodeToExplore;
//     }
//     vector<TreeNode*> res;
    
//     void allForest(TreeNode* root, unordered_set<int> st){
//         if(!root) return;
//         vector<TreeNode*> tmp = helper(root, st);
//         for(auto i : tmp){
//             cout<<i->val<<" ";
//         }
//         cout<<"\n";
//         if(st.find(root->val)==st.end()) res.push_back(root);
//         for(auto i : tmp){
//             allForest(i, st);
//         }
//     }
    
    
    
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        
//         unordered_set<int> st(to_delete.begin(), to_delete.end());

//         allForest(root, st);
        
//         return res;
//     }
    
    
    vector<TreeNode*>arr;
    unordered_set<int>s;
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return NULL;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if(s.find(root->val)!=s.end())
        {
            if(root->left)arr.push_back(root->left);
            if(root->right) arr.push_back(root->right);
            root->left=root->right=NULL;
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete) s.insert(x);
        TreeNode* temp = dfs(root);
        if(temp) arr.push_back(root);
        return arr;
    }
};
