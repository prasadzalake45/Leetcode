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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long,vector<long>,greater<long>>pq;
        queue<TreeNode*>q;

        q.push(root);
        // pq.push(root->val);


        while(!q.empty()){

            int size=q.size();
            long sum=0;

            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                sum+=a->val;

                if(a->left!=NULL){
                    q.push(a->left);
                }
                if(a->right!=NULL){
                    q.push(a->right);
                }
            }
            pq.push(sum);

            if(pq.size()>k){
                pq.pop();
            }
        }


        return pq.size()<k?-1:pq.top();
        
    }
};