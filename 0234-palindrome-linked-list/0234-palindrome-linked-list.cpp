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

    ListNode* reverse(ListNode*& head){

        ListNode* prev=NULL;
        ListNode* temp=head;


        while(temp!=NULL){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL  && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ret=reverse(slow);

        ListNode* again=head;
        
        while(ret!=NULL){
            if(again->val!=ret->val){
                return false;

            }
            else{
                again=again->next;
                ret=ret->next;
            }


        }

        return true;


        
    }
};