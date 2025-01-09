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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL){
            return NULL;
        }

        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }

        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            //not having child or either one child

            if(!root->left){
                return root->right;

            }
            if(!root->right){
                return root->left;

            }

            //having both child
            TreeNode* suc=root->right;
            while(suc->left){
                suc=suc->left;
            }

            root->val=suc->val;
            root->right=deleteNode(root->right,suc->val);
        }
        return root;
        
    }
};