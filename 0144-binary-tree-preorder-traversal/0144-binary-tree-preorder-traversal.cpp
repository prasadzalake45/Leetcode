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
        if(root==NULL){
            return;
        }

        stack<TreeNode*>st;
        st.push(root);
      
        while(!st.empty()){
            TreeNode * cur=st.top();
            st.pop();

            answer.push_back(cur->val);

            if(cur->right){
                st.push(cur->right);
            }
            if(cur->left){
                st.push(cur->left);
            }

        }

        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>answer;
        helper(root,answer);    

        return answer;    
    }

};