/*



You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue
Accepted
17,866
Submissions
37,636


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
    TreeNode* lca(TreeNode* root, int start, int end){
        if(!root) return nullptr;
        if(root->val==start or root->val==end) return root;
        TreeNode* left = lca(root->left, start, end);
        TreeNode* right = lca(root->right, start, end);
        if(left and right) return root;
        return left ? left : right;
    }
    
    string sPath="", dPath="";
    void dfs(TreeNode* root, int start, int end, string &s){
        if(!root) return;
        if(root->val==start){
            sPath=s;
        }
        if(root->val==end){
            dPath=s;
        }
        s.push_back('L');
        dfs(root->left, start, end, s);
        s.pop_back();
        s.push_back('R');
        dfs(root->right, start, end, s);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lc=lca(root, startValue, destValue);
        string k="";
        dfs(lc, startValue, destValue, k);
        for(int i=0;i<sPath.size(); i++){
            sPath[i]='U';
        }
        return sPath+dPath;
    }
};
