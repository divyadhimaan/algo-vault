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

---

## Variation: p or q Might Not Exist

The standard recursive solution returns early when it *finds* p or q, assuming the other must exist somewhere. If either node might be absent, we can't do that — we must fully traverse the tree and confirm both were actually found.

**Key idea:** track a `found` count alongside the LCA candidate. Only return a non-null LCA if both nodes were seen.

```cpp
class Solution {
    int found = 0; // counts how many of {p, q} were found

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        TreeNode* left  = dfs(root->left,  p, q);
        TreeNode* right = dfs(root->right, p, q);

        // check current node after children (post-order)
        if (root == p || root == q) {
            found++;
            return root;
        }

        if (left && right) return root;   // one on each side → LCA
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* candidate = dfs(root, p, q);
        return found == 2 ? candidate : nullptr;
    }
};
```

**Why post-order matters here:** we visit children *before* checking `root == p/q`. This ensures that if `p` is an ancestor of `q`, `q` is counted as found (in the subtree) before we count `p` itself — so `found` correctly reaches 2 when both exist.

> Time Complexity: O(n) — full traversal always
>
> Space Complexity: O(h) recursion stack

---

## Variation: Nodes Have Parent Pointers

Each node has a `parent` field, so we can walk upward from any node to the root like a linked list.

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
```

### Approach 1: Hash Set of Ancestors

Walk up from `p`, storing every ancestor in a set. Then walk up from `q` until hitting a node already in the set.

```cpp
Node* lowestCommonAncestor(Node* p, Node* q) {
    unordered_set<Node*> ancestors;
    while (p) {
        ancestors.insert(p);
        p = p->parent;
    }
    while (ancestors.find(q) == ancestors.end())
        q = q->parent;
    return q;
}
```

> Time O(h), Space O(h)

### Approach 2: Two-Pointer (O(1) Space)

Same idea as finding the intersection of two linked lists. Both pointers walk up; when one hits null it restarts from the *other's* original position. They meet at LCA after at most `depth(p) + depth(q)` steps.

```cpp
Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* a = p;
    Node* b = q;
    while (a != b) {
        a = a ? a->parent : q;
        b = b ? b->parent : p;
    }
    return a;
}
```

**Why it works:** pointer `a` travels `depth(p)` steps then `depth(q)` steps; pointer `b` travels `depth(q)` then `depth(p)`. Both cover the same total distance, so they meet exactly at the LCA.

> Time O(h), Space O(1)

---

## Variation: LCA of Multiple Nodes

Find the LCA of all nodes in a given array (not just two).

### Approach 1: Reduce to Pairwise LCA

LCA is associative: `LCA(a, b, c) = LCA(LCA(a, b), c)`. So fold over the array, accumulating the result.

```cpp
class Solution {
    TreeNode* lca2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left  = lca2(root->left,  p, q);
        TreeNode* right = lca2(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        TreeNode* result = nodes[0];
        for (int i = 1; i < nodes.size(); i++)
            result = lca2(root, result, nodes[i]);
        return result;
    }
};
```

> Time O(k · n), Space O(h) — k calls each costing O(n). Fine for small `k`, expensive otherwise.

### Approach 2: Single-Pass DFS with a Set (Optimal)

Put all target nodes in a hash set. Run one DFS — same logic as the 2-node recursive solution, but check `nodeSet.count(root)` instead of `root == p || root == q`.

**Key insight:** if a node in the set is an ancestor of another node in the set, returning early at the ancestor is still correct — the ancestor already "covers" its descendants for LCA purposes.

```cpp
class Solution {
    unordered_set<TreeNode*> nodeSet;

    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;
        if (nodeSet.count(root)) return root; // covers all descendants in set too

        TreeNode* left  = dfs(root->left);
        TreeNode* right = dfs(root->right);

        if (left && right) return root;
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        nodeSet = {nodes.begin(), nodes.end()};
        return dfs(root);
    }
};
```

> Time O(n), Space O(n) for the set + O(h) stack