# Serialize and Deserialize Binary Tree

Practice [Here](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.


```cpp
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
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);

        string str = "";

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node){
                str += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
            else
                str += "N,";
        }
        str.pop_back();
        cout<<str<<endl;
        return str;
    }

    TreeNode* buildTree(vector<string> &nodeVals)
    {
        if(nodeVals.size()==1){
            return new TreeNode(stoi(nodeVals[0]));
        }

        TreeNode* root = new TreeNode(stoi(nodeVals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i =1;
        while(!q.empty() && i < nodeVals.size())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(i<nodeVals.size() && nodeVals[i] != "N")
            {
                curr->left = new TreeNode(stoi(nodeVals[i]));
                q.push(curr->left);
            }
            i++;

            if(i<nodeVals.size() && nodeVals[i] != "N")
            {
                curr->right = new TreeNode(stoi(nodeVals[i]));
                q.push(curr->right);
            }
            i++;

        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size()==0)
            return NULL;

        vector<string> nodeVals;
        stringstream ss(data);
        string nodeVal;

        while(getline(ss, nodeVal, ',')){
            nodeVals.push_back(nodeVal);
        }

        TreeNode* root = buildTree(nodeVals);
        cout<<root->val;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```

# Complexities

| Function      | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| `serialize`   | O(n)            | O(n)             |
| `deserialize` | O(n)            | O(n)             |
