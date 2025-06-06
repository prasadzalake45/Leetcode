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

    int helper(TreeNode* root,int& maxSum){
        if(root==NULL){
            return 0;

        }

        int lh=max(0,helper(root->left,maxSum));
        int rh=max(0,helper(root->right,maxSum));

        maxSum=max(maxSum,root->val+lh+rh);

        return root->val+max(lh,rh);
        
}
    int maxPathSum(TreeNode* root) {

        int maxSum=INT_MIN;
         
        helper(root,maxSum);
        return maxSum;
        
    }
};