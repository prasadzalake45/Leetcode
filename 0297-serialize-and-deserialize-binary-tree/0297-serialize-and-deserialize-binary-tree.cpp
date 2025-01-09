/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root==NULL){
            return "#,";
        }

        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
        
    }

    // Decodes your encoded data to tree.

    TreeNode* deHelper(queue<string>&nodes){
        if(nodes.empty()){
            return NULL;
        }

        string val=nodes.front();
        nodes.pop();

        if(val=="#"){
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(val));
        root->left=deHelper(nodes);
        root->right=deHelper(nodes);

        return root;


    }
    TreeNode* deserialize(string data) {


        queue<string>nodes;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            nodes.push(token);
        }
        

        return deHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));