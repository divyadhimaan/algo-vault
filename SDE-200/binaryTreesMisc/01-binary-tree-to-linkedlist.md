# Flatten Binary Tree to Linked List

Practice [Link](https://leetcode.com/problems/flood-fill/description/)

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

## RECURSION

```cpp
class Solution {
public:
    TreeNode* prev=NULL;

    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        prev= root;
        root->left = NULL;
    }
};
```


## USING STACK

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {

        if(!root)
            return;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty())
        {
            TreeNode* curr = stk.top();
            stk.pop();

            if(curr->right)
                stk.push(curr->right);
            if(curr->left)
                stk.push(curr->left);
            if(!stk.empty())
                curr->right = stk.top();
            curr->left = NULL;

        }
    }
};
```

## MORRIS MODIFIED

```cpp
class Solution {
public:

    TreeNode* findPredicate(TreeNode* root)
    {
        while(root->right)
        {
            root=root->right;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr)
        {
            if(curr->left)
            {
                TreeNode* prev = findPredicate(curr->left);

                prev->right = curr->right;
                curr->right = curr->left;
                
                curr->left = NULL;
            }
            curr=curr->right;
        }
    }
};
```
