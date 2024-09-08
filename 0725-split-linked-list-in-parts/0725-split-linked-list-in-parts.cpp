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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>vec(k,nullptr);

        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

       

        int split=cnt/k;
        int rem=cnt%k;

        ListNode* prev=NULL;
        ListNode* cur=head;
        
        for(int i=0;i<k;i++){

        
            vec[i]=cur;

            for(int i=0;i<split+(rem>0?1:0);i++){
                
                prev=cur;
                cur=cur->next;
                
            }
            if(prev!=NULL){
              prev->next=NULL;
            }
           
            rem--;
        }

        return vec;
        
    }
};