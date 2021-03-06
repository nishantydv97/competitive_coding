/*


A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
The number of nodes will not exceed 1000.


*/




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* p=head;
        while(p){
            Node* tmp=new Node(p->val);
            tmp->next=p->next;
            p->next=tmp;
            p=p->next->next;
        }
        p=head;
        Node* q=head->next;
        while(q->next!=NULL){
            if(p->random==NULL){
                q->random=NULL;
            }else{
                q->random=p->random->next;
            }
            p=p->next->next;
            q=q->next->next;
        }
        if(p->random==NULL){
            q->random=NULL;
        }else{
            q->random=p->random->next;
        }
        Node* ans=head->next;
        p=head;
        q=ans;
        while(q->next!=NULL){
            p->next=p->next->next;
            q->next=q->next->next;
            p=p->next;
            q=q->next;
            
        }
        p->next=NULL;
        q->next=NULL;
        return ans;
    }
};
