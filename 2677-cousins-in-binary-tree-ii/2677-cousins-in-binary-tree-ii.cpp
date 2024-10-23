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
    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);

        vector<int>vec;

        while(!q.empty()){
            int cummsum=0;
            int n=q.size();

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                cummsum+=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }

            vec.push_back(cummsum);


        }

        q.push(root);
        root->val=0;

        int j=1;

        while(!q.empty()){
            int n=q.size();


            for(int i=0;i<n;i++){
                TreeNode* cur=q.front();
                q.pop();

                int sibsum=cur->left!=NULL?cur->left->val:0;
                sibsum+=cur->right!=NULL?cur->right->val:0;

                if(cur->left){
                    cur->left->val=vec[j]-sibsum;
                    q.push(cur->left);
                }

                if(cur->right){
                    cur->right->val=vec[j]-sibsum;
                    q.push(cur->right);
                }
            }
            j++;
        }


        return root;



        
        
    }
};