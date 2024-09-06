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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int>s(begin(nums),end(nums));

        while( head!=NULL && s.find(head->val)!=s.end()){
            ListNode* temp=head;
           head=head->next;
           delete(temp);
        }

        ListNode* cur=head;

        while(cur!=NULL && cur->next!=NULL){
            if(s.find(cur->next->val)!=s.end()){
               ListNode* temp=cur->next;
               cur->next=cur->next->next;
               delete(temp);

            }
            else{
                cur=cur->next;
            }
        }

        return head;
       
        

       
    }
};