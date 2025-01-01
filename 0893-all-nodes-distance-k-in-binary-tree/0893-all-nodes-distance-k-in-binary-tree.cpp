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
   
    void findParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parentTrack, TreeNode* target){

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                parentTrack[node->left]=node;
                q.push(node->left);

            }
            if(node->right){
                parentTrack[node->right]=node;
                q.push(node->right);


            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parentTrack;
        findParent(root,parentTrack,target);

        unordered_map<TreeNode*,bool>visited;
        int cur=0;

        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;

        while(!q.empty()){
            int size=q.size();
            if(cur==k){
                break;
            }
            cur++;

            for(int i=0;i<size;i++){
                TreeNode* curNode=q.front();
                q.pop();

                if(curNode->left && !visited[curNode->left]){
                    q.push(curNode->left);
                    visited[curNode->left]=true;
                }
                if(curNode->right && !visited[curNode->right]){
                    q.push(curNode->right);
                    visited[curNode->right]=true;
                }

                if(parentTrack[curNode] && !visited[parentTrack[curNode]]){
                    q.push(parentTrack[curNode]);
                    visited[parentTrack[curNode]]=true;
                }
            }
        }

        vector<int>result;

        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop();
            result.push_back(n->val);
        }

        return result;


        
    }
};