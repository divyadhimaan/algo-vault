# Same tree

Practice [here](https://leetcode.com/problems/same-tree/description/)

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


## Recursive Approach
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

> Time Complexity: `O(n)`
>
> Space Complexity: `O(h)`, Recursion stack height = height of the tree (h)

## Iterative Approach

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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p,q});

        while(!qu.empty())
        {
            auto [node1, node2] = qu.front();
            qu.pop();

            if(!node1 && !node2)
                continue;

            if(!node1 || !node2 || node1->val != node2->val)
                return false;

            qu.push({node1->left, node2->left});
            qu.push({node1->right, node2->right});
        }

        return true;
    }
};
```


> Time Complexity: `O(n)`
>
> Space Complexity: `O(n)`