# Delete Node in a Linked List O(1)

Write a function to delete a node in a singly-linked list, given only access to that node.

You will not be given access to the head of the list, instead you will be given a reference to the node that needs to be deleted. It is guaranteed that the node to be deleted is not the tail of the list.

You must modify the linked list in-place without returning anything.


## Data Overwriting

Since we cannot access the previous node, we will overwrite the data for all upcoming nodes

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        
       //data overwriting
       ListNode* tail = NULL;

       while(node->next){
        node->val = node->next->val;
        tail = node;
        node=node->next;
       }
       tail->next = NULL;
    }
};
```

> Time Complexity:O(n), where n is the number of nodes from the node to be deleted to the tail of the linked list.
> 
> Space Complexity:O(1), as the algorithm uses a constant amount of extra space.