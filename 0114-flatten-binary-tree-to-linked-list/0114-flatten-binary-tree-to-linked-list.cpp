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

    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        helper(root->right);


        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        TreeNode* cur=root;
        while(cur->right){
            cur=cur->right;

        }
        cur->right=temp;
    }
    void flatten(TreeNode* root) {

        helper(root);
        

      


        
    }
};