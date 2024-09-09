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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));


        int top=0;
        int left=0;
        int down =m-1;
        int right=n-1;

        int id=0;

        while(top<=down && left<=right){
            if(id==0){// left -->right

                for(int i=left;head!=NULL && i<=right;i++){
                    mat[top][i]=head->val;
                    head=head->next;
                }
                top++;

            }
            if(id==1){// top-->down

                for(int i=top;head!=NULL &&i<=down;i++){
                    mat[i][right]=head->val;
                    head=head->next;
                }
                right--;

            }
            if(id==2){//right-->left
               for(int i=right;head!=NULL && i>=left;i--){
                mat[down][i]=head->val;
                head=head->next;
               }
               down--;
            }




            if(id==3){//down -->top

                for(int i=down;head!=NULL && i>=top;i--){
                    mat[i][left]=head->val;
                    head=head->next;
                }
                left++;

            }

            id=(id+1)%4;
        }

        return mat;

    }
};