# Kth Smallest Element in a BST

practice [here](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

Given the `root` of a binary search tree, and an integer `k`, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

## Brute Force

- Find any traversal of BST
- Sort the stored traversal
- return k-1 element

> Time Complexity: O(nlogn)
>
> Space Complexity: O(n)

## Better Approach
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
    void inOrderTraversal(TreeNode* root, vector<int> &inorder)
    {
        if(!root)
            return;

        inOrderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inOrderTraversal(root->right, inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        inOrderTraversal(root, inorder);
        return inorder[k-1];
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Optimal Approach
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
    void inOrderTraversal(TreeNode* root, int &cnt, int &ans, int k)
    {
        if(!root)
            return;

        inOrderTraversal(root->left, cnt, ans, k);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        inOrderTraversal(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        inOrderTraversal(root, cnt, ans, k);
        return ans;
    }
};
```


> Time Complexity: O(n)
>
> Space Complexity: O(1)