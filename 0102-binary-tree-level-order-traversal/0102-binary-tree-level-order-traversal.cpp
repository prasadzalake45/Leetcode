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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==NULL){
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>result;


        while(!q.empty()){
            int size=q.size();
            vector<int>ans;

            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();


                 ans.push_back(it->val);

                 if(it->left){
                    q.push(it->left);

                 }

                 if(it->right){
                    q.push(it->right);
                 }


            }

            result.push_back(ans);

        }

        return result;
        
    }
};