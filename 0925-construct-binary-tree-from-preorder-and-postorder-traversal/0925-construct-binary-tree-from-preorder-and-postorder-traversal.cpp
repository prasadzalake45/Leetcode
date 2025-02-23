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

   TreeNode* helper(vector<int>& preorder, vector<int>& postorder,int& preIndex,int left,int right,unordered_map<int,int>&mp){

    if(preIndex>=preorder.size() || left>right){
        return NULL;
    }

    int rootVal=preorder[preIndex];
    TreeNode* root=new TreeNode(rootVal);
    preIndex++;

    if(left==right){
        return root;
    }

    int leftchild=preorder[preIndex];
    int leftchildVal=mp[leftchild];

    root->left=helper(preorder,postorder,preIndex,left,leftchildVal,mp);

    root->right=helper(preorder,postorder,preIndex,leftchildVal+1,right-1,mp);

    return root;






   }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mp;

        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }

        int preIndex=0;

        return helper(preorder,postorder,preIndex,0,postorder.size()-1,mp);
    }
};