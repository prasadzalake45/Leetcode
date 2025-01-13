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

    TreeNode* deleteHelper(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&result){

        if(!root){
            return NULL;
        }

        root->left=deleteHelper(root->left,st,result);
        root->right=deleteHelper(root->right,st,result);

        if(st.find(root->val)!=st.end()){
            if(root->left){
                result.push_back(root->left);
            }           
            if(root->right){
                result.push_back(root->right);
            } 
            else{
                return NULL;
            }
        }
        else{

            return root;
        

        }
      return NULL;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*>result;

        unordered_set<int>st;
        for(auto it:to_delete){
            st.insert(it);
        }

        deleteHelper(root,st,result);

        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }


        return result;
    }
};