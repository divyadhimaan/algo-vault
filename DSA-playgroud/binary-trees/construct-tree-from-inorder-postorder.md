# Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the `postorder` traversal of the same tree, construct and return the binary tree.


```cpp
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
    TreeNode* buildTreeUtil(int inStart, int inEnd, vector<int>& postorder, int &postIdx, unordered_map<int,int> &inMap){
        if(postIdx<0 || inStart>inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int inIdx = inMap[root->val];
        
        root->right = buildTreeUtil(inIdx+1, inEnd, postorder, postIdx, inMap);
        root->left = buildTreeUtil(inStart, inIdx-1, postorder, postIdx, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;

        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        
        return buildTreeUtil(0, inorder.size()-1, postorder, postIdx, inMap);
    }
};
```