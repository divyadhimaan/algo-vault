# Middle of Linked List

Given the head of a singly Linked List, return the middle node of the Linked List.

If the Linked List has an even number of nodes, return the second middle one.


## Brute Force

- Find length of linked list
- Traverse till length/2

> Time Complexity: O(N) -> 2 traversals
> 
> Space Complexity: O(1)


## Better Approach
Use hare-tortoise approach
```cpp
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* middleOfLinkedList(ListNode* head) {
        ListNode* frontNode = head;
        ListNode* tailNode = head;

        while(frontNode && frontNode->next){
            frontNode = frontNode->next->next;
            tailNode = tailNode->next;
        }
        return tailNode;
    }
};
```

> Time Complexity: O(N) -> 1 traversal
>
> Space Complexity: O(1)