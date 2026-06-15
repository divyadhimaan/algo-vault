# Lowest Common Ancestor of a Binary Tree

Practice [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)


Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

## Recursive Solution

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;

        TreeNode* leftNode = lowestCommonAncestor(root->left, p,q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p,q);

        if(!leftNode)   
            return rightNode;
        if(!rightNode)
            return leftNode;

        return root;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n) in worst case (skewed tree), O(log n) = O(h) in best case (balanced tree)

---

## Parent Pointers + Hash Set

Walk the tree to build a `parent` map for every node. Then trace ancestors of `p` into a set, and walk `q`'s ancestors until one hits the set.

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;

        stack<TreeNode*> stk;
        stk.push(root);

        // populate parent map until both p and q are found
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = stk.top(); stk.pop();
            if (node->left) {
                parent[node->left] = node;
                stk.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                stk.push(node->right);
            }
        }

        // collect all ancestors of p
        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        // first ancestor of q that's also an ancestor of p
        while (ancestors.find(q) == ancestors.end())
            q = parent[q];

        return q;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

---

## Path Compression (Path to Root)

Find the full root-to-node paths for both `p` and `q`, then walk them together from the front and return the last node where they agree.

```cpp
class Solution {
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if (findPath(root->left, target, path) || findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        TreeNode* lca = nullptr;
        for (int i = 0; i < (int)min(pathP.size(), pathQ.size()); i++) {
            if (pathP[i] == pathQ[i])
                lca = pathP[i];
            else
                break;
        }
        return lca;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n) for the two paths

---

## Comparison

|                | Recursive             | Parent Pointers + Hash Set                | Path Compression           |
|----------------|-----------------------|-------------------------------------------|----------------------------|
| **Time**       | O(n)                  | O(n)                                      | O(n)                       |
| **Space**      | O(h) stack            | O(n)                                      | O(n)                       |
| **Style**      | Implicit post-order   | Iterative, explicit parents               | Two explicit paths         |
| **Early exit** | Yes (returns on find) | Yes (stops once p & q found)              | No (traverses full paths)  |
| **Best for**   | Clean, minimal code   | When parent pointers are needed elsewhere | When full paths are useful |