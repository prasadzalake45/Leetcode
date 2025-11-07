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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // bfs

        if(root==NULL){
            return {};
        }

        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);
        bool zigzag=true;

        while(!q.empty()){
            int n=q.size();
            vector<int>res;

            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                res.push_back(cur->val);

                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            if(zigzag){
                ans.push_back(res);
            }
            if(!zigzag){
                reverse(res.begin(),res.end());
                ans.push_back(res);
            }
            zigzag=!zigzag;
        }


        return ans;
        
        
    }
};