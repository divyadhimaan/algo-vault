# Construct Binary Tree from Preorder and Inorder Traversal

Pratice [here](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.


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

    TreeNode* buildTreeUtil(int inStart, int inEnd, vector<int>& preorder, int &preIdx, unordered_map<int,int> &inMap){
        if(preIdx>= preorder.size() || inStart>inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = inMap[root->val];
        
        root->left = buildTreeUtil(inStart, inIdx-1, preorder, preIdx, inMap);
        root->right = buildTreeUtil(inIdx+1, inEnd, preorder, preIdx, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        
        return buildTreeUtil(0, inorder.size()-1, preorder, preIdx, inMap);
    }
};
```