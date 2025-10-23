# Add two numbers as LL

Given two non-empty linked lists l1 and l2 which represent two non-negative integers.

The digits are stored in reverse order with each node storing one digit.
Add two numbers and return the sum as a linked list.

- The sum Linked List will be in reverse order as well.
- The Two given Linked Lists represent numbers without any leading zeros, except when the number is zero itself.

## Using Dummy Node

```cpp
/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tailPointer = dummyHead;

        int carry = 0;
        while(l1 || l2){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = num1 + num2 + carry;
            carry = sum/10;

            ListNode* curr = new ListNode(sum%10);
            tailPointer->next = curr;
            tailPointer = tailPointer->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry){
            ListNode* curr = new ListNode(carry);
            tailPointer->next = curr;
            tailPointer = tailPointer->next;
        }

        return dummyHead->next;
    }
};
```

> Time Complexity:O(max(m,n)), where m and n are the lengths of the two linked lists.
> 
>Space Complexity:O(max(m,n)), where m and n are the lengths of the two linked lists, due to the creation of a new linked list to store the result.