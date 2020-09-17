/*

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
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
