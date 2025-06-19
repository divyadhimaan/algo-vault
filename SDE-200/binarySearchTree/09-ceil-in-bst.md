# Ceil in BST

Practice [Link](https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1)


Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.


```cpp
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int c=-1;
    while(root)
    {
        if(root->data>=input)
        {
            c=root->data;
            if(c==input)
                break;
            else
                root=root->left;
        }else
            root=root->right;
        
    }
    return c;
    
}
```

> Time Complexity:
> - Average -> O(logn) (balanced)
> - Worst -> O(n) (skewed)
>
> Space Complexity: O(1)