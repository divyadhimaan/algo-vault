# Balanced Bianry Tree


## Naive Approach

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
private:
    int getHeight(TreeNode* root){
        if(!root)
            return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);


        return max(lh, rh)+1;
    }
public:

    bool isBalanced(TreeNode *root){
    	if(!root)
            return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};
```

Note: the `isBalanced` function calculates the height of subtrees repeatedly, leading to a time complexity of O(n^2). This can be improved by calculating the height and balance status in a single pass.

> Time Complexity: O(n<sup>2</sup>), worst case O(n^2) for skewed tree, best case O(nlogn) for balanced tree.
> 
> Space Complexity: O(h)

## Better Solution


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
private:
    int getHeight(TreeNode* root){
        if(!root)
            return 0;
        int lh = getHeight(root->left);
        if(lh==-1)
            return -1;
        int rh = getHeight(root->right);
        if(rh==-1)
            return -1;
        
        if(abs(lh-rh)> 1)
            return -1;

        return max(lh, rh)+1;
    }
public:

    bool isBalanced(TreeNode *root){
    	return getHeight(root) != -1;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(h)