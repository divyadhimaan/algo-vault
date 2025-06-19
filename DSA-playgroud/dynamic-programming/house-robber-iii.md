# House Robber - III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return **the maximum amount of money the thief can rob without alerting the police.**

Practice [Link](https://leetcode.com/problems/house-robber-iii/description/)


### Recursive

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
    int robUtil(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int rob = 0, notRob = 0;

        rob += root->val;

        if(root->left)
            rob += robUtil(root->left->left) + robUtil(root->left->right);
        if(root->right)
            rob += robUtil(root->right->left) + robUtil(root->right->right);

        notRob = robUtil(root->left) + robUtil(root->right, memo);

        return max(rob, notRob);
    }

    int rob(TreeNode* root) {
        return robUtil(root);
    }
};
```

> Time Complexity: O(2^n) -> TLE
> 
> Space Complexity: O(n)


### Memoized version

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
    int robUtil(TreeNode* root, unordered_map<TreeNode*, int> &memo)
    {
        if(!root)
            return 0;

        if(memo.find(root) != memo.end())
            return memo[root];
        
        int rob = 0, notRob = 0;

        rob += root->val;

        if(root->left)
            rob += robUtil(root->left->left, memo) + robUtil(root->left->right, memo);
        if(root->right)
            rob += robUtil(root->right->left, memo) + robUtil(root->right->right, memo);

        notRob = robUtil(root->left, memo) + robUtil(root->right, memo);

        return memo[root] = max(rob, notRob);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return robUtil(root, memo);
    }
};

```

> Time Complexity: O(logn)
> 
> Space Complexity: O(n)

