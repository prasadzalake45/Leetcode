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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* head1=NULL;
        ListNode* head2=NULL;
        ListNode* tail1=NULL;
        ListNode* tail2=NULL;
        
        ListNode* cur=head;
        bool add=true;
        
        while(cur!=NULL){
            if(add){
                
                if(head1==NULL){
                    head1=cur;
                    tail1=head1;
                }
                else{
                    tail1->next=cur;
                    tail1=tail1->next;
                }
                
            }
            else{
                if(head2==NULL){
                    head2=cur;
                    tail2=head2;
                }
                else{
                    tail2->next=cur;
                    tail2=tail2->next;
                }
            }
            
            cur=cur->next;
            add=!add;
        }
        
        if(tail1!=NULL){
            tail1->next=head2;
        }

        if(tail2!=NULL){
            tail2->next=NULL;
        }
        
        
        return head1;
        
        
    }
};