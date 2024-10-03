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

   int removeMiddle(ListNode* head,int length,int cnt){

    if(head==NULL){
        return 0;
    }

    int index=removeMiddle(head->next,length,cnt+1);

    if(cnt==(length/2)-1){
        head->next=head->next->next;
    }

    return index+1;

    
   }
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return NULL;
        }

        int length=removeMiddle(head,0,0);

        removeMiddle(head,length,0);

        return head;
        
    }
};