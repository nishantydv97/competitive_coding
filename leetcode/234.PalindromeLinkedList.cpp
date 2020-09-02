/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?


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
    ListNode *reverse(ListNode *head){
        ListNode* prev=NULL,*curr=head;
        while(curr!=NULL){
            ListNode* tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        head=prev;
        return head;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return true;
        }
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second;
        
            second=slow->next;
            slow->next=NULL;
        
        second=reverse(second);
        
        bool ans=true;
        while(head!=NULL && second!=NULL){
            if(head->val!=second->val){
                ans=false;
                break;
            }
            head=head->next;
            second=second->next;
        }
        
        return ans;
    }
};
