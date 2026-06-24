# Path Sum II

**Problem:** [LeetCode 113](https://leetcode.com/problems/path-sum-ii/)  
**Difficulty:** Medium  
**Topic:** Binary Tree, DFS, Backtracking

## Problem Summary

Given the root of a binary tree and a `targetSum`, return all root-to-leaf paths where the node values sum to `targetSum`. Each path is returned as a list of values.

---

## Approach 1: DFS + Backtracking (Optimal) 

Traverse every root-to-leaf path, decrementing `targetSum` at each node. At a leaf, if `targetSum == 0`, the path is valid. Backtrack by popping before returning.

**Key insight:** subtracting `root->val` from `targetSum` instead of accumulating avoids an extra parameter — the remaining target carries the state.

```cpp
class Solution {
public:
    void findPath(TreeNode* root, int targetSum, vector<int> &temp, vector<vector<int>> &result) {
        if (!root) return;

        targetSum -= root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right && targetSum == 0)
            result.push_back(temp);

        findPath(root->left,  targetSum, temp, result);
        findPath(root->right, targetSum, temp, result);

        temp.pop_back();   // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        findPath(root, targetSum, temp, result);
        return result;
    }
};
```

**Complexity:** Time O(n²), Space O(h)

---

## Approach 2: DFS with Running Sum (Accumulate Instead of Decrement)

Build up `currSum` as we descend. At a leaf, check if `currSum == targetSum`. Functionally identical to Approach 1 — just a different way to carry state.

```cpp
class Solution {
    void dfs(TreeNode* root, int currSum, int targetSum, vector<int> &temp, vector<vector<int>> &result) {
        if (!root) return;

        currSum += root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right && currSum == targetSum)
            result.push_back(temp);

        dfs(root->left,  currSum, targetSum, temp, result);
        dfs(root->right, currSum, targetSum, temp, result);

        temp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(root, 0, targetSum, temp, result);
        return result;
    }
};
```

**Complexity:** Time O(n²), Space O(h)

---

## Approach 3: Iterative DFS with Explicit Stack

Replaces recursion with an explicit stack. Each stack entry holds the current node, remaining target, and the path so far.

```cpp
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> result;
        // stack of {node, remaining_sum, path}
        stack<tuple<TreeNode*, int, vector<int>>> stk;
        stk.push({root, targetSum - root->val, {root->val}});

        while (!stk.empty()) {
            auto [node, rem, path] = stk.top();
            stk.pop();

            if (!node->left && !node->right && rem == 0)
                result.push_back(path);

            if (node->right) {
                auto p = path;
                p.push_back(node->right->val);
                stk.push({node->right, rem - node->right->val, p});
            }
            if (node->left) {
                auto p = path;
                p.push_back(node->left->val);
                stk.push({node->left, rem - node->left->val, p});
            }
        }
        return result;
    }
};
```

**Tradeoff:** no recursion stack overflow risk, but copies the path vector at every push — higher constant factor in practice.

**Complexity:** Time O(n²), Space O(n·h) — stores path copies on the stack

---

## Comparison

| Approach                | Time  | Space  | Notes                                             |
|-------------------------|-------|--------|---------------------------------------------------|
| DFS + backtrack (yours) | O(n²) | O(h)   | Optimal space; clean and idiomatic                |
| DFS accumulate sum      | O(n²) | O(h)   | Same idea, slightly more parameters               |
| Iterative DFS           | O(n²) | O(n·h) | No recursion risk; worse space due to path copies |

**Approach 1 is best** — backtracking reuses a single `temp` vector, avoiding the path copies that make Approach 3 heavier.

## Notes

- `temp` and `result` are passed by reference to avoid copying on every call.
- The leaf check (`!root->left && !root->right`) ensures internal nodes with a zero remaining sum don't get recorded.
- `temp.pop_back()` is the backtracking step — restores `temp` to its state before visiting this node.
