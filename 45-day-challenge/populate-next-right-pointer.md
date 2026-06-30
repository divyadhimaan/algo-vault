# Populate Next Right Pointers in Each Node

**Problem:** [LeetCode 116](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)  
**Difficulty:** Medium  
**Topic:** Binary Tree, BFS, Linked List

## Problem Summary

Given a **perfect binary tree**, populate each node's `next` pointer to point to its next right node at the same level. If no such node exists, `next` should be `NULL`.

---

## Approach 1: O(1) Space — Level Pointer Traversal

**Intuition:** Since it's a perfect binary tree, every internal node has exactly two children. We can wire up `next` pointers for level `k+1` while traversing level `k` using the `next` pointers we just established.

Two connections to make per node `curr` at the current level:
1. **Left → Right (same parent):** `curr->left->next = curr->right`
2. **Right → Left of next parent:** `curr->right->next = curr->next->left` (if `curr->next` exists)

Use `prev` to track the leftmost node of each level (the entry point), and drop down via `prev = prev->left` after each level is processed.

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return {};

        Node* prev = root;   // leftmost node of current level

        while (prev) {
            Node* curr = prev;

            while (curr && curr->left) {
                // connect left child to right child (same parent)
                curr->left->next = curr->right;

                // connect right child to left child of next parent
                if (curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next;  // move right across current level
            }

            prev = prev->left;  // drop down to next level
        }
        return root;
    }
};
```

**Time:** O(n) — every node visited once  
**Space:** O(1) — no extra data structures; traversal uses already-established `next` pointers

---

## Approach 2: BFS Level Order

**Intuition:** Process the tree level by level using a queue. Within each level, link `prev->next = curr` for every consecutive pair. Use the index `i` to skip the first node (no predecessor to link from).

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return {};

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* prev;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* currNode = q.front();
                q.pop();

                if (i != 0)
                    prev->next = currNode;   // link previous to current

                if (currNode->left)  q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);

                prev = currNode;
            }
            // last node in level keeps next = NULL (default)
        }
        return root;
    }
};
```

**Time:** O(n) — every node visited once  
**Space:** O(w) — queue holds one full level at a time; w = max width = n/2 at the last level of a perfect binary tree → O(n) worst case

---

## Comparison

| Approach | Time | Space | Works on any binary tree? |
|---|---|---|---|
| Level pointer traversal | O(n) | O(1) | No — perfect binary tree only |
| BFS level order | O(n) | O(n) | Yes |

**Prefer Approach 1** when the constraint guarantees a perfect binary tree — O(1) space is a significant win. For a general binary tree (LeetCode 117), use BFS.

## Notes

- Approach 1 relies on the perfect binary tree guarantee — if any node could be missing children, `curr->left` or `curr->next->left` might be NULL and the logic breaks.
- In Approach 2, `prev` is technically uninitialized before the loop but is always assigned before use (since we skip it when `i == 0`). Declaring `Node* prev = nullptr;` is safer style.
- `root->next = NULL` in Approach 2 is redundant — the constructor already sets `next = NULL`.
