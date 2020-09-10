/*

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *q=NULL;
        ListNode *ans=q;
        //cout<<ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(ListNode *i : lists){
            ListNode* p=i;
            while(p!=NULL){
                pq.push(p->val);
                p=p->next;
            }
        }
        while(!pq.empty()){
            if(q==NULL){
                q=new ListNode(pq.top());
                ans=q;
            }else{
                q->next=new ListNode(pq.top());
                q=q->next;
            }
            pq.pop();
        }
        return ans;
}
