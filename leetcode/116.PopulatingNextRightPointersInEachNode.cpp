/*


You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 212 - 1].
-1000 <= Node.val <= 1000
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.



*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void bfs(Node* root){
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        while(!q1.empty() or !q2.empty()){
            if(!q1.empty()){
                Node* p=nullptr;
                while(!q1.empty()){
                    if(p)
                        p->next=q1.front();
                    if(q1.front()->left)
                        q2.push(q1.front()->left);
                    if(q1.front()->right)
                        q2.push(q1.front()->right);
                    p=q1.front();
                    q1.pop();
                }
            }else{
                Node* p=nullptr;
                while(!q2.empty()){
                    if(p)
                        p->next=q2.front();
                    if(q2.front()->left)
                        q1.push(q2.front()->left);
                    if(q2.front()->left)
                        q1.push(q2.front()->right);
                    p=q2.front();
                    q2.pop();
                    
                }
            }
        }
    }
    Node* connect(Node* root) {
        if(!root) return root;
        bfs(root);
        return root;
    }
};
