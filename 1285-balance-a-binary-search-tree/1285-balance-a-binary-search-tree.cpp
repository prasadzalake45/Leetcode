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

    void inorder(TreeNode* root,vector<int>&ans){
        if(!root){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);


    }

    TreeNode* helper(vector<int>&ans,int s,int e){
        if(s>e){
            return NULL;
        }

        int mid=(s+e)/2;

        TreeNode* root=new TreeNode(ans[mid]);


        root->left=helper(ans,s,mid-1);
        root->right=helper(ans,mid+1,e);

        return root;


        
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int>ans;
        inorder(root,ans);

        return helper(ans,0,ans.size()-1);

        
    }
};