/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void findParent(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&ParentTrack){

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){

        TreeNode* node=q.front();
        q.pop();

        if(node->left){
            ParentTrack[node->left]=node;
            q.push(node->left);
        }

        if(node->right){
            ParentTrack[node->right]=node;
            q.push(node->right);

        }

    }

   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

       unordered_map<TreeNode*,TreeNode*>ParentTrack;

       findParent(root,target,ParentTrack);

        vector<int>result;
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int cur=0;

        while(!q.empty()){
            int size=q.size();

            if(cur==k){
                break;
            }

            cur++;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }

                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }

                if(ParentTrack[node] && !vis[ParentTrack[node]]){
                    q.push(ParentTrack[node]);
                    vis[ParentTrack[node]]=true;
                }






            }
        }

        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            result.push_back(n->val);
        }

        return result;

        
    }
};