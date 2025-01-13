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

    int findNodes(TreeNode* root){
        if(!root){
            return 0;
        }

        int lh=findNodes(root->left);

        int rh=findNodes(root->right);

        return 1+lh+rh;
    }

    bool helper(TreeNode* root,int i,int totalNodes){

        if(!root){
            return true;
        }

        if(i>totalNodes){
            return false;
        }


        return helper(root->left,2*i,totalNodes)&& helper(root->right,2*i+1,totalNodes);



    }

    bool isCompleteTree(TreeNode* root) {



      int totalNodes=findNodes(root);

      int i=1;

      return helper(root,i,totalNodes);

        
    }
};