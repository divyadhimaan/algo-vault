# Linked List Cycle

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

## Hash Approach

`Analogy`:  Like marking every door you pass; if you see a marked door again, you are in a loop.

```cpp
bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    while(head) {
        if(visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}
```

> Time Complexity: O(n)
>
> Space Complexity: O(n) (hash set)

## Floyd's Cycle Detection: Hare-tortoise method
`Analogy`: A fast runner will eventually lap the slow runner on a circular track if a cycle exists.

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        while(fastPointer && fastPointer->next)
        {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
            if(slowPointer==fastPointer)
                return true;
        }
        
        return false;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)


