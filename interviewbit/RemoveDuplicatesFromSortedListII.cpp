/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* p=head;
        if(p==NULL){
            return head;
        }
        map<int,int> ump;
        while(p!=NULL){
            ump[p->val]++;
            p=p->next;
        }
        head=NULL;
        ListNode* q=head;;
        for(auto i : ump){
            if(i.second==1){
                if(head==NULL){
                    head=new ListNode(i.first);
                    q=head;
                }else{
                    q->next=new ListNode(i.first);
                    q=q->next;
                }
            }
            //cout<<i.first<<" "<<i.second<<endl;
        }
        
        
        return head;
}
