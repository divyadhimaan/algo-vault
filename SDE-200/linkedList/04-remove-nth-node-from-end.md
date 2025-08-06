# Remove Nth Node From End of List

Practice [here](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.


## Naive approach

> Requires 2 traversals

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int length(ListNode* head)
    {
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        ListNode* curr = head;

        int nth = len - n + 1;

        if(n==len)
            return head->next;

        for(int i=1;i<nth-1;i++){
            curr=curr->next;
        }

        curr->next = curr->next->next;
        return head;
    }
};
```

## Better Approach

> Requires 1 traversal

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++)
            fast=fast->next;

        if(!fast)
            return head->next;

        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;
        return head;
    }
};
```