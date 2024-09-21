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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next==NULL){
            return 0;
        }
        ListNode* temp=head;
        int cnt=0;

        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        if(cnt==n){
            return head->next;
        }

        int cur=cnt-n;

        
      
        temp=head;

        for(int i=0;i<cur-1;i++){
            temp=temp->next;

        }
        if(temp->next==NULL){
            temp->next=NULL;

        }

        temp->next=temp->next->next;


        return head;

    }
};