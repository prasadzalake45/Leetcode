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

       
        if(head==NULL){
            return NULL;
        }

    ListNode* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;

    }

    temp=head;

    if(cnt==n){
        return head->next;
    }
    int ans=cnt-n;

    for(int i=1;i<ans;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;


        return head;




    }
};