/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(TreeNode* root,vector<vector<int>>&answer){

        

        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight=true;


        while(!q.empty()){

            int size=q.size();
            vector<int>vec(size);

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                // if(leftToRight==true){
                //     vec[i]=node->val;

                // }
                // else if(leftToRight==false){
                //     vec[size-i-1]=node->val;
                // }

                int ind=leftToRight?i:size-i-1;

                vec[ind]=node->val;

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            leftToRight=!leftToRight;
            answer.push_back(vec);

        }



    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root==NULL){
            return {};
        }

        vector<vector<int>>answer;
        helper(root,answer);
        return answer;
        
    }
};