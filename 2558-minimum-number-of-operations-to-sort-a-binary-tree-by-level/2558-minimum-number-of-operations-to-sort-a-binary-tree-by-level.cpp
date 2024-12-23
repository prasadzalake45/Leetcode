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
        int n = arr.size();
        vector<pair<int, int>> pairedArray(n);

        // Pair values with their original indices
        for (int i = 0; i < n; ++i) {
            pairedArray[i] = {arr[i], i};
        }

        // Sort pairs based on the values
        sort(pairedArray.begin(), pairedArray.end());

        // Count swaps
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || pairedArray[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pairedArray[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
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