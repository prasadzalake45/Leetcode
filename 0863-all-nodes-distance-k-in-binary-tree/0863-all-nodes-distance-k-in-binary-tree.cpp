class Solution {
public:
    void markedParentNode(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& Parent) {
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left) {
                    Parent[cur->left] = cur;
                    q.push(cur->left);
                }

                if (cur->right) {
                    Parent[cur->right] = cur;
                    q.push(cur->right);
                }
            }
        }
    }
    vector<int> helper(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> visited;
        vector<int> finalAns;
        markedParentNode(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            if (level++ == k) {
                break;
            }

            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (!visited.count(cur->left) && cur->left) {
                    q.push(cur->left);
                    visited.insert(cur->left);
                }

                if (!visited.count(cur->right) && cur->right) {
                    q.push(cur->right);
                    visited.insert(cur->right);
                }

                if (parent.find(cur) != parent.end() && !visited.count(parent[cur])
                    ) {
                    q.push(parent[cur]);
                    visited.insert(parent[cur]);
                }
            }
        }
        if (q.empty()) {
            return {};
        } else {
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                finalAns.push_back(cur->val);
            }
        }

        return finalAns;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) {
            return {};
        }
        return helper(root, target, k);
    }
};