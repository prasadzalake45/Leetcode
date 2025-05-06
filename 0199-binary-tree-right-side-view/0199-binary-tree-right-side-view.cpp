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

void helper(TreeNode* root,vector<int>&answer){

    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){

        int siz=q.size();

        for(int i=0;i<siz;i++){
            TreeNode* node=q.front();
            q.pop();

            if(i==siz-1){
                answer.push_back(node->val);
            }

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

    }
}
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>answer;
        helper(root,answer);
        return answer;       
    }
};