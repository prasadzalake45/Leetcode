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

    void helper(TreeNode* root,map<int,vector<pair<int,int>>>&mp){

         queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        

        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();

                mp[y].push_back({x,node->val});

                if(node->left){
                    q.push({node->left,{x+1,y-1}});
                }

                if(node->right){
                    q.push({node->right,{x+1,y+1}});
                }




            }
        }
        



    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>>answer;
        map<int,vector<pair<int,int>>>mp;
        helper(root,mp);

        // sort(mp.begin(),mp.end());

        for(auto& [col,nodes]:mp){

            sort(nodes.begin(),nodes.end());

            vector<int>temp;

            for(auto [row,value]:nodes){
                temp.push_back(value);
            }

            answer.push_back(temp);

            
            
           
        }

       
        
        return answer;
        

    }
};