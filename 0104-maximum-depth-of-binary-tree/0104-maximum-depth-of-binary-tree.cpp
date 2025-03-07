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

    int  preorder(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        // int lh=preorder(root->left);
        // int rh=preorder(root->right);

        return 1+max(preorder(root->left),preorder(root->right));




      }
    int maxDepth(TreeNode* root) {
        
        return preorder(root);
    }
};