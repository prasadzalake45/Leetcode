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
    vector<int> largestValues(TreeNode* root) {

        if(root==NULL){
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        // ans.push_back(root->val);

        while(!q.empty()){
            int size=q.size();
            vector<int>vec;

            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

                vec.push_back(node->val);
                
                
            }

            int op=*max_element(vec.begin(),vec.end());
            ans.push_back(op);
        }

        return ans;
        
    }
};