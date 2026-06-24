# Path Sum II

**Problem:** [LeetCode 113](https://leetcode.com/problems/path-sum-ii/)  
**Difficulty:** Medium  
**Topic:** Binary Tree, DFS, Backtracking

## Problem Summary

Given the root of a binary tree and a `targetSum`, return all root-to-leaf paths where the node values sum to `targetSum`. Each path is returned as a list of values.

## Approach: DFS + Backtracking

Traverse every root-to-leaf path, decrementing `targetSum` at each node. At a leaf, if `targetSum == 0`, the path is valid — add it to results. Backtrack by popping the current node off `temp` before returning.

**Key insight:** subtracting `root->val` from `targetSum` (instead of accumulating a sum) avoids needing an extra parameter — the remaining target carries the state.

## Solution

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

## Complexity

|       |                                                   |
|-------|---------------------------------------------------|
| Time  | O(n²) — O(n) nodes × O(n) to copy each valid path |
| Space | O(h) — recursion stack + `temp`, h = tree height  |

## Notes

- `temp` and `result` are passed by reference to avoid copying on every call.
- The leaf check (`!root->left && !root->right`) ensures internal nodes with a zero remaining sum don't get recorded.
- `temp.pop_back()` is the backtracking step — restores `temp` to its state before visiting this node.
