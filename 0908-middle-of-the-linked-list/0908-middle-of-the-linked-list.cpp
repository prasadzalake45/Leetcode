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
    ListNode* middleNode(ListNode* head) {

        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;

        }
        int ans=(cnt/2);

        ListNode* cur=head;

        for(int i=0;i<ans;i++){
            cur=cur->next;

        }

        return cur;
        
    }
};