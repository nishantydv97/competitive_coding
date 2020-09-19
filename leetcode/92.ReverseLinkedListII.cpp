/*

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL


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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* tmp=curr->next;
            tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int def=n-m;
        if(m==1){
            ListNode* p=head;
            while(def-- and p){
                p=p->next;
            }
            
            if(!p){
                return reverse(head);
            }else{
                ListNode* h1=p->next;
                p->next=NULL;
                head=reverse(head);
                p=head;
                while(p->next!=NULL){
                    p=p->next;
                }
                p->next=h1;
                return head;
            }
        }else{
            ListNode* p=head;
            
            while(--m>1 && p){
                p=p->next;
            }
            if(!p or p->next==NULL){
                return head;
            }else{
                ListNode* h1=p;
                ListNode* q=p->next;
                while(def-- and q->next){
                    q=q->next;
                }
                ListNode* tmp=q->next;
                q->next=NULL;
                h1->next=reverse(h1->next);
                while(q->next){
                    q=q->next;
                }
                q->next=tmp;
            }
        }
        
        return head;
        
    }
};
