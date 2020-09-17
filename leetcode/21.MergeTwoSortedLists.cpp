/*


Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* head=NULL;
        ListNode* r=NULL;
        if(p==NULL || q==NULL){
            if(p==NULL) return q;
            return p;
        }
        while(p!=NULL && q!=NULL){
            if(p->val<q->val){
                if(head==NULL){
                    head=new ListNode(p->val);
                    r=head;
                }else{
                    r->next=new ListNode(p->val);
                    r=r->next;
                }
                //cout<<p->val<<" ";
                p=p->next;
            }else{
                if(head==NULL){
                    head=new ListNode(q->val);
                    r=head;
                }else{
                    r->next=new ListNode(q->val);
                    r=r->next;
                }
                //cout<<q->val<<" ";
                q=q->next;
            }
            //cout<<head->val<<endl;
        }
        if(p==NULL){
            while(q!=NULL){
                r->next=new ListNode(q->val);
                r=r->next;
                q=q->next;
            }
        }else{
            while(p!=NULL){
                r->next=new ListNode(p->val);
                r=r->next;
                p=p->next;
            }
        }
        return head;
    }
};
