# Validate Binary Search Tree

Practice [here](https://leetcode.com/problems/validate-binary-search-tree/description/)

Given the `root` of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

1. The left subtree of a node contains only nodes with keys strictly less than the node's key.
2. The right subtree of a node contains only nodes with keys strictly greater than the node's key.
3. Both the left and right subtrees must also be binary search trees.

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
    bool validate(TreeNode* root, long low, long high)
    {
        if(!root)
            return true;
        
        if((root->val <=low) || (root->val >=high))
            return false;

        return validate(root->left, low, root->val) && validate(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX); 
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(h)

---

## Inorder Traversal (Strictly Increasing Check)

A valid BST's inorder traversal yields a strictly increasing sequence. Track the previously visited value and fail if the current node is not greater.

```cpp
class Solution {
    long prev = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return isValidBST(root->right);
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(h)

---

## Iterative Inorder (Stack)

Same inorder logic but with an explicit stack — avoids recursion overhead on skewed trees.

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        long prev = LLONG_MIN;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            if (root->val <= prev) return false;
            prev = root->val;
            root = root->right;
        }
        return true;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(h)

---

## Comparison

|                | Min/Max Bounds                   | Inorder Recursive           | Inorder Iterative           |
|----------------|----------------------------------|-----------------------------|-----------------------------|
| **Time**       | O(n)                             | O(n)                        | O(n)                        |
| **Space**      | O(h)                             | O(h)                        | O(h)                        |
| **Early exit** | Yes                              | Yes                         | Yes                         |
| **Intuition**  | Top-down range check             | BST property → sorted order | Same, no call stack         |
| **Best for**   | Most readable, interview default | Alternative angle           | Skewed trees / stack safety |