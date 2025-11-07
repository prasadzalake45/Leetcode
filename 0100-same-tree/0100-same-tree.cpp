/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL){
            return true;
        }

        if (p == NULL || q == NULL){
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        bool lh = helper(p->left, q->left);
        bool rh = helper(p->right, q->right);
        return lh && rh;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
         bool ans= helper(p, q); 
         return ans;
    }
};