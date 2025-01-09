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
    bool isValidHelper(TreeNode* root,long minVal,long maxval){

        if(root==NULL){
            return true;
        }

        if(root->val<=minVal || root->val>=maxval){
            return false;
        }


        return isValidHelper(root->left,minVal,root->val) && isValidHelper(root->right,root->val,maxval);

    }
    bool isValidBST(TreeNode* root) {

        return isValidHelper(root,LONG_MIN,LONG_MAX);

        
        
    }
};