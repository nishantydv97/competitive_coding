/*

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 104]
Accepted
137,342
Submissions
202,274



*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        vector<vector<int>> res;
        if(!root) return res;
        while(!q1.empty() or !q2.empty()){
            vector<int> k;
            if(!q1.empty()){
                while(!q1.empty()){
                    Node* tmp=q1.front();
                    k.push_back(tmp->val);
                    for(auto i : tmp->children){
                        q2.push(i);
                    }
                    q1.pop();
                }
                res.push_back(k);
            }else{
                while(!q2.empty()){
                    Node* tmp=q2.front();
                    k.push_back(tmp->val);
                    for(auto i : tmp->children){
                        q1.push(i);
                    }
                    q2.pop();
                }
                res.push_back(k);
            }
        }
        return res;
    }
};
