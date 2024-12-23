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

   int countSwapsToSort(vector<int>& arr) {
        int swaps=0;
        vector<int>sortedArray(arr.begin(),arr.end());
        sort(sortedArray.begin(),sortedArray.end());
        

        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;

        }


        for(int i=0;i<arr.size();i++){
            if(arr[i]==sortedArray[i]){
                continue;
            }

            else{

                int curIdx=mp[sortedArray[i]];
                mp[arr[i]]=curIdx;
                swap(arr[curIdx],arr[i]);
                swaps++;
            }
        }
       return swaps;




}
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        int totalSwaps=0;
        int level=0;
       

        while(!q.empty()){
            int size=q.size();
             vector<int>ans;

            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();

                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }

                ans.push_back(it->val);
            }

         totalSwaps += countSwapsToSort(ans);




        }

        return totalSwaps;
        
    }
};