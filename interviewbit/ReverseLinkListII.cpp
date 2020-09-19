/*


Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    
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
