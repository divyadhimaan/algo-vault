# Right Side View of Binary Tree

**Problem:** [LeetCode 199](https://leetcode.com/problems/binary-tree-right-side-view/)  
**Difficulty:** Medium  
**Topic:** Binary Tree, BFS, DFS

## Problem Summary

Given the root of a binary tree, return the values of the nodes visible when looking at the tree from the right side, ordered top to bottom. The rightmost node at each level is what's visible.

---

## Approach 1: BFS (Level Order) 

Process the tree level by level. For each level, the **last node dequeued** is the rightmost visible node.

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == size - 1)
                    result.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return result;
    }
};
```

**Complexity:** Time O(n), Space O(w) where w = max width of tree

---

## Approach 2: DFS (Preorder, Right-First)

Traverse right child before left. The first time we reach a new depth, that node is the rightmost at that level.

```cpp
class Solution {
    void dfs(TreeNode* root, int depth, vector<int> &result) {
        if (!root) return;

        if (depth == result.size())       // first visit to this level
            result.push_back(root->val);

        dfs(root->right, depth + 1, result);
        dfs(root->left,  depth + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};
```

**Key insight:** visiting right before left guarantees the first node seen at each depth is the rightmost one. `result.size()` acts as a depth watermark.

**Complexity:** Time O(n), Space O(h) — recursion stack

---

## Approach 3: DFS (Postorder, Left-First, Overwrite)

Traverse left child before right. Overwrite `result[depth]` at every visit — the last write at each depth will be the rightmost node.

```cpp
class Solution {
    void dfs(TreeNode* root, int depth, vector<int> &result) {
        if (!root) return;

        if (depth == (int)result.size())
            result.push_back(root->val);
        else
            result[depth] = root->val;   // overwrite with rightmost seen so far

        dfs(root->left,  depth + 1, result);
        dfs(root->right, depth + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};
```

**Complexity:** Time O(n), Space O(h)

---

## Comparison

| Approach                 | Time | Space | Notes                                           |
|--------------------------|------|-------|-------------------------------------------------|
| BFS (level order)        | O(n) | O(w)  | Intuitive; w can be O(n) at widest level        |
| DFS right-first          | O(n) | O(h)  | Cleanest; no overwriting needed                 |
| DFS left-first overwrite | O(n) | O(h)  | Visits all nodes unnecessarily for this problem |

**Prefer Approach 2** for space efficiency — O(h) vs O(w), and h ≤ w in wide trees.

## Notes

- The early returns in your solution (`!root`, `!root->left && !root->right`) are correct but the leaf check is redundant — the BFS loop handles single nodes fine without it.
- Right side view is not always the rightmost node in the tree — a node with only a left subtree at a given level is still visible from the right.
