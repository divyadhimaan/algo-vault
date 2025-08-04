# Reverse Linked List

Practice [here](https://leetcode.com/problems/reverse-linked-list/)

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

## Iterative Solution
`Analogy`: Like flipping a chain link by link as you walk along it.

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* frontNode = head;
        ListNode* node = head;
        ListNode* tailNode = NULL;

        while(frontNode){
            node = frontNode;
            frontNode = frontNode->next;
            node->next = tailNode;
            tailNode = node;
        }

        return node;
    }
};
```

> Time Complexity: O(n), n-> number of nodes
>
> Space Complexity: O(1)

## Recursive Solution

`Analogy`: Like walking to the end of the chain, then flipping the links backward on your way back.
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
};
```


> Time Complexity: O(n)
>
> Space Complexity: O(n)