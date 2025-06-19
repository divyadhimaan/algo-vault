# Floor in BST

Practice [Link](https://www.geeksforgeeks.org/problems/floor-in-bst/1)

You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.


```cpp
class Solution{

public:
    int floor(Node* root, int x) {
        int f = -1;
        while(root)
        {
            if(root->data <= x)
            {
                f = root->data;
                if(root->data ==x)
                    break;
                else
                    root=root->right;
            }else
                root=root->left;
        }
        return f;
    }
};
```


> Time Complexity:
> - Average -> O(logn) (balanced)
> - Worst -> O(n) (skewed)
>
> Space Complexity: O(1)